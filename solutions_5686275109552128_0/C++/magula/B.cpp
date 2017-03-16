#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <stack>
#include <cassert>
using namespace std;

typedef long long LL;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii > vii;
typedef queue<int> qi;
typedef set<int> si;

#define RE(i,b) for(int i=0; i<(int)(b); i++)
#define REP(i,a,b) for(int i=(a); i<(int)(b); i++)
#define BREP(i,a,b) for(int i=(a)-1; i>=(b); i--)
#define FE(i,X) for(typeof((X).begin()) i=(X).begin(); i!=(X).end(); ++i)

#define INF 1000000000
#define MP make_pair
#define FI first
#define SE second

#define Result(a) {printf("Case #%d: %d\n",tc+1,a);continue;}

int main(){
	int TC;scanf("%d ",&TC);
	RE(tc,TC){
		int D;scanf("%d ",&D);
		multiset<int> V;
		RE(i,D){
			int a;scanf("%d ",&a);V.insert(a);
		}
		int E=*(--V.end()),O=0;
		while(V.size()){
			E=min(E,*(--V.end())+O);
			if(*(--V.end())==1)
				break;
			V.insert(*(--V.end())/2);
			V.insert(*(--V.end())-*(--V.end())/2);
			V.erase(--V.end());
			O++;
		}
		Result(E);
	}
	return 0;
}