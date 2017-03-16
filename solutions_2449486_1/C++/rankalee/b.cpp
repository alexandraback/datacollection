#include<iostream>
#include<sstream>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<complex>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cassert>

#define rep(i,n) for(int i=0;i<(int)n;i++)
#define all(c) (c).begin(),(c).end()
#define mp make_pair
#define pb push_back
#define each(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define dbg(x) cerr<<__LINE__<<": "<<#x<<" = "<<(x)<<endl

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
const int inf = (int)1e9;
const double INF = 1e12, EPS = 1e-9;

int h, w;
int a[100][100], r[100], c[100];

int main(){
	int CS;
	cin >> CS;
	rep(cs, CS){
		cout << "Case #" << cs + 1 << ": ";
		
		cin >> h >> w;
		rep(i, h) r[i] = 0;
		rep(i, w) c[i] = 0;
		rep(i, h) rep(j, w){
			cin >> a[i][j];
			r[i] = max(r[i], a[i][j]);
			c[j] = max(c[j], a[i][j]);
		}
		bool ok = 1;
		rep(i, h) rep(j, w){
			if(r[i] > a[i][j] && c[j] > a[i][j]) ok = 0;
		}
		cout << (ok ? "YES" : "NO") << endl;
	}
	return 0;
}
