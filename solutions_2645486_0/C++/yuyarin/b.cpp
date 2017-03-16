#include <cstdio>
#include <string>
#include <vector>
#include <iostream>

#include <cstdlib>
#include <cctype>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <algorithm>
#include <functional>
#include <numeric>
#include <bitset>
#include <sstream>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long ll;
typedef unsigned int uint;

inline int toi(string s){int v; istringstream iss(s);iss>>v;return v;}
template<class T> inline string tos(T x){ostringstream oss;oss<<x;return oss.str();}

#define All(a)  (a).begin(),(a).end()
#define Rall(a) (a).rbegin(),(a).rend()
#define pb push_back
#define mp make_pair
#define sz(a) int((a).size())
#define exist(s,e) ((s).find(e)!=(s).end())

#define Forall(i,v)   for(int i=0;i<(int)v.size();++i)
#define For(i,a,b)    for(int i=(a);i<(b);++i)
#define ForD(i,a,b)   for(int i=(a);i>(b);--i)
#define Step(i,a,b,s) for(int i=(a);i<(b);i+=(s))
#define Rep(i,n)      for(int i=0;i<(n);++i)
#define Each(i,c)     for(typeof((c).begin()) i=(c).begin();i!=(c).end();++i)

#define Fill(a,b)   memset(a,b,sizeof(a))
#define Clear(a)    memset((a),0,sizeof(a))
#define Sort(c)     sort((c).begin(),(c).end())

#define MinOf(x)    *min_element(All(x))
#define MaxOf(x)    *max_element(All(x))

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

#define MAX_E 10000001
#define MAX_N 10001

int dp[MAX_N][MAX_E] = {0};
int vs[MAX_N] = {0};
void main2(void){
	int e,r,n;
	cin >> e >> r >> n;
	Rep(i,n){
		int v;
		cin >> v;
		vs[i] = v;
	}
	Rep(i,n){
		Rep(j,e+1){
			dp[i+1][j] = 0;
		}
		Rep(j,e+1){
			int cg = dp[i][j]; // current gain
			Rep(c,j+1){
				int g = c*vs[i]; // gain
				int tg = g + cg; // total gain
				int re = j - c + r; // next remain energy
				if(re>e) re = e;
				if(dp[i+1][re]<tg){
					dp[i+1][re] = tg;
				}
			}
		}
	}
	int mg = 0; // max gain
	Rep(j,e+1){
		int g = dp[n][j];
		if(mg<g) mg = g;
	}
	cout << " " << mg << endl;
}

int main(void){
	int T,t;
	cin >> T;
	REP(t,T){
		printf("Case #%d:",t+1);
		main2();
	}
	return 0;
}
