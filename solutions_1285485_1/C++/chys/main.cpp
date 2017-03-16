#undef NDEBUG
#include <assert.h>
#include <set>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>

#include <gmpxx.h>

namespace {

typedef mpz_class Z;
typedef mpq_class Frac;

struct Pt
{
	Frac i, j;

	Pt &operator -= (const Pt &o) { i -= o.i; j -= o.j; return *this; }
	Pt operator - (const Pt &o) const { return Pt(*this)-=o; }
	Frac sqr_norm () const { return (i*i + j*j); }

	bool operator < (const Pt &o) const
	{
		int ci = cmp(i, o.i);
		return (ci < 0) || (ci == 0 && (j < o.j));
	}
};

struct Input
{
	uint8_t M[32][32];
	size_t H, W;
	unsigned D;
	Frac OI, OJ;
};

Input input[128];

uint8_t M[32][32];
size_t H, W;
unsigned D;
Frac OI, OJ;

std::set<Pt> get_dests ()
{
	Pt OP {OI, OJ};
	std::set<Pt> DEST {OP};
	size_t num = 0;
	while (DEST.size() > num) {
		num = DEST.size();
		// Vertical mirror
		for (size_t j=0; j<W; ++j) {
			bool mirror = false;
			for (size_t i=0; i<H; ++i)
				if (M[i][j-1] != M[i][j]) {
					mirror = true;
					break;
				}
			// Mirror by vertical j
			if (mirror) {
				for (const auto &IJ : std::set<Pt>(DEST)) {
					Pt NP {IJ.i, 2*j-IJ.j};
					if ((OP - NP).sqr_norm() <= D * D)
						DEST.insert(NP);
				}
			}
		}
		for (size_t i=0; i<H; ++i) {
			if (memcmp(M[i-1], M[i], sizeof(M[0]))) {
				// Mirror by horizontal i
				for (const auto &IJ : std::set<Pt>(DEST)) {
					Pt NP {2*i-IJ.i, IJ.j};
					if ((OP - NP).sqr_norm() <= D * D)
						DEST.insert(NP);
				}
			}
		}
	}
	DEST.erase(OP);
	return DEST;
}

unsigned try_vertical();
unsigned try_horizontal();
unsigned try_angle (Frac, int);

unsigned work (size_t i)
{
	memcpy(M, input[i].M, sizeof M);
	H = input[i].H;
	W = input[i].W;
	D = input[i].D;
	OI = input[i].OI;
	OJ = input[i].OJ;

	assert(OI.get_den() == 2);
	assert(OJ.get_den() == 2);

	unsigned res = 0;
	res += try_vertical();
	res += try_horizontal();

	std::set<Pt> TRIED_ANGLES;
	for (const Pt &DP : get_dests()) {
		if (DP.j == OJ || DP.i == OI)
			continue;
		auto AI = (DP.i - OI) / abs(DP.j - OJ);
		int AJ = sgn(DP.j - OJ);
		Pt ANGLE {AI, AJ};

		if (TRIED_ANGLES.insert(ANGLE).second) {
			res += try_angle(AI, AJ);
		}
	}

	return res;
}

size_t to_num (const Frac &q)
{
	return q.get_num().get_ui() / q.get_den().get_ui();
}

unsigned try_angle (Frac AI, int AJ)
{
	Frac PI = OI;
	Frac PJ = OJ; // Current pos

	Frac DJ = 0; // Traveled J distance. I distance can be computed with (AI,AJ)
	Frac DJL = D*D / (1 + AI*AI); // Requires (DJ*DJ <= DJL)

	Frac oPI, oPJ;
	Frac d0I;

	while (DJ*DJ <= DJL) {

		// Will it hit OP?
		if ((abs(PI-OI)*2<=1 and abs(PJ-OJ)*2<=1) and sgn(OJ-PJ)==AJ and
				(OI-PI)/(OJ-PJ)==AI/AJ) {
			DJ += abs(OJ-PJ);
			return (DJ*DJ <= DJL);
		}

		oPI = PI;
		oPJ = PJ;

		int dirJ = AJ;
		int dirI = sgn(AI);
		size_t dJ;
		size_t dI;

		if (dirJ > 0)
			dJ = to_num(PJ) + 1;
		else
			dJ = to_num(PJ) - (PJ.get_den() == 1);
		if (dirI > 0)
			dI = to_num(PI) + 1;
		else
			dI = to_num(PI) - (PI.get_den() == 1);

		d0I = PI + AI/AJ*(dJ-PJ);
//		auto d0J = dJ;
//		d1I,d1J = dI, PJ + AJ/AI*(dI-PI)

		if (d0I == dI) { // Hit an angle (dI,dJ)
			PI = dI;
			PJ = dJ;
			if (M[dI + (dirI>0 ? 0 : -1)][dJ + (AJ>0 ? 0 : -1)] == 0) // Pass
				;
			else {
				bool reflectI = M[dI + (dirI>0 ? 0 : -1)][dJ + (AJ>0 ? -1 : 0)];
				bool reflectJ = M[dI + (dirI>0 ? -1 : 0)][dJ + (AJ>0 ? 0 : -1)];
				if (!reflectI && !reflectJ) // Absorbed
					return 0;
				if (reflectI && reflectJ) { // Reflect on both side. Do a short cut
					DJ = 2 * (DJ + abs(dJ - oPJ));
					return (DJ*DJ <= DJL);
				}
				if (reflectI)
					AI = -AI;
				if (reflectJ)
					AJ = -AJ;
			}
		}
		else if (abs(d0I - oPI) < abs(dI - oPI)) { // Hit vertical line
			PI = d0I;
			PJ = dJ;
			dI = to_num(d0I);
			if (M[dI][dJ + (AJ>0 ? 0 : -1)]) // Reflect
				AJ = -AJ;
		}
		else { // Hit horizontal line
			PJ += AJ/AI*(dI-PI);
			PI = dI;
			dJ = to_num(PJ);
			if (M[dI + (dirI>0 ? 0 : -1)][dJ]) // Reflect
				AI = -AI;
		}

		DJ += abs(PJ - oPJ);
	}
	return 0;
}

unsigned try_horizontal ()
{
	size_t i = to_num(OI);
	size_t minusJ = 0;
	size_t plusJ = ~(size_t)0;
	for (size_t j=0; j<W; ++j)
		if (j < OJ && M[i][j])
			minusJ = j;
	for (size_t j=W-1; j; --j)
		if (j > OJ && M[i][j])
			plusJ = j;
	return int(2 * (OJ - (minusJ+1)) <= D) +
		int(2 * (plusJ - OJ) <= D);
}

unsigned try_vertical ()
{
	size_t j = to_num(OJ);
	size_t minusI = 0;
	size_t plusI = ~(size_t)0;
	for (size_t i=0; i<H; ++i)
		if (i<OI && M[i][j])
			minusI = i;
	for (size_t i=H-1; i; --i)
		if (i>OI && M[i][j])
			plusI = i;
	return int(2*(OI - (minusI+1)) <= D) +
		int(2*(plusI - OI) <= D);
}

}

