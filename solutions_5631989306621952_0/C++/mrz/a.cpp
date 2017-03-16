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
const int N = 100005;
const ll mod = (ll) 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	int test;
	cin >> test;
	fore(t,0,test) {
		string s,sol = "";
		cin >> s;
		sol += s[0];
		fore(i,1,s.size()) {
			if(s[i] >= sol[0]) {
				sol = s[i] + sol;
			} else
				sol += s[i];
		}
		cout << "Case #" << t+1 << ": " << sol << endl;
	}
	
}
