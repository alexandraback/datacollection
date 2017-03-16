#include<iostream>
#include<sstream>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#include<numeric>
#include<complex>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cassert>

#define rep(i,n) for(int i=0;i<(int)n;i++)
#define all(c) (c).begin(),(c).end()
#define mp make_pair
#define pb push_back
#define fr(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pi;
const int inf=(int)1e9;
const double INF=1e12,EPS=1e-9;

int main()
{
	int CS; cin>>CS;
	rep(cs,CS)
	{
		int a, b, ans = 0;
		cin >> a >> b;
		for(int i = a; i <= b; i++){
			char s[20];
			sprintf(s, "%d", i);
			string t(s), u;
			
			set<int> m;
			for(int j = 0; s[j]; j++){
				u = t.substr(j) + t.substr(0, j);
				int x = atoi(u.c_str());
				if(x > i && x <= b && !m.count(x)) ans++;
				m.insert(x);
			}
		}
		cout<<"Case #"<<cs+1<<": "<<ans<<endl;
	}
	
	return 0;
}
