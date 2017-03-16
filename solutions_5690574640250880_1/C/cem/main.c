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

static char mgrid[50][50];

static void
print_grid(unsigned r, unsigned c)
{
	for (unsigned i = 0; i < r; i++) {
		FWRITE(mgrid[i], 1, c, stdout);
		putchar('\n');
	}
}

static void
do_single(unsigned r, unsigned c)
{
	mgrid[0][0] = 'c';
	print_grid(r, c);
}

static void
do_flat(unsigned c, unsigned m)
{
	mgrid[0][0] = 'c';

	for (unsigned i = 0; i < (c - m - 1); i++)
		mgrid[0][1+i] = '.';
	print_grid(1, c);
}

static void
do_tall(unsigned r, unsigned m)
{
	mgrid[0][0] = 'c';

	for (unsigned i = 0; i < (r - m - 1); i++)
		mgrid[1+i][0] = '.';
	print_grid(r, 1);
}

static bool
determine_open_rect(unsigned r, unsigned c, unsigned area,
    unsigned *out_r, unsigned *out_c)
{
	for (unsigned ir = 2; ir <= r; ir++) {
		for (unsigned ic = 2; ic <= c; ic++) {
			unsigned rem, barea = ir*ic;

			if (barea > area)
				continue;

			rem = area - barea;
			// this box maps area perfectly? fine.
			if (rem == 0) {
				*out_r = ir;
				*out_c = ic;
				return true;
			}

#if 0
			if ((   (ir == r-1 && ic == c-1) ||
				(ir == r && ic == c-1) ||
				(ir == r-1 && ic == c)


			    ) && rem > 1) {
				*out_r = ir;
				*out_c = ic;
				return true;
			}
#endif

			// rem cannot fit in a partial row or column? we can go
			// bigger
			if (rem >= ic && rem >= ir)
				continue;

			// rem is one cannot be satisfied with minesweeper
			// fill.
			if (rem == 1)
				continue;

			// we have room for another row. and our box is wide
			// enough to accomodate rem:
			if (ir < r && rem < ic) {
				*out_r = ir;
				*out_c = ic;
				return true;
			// we have room for another column. and our box is tall
			// enough to accomodate rem:
			} else if (ic < c && rem < ir) {
				*out_r = ir;
				*out_c = ic;
				return true;
			}
		}
	}

	return false;
}

#define min(x, y) ({					\
	typeof(x) _min1 = (x);				\
	typeof(y) _min2 = (y);				\
	(void) (&_min1 == &_min2);			\
	_min1 < _min2 ? _min1 : _min2; })

static void
do_sparse_colfirst(unsigned r, unsigned c, unsigned m)
{

	memset(mgrid[r-1], '.', sizeof(mgrid[0]));

	//printf("XXX %s\n", __func__);

	if (c > 2) {
		unsigned nrow = min(m, r);

		if (nrow == r - 1)
			nrow--;

		for (unsigned i = 0; i < nrow; i++)
			mgrid[r-1-i][c-1] = '*';
		m -= nrow;
		m++;
	}

	ASSERT(m != c - 1);

	for (unsigned i = 0; i < m; i++)
		mgrid[r-1][c-1-i] = '*';

	print_grid(r, c);
}

static void
do_sparse(unsigned r, unsigned c, unsigned m)
{
	unsigned m_copy = m;

	memset(mgrid, '.', r * sizeof(mgrid[0]));
	mgrid[0][0] = 'c';

	if (m == 0) {
		print_grid(r, c);
		return;
	}

	//printf("XXX %s\n", __func__);

	if (r > 2) {
		unsigned ncol = min(m, c);

		if (ncol == c - 1)
			ncol--;

		for (unsigned i = 0; i < ncol; i++)
			mgrid[r-1][c-1-i] = '*';
		m -= ncol;
		m++;
	}

	if (m == r - 1) {
		do_sparse_colfirst(r, c, m_copy);
		return;
	}

	for (unsigned i = 0; i < m; i++)
		mgrid[r-1-i][c-1] = '*';

	print_grid(r, c);
}

static void
do_multi(unsigned r, unsigned c, unsigned m)
{

	mgrid[0][0] = 'c';

	unsigned opens = r*c - m,
		 or, oc;
	bool sat;

	if (m == 0) {
		do_sparse(r, c, m);
		return;
	}

	//printf("XXX %s\n", __func__);

	ASSERT(opens >= 4);

	sat = determine_open_rect(r, c, opens, &or, &oc);
	if (!sat) {
		printf("Impossible\n");
		return;
	}
	ASSERT(or >= 2 && oc >= 2);

	// c...*****
	// ....*****
	// *********
	// *********
	for (unsigned i = 0; i < or; i++)
		for (unsigned j = 0; j < oc; j++)
			mgrid[i][j] = '.';
	mgrid[0][0] = 'c';

	unsigned rem = opens - or*oc;
	if (rem == 0) {
		print_grid(r, c);
		return;
	}

	ASSERT(rem > 1);

	// We have room for an extra partial row
	if (or < r && rem < c) {
		for (unsigned i = 0; i < rem; i++)
			mgrid[or][i] = '.';
	} else if (oc < c && rem < r) {
		for (unsigned i = 0; i < rem; i++)
			mgrid[i][oc] = '.';
	// nearly empty case
	} else if (or == r-1 && oc == c-1) {
		ASSERT(rem < r + c - 1);
		for (unsigned i = 0; i < oc; i++)
			mgrid[or][i] = '.';
		rem -= oc;
		for (unsigned i = 0; i < rem; i++)
			mgrid[i][oc] = '.';
	} else {
		ASSERT(false);
	}
	print_grid(r, c);
}

static void
do_case(unsigned cno, unsigned rows, unsigned cols, unsigned mines)
{
	printf("Case #%u:\n", cno);

	memset(mgrid, '*', rows * sizeof(mgrid[0]));

	if (mines == rows*cols - 1)
		do_single(rows, cols);
	else if (rows == 1 && mines <= cols - 2)
		do_flat(cols, mines);
	else if (cols == 1 && mines <= rows - 2)
		do_tall(rows, mines);
	else if (mines == cols && rows > 2)
		do_sparse(rows, cols, mines);
	else if (mines < cols - 1 && rows > 2)
		do_sparse(rows, cols, mines);
	else if (mines == rows && cols > 2)
		do_sparse(rows, cols, mines);
	else if (mines < rows - 1 && cols > 2)
		do_sparse(rows, cols, mines);
	else if ((rows > 2 && cols > 2) && mines == rows + cols - 1)
		do_sparse(rows, cols, mines);
	else if ((rows > 2 && cols > 2) && mines == rows + cols - 3)
		do_sparse(rows, cols, mines);
	else if ((rows > 2 && cols > 2) && mines <= rows + cols - 5)
		do_sparse(rows, cols, mines);
	else if (mines <= rows*cols - 4)
		do_multi(rows, cols, mines);
	else
		printf("Impossible\n");
}

// This one is pretty straightforward. It is solvable iff:
//   M <= R*C - 4 or
//   M = RC - 1
//
// Solutions look like:
// c.*** (M <= RC - 4)
// ..***
// *****
//
// or
// c** (M = RC - 1)
// ***
int
main(void)
{
	unsigned Tcases, i;

	SCANF("%u", 1, &Tcases);
	for (i = 1; i <= Tcases; i++) {
		unsigned Rows, Cols, Mines;

		SCANF("%u %u %u", 3, &Rows, &Cols, &Mines);

		do_case(i, Rows, Cols, Mines);
	}

	return 0;
}
