/*
 	Beautiful Codes are MUCH better than 'Shorter' ones !
user  : triveni
date  : 12/04/2015
time  : 04:45:16
*/
#include <bits/stdc++.h>

using namespace std;

#define      pii               std::pair<int,int>
#define      vi                std::vector<int>
#define      mp(a,b)           std::make_pair(a,b)
#define      pb(a)             std::push_back(a)
#define      each(it,s)        for(auto it = s.begin(); it != s.end(); ++it)
#define      rep(i, n)         for(int i = 0; i < (n); ++i)
#define      fill(a)           memset(a, 0, sizeof (a))
#define      sortA(v)          sort(v.begin(), v.end())
#define      sortD(v)          sort(v.begin(), v.end(), greater<auto>())

typedef long long LL;
LL MOD = 1000000007;
LL INF = MOD * MOD;

char A[4][4] = {'h','i','j','k',
			   'i','h','k','j',
			   'j','k','h','i',
			   'k','j','i','h'};
int sgn[4][4] = {1,1,1,1,
				 1,-1,1,-1,
				 1,-1,-1,1,
				 1,1,-1,-1};

class Ira{
public:
	Ira (){}
	Ira(char c){
		ch = c;
		sign = +1;
	}
	char ch;
	int sign;
	Ira operator * (char c){
		Ira ret;
		ret.ch = A[ch-'h'][c-'h'];
		ret.sign = sign * sgn[ch-'h'][c-'h'];
		return ret;
	}
	Ira operator * (Ira val) {
		Ira ret;
		ret.ch = A[ch-'h'][val.ch-'h'];
		ret.sign = sign * val.sign * sgn[ch-'h'][val.ch-'h'];
		return ret;
	}
	bool operator == (Ira val){
		return ch == val.ch && sign == val.sign;
	}
};

Ira I('i');
Ira J('j');
Ira K('k');
Ira H('h');

int main()
{
	int T; LL L, X;
	string inp;
	scanf("%d",&T);
	for(int tc = 1; tc <= T; ++tc){
		scanf("%lld %lld",&L, &X);
		cin >> inp;
		assert((int)inp.length() == L);
		if(L * X < 3){
			printf("Case #%d: NO\n", tc);
			continue;
		}
		Ira tot(inp[0]);
		for(int i = 1; i < L; ++i){
			tot = tot * inp[i];
		}
		LL minLength = INF;
		Ira pow4[4];
		pow4[0] = H;
		for(int i = 1; i < 4; ++i) pow4[i] = pow4[i-1] * tot;
		if(pow4[X % 4].ch != 'h' || pow4[X % 4].sign != -1){
			printf("Case #%d: NO\n", tc);
			continue;
		}
		
		tot = H;
		for(int i = 0; i < L; ++i){
			tot = tot * inp[i];
			for(int j = 0; j < 4; ++j){
				if(L * j + i + 1 >= minLength) break;
				if(pow4[j] * tot == I){
					minLength = L * j + i + 1;
				}
			}
		}
		// cerr << "minLength " << minLength << endl;
		LL maxLength = INF;
		tot = H;
		for(int i = L-1; i >= 0; --i){
			if(inp[i] == 'i') tot = I * tot;
			if(inp[i] == 'j') tot = J * tot;
			if(inp[i] == 'k') tot = K * tot;
			for(int j = 0; j < 4; ++j){
				if(L * j + L - i >= maxLength) break;
				if(tot * pow4[j] == K){
					maxLength = L * j + L - i;
				}
			}
		}
		// cerr << "maxLength " << maxLength << endl;
		if(minLength + maxLength >= L * X) {
			printf("Case #%d: NO\n", tc);
			continue;
		}
		printf("Case #%d: YES\n", tc);
	}
	return 0;
}
