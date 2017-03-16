# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define SIZE 40

int intcmp(char *a, char *b)
{
	int d = strlen(a) - strlen(b);
	return d ? d : strcmp(a, b);
}

char* add(char *a, char *b, char *c)
{
    int la, lb;
	char *s, *bs, *t;

	if ((la = strlen(a)) < (lb = strlen(b)))
		return add(b, a, c);

    s = bs = (char*) malloc(la + 1);
    memset(s, 0, la + 1);
    for (s = bs + la, t = b + lb - 1; t >= b; --s, --t)
        *s = *t - '0';
    for (s = bs + la, t = a + la - 1; t >= a; --s, --t)
        if ((*s += *t - '0') >= 10) {
            *(s - 1) += 1;
            *s -= 10;
        }

	for (s = bs; *s == 0 && s < bs + la ; ++s) ;
    for (t = c; s <= bs + la; ++s, ++t)
        *t = *s + '0';
    *t = '\0';
	free(bs);
	return c;
}

char* minus(char *a, char *b, char *c)
{
    int la, lb, ls;
	char *s, *bs, *t;

	la = strlen(a);
	lb = strlen(b);
	ls = la;
    s = bs = (char*) malloc(ls + 1);// possible carry bit
    memset(s, 0, ls + 1);
    for (s = bs + ls, t = a + la - 1; t >= a; --s, --t)
		*s = *t - '0';
    for (s = bs + ls, t = b + lb - 1; t >= b; --s, --t)
        *s -= (*t - '0');
    for (s = bs + ls; s > bs; --s)
		if ((*s) < 0) {
			-- *(s - 1);
			*s += 10;
		}
	for (s = bs; *s == 0 && s < bs + la; ++s) ;
    for (t = c; s <= bs + ls; ++s, ++t)
        *t = *s + '0';
    *t = '\0';
	free(bs);
	return c;
}

char* multiply(char* a, char* b, char* c)
{
    int i, j, ca, cb, *s;
    ca = strlen(a);
    cb = strlen(b);
    s = (int*) malloc(sizeof(int)*(ca + cb));
    for (i = 0; i < ca + cb; i++)
        s[i] = 0;
    for (i = 0; i < ca; i++)
        for (j = 0; j < cb; j++)
            s[i+j+1] += (a[i]-'0') * (b[j]-'0');
    for (i = ca + cb - 1; i >= 0; i--)
        if (s[i] >= 10) {
            s[i-1] += s[i]/10;
            s[i] %= 10;
        }
    i = 0;
    while (s[i] == 0 && i < ca + cb - 1)
        i++;
    for (j = 0; i < ca + cb; i++,j++)
        c[j] = s[i]+'0';
    c[j] = '\0';
    free(s);
	return c;
}

char* div2(char* a, char* c)
{
	int *s, i, j, la;
	la = strlen(a);
	s = (int*)malloc((la + 1) * sizeof(int));
	memset(s, 0, la * sizeof(int));
	for (i = 0; i < la; ++i) {
		if ((s[i] += a[i] - '0') & 1)
			s[i + 1] += 10;
		s[i] >>= 1;
	}
    i = 0;
    while (s[i] == 0 && i < la - 1)
        i++;
    for (j = 0; i < la; i++,j++)
        c[j] = s[i] + '0';
    c[j] = '\0';
    free(s);
	return c;
}

char* bsqrt(char* k, char *r)	// return r^2 <= a < (r+1)^2
{
	char *a, *b, *c, *prod;
	int len, la, lb;
	len = strlen(k);
	la = (len & 1) ? (len + 1) >> 1 : len >> 1;
	a = (char*)malloc(la + 1);
	b = (char*)malloc(la + 1);
	*a = '1';
	for (c = a+1; c < a + la; ++c)
		*c = '0';
	*c = '\0';
	for (c = b; c < b + la; ++c)
		*c = '9';
	*c = '\0';
	c = (char*) malloc(la + 2);	
	prod = (char*) malloc(len + 2);
	while (intcmp(b, add(a, "1", c)) > 0) {
		div2(add(a, b, c), r);
		if (intcmp(k, multiply(r, r, prod)) >= 0)
			strcpy(a, r);
		else
			strcpy(b, r);
	}
	strcpy(r, a);
	free(a);
	free(b);
	free(c);
	free(prod);
	return r;
}

int isOK(char* n, char*r, char*t)
{
	char c[SIZE], d[SIZE];
	add(n, n, d);		// d = 2n
	add(n, r, c);		// c = r + n
	multiply(c, d, c);  // c = 2nr + 2n*n
	minus(c, n, c);
	return intcmp(c, t) <= 0 ? 1 : 0;
}

char * simplecount(char *r, char *t, char *n)
{
	char c[SIZE], d[SIZE];
	multiply(r, r, c);
	add(t, t, d);
	add(c, d, c);
	bsqrt(c, d);
	minus(d, r, c);
	div2(c, n);
	add(n, "1", d);
	if (isOK(d, r, t))
		strcpy(n, d);
	return n;
}

char * count(char *r, char *t, char *n)
{
	char c[SIZE], d[SIZE], b[SIZE];
	add(r, r, d);
	minus(d, "1", d);
	multiply(d, d, c);
	multiply(t, "8", b);
	add(c, b, c);
	bsqrt(c, b);
	minus(b, d, c);
	div2(c, n);
	div2(n, n);
	add(n, "1", d);
	if (isOK(d, r, t))
		strcpy(n, d);
	return n;
}
int main()
{
	int T, iT;
    scanf("%d", &T);
    for(iT = 1; iT <= T; ++iT) {
		char r[SIZE], t[SIZE], n[SIZE];
        scanf("%s%s", r, t);
		printf("Case #%d: %s\n", iT, count(r, t, n));
    }
    return 0;
}