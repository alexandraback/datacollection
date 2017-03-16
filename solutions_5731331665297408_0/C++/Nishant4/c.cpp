#include <iostream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <ctime>
#include <math.h>
#include <algorithm>
#include <iomanip>
#include <assert.h>
#include <map>
#include <queue>
#include <cstring>
#include <set>
#include <stack>
#include <numeric>
using namespace std;

typedef unsigned long long int ull;
typedef long long int ll;
#define vi vector<int>
#define vvi vector< vector<int> >
#define vd vector<double>
#define vb vector<bool>
#define vs vector<string>
#define pi pair<int,int>
#define pb push_back
#define out(a) cout<<(a)<<endl
#define pout(a) cout<<(a).first<<' '<<(a).second<<endl
#define sz(c) (int)(c).size()
#define fr(n,i) for(int (i)=0;(i)<(n);(i)++)
#define rng(s,e,i) for(int (i)=(s);(i)<=(e);(i)++)
#define all(c) (c).begin(),(c).end()
#define ifBit(n,i) ( ((n) >> (i)) & 1 )
#define mp make_pair
template<typename typ> void vout(vector<typ>& v){for(int vint=0;vint<sz(v);vint++){cout<<(v)[vint];if(vint==sz(v)-1) cout<<endl;else cout<<' ';}}
template<typename typ> void arrout(typ* arr,int l){for(int i=0;i<l;i++){cout<<arr[i];if(i<l-1) cout <<' ';else cout<<endl;}}

#ifdef DEBUG
	#define debug(args...)            {dbg,args; cerr<<endl;}
#else
	#define debug(args...)              // Just strip off all debug tokens
#endif

struct debugger
{
	template<typename T> debugger& operator , (const T& v)
	{
		cerr<<v<<" ";
		return *this;
	}
}dbg;

int n, m;
string zip[51];
bool graph[51][51];
string ans;

int perm[51];

void calc() {
	int cur = perm[0];

	vi visited;
	for(int i = 1 ; i < n ; i++) {
		int next = perm[i];
		while(!graph[cur][next] && sz(visited) > 0) {
			cur = visited[sz(visited) - 1];
			visited.pop_back();
		}
		if( !graph[cur][next] ) {
			return;
		}

		visited.pb(cur);
		cur = next;
	}

	string z = "";
	for(int i = 0 ; i < n ; i++) {
		z += zip[perm[i]];
	}
	ans = min(ans, z);
}

void permute(int node) {
	if( node == n ) {
		// arrout(perm, n);
		calc();
		return;
	}

	for(int i = node ; i < n ; i++) {
		swap(perm[i], perm[node]);
		permute(node + 1);
		swap(perm[i], perm[node]);
	}
}

int main()
{
	int T;
	cin >> T;
	for(int t = 1 ; t <= T ; t++) {
		cin >> n >> m;
		ans = string(n * 5, '9');
		for(int i = 0 ; i < n ; i++) {
			cin >> zip[i];
		}

		memset(graph, false, sizeof graph);

		for(int i = 0 ; i < m ; i++) {
			int from, to;
			cin >> from >> to;
			graph[from - 1][to - 1] = graph[to - 1][from - 1] = true;
		}

		for(int i = 0 ; i < n ; i++) {
			perm[i] = i;
		}
		permute(0);
		printf("Case #%d: ", t);
		out(ans);
	}
}