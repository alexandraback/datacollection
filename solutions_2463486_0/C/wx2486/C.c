#include <stdio.h>
#include <string.h>
#include <assert.h>

#define SIZE 101
#define IN_RANGE(n) ( Comp((n), a) >= 0 && Comp((n), b) <= 0)

typedef struct
{
	int n[SIZE];
}BI;

enum SF{ SEL, FLR};

int Calc(BI a, BI b);
void Get(BI *n);
int Comp(BI a, BI b);
BI Mult(BI a, BI b);
BI Sqrtsf(BI n, int sf);
BI PlusOne(BI n);

int main()
{
	int cn, cc;
	freopen("s.in", "r", stdin);
	freopen("s.out", "w", stdout);
	scanf("%d", &cn);

	for (cc=1; cc<=cn; cc++)
	{
		BI a, b;

		//fprintf(stderr, "Processing Case #%d\n", cc);
		Get(&a);
		Get(&b);

		/*
		memset(&a, 0, sizeof(a));
		memset(&b, 0, sizeof(b));
		a.n[0] = 1;
		b.n[SIZE-1] = 1;
		*/

		a = Sqrtsf(a, SEL);
		b = Sqrtsf(b, FLR);

		printf("Case #%d: %d\n", cc, Calc(a, b));
	}

	return 0;
}

void Get(BI *n)
{
	char s[102];
	int len;
	int i;

	scanf("%s", s);
	len = strlen(s);

	memset(n, 0, sizeof(*n));
	for (i=0; i<len; i++)
		n->n[i] = s[len-i-1] - '0';
}

int Comp(BI a, BI b)
{
	int i;

	for (i=SIZE-1; i>=0; i--){
		if (a.n[i] > b.n[i])
			return 1;
		else if (a.n[i] < b.n[i])
			return -1;
	}

	return 0;
}

BI Mult(BI a, BI b)
{
	BI c;
	int i,j;

	memset(&c, 0, sizeof(c));
	for (i=0; i<SIZE; i++){
		for (j=0; i+j<SIZE; j++)
			c.n[i+j] += a.n[i]*b.n[j];
	}

	for (i=0; i<SIZE-1; i++){
		if (c.n[i] > 9)
		{
			c.n[i+1] += c.n[i] / 10;
			c.n[i] %= 10;
		}
	}

	return c;
}

BI Sqrtsf(BI n, int sf)
{
	BI a;
	int i,j;

	memset(&a, 0, sizeof(a));
	for (i=SIZE/2; i>=0; i--){ assert(i<SIZE);
		for (j=9; j>=0; j--)
		{
			a.n[i] = j;
			if (Comp(Mult(a, a), n) <= 0)
				break;
		}
		if (j<0)
			assert(j>=0);
	}

	if (sf == FLR || Comp(Mult(a, a), n) == 0)
		return a;
	else
		return PlusOne(a);
}

BI PlusOne(BI n)
{
	int i;
	for (i=0; i<SIZE; i++){
		if (n.n[i] == 9)
			n.n[i] = 0;
		else
		{
			n.n[i]++;
			break;
		}
	}

	return n;
}

