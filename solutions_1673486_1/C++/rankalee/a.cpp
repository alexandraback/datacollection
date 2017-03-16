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

int a, b;
double p[100000];

int main()
{
	int CS; cin>>CS;
	rep(cs,CS)
	{
		
		cin >> a >> b;
		rep(i, a) cin >> p[i];
		double ans = b + 2, tmp = 1;
		rep(i, a){
			ans = min(ans, tmp * (a-i+b-i+1) + (1-tmp) * (a-i+b-i+1+b+1));
			tmp *= p[i]; 
		}
		ans = min(ans, tmp * (b-a+1) + (1-tmp) * (b-a+2+b));
		
		cout<<"Case #"<<cs+1<<": ";
		printf("%.6f\n", ans);
	}
	
	return 0;
}
