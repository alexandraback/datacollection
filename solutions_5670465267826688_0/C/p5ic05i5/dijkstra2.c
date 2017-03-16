
#include <ctype.h>
#include <stdio.h>

char m[256];
char val[4][4] = {
	{ '1', 'i', 'j', 'k' },
	{ 'i', '1', 'k', 'j' },
	{ 'j', 'k', '1', 'i' },
	{ 'k', 'j', 'i', '1' },
};

int sign[4][4] = {
	{  1,  1,  1,  1 },
	{  1, -1,  1, -1 },
	{  1, -1, -1,  1 },
	{  1,  1, -1, -1 },
};

typedef struct {
	int s;
	char v;
} quat_t;

quat_t* new(quat_t *q, char c) {
	q->s = 1;
	q->v = c;
	return q;
}

quat_t* mult(quat_t *a, quat_t *b, quat_t *r) {
	r->s = a->s * b->s * sign[m[a->v]][m[b->v]];
	r->v = val[m[a->v]][m[b->v]];
	return r;
};

int eq(quat_t *a, quat_t *b) {
	return a->s == b->s && a->v == b->v;
}

long long int L, X;
char seq[10001];

quat_t* multb(long long int i, long long int j, quat_t *r) {
	quat_t a, b;
	int d = j - i;
	if (d == 1)
		new(r, seq[i%L]);
	else if (d == 2)
		mult(new(&a, seq[i%L]), new(&b, seq[(i+1)%L]), r);
	else if (d % 2)
		mult(new(&a, seq[i%L]), multb(i+1, j, &b), r);
	else
		mult(multb(i, i+d/2, &a), multb(i+d/2, j, &b), r);
	return r;
}

int main() {
	m['1'] = 0; m['i'] = 1;
	m['j'] = 2; m['k'] = 3;

	int t, x = 1;
	quat_t S, 
		ONE = { 1, '1'},
		I = { 1, 'i'},
		K = { 1, 'k'},
		R = { -1, '1'};

	scanf("%d\n", &t);
	while (t--) {
		scanf("%lld %lld\n", &L, &X);
		scanf("%[^\n]\n", seq);
		
		multb(0, L*X, &S);
		if (eq(&R, &S)) {
			long long int i = -1, k = -1, j;

			quat_t s, t;
			s = ONE;
			for (j = 0; i == -1 && j < L*X; ++j)
				if (eq(&I, mult(&s, new(&t, seq[j%L]), &s)))
					i = j;

			s = ONE;
			if (i != -1)
				for (j = L*X-1; k == -1 && j >= i; --j)
					if (eq(&K, mult(new(&t, seq[j%L]), &s, &s)))
						k = j;

			printf("Case #%d: %s\n", x++, i != -1 && k != -1 ? "YES" : "NO");
		} else {
			printf("Case #%d: NO\n", x++);
		}
	}
	return 0;
}
