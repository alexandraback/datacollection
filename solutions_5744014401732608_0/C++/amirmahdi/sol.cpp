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

const int maxb = 60;

ll p[maxb];
int a[maxb][maxb];
int c[maxb][maxb];

void solve(){
	memset(a, 0, sizeof(a));
	memset(c, 0, sizeof(c));
	int b;
	ll m;
	cin >> b >> m;
	p[1] = 1;
	p[2] = 1;
	for(int i=3;i<=b;i++){
		p[i] = p[i-1] * 2;
	}
	if(p[b] < m){
		cout << "IMPOSSIBLE" << endl;
		return;
	}
	int k = 0;
	for(;k<=b;k++)
		if(p[k] >= m)
			break;

	for(int i=k-1;i>=1;i--)
		for(int j=i-1;j>=1;j--)
			a[i][j] = 1;
	for(int i=k-1;i>=1 && m > 0;i--)
		if(m >= p[i]){
			m-=p[i];
			a[k][i] = 1;
		}
	for(int i=b;i>k;i--)
		a[i][i-1] = 1;
	cout << "POSSIBLE" << endl;
	For(i,1,b+1)
		For(j,1,b+1)
			c[i][j] = a[j][i];
	For(i,1,b+1){
		For(j,1,b+1)
			cout << c[i][j];
		cout << endl;
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
