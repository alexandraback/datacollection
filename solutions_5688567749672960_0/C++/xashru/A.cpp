#include <cctype>
#include <climits>
#include <cmath>
#include <cstring>
#include <deque>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <bitset>
#include <numeric>
#include <ratio>
#include <regex>
#include <sstream>
#include <string>
#include <tuple>
#include <utility>
#include <valarray>

using namespace std;

#define sz(v) v.size()
#define eps 1e-10
#define fill(v,n,x) for(int i=0;i<(int)n;i++) v.push_back(x)
#define re return
#define sum(v) accumulate(v.begin(),v.end(),0)
#define asrt(v) sort(v.begin(),v.end())
#define dsrt(v) sort(v.rbegin(),v.rend())
#define rev(v) reverse(v.begin(),v.end())
#define pi 3.1415926535897932384626433832795
#define print(v) for (auto& i:v) cout<<i<<endl
#define print "Case #"+to_string(t1)+": "

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<string> vs;
typedef vector<vector<int>> vvi;

struct node {
	int n,c;
};

bool vis[1000000+1];

int main() {
	freopen("a.txt", "r", stdin);
	freopen("a.out", "w", stdout);
	int T;
	cin>>T;
	for(int t1=1; t1<=T; t1++) {
		int x;
		cin>>x;
		for(int i=0; i<=x; i++) vis[i]=false;
		node start {1,1};
		queue<node> q;
		q.push(start);
		vis[1]=true;
		int res=0;
		while(!q.empty()) {
			node top=q.front();
			q.pop();
			if(top.n==x) {
				res=top.c;
				break;
			}

			node t1 {top.n+1,top.c+1};
			if(!vis[t1.n]) q.push(t1);
			vis[t1.n]=true;
			string s=to_string(top.n);
			rev(s);
			node t2 {stoi(s),top.c+1};
			if(!vis[t2.n]) q.push(t2);
			vis[t2.n]=true;
		}
		cout<<print<<res<<endl;
	}
	return 0;
}