int Calc(BI a, BI b)
{
	int sum = 0;
	BI zero;

	memset(&zero, 0, sizeof(zero));

	// (3) (2) (1)
	{
		BI n = zero;
		n.n[0] = 3;
		sum += IN_RANGE(n);
		n.n[0] = 2;
		sum += IN_RANGE(n);
		n.n[0] = 1;
		sum += IN_RANGE(n);
	}

	// (2 2) (1 1)
	{
		BI n = zero;
		int i;
		for (i=1; i<SIZE; i++)
		{
			n.n[0] = 2;	n.n[i] = 2;
			sum += IN_RANGE(n);
			n.n[0] = 1;	n.n[i] = 1;
			sum += IN_RANGE(n);
			n.n[0] = 0;	n.n[i] = 0;
		}
	}

	// (2 1 2) (1 2 1) (1 1 1)
	{
		BI n = zero;
		int i;
		for (i=1; 2*i<SIZE; i++)
		{
			n.n[0] = 2;	n.n[i] = 1;	n.n[2*i] = 2;
			sum += IN_RANGE(n);
			n.n[0] = 1;	n.n[i] = 2;	n.n[2*i] = 1;
			sum += IN_RANGE(n);
			n.n[0] = 1;	n.n[i] = 1;	n.n[2*i] = 1;
			sum += IN_RANGE(n);
			n.n[0] = 0;	n.n[i] = 0;	n.n[2*i] = 0;
		}

		// (1 1 1 1)
		{
			BI n = zero;
			int i,j;
			for (i=1; 2*i+1<SIZE; i++){
				for (j=1;2*i+j<SIZE; j++)
				{
					n.n[0] = 1; n.n[i] = 1; n.n[i+j] = 1; n.n[2*i+j] = 1;
					sum += IN_RANGE(n);
					n.n[0] = 0; n.n[i] = 0; n.n[i+j] = 0; n.n[2*i+j] = 0;
				}
			}
		}

		// (1 1 1 1 1) (1 1 2 1 1)
		{
			BI n = zero;
			int i,j;
			for (i=1; 2*i+2<SIZE; i++){
				for (j=1; 2*i+2*j<SIZE; j++)
				{
					n.n[0] = 1; n.n[i] = 1; n.n[i+j] = 1; n.n[i+2*j] = 1; n.n[2*i+2*j] = 1;
					sum += IN_RANGE(n);
					n.n[0] = 1; n.n[i] = 1; n.n[i+j] = 2; n.n[i+2*j] = 1; n.n[2*i+2*j] = 1;
					sum += IN_RANGE(n);
					n.n[0] = 0; n.n[i] = 0; n.n[i+j] = 0; n.n[i+2*j] = 0; n.n[2*i+2*j] = 0;
				}
			}
		}

		// (1 1 1 1 1 1)
		{
			BI n = zero;
			int i,j,k;
			for (i=1; 2*i+3<SIZE; i++){
				for (j=1;2*i+2*j+1<SIZE; j++){
					for (k=1; 2*i+2*j+k<SIZE; k++)
					{
						n.n[0] = 1; n.n[i] = 1; n.n[i+j] = 1; n.n[i+j+k] = 1; n.n[i+2*j+k] = 1; n.n[2*i+2*j+k] = 1;
						sum += IN_RANGE(n);
						n.n[0] = 0; n.n[i] = 0; n.n[i+j] = 0; n.n[i+j+k] = 0; n.n[i+2*j+k] = 0; n.n[2*i+2*j+k] = 0;
					}
				}
			}
		}

		// (1 1 1 1 1 1 1) 7
		{
			BI n = zero;
			int i,j,k;
			for (i=1; 2*i+4<SIZE; i++){
				for (j=1; 2*i+2*j+2<SIZE; j++){
					for (k=1; 2*i+2*j+2*k<SIZE; k++)
					{
						n.n[0] = 1; n.n[i] = 1; n.n[i+j] = 1; n.n[i+j+k] = 1; n.n[i+j+2*k] = 1; n.n[i+2*j+2*k] = 1; n.n[2*i+2*j+2*k] = 1;
						sum += IN_RANGE(n);
						n.n[0] = 0; n.n[i] = 0; n.n[i+j] = 0; n.n[i+j+k] = 0; n.n[i+j+2*k] = 0; n.n[i+2*j+2*k] = 0; n.n[2*i+2*j+2*k] = 0;
					}
				}
			}
		}

		// (1 1 1 1 1 1 1 1) 8
		{
			BI n = zero;
			int i,j,k,m;
			for (i=1; 2*i+5<SIZE; i++){
				for (j=1; 2*i+2*j+3<SIZE; j++){
					for (k=1; 2*i+2*j+2*k+1<SIZE; j++){
						for (m=1; 2*i+2*j+2*k+m<SIZE; m++)
						{
							n.n[0] = 1; n.n[i] = 1; n.n[i+j] = 1; n.n[i+j+k] = 1; n.n[i+j+k+m] = 1; n.n[i+j+2*k+m] = 1; n.n[i+2*j+2*k+m] = 1; n.n[2*i+2*j+2*k+m] = 1;
							sum += IN_RANGE(n);
							n.n[0] = 0; n.n[i] = 0; n.n[i+j] = 0; n.n[i+j+k] = 0; n.n[i+j+k+m] = 0; n.n[i+j+2*k+m] = 0; n.n[i+2*j+2*k+m] = 0; n.n[2*i+2*j+2*k+m] = 0;
						}
					}
				}
			}
		}

		// (1 1 1 1 1 1 1 1 1) 9
		{
			BI n = zero;
			int i,j,k,m;
			for (i=1; 2*i+6<SIZE; i++){
				for (j=1; 2*i+2*j+4<SIZE; j++){
					for (k=1; 2*i+2*j+2*k+2<SIZE; k++){
						for (m=1; 2*i+2*j+2*k+2*m<SIZE; m++)
						{
							n.n[0] = 1; n.n[i] = 1; n.n[i+j] = 1; n.n[i+j+k] = 1; n.n[i+j+k+m] = 1; n.n[i+j+k+2*m] = 1; n.n[i+j+2*k+2*m] = 1; n.n[i+2*j+2*k+2*m] = 1; n.n[2*i+2*j+2*k+2*m] = 1;
							sum += IN_RANGE(n);
							n.n[0] = 0; n.n[i] = 0; n.n[i+j] = 0; n.n[i+j+k] = 0; n.n[i+j+k+m] = 0; n.n[i+j+k+2*m] = 0; n.n[i+j+2*k+2*m] = 0; n.n[i+2*j+2*k+2*m] = 0; n.n[2*i+2*j+2*k+2*m] = 0;
						}
					}
				}
			}
		}
	}

	return sum;
}