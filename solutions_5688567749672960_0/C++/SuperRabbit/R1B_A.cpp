#include<stdio.h>
#include<vector>
#include<algorithm>

using std::vector;

int main()
{
	long long u[22];
	long long a = 1;
	long long b = 0;
	for (int i = 0 ; i < 9 ; i++)
	{
		b = b * 10 + 9;
		u[i * 2] = a + b;
		a *= 10;
		u[i * 2 + 1] = a + b;
	}

	u[0] -= 1;

	FILE *i_fileOut;
	fopen_s(&i_fileOut, "R1B_A.out", "w");
	int i_numCases;
	scanf("%d", &i_numCases);
	for (int i_case = 1 ; i_case <= i_numCases ; i_case++)
	{		
		long long n = 0;

		scanf("%lld", &n);

		long long m = n;
		long long p[20];
		int k = 0;

		while (m)
		{
			p[k] = m % 10;
			k++;
			m /= 10;
		}

		long long ans = 0;

		for (int i = 0 ; i < k - 1 ; i++)
		{
			ans += u[i];
		}

		long long aa = 0;
		long long bb = 0;
		
		long long t = 1;
		
		for (int i = 0 ; i < (k + 1) / 2 ; i++)
		{
			aa += p[i] * t;
			t *= 10;
		}
		t = 1;
		for (int i = k - 1 ; i >= (k + 1) / 2 ; i--)
		{
			bb += p[i] * t;
			t *= 10;
		}

		if (k > 1 && aa == 0 && bb != 1)
		{
			long long m = n - 1;
			long long p[20];
			int k = 0;

			while (m)
			{
				p[k] = m % 10;
				k++;
				m /= 10;
			}

			ans = 1;

			for (int i = 0 ; i < k - 1 ; i++)
			{
				ans += u[i];
			}

			long long aa = 0;
			long long bb = 0;
		
			long long t = 1;
		
			for (int i = 0 ; i < (k + 1) / 2 ; i++)
			{
				aa += p[i] * t;
				t *= 10;
			}
			t = 1;
			for (int i = k - 1 ; i >= (k + 1) / 2 ; i--)
			{
				bb += p[i] * t;
				t *= 10;
			}

			ans += (aa + bb);
			if (bb > 1) ans += 1;	//for reversing
		} else
		{
			ans += (aa + bb);
			if (bb > 1) ans += 1;	//for reversing
		}

		// 1,2,...9,
		// 10,11,12,...,19,91,92,...,99,
		// 100,101,102,...109,901,...,999,	need: 10+99
		// 100,...,199,991,...,999 need: 100+9
		// 1000, 1001, ...,1009, 9001,...9999     need: 10+999          9051 1059  9358 8539 8531 8521 1258 8521                
		// 1000,...,1021,1201,1258,8521,...,8539, 9358, ... 9999   need: 22+58+19+999-357
		// 1000,...,1099,9901,9902,...9999    need: 100+99
		// 10000,...10999,99901,...,99999    need:  1000+99

		//9 (8)
		//19
		//109
		//199
		//1099
		//1999
		
		printf("Case #%d: ", i_case);
		fprintf(i_fileOut, "Case #%d: ", i_case);

		printf("%d\n", ans);
		fprintf(i_fileOut, "%d\n", ans);
	}

	fclose(i_fileOut);
	return 0;
}