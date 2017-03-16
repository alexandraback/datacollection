//#pragma comment(linker, "/STACK:32777216")
#include <iostream> 
#include <vector>
#include <set>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
#include <memory.h>
#include <fstream>
using namespace std;

#define FOR(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define RFOR(i,a,b) for(int (i)=(a)-1;(i)>=(b);(i)--)
#define MP make_pair
#define ALL(a) (a).begin(),(a).end()
#define PB push_back
#define PII pair<int,int>
#define CLEAR(a) memset((a),0,sizeof((a)))
#define X first
#define Y second
#define sz(a) (int)(a).size()

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;

const double pi=3.141592653589793;
const int INF=1000000000;
const ll mod=1000000007;

int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t;
	cin >> t;
	FOR(ttt,0,t){
		cout << "Case #" << ttt + 1 << ": ";
		bool qw = 0;
		int n;
		cin >> n;
		vector<int> g[1005];
		FOR(i,0,n){
			int m;
			cin >> m;
			FOR(j,0,m){
				int k;
				cin >> k;
				--k;
				g[i].PB(k);
			}
		}
		FOR(s,0,n)
			if (!qw){
				queue<int> q;
				q.push (s);
				vector<bool> used (n);
				used[s] = true;
				while (!q.empty()) {
					int v = q.front();
					q.pop();
					for (size_t i=0; i<g[v].size(); ++i) {
						int to = g[v][i];
						if (!used[to]) {
							used[to] = true;
							q.push (to);
						}
						else{
							if (!qw){qw = 1;cout << "Yes" << endl;break;}
						}
					}
				}
			}
		if (!qw) cout << "No" << endl;

	}
	return 0;
}