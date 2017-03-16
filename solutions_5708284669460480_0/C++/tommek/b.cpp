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

string akt, keys, word;
LD Res, probab;
int k,l,s, P[MX], mx;

int kmp()
{
	string kupa = '@' + word + '#' + akt + '$';
	int N = kupa.size()-1;
	
	int t = 0; P[1] = 0;
	for (int i = 2; i <= N; ++ i)
	{
		P[i] = 0;
		while (t > 0 && kupa[t+1] != kupa[i]) t = P[t];
		if (kupa[t+1] == kupa[i]) t ++;
		P[i] = t;
	}

//	cout << kupa << endl;
//	for (int i = 1; i <= N;++i)
//		cout << P[i] << " ";
//	cout << endl;

	int res = 0;
	for (int i = 1; i <= N; ++ i)
		if (P[i] == word.size())
			res ++; 

//	printf("%d\n", res);

	return res;
}

void rek(int a) 
{
	if (a == s)
	{
	//	cout << akt << endl;
		Res += (LD)kmp() * probab;
		mx = max(mx, kmp());
		return;
	}
	for (int i = 0; i < k; ++ i)
	{
		akt += keys[i];
		rek(a+1);
		akt.pop_back();
	}
}

int main()
{
//	ios_base::sync_with_stdio(false);	
	
	int cases; cin >> cases; for (int ca = 1; ca <= cases; ++ ca)
	{
		cin >> k >> l >> s >> keys >> word;

		probab = 1.0;
		for (int i = 0; i < s; ++ i)
			probab /= (LD)k;
		Res = 0;

//		printf("%Lf\n", probab);

		mx = 0;

		rek(0);


		Res = mx - Res;

		printf("Case #%d: %.7Lf\n", ca, Res);
	}
	

	return 0;
}
