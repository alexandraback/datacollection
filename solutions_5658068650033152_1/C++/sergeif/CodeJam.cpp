#include <cstdio>
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

typedef long long LL;
typedef long double LD;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int,int> PII;
#define FOR(k,a,b) for(typeof(a) k=(a); k <= (b); ++k)
#define REP(k,a) for(int k=0; k < (a); ++k)
#define REPD(k,a) for(int k=(a)-1; k >= 0; --k)
#define PB push_back 
#define MP make_pair


int main()
{
	int T;
	cin >> T;
	REP(t,T)
	{
		int N,M,K;
		cout << "Case #" << (t+1) <<": ";
		cin >> N >> M >> K;
		if (N <= 2 || M <= 2)
		{
			cout << K << endl;
			continue;
		}
		int res = K;
		for (int a=1; a<=N-2; ++a)
		{
			for (int b=1; b<=M-2; ++b)
			{
				for (int ca=0; ca<=a-1 && (b<M-2 || ca == 0); ++ca)
				{
					for (int cb=0; cb<=b-1 && (a<N-2 || cb == 0); ++cb)
					{
						for (int c3=0; c3<=4; ++c3)
						{
							if ((2 * (a+b) + a*b + ca + cb + c3) == K && (2 * (a+b) + c3) < res)
							{
								//cout << a << " " << b << " " << c3 << endl;
								res = 2 * (a+b) + c3;
							}
						}
					}
				}
			}
		}
		cout << res << endl;
	}
	
	return 0;
}

