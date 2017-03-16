#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <cstdio>
#include <set>
#include <map>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <cassert>
#include <sstream>

using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef stringstream SS;

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define ABS(a) MAX(a,-(a))

#define SS(a) scanf("%d",&a)
#define SZ(a) ((int)a.size())
#define PB(a) push_back(a)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define REP(i,n) FOR(i,0,(int)(n-1))
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define printv(v) REP(i,SZ(v))printf("%d ",v[i]);
#define mp(a,b) make_pair(a,b)
#define MOD 1000000007
#define INF 2147483647

int cons[1111111];

bool isvowel(char ch){
	string a = "aeiou";
	REP(i,SZ(a)){
		if (ch == a[i]) return true;
	}
	return false;
}

int main(){
	freopen("a1.in","r",stdin);
	freopen("a.out","w",stdout);
    int t;
    cin>>t;
    FOR(tt,1,t){
		string s;
		int d;
		cin>>s>>d;

		int n = SZ(s);

		if (d==0){
			LL ans = (((LL)n) * (n+1)) / 2;
			cout<<"Case #"<<tt<<": "<<ans<<endl;
			continue;
		}

		if (!isvowel(s[0])) cons[0] = 1;
		else cons[0] = 0;
		FOR(i,1,n-1){
			if (isvowel(s[i])) cons[i] = 0;
			else cons[i] = 1 + cons[i-1];
		}

		int lpos = -1;
		LL ans = 0;
		REP(i,n){
			if (cons[i]>=d){
				lpos = i;
			}
			if (lpos-d+2 > 0)
			ans += lpos-d+1+1;
		}
		cout<<"Case #"<<tt<<": "<<ans<<endl;
    }

    return 0;
}
