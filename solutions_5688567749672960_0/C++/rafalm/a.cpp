#include <iostream>
#include <cstring>
#include <climits>

using namespace std;

long long reverse(long long a)
{
	char l[20], len;
	long long v = 0LL, pow = 1LL;

	while (a)
	{
		l[len++] = a % 10LL;
		a /= 10;
	}

	for (len = len - 1; len >= 0; len--)
	{
		v += ((long long)l[len] * pow);
		pow *= 10LL;
	}

	return v;
}

#define MIN(a, b) (a < b ? a : b)

int main()
{
	int T, test, i, j;
	long long N, *t, vr;

	t = new long long[10000001];

	cin>>T;
	for (test = 1; test <= T; test++)
	{
		cin>>N;

		//memset(t, 0, sizeof(long long) * 10000001);
		for (i = 0; i <= N; i++)
		{
			t[i] = LLONG_MAX;
		}

		t[1] = 1LL;
		for (i = 1; i < N; i++)
		{
			if (t[i] != LLONG_MAX)
			{
				t[i+1] = MIN(t[i+1], t[i] + 1LL);

				vr = reverse(i);
				if (vr <= N)
				{
					t[vr] = MIN(t[vr], t[i] + 1LL);
				}
			}
		}

		cout<<"Case #"<<test<<": "<<t[N]<<endl;
	}

	return 0;
}

/*int main()
{
	int T, test;
	long long N, v, vr, count;

	cin>>T;

	for (test = 1; test <= T; test++)
	{
		cin>>N;

		count = 1LL;
		v = 1LL;
		while (v < N)
		{
			vr = reverse(v);
			if (vr <= N && v < vr)
			{
				v = vr;
				count++;
			}
			else
			{
				v++;
				count++;
			}
		}

		cout<<"Case #"<<test<<": "<<count<<endl;
	}

	return 0;
}*/
