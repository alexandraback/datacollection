#include <math.h>
#include <search.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define SCANF(fmt, n, args...)						\
do {									\
	int __rc = scanf(fmt, args);					\
	if (__rc != (n))						\
		die("scanf: wanted %d, got %d\n", (int)(n), __rc);	\
} while (false)

#define FWRITE(P, Sz, Nm, Fs)						\
do {									\
	size_t __r = fwrite((P), (Sz), (Nm), (Fs));			\
	if (__r != (Nm))						\
		die("fwrite: wanted %zu, got %zu\n", (size_t)(Nm), __r);\
} while (false)

#define ASSERT(x) ({ if (!(x)) {					\
	printf("failed assert " #x " on %s:%d\n", __func__, __LINE__);	\
	abort();							\
} })

static void
die(const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	vprintf(fmt, ap);
	va_end(ap);

	exit(1);
}

#define min(x, y) ({					\
	typeof(x) _min1 = (x);				\
	typeof(y) _min2 = (y);				\
	(void) (&_min1 == &_min2);			\
	_min1 < _min2 ? _min1 : _min2; })

const double epsilon = 0.0000001;

static int
hand_compare(const void *a, const void *b)
{
	const double *pc1 = a, *pc2 = b;

	if (*pc1 < *pc2)
		return -1;
	else if (*pc1 > *pc2)
		return 1;
	return 0;
}


double Naomi[1000];
double NaomiW[1000];
double Ken[1000];
double KenW[1000];
unsigned N;

static int
can_ken_beat(double val, double *khand, int start, unsigned lo, unsigned hi)
{
	unsigned i = lo;

	if (start >= 0 && start >= (int)lo)
		i = (unsigned)start;

	for (; i <= hi; i++)
		if (khand[i] > val)
			return i;

	return -1;
}

static unsigned
score_war(void)
{
	unsigned nscr = 0;
	unsigned i, kenhi = N - 1, kenlo = 0;

	int previdx = -1;
	for (i = 0; i < N; i++) {
		// shortcut if all of our cards are better than all of ken's
		if (NaomiW[i] > KenW[kenhi]) {
			nscr += N - i;
			break;
		}

		// Naomi plays smallest to largest
		int idx = can_ken_beat(NaomiW[i], KenW, previdx, kenlo, kenhi);
		if (idx < 0) {
			// ken can't beat
			nscr++;
			KenW[kenlo] = 0.;
			kenlo++;
		} else {
			// ken beats us
			KenW[idx] = 0.;
			if ((unsigned)idx == kenhi)
				kenhi--;
			else if ((unsigned)idx == kenlo)
				kenlo++;

			previdx = idx + 1;
		}
	}

	return nscr;
}

static unsigned
score_dw(void)
{
	unsigned nscr = 0,
		 kenlo = 0, kenhi = N-1,
		 namlo = 0, namhi = N-1,
		 turns = 0;

	//printf("XXX dw: turns: %u/%u\n", turns, N);
	while (turns < N) {
		while (turns < N && Naomi[namhi] > Ken[kenlo]) {
			// Use one of ours to beat his lowest:
			int idx = can_ken_beat(Ken[kenlo], Naomi, -1, namlo,
			    namhi);
			// guaranteed by N[namhi] > Ken[kenlo]
			ASSERT(idx >= 0);

			nscr++;
			//printf("XXX + (%f vs %f) N:%f(%u) K:%f(%u) (%u)\n",
			//    Naomi[(unsigned)idx], Ken[kenlo],
			//    Naomi[namhi], namhi,
			//    Ken[kenhi], kenhi, nscr);

			kenlo++;
			Naomi[(unsigned)idx] = 0.;
			if ((unsigned)idx == namlo)
				namlo++;
			if ((unsigned)idx == namhi)
				namhi--;

			turns++;
			//printf("XXX dw: turns: %u/%u\n", turns, N);
		}

#if 0
		while (turns < N && Naomi[namhi] > Ken[kenhi]) {
			nscr++;
			printf("XXX + N:%f(%u) K:%f(%u) (%u)\n", Naomi[namhi], namhi,
			    Ken[kenhi], kenhi, nscr);

			// We play our highest truthfully, he folds with lowest
			namhi--;
			kenlo++;

			turns++;
			printf("XXX dw: turns: %u/%u\n", turns, N);
		}
#endif

		if (turns >= N)
			break;

		// find lowest non-discarded piece
		while (Naomi[namlo] == 0.)
			namlo++;

		// XXX is this the optimal time to burn our lowest ??? probably
		ASSERT(Naomi[namlo] < Ken[kenlo]);
		//printf("XXX _ (%f vs %f) N:%f(%u) K:%f(%u) (%u)\n",
		//    Naomi[namlo], Ken[kenhi],
		//    Naomi[namhi], namhi,
		//    Ken[kenhi], kenhi, nscr);

		namlo++;
		kenhi--;

		turns++;
		//printf("XXX dw: turns: %u/%u\n", turns, N);
	}

	return nscr;
}

// For the given hands, compute Naomi's optimal War and DWar scores.
static void
do_case(unsigned cno)
{
	unsigned W, DW;

	// Sort hands smallest to largest.
	qsort(Naomi, N, sizeof(Naomi[0]), hand_compare);
	qsort(Ken, N, sizeof(Ken[0]), hand_compare);

	memcpy(NaomiW, Naomi, N * sizeof(Naomi[0]));
	memcpy(KenW, Ken, N * sizeof(Ken[0]));

	W = score_war();
	DW = score_dw();

	printf("Case #%u: %u %u\n", cno, DW, W);
}



// War:
//  - Each player gets N blocks
//  - Over N turns,
//    - Naomi picks one, announces weight
//    - Ken picks one
//    - Compare, heavier gets 1pt.
//
// Optimal strategy for Ken:
//  - Play lowest piece that can beat Naomi, or burn lowest piece.
//
// Deceitful war: Naomi knows Ken's pieces AND can lie about her weights, so
// long as comparison stays true.
//
// Optimal Naomi strategy:
//   - While she has a larger piece than Ken, play that piece truthfully.
//   - While she doesn't, play her smallest piece but lie and say it weighs
//     epsilon less than Ken's highest piece (force him to burn a good piece)
//     THIS MUST NOT BE ONE OF KEN's PIECES nor one of Naomi's.
int
main(void)
{
	unsigned Tcases, i;

	SCANF("%u", 1, &Tcases);
	for (i = 1; i <= Tcases; i++) {

		SCANF("%u", 1, &N);
		//printf("XXX N:%u\n", N);

		// Naomi's in KG
		for (unsigned j = 0; j < N; j++)
			SCANF("%lf", 1, &Naomi[j]);
		// Ken's in KG
		for (unsigned j = 0; j < N; j++)
			SCANF("%lf", 1, &Ken[j]);

		do_case(i);
	}

	return 0;
}
