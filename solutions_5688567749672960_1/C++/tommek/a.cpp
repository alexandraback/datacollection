#include "bits/stdc++.h"
using namespace std;

typedef long long LL;
typedef long double LD;
typedef vector<int> VI;
typedef pair<int,int> PII;
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define FOREACH(it,v) for(decltype((v).begin())it=(v).begin();it!=(v).end();++it)
#define ST first
#define ND second
#define MP make_pair
#define PB push_back
#define ALL(v) (v).begin(),(v).end()
#define SIZE(x) ((int)(x).size())
#define DBG(x) cerr<<">> "<<#x<<" = "<<x<<endl;
const int MX = 1e6 + 5;
const int INF = 1e9 + 5;

LL dig(LL x)
{
	int res = 0;
	while(x)
	{
		++ res;
		x /= 10;
	}
	return res;
}

LL n, res, akt;

void idz(int x) {
	while(akt < x)
	{
		++ akt; 
		++ res;
	}
}	

void obroc() {
	LL newN = 0;
	while(akt) {
		newN *= 10LL;
		newN += akt % 10LL;
		akt /= 10;
	}
	++ res;
	akt = newN;
}

LL stDig(LL x) {
	while(x >= 10) x /= 10;
	return x;
}

LL t[20];

int main(int argc, char* argv[])
{
	t[0] = 19;
	for(int i = 1; i < 17; ++ i)
	{
		t[i] = t[i-1] * 10LL - 90 + 9;
	}

	int cases; scanf("%d", &cases); for(int ccc = 1; ccc <= cases; ++ ccc)
	{
		scanf("%lld", &n); res = 1; akt = 1;

		if(n <= 19) {
			idz(n); goto konc;
		}

		for(int i = 0; i < 16; ++ i)  {
	//		printf("pos: %d, %lld\n", i, t[i]);

			if(n <= t[i+1])
		{
		//		printf("juz tam nie ide :(\n");			
				LL ss = stDig(n);
				
				if(n % 10 == 0)
					ss --;

				LL x = t[i] - 9 + ss;

				if(dig(n) == dig(t[i+1]))
				{
					idz(t[i]); obroc(); idz(n); 
	//				printf("ale gópi przypadek\n");
					goto konc;
				}

				if(ss <= 1) {
					idz(n); 
		//			printf("ide na pale\n");

					goto konc;
				}

	//			printf("cyfra: %lld, ide do :%lld\n", ss, x);

				idz(x); 
				
				if(akt == n) goto konc;

				obroc();
				idz(n);
				goto konc;
			}

			idz(t[i]); obroc();
		}

		konc: printf("Case #%d: %lld\n", ccc, res);
	}

	return 0;
}
