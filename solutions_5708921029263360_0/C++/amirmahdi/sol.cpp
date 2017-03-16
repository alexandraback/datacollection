#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<set>
#include<map>
#include<cmath>
#include<cstdlib>
#include<complex>
#include<sstream>
#include<iomanip>

using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)
#define For(i,a,b) for(int i=a;i<b;i++)
#define pb(x) push_back(x)
#define ll long long
#define VI vector<int>

typedef pair<int,int> pi;


void solve(){
	int q, p, s, m;
	cin >> q >> p >> s >> m;
	int n = q*p*s;
	int r = 1<<n;
	int ans = 0;
	int ind = -1;
	for(int i=r-1;i>=0;i--){
		int v[30], cnt = 0;
		rep(j,n)
			if((i>>j)&1)
				v[cnt++] = j;
				
		if(cnt <= ans)
			continue;
		int d[3][4][4];
		memset(d,0,sizeof(d));
		rep(j,cnt){
			int i3 = v[j]%s, i2 = (v[j]/s)%p, i1 = (v[j]/s/p)%q;
			d[0][i1][i2]++;
			d[1][i1][i3]++;
			d[2][i2][i3]++;
		}
		rep(j,3)
			rep(k,3)
				rep(l,3)
					if(d[j][k][l] > m)
						goto hell;
		ans = cnt;
		ind = i;
		hell:;
	}
	cout << ans << endl;
	rep(j,n)
		if((ind>>j)&1){
			int i3 = j%s, i2 = (j/s)%p, i1 = (j/s/p)%q;
			cout << i1+1 << " " << i2+1 << " " << i3+1 << endl;
		}
}

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	rep(g,t){
		cout << "Case #" << g+1 << ": ";
		solve();
	}
	return 0;
}
