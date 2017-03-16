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
		die("scanf: wanted %d, got %d", (int)(n), __rc);	\
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

#if 0
static void
skip_n(unsigned n)
{
	unsigned x;

	for (unsigned i = 0; i < n; i++)
		SCANF("%u", 1, &x);
}
#endif

static void*
xmalloc(size_t X)
{
	void *v = malloc(X);
	if (!v)
		die("oom");
	return v;
}

double Fcost, Frate, Goal;

struct gamestate {
	double cookies, farms, elapsed;
};

static inline double
seconds_to_farm(const struct gamestate *gs)
{
	if (gs->cookies >= Fcost)
		return 0;

	return (Fcost - gs->cookies) / (2. + Frate * gs->farms);
}

static int
gs_compare(const void *a, const void *b)
{
	const struct gamestate *g1 = a,
	      *g2 = b;

	if (g1->elapsed < g2->elapsed)
		return -1;
	else if (g1->elapsed > g2->elapsed)
		return 1;

	if (g1->cookies > g2->cookies)
		return -1;
	else if (g1->cookies < g2->cookies)
		return 1;

	if (g1->farms > g2->farms)
		return -1;
	else if (g1->farms < g2->farms)
		return 1;
	return 0;
}

static void
ins_state(void **root, double cook, double farm, double ela)
{
	struct gamestate *st;
	void *x;

	st = xmalloc(sizeof *st);
	st->cookies = cook;
	st->farms = farm;
	st->elapsed = ela;

	//printf("XXX inserting (%f,%f,%f) (%p)\n", cook, farm, ela, st);

	x = tsearch(st, root, gs_compare);
	ASSERT(x != NULL);

	// if they are truly duplicate states, no point having both.
	//
	// the compar function should ensure they are exact duplicates, but
	// validate with memcmp (why? whatever)
	if (*(struct gamestate **)x != st) {
		ASSERT(memcmp(*(struct gamestate **)x, st, sizeof *st) == 0);
		free(st);
	}
}

static inline double
time_to_win(const struct gamestate *gs)
{
	if (gs->cookies >= Goal)
		return 0;

	return (Goal - gs->cookies) / (2. + Frate * gs->farms);
}

static struct gamestate *minfound;
static void
_min_visitor(const void *node, const VISIT which, const int depth)
{
	struct gamestate *x;

	(void)depth;
	(void)which;

	x = *(struct gamestate * const *)node;

	if (x == NULL) {
		die("what the fuckkkk?\n");
	}
	if (minfound == NULL || gs_compare(x, minfound) < 0)
		minfound = x;
}

static inline struct gamestate *
deletemin(void **root)
{

	minfound = NULL;
	twalk(*root, _min_visitor);
	if (minfound)
		tdelete(minfound, root, gs_compare);
	return minfound;
}

// quick and dirty
static inline bool
epseq(double a, double b, double eps)
{
	double diff;

	diff = fabs(a - b);
	if (diff <= eps)
		return true;
	return false;
}

static inline double
rate(struct gamestate *st)
{
	return 2. + Frate * st->farms;
}

// Search for the shortest (measured in seconds) possible path to victory.
// Basic game tree search.
static double
play(void)
{
	void *game_tree = NULL;
	struct gamestate *lowest;

	// start search at:
	ins_state(&game_tree, 0., 0., 0.);

	while ((lowest = deletemin(&game_tree)) != NULL) {
		//printf("XXX aa\n");
		if (epseq(lowest->cookies, Goal, 0.0000001)) {
			double ret = lowest->elapsed;
			tdestroy(game_tree, free);
			return ret;
		}

		double ttf = seconds_to_farm(lowest),
		       ttw;
		//printf("XXX bb\n");

		// we can buy a farm now? add state like we did it
		if (ttf == 0.) {
			ins_state(&game_tree,
			    lowest->cookies - Fcost,
			    lowest->farms + 1,
			    lowest->elapsed);
		} else {
			// wait to buy a farm
			ins_state(&game_tree,
			    lowest->cookies + ttf*rate(lowest),
			    lowest->farms,
			    lowest->elapsed + ttf);
		}

		// wait until goal
		ttw = time_to_win(lowest);
		ins_state(&game_tree,
		    lowest->cookies + ttw*rate(lowest),
		    lowest->farms,
		    lowest->elapsed + ttw);

		free(lowest);
	}

	die("exhausted game tree?\n");
	return INFINITY;
}

// This one is game tree search. We want to go prio-first, sorted by least time
// first. The branching factor is just two: buy the farm, or don't buy the
// farm.
int
main(void)
{
	uintmax_t T, i;

	SCANF("%ju", 1, &T);
	for (i = 1; i <= T; i++) {
		double minseconds;

		SCANF("%lf", 1, &Fcost);
		SCANF("%lf", 1, &Frate);
		SCANF("%lf", 1, &Goal);

		minseconds = play();

		printf("Case #%ju: %.7f\n", i, minseconds);
	}

	return 0;
}
