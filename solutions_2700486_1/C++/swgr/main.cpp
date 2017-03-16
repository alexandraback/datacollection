#include<iostream>
#include<utility>
#include<algorithm>

using namespace std;

long long A;
int N,X,Y,n;

#define v(x) ((x)&1)

long double d[100000][2];

long double b(int n, int k)
{
	if (k>n/2) k = n-k;
	double ret = 1.0, t;
	for (int i = n; i > 0; i--)
	{
		ret = ret * 0.5;
		if (i<=k)
		{
			t = n-(k-i);
			t /= i;
			ret *= t;
		}
	}
	return ret;
}

int main()
{
	freopen("B-large.in", "r",stdin);
	freopen("B-large.out", "w",stdout);
	int T;
	cin>>T;
	for(int tt=1;tt<=T;tt++)
	{
		long double ans = -1.0;
		cin>>N>>X>>Y;
		X = abs(X);
		int s = 1, n = 0;
		for(int i=2;s<N;i+=2,n++) s+=2*i+1;
		N-=(s-(4*n+1));
		int l = (X+Y)/2;
		if (l<n) ans = 1.0;
		else if (l>n) ans = 0.0;
		else if (l==n&&N==4*n+1) ans = 1.0; 
		else
		{
			int k = Y+1;
			if (k==2*n+1) ans = 0.0;
			else
			{
				ans = 0.0;
				int T = 2*n;
				d[0][0] = 1.0;
				for(int j=1;j<=N;j++)
				{
					for(int i=0;i<=j;i++)
					{
						int le = i, ri = j-i;
						if (le>T||ri>T) continue;
						if (le==0||ri==0)
							d[i][v(j)] = 0.5*d[0][v(j-1)];
						else
						{
							d[i][v(j)] = 0.0;
							if (ri>0)
							{
								if (ri<T) d[i][v(j)] += 0.5*d[i-1][v(j-1)];
								else d[i][v(j)] += d[i-1][v(j-1)];
							}
							if (le>0)
							{
								if (le<T) d[i][v(j)] += 0.5*d[i][v(j-1)];
								else d[i][v(j)] += d[i][v(j-1)];
							}
						}
						if (j==N&&ri>=k) ans+=d[i][v(j)];
					}
				}
				/*
				for(int le=0;le<=2*n;le++)
				{
					int ri=N-le;
					if (ri>2*n||ri<k) continue;
					ans += b(N,le);
				}
				*/
			}
		}

		cout<< "Case #" << tt << ": " /*<< n << " " << s << " " << N << " "*/ << ans << endl;
	}

	return 0;
}
