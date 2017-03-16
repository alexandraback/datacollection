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

int n, s, p;

int main()
{
	int CS; cin>>CS;
	rep(cs,CS)
	{
		cin >> n >> s >> p;
		int ans = 0;
		rep(i,n){
			int x;
			cin >> x;
			int a = x / 3, b = x / 3, c = x - a - b;
			//dbg(a); dbg(b); dbg(c);
			if(c == a+2){
				if(a+1 >= p) ans++;
				else if(c >= p && s) ans++, s--;
			}
			else if(c == a+1){
				if(c >= p) ans++;
			}
			else{
				if(c >= p) ans++;
				else if(c > 0 && c+1 >= p && s) ans++, s--;
			}
		}
		cout<<"Case #"<<cs+1<<": "<<ans<<endl;
	}
	
	return 0;
}
