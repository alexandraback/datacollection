/**************************************************
 * Author	 : xiaohao Z
 * Blog	 : http://www.cnblogs.com/shu-xiaohao/
 * Last modified : 2016-04-30 23:44
 * Filename	 : A.cpp
 * Description	 : 
 * ************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
#define MP(a, b) make_pair(a, b)
#define PB(a) push_back(a)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<unsigned int,unsigned int> puu;
typedef pair<int, double> pid;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;

const int INF = 0x3f3f3f3f;
const double eps = 1E-6;
const int LEN = 1010;
vector<int> Map[LEN];
int xn, yn, n, vis[LEN], match[LEN];
map<string, int> mpa, mpb;
string s[LEN][2];

bool dfs(int v){
	vis[v] = 1;
	for(int i=0; i<Map[v].size(); i++){
		int u = Map[v][i], w = match[u];
		if(w < 0 || (!vis[w] && dfs(w))){
			match[v] = u;
			match[u] = v;
			return true;
		}
	}
	return false;
}
int hungary(){
	int ret = 0;
	memset(match, -1, sizeof match);
	for(int i=0; i<n; i++){
		if(match[i] < 0){
			memset(vis, 0, sizeof vis);
			if(dfs(i)) ret ++;
		}
	}
	return ret;
}

int getcha(string name) {
	if(!mpa.count(name)) return mpa[name] = xn ++;
	else return mpa[name];
}

int getchb(string name) {
	if(!mpb.count(name)) return mpb[name] = yn ++;
	else return mpb[name];
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int T, kase = 1, N;
	string sa, sb;
	cin >> T;
	while(T --) {
		mpa.clear(); mpb.clear();
		for(int i=0; i<LEN; i++) Map[i].clear();
		xn = yn = 0;
		cin >> N;
		for(int i=0; i<N; i++) {
			cin >> s[i][0] >> s[i][1];
			getcha(s[i][0]); getchb(s[i][1]);
		}
		for(int i=0; i<N; i++) {
			int a = getcha(s[i][0]), b = getchb(s[i][1]);
			Map[a].PB(b+xn);
			Map[b+xn].PB(a);
		}
		n = xn + yn;
		int ans = hungary();
		cout << "Case #" << kase ++ << ": " << N - (n - 2*ans) - ans << endl;
		
	}
	return 0;
}

