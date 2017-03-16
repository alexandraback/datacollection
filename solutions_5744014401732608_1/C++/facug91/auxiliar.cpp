/*
	By: facug91
	From: 
	Name: 
	Date: 08/05/2016
*/

#include <bits/stdc++.h>
#define endl "\n"
#define EPS 1e-9
#define MP make_pair
#define F first
#define S second
#define DB(x) cerr << " #" << (#x) << ": " << (x)
#define DBL(x) cerr << " #" << (#x) << ": " << (x) << endl
const double PI = acos(-1.0);

#define INF 1000000000
//#define MOD 1000000000ll
//#define MAXN 30015

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

ll b, m;
bool mat[55][55];

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(2); cerr<<fixed<<setprecision(2); //cin.ignore(INT_MAX, ' '); //cout<<setfill('0')<<setw(9)
	int tc = 1;
	
	cin>>tc;
	for (int it=1; it<=tc; it++) {
		cin>>b>>m;
		memset(mat, 0, sizeof mat);
		for (int i=0; i<b-1; i++) mat[i][i+1] = 1;
		ll curr = 1ll;
		for (ll i=b-3ll; i>=0ll; i--) {
			for (ll j=i+2; j<b; j++) {
				if (m >= curr + (1ll<<(max(b-j-2ll, 0ll)))) {
					curr += (1ll<<(max(b-j-2ll, 0ll)));
					mat[i][j] = 1;
				}
			}
		}
		if (curr != m) cout<<"Case #"<<it<<": IMPOSSIBLE"<<endl;
		else {
			cout<<"Case #"<<it<<": POSSIBLE"<<endl;
			for (int i=0; i<b; i++) {
				for (int j=0; j<b; j++) cout<<mat[i][j];
				cout<<endl;
			}
		}
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
