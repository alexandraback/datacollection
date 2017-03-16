#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <map>
#include <deque>
#include <set>
using namespace std;

#define sz size()
#define FOR(i,a,b) for(int (i) = (a); (i) <= (b); ++(i))
#define ROF(i,a,b) for(int (i) = (a); (i) >= (b); --(i))
#define rep(i,n) for (int (i) = 0; (i) < (n); ++(i))
#define fe(i,a) for (int (i) = 0; (i) < int((a).size()); ++(i))
#define C(a) memset((a),0,sizeof(a))
#define inf 1000000000
#define pb push_back
#define ppb pop_back
#define all(c) (c).begin(), (c).end()
#define pi 2*acos(0.0)
#define sqr(a) (a)*(a)
#define mp(a,b) make_pair((a), (b))
#define X first
#define Y second

typedef vector<int> vint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int INF=2000000000;   
int main() {
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    //freopen("input.txt","r",stdin);
    int T,n,m,c,g,h,len,a,b; char ch;
    cin>>T;
	rep(zalupa,T){
		cin>>a>>b;
		vector<double> p(a);
		rep(i,a)cin>>p[i];
		double ans=b+2,g=1,h;
		rep(i,a){
			g*=p[i];
			ans=min(ans,g*(a-i+b-i-1)+(1-g)*(a-i+b-i+b));
		}
		
		printf("Case #%d: %.6lf\n",zalupa+1,ans);
	}
    return 0;
}