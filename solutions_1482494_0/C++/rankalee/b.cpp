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
		int n, a[10], b[10], o[10];
		
		cin >> n;
		rep(i, n) cin >> a[i] >> b[i], o[i] = i;
		
		int ans = inf;
		do{
			int get[10] = {}, cnt = 0, step = 0;
			rep(i, n + 1){
				while(1){
					bool ok = 1;
					rep(j, n) if(get[j] < 2 && b[j] <= cnt){
						step++;
						cnt += 2 - get[j];
						get[j] = 2;
						ok = 0;
					}
					if(ok) break;
				}
				if(i == n) break;
				if(get[o[i]] == 0 && a[o[i]] <= cnt){
					step++;
					cnt++;
					get[o[i]] = 1;
				}
			}
			if(cnt == 2 * n) ans = min(ans, step);
		}while(next_permutation(o, o + n));
		
		
		cout<<"Case #"<<cs+1<<": ";
		if(ans == inf) cout << "Too Bad" << endl;
		else cout << ans << endl;
	}
	
	return 0;
}
