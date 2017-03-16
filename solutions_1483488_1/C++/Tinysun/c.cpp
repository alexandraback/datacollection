
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define  max(x, y)  ((x)>(y)?(x):(y))
#define  min(x, y)  ((x)<(y)?(x):(y))
#define  abs(x)   ((x)<0?-(x):(x))

char buf[1024];

typedef  long long  int64;

int get_digit( int a)
{
	if ( a >= 1000000 )
		return 7;
	if ( a >= 100000 )
		return 6;
	if ( a >= 10000 )
		return 5;
	if ( a >= 1000 )
		return 4;
	if ( a >= 100 )
		return 3;
	if ( a >= 10 )
		return 2;
	return 1;
}

const int MAXINT = 9999999;

int intersect(int a, int b, int x, int y)
{
	int  low = a;
	if ( x > low )
		low = x;

	int high = b;
	if ( y < high )
		high = y;

	if ( low > high )
		return 0;

	return  high - low + 1;
}

int get_rptnum( int a, int b)
{
	if ( a == 2 && b == 4 )
		return 2;
	if ( a == 3 && b == 3 )
		return 3;
	if ( a == 2 && b == 2 )
		return 2;
	return 1;
}

int intexp( int n )
{
	if ( n == 0 )
		return 1;
	if ( n == 1 )
		return 10;
	if ( n == 2 )
		return 100;
	if ( n == 3 )
		return 1000;
	if ( n == 4 )
		return 10000;
	if ( n == 5 )
		return 100000;
	if ( n == 6 )
		return 1000000;
	if ( n == 7 )
		return 10000000;
	if ( n == 8 )
		return 100000000;
	return 1;
}

int gen_autonum( int base, int rptnum, int digit )
{
	int m = 0;
	int exp = intexp(rptnum);
	for (int i=0; i<digit; i+=rptnum)
	{
		m = m * exp + base;
	}
	return  m;
}

int rotation(int n, int digit, int rot)
{
	int S1 = intexp(rot);
	int S2 = intexp(digit-rot);

	return  n%S2 * S1 + n/S2; 
}


int main()
{
	gets(buf);
	int ncase = atoi(buf);
  
	for(int i=1; i<=ncase; i++)
	{
		int  A, B;
		scanf("%d %d", &A, &B);

		int digit = get_digit(A);

		int ans = 0;

		for(int k=1; k<=digit/2; k++)
		{
			int d1 = k;
			int d2 = digit - k;

			int S1 = intexp(d1);
			int S2 = intexp(d2);

			int A1 = A/S2;
			int A3 = A/S1;
			int A4 = A%S1;
			int B1 = B/S2;
			int B3 = B/S1;
			int B4 = B%S1;


			int totcnt = 0;

			//
			// 1. count for A <= n, m <= B
			//

			// count first d1 digit of n is in A1+1 ~ B1-1
			if ( B1-A1 >= 2 )
			{
				totcnt = (B1-1-(A1+1)+1)*(B3-A3+1);
				totcnt -= intersect(A1+1, B1-1, 0, A4-1) + intersect(A1+1, B1-1, B4+1, MAXINT);
			}

			// count for A1 
			int Low = A1*S2 + A3;
			int High = A1*S2 + B3;
			if ( A1 < A4 )
				Low++;
			if ( A1 > B4 )
				High--;
			totcnt += intersect(Low, High, A, B);
		
			// count for B1
			if (A1 != B1 )
			{
				int Low = B1*S2 + A3;
				int High = B1*S2 + B3;
				if ( B1 < A4 )
					Low++;
				if ( B1 > B4 )
					High--;
				totcnt += intersect(Low, High, A, B);
			}


			//
			// 2. subtract count for n == m
			//
			int rptnum = get_rptnum(d1, d2);
		
			// basic count
			int forshift = intexp(digit-rptnum);
			int AA = A/forshift;
			int BB = B/forshift;
			int count = BB-AA+1;

			// adjust count
			int autonum = gen_autonum(AA, rptnum, digit);
			if ( autonum < A || autonum > B )
				count--;
			if ( AA != BB )
			{
				autonum = gen_autonum(BB, rptnum, digit);
				if ( autonum < A || autonum > B )
					count--;
			}
			totcnt -= count;

			//
			// 3. if d1 == d2, it was double
			// 
			if ( d1 == d2 )
				totcnt /= 2;

			ans += totcnt;
		}

		if ( digit == 4 )
		{
			int A1 = A/100;
			int B1 = B/100;

			for (int i=A1; i<=B1; i++)
			{
				int n = i*100 + i;
				int m = rotation(n, 4, 1);
				if ( A <= n && n < m && m <= B )
					ans--; // equals 1,3
			}
		}

		if ( digit == 6 )
		{
			int A1 = A/10000;
			int B1 = B/10000;

			for (int i=A1; i<=B1; i++)
			{
				int n = i*10000 + i*100 + i;
				int m = rotation(n, 6, 1);
				if ( A <= n && n < m && m <= B )
					ans-=2; // equals 1,3,5
			}

			A1 = A/1000;
			B1 = B/1000;

			for (int i=A1; i<=B1; i++)
			{
				int n = i*1000 + i;
				int m = rotation(n, 6, 1);
				if ( A <= n && n < m && m <= B )
					ans--; // equals 1,4
			}

			for (int i=A1; i<=B1; i++)
			{
				int n = i*1000 + i;
				int m = rotation(n, 6, 2);
				if ( A <= n && n < m && m <= B )
					ans--; // equals 2,5
			}
		}
	

		printf("Case #%d: ", i);

		printf("%d", ans);
		printf("\n");
	}
  
	return  0;  
}
