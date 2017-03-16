#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define fore(i,a,n) for(int i=a;i<n;i++)
#define rev(i,n) for(int i = n-1; i>= 0; i--)
#define pb push_back
#define mp make_pair
#define dprint(v) cerr << #v " = " << v << endl
#define endl '\n'
#define fill(m,v) memset(m,v,sizeof m)
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
const int N = 3505;
const ll mod = (ll) 1e9 + 7;
ll cant[N];
vector<int> sol;
int main() {
	ios_base::sync_with_stdio(false);
	int test;
	cin >> test;
	fore(t,0,test) {
		int n,to;
		cin >> n;
		to = 2 * n;
		to--;
		fill(cant,0);
		sol.clear();
		fore(i,0,to) {
			fore(j,0,n) {
				int tmp;
				cin >> tmp;
				cant[tmp]++;
			}
		}
		fore(i,1,2600) {
			if(cant[i] & 1LL)
				sol.pb(i);
		}
		cout << "Case #" << t+1 << ":";
		fore(i,0,sol.size()) {
			cout << " " << sol[i];
		}
		cout << endl;
	}
}