int main()
{
	size_t T;
	scanf("%zu", &T);

	for (size_t l=0; l<T; ++l) {
		memset(input[l].M, 0, sizeof input[l].M);
		scanf ("%zu%zu%u", &input[l].H, &input[l].W, &input[l].D);

		input[l].OI = input[l].OJ = 0;

		for (size_t i=0; i<input[l].H; ++i)
			for (size_t j=0; j<input[l].W; ++j) {
				char c;
				scanf(" %c", &c);
				if (c == '#')
					input[l].M[i][j] = 1;
				else if (c == 'X') {
					input[l].OI = Frac(2*i+1, 2);
					input[l].OJ = Frac(2*j+1, 2);
				}
			}
	}

	// Parallelize...
	const unsigned nprocs = 4;
	int pfds[nprocs][2];

	for (unsigned i=0; i<nprocs; ++i)
		pipe(pfds[i]);

	for (unsigned i=0; i<nprocs; ++i) {
		pid_t pid = fork();
		if (pid == 0) {
			close(pfds[i][0]);
			for (size_t j=i; j<T; j+=nprocs) {
				unsigned u = work(j);
				write(pfds[i][1], &u, sizeof u);
			}
			_exit(0);
		}
		close(pfds[i][1]);
	}

	for (size_t i=0; i<T; ++i) {
		fprintf(stderr, "%zu\n", i+1);
		unsigned u;
		read(pfds[i%nprocs][0], &u, sizeof u);
		printf("Case #%zu: %u\n", i+1, u);
	}
	return 0;
}
