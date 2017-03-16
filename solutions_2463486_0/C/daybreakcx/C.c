#include <stdio.h>
#include <string.h>
#ifdef DEBUG
	#define INPUT "C.in"
	#define OUTPUT "C.out"
#else
	#ifdef SMALL
		#define INPUT "C-small-attempt0.in"
		#define OUTPUT "C-small-attempt0.out"
	#else
		#ifdef LARGE
			#define INPUT "C-large.in"
			#define OUTPUT "C-large.out"
		#endif
	#endif
#endif

void
reverse(char *str) {
	int f, t;

	for (f = 0, t = strlen(str) - 1; f < t; ++f, --t) {
		str[f] ^= str[t];
		str[t] ^= str[f];
		str[f] ^= str[t];
	}
}

void
dec(char *str) {
	int i;

	reverse(str);
	for (i = 0; str[i]; ++i)
		if (str[i] != '0') {
			--str[i];
			reverse(str);
			return;
		} else
			str[i] = '9';
	for (--i; i > 0 && str[i] == '0'; str[i--] = 0);
	reverse(str);
}

void
incr(char *str) {
	int i;

	for (i = 0; str[i]; ++i) {
		++str[i];
		if (((i == 0 || str[i + 1] == 0) && str[i] == '3') || (i != 0 && str[i + 1] && str[i] == '2'))
			str[i] = '0';
		else
			break;
	}
	if (!str[i]) {
		str[i] = '1';
		str[i + 1] = 0;
	}
}

int
larger(char *s, char *t) {
	int lens = strlen(s), lent = strlen(t), i;

	if (lens != lent)
		return lens > lent ? 1 : 0;
	else {
		for (i = 0; s[i]; ++i)
			if (s[i] != t[i])
				return s[i] > t[i] ? 1 : 0;
		return 0;
	}
}

int
is_fair(char *s) {
	int f, t;

	for (f = 0, t = strlen(s) - 1; f < t; ++f, --t)
		if (s[f] != s[t])
			break;
	return f >= t ? 1 : 0;
}

void
mirror_sqr(char *s, char *t, int dup) {
	int l, r, i, j, len = strlen(s), sqr[300];

	for (l = len - 1, r = l + dup; l >= 0; --l, ++r)
		t[l] = t[r] = s[len - 1 - l];
	t[len = r] = 0;
	memset(sqr, 0, sizeof(sqr));
	sqr[0] = (len << 1) - 1;
	for (i = 0; i < len; ++i)
		for (j = 0; j < len; ++j)
			sqr[i + j + 1] += (t[i] - '0') * (t[j] - '0');
	for (i = 1, j = 0; i <= sqr[0]; ++i) {
		sqr[i] += j;
		j = sqr[i] / 10;
		sqr[i] %= 10;
	}
	while (j) {
		sqr[++sqr[0]] = j % 10;
		j /= 10;
	}
	for (i = sqr[0]; i >= 1; --i)
		t[sqr[0] - i] = sqr[i] + '0';
	t[sqr[0]] = 0;
}

int
calc(char *str) {
	int len = strlen(str), ret;
	char cur[300], p[300];

	ret = (len > 1 || str[0] >='9');
	cur[0] = '0';
	cur[1] = 0;
	for (; ; ) {
		incr(cur);
		mirror_sqr(cur, p, 0);
		if (larger(p, str))
			break;
		ret += is_fair(p);
		mirror_sqr(cur, p, 1);
		ret += (1 - larger(p, str)) * is_fair(p);
	}
	return ret;
}

int
main()
{
	int ti, tn;
	char A[120], B[120];
	FILE *inp, *oup;

	if ((inp = fopen(INPUT, "r")) == NULL) {
		fprintf(stderr, "Failed to open the input file\n");
		return -1;
	}
	if ((oup = fopen(OUTPUT, "w")) == NULL) {
		fprintf(stderr, "Failed to open the output file\n");
		return -1;
	}
	fscanf(inp, "%d\n", &tn);
	for (ti = 1; ti <= tn; ++ti) {
		fscanf(inp, "%s %s", A, B);
		dec(A);
		fprintf(oup, "Case #%d: %d\n", ti, calc(B) - calc(A));
	}
	fclose(inp);
	fflush(oup);
	fclose(oup);
	return 0;
}
