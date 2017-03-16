//#pragma comment(linker,"/STACK:16777216") /*16Mb*/
//#pragma comment(linker,"/STACK:33554432") /*32Mb*/
#include<sstream>
#include<iostream>
#include<numeric>
#include<sstream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<memory>
#include<memory.h>
#include<string>
#include<vector>
#include<cctype>
#include<list>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

typedef unsigned long long      ULL;
typedef long long               LL;

#define PB                      push_back
#define MP                      make_pair
#define X                       first
#define Y                       second
#define FOR(i, a, b)            for(int i = (a); i < (b); ++i)
#define RFOR(i, a, b)           for(int i = (a) - 1; i >= (b); --i)
#define CLEAR(a, b)             memset(a, b, sizeof(a))
#define SZ(a)                   int((a).size())
#define ALL(a)                  (a).begin(), (a).end()
#define RALL(a)                 (a).rbegin(), (a).rend()
#define INF                     (1000000000)
#define FILL                    CLEAR

const int MOD = 1000000007;

void submit(){
	freopen("in.txt" , "r" , stdin);
	freopen("out.txt" , "w" , stdout);
}

bool f(LL X , LL r , LL t){
	double d = 1.0 * X * (2 * X + 2 * r - 1);
	if (d > 4E18) return 0;
	if (X * (2 * X + 2 * r - 1) <= t) return 1;
	return 0;
}

LL v[10007];
LL down[10007] , up[10007];

int main()
{
	submit();

	int t;
	cin >> t;
	FOR(ttt,0,t){
		cerr<<ttt<< endl;
		LL E , R;
		cin >> E >> R;
		int n;
		cin >> n;
		FOR(i,0,n)
			cin >> v[i];
		LL res = 0;
		FOR(i,0,n)
			down[i] = 0 , up[i] = E;
		vector<pair<LL,int> > a;
		FOR(i,0,n)
			a.PB(MP(v[i] , i));
		sort(a.rbegin() , a.rend());
		FOR(i,0,n){
			int cur = a[i].second;
			res += (up[cur] - down[cur]) * v[cur];
			FOR(j,0,cur){
				LL t = up[cur] - (j + 1) * R;
				if (t < 0) break;
				down[cur - j - 1] = max(down[cur - j - 1] , t);
			}
			FOR(j,cur + 1 , n){
				LL t =  down[cur] + (j - cur) * R;
				if (t > E) break;
				up[j] = min(up[j] , t);
			}
		}
		cout << "Case #" << ttt + 1 << ": " << res << endl;
	}

    return 0;
};