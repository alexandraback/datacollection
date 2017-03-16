#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
string word[]={"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
ll order[]={0,2,6,7,5,4,3,8,1,9};
ll ans[100];
int main() {
	cout.precision(300);
	ios::sync_with_stdio(false);
	ll cases;
	cin >> cases;
	map<ll,char> sp;
	sp[0]='Z';
	sp[2]='W';
	sp[6]='X';
	sp[7]='S';
	sp[5]='V';
	sp[4]='U';
	sp[3]='R';
	sp[8]='H';
	sp[1]='O';
	sp[9]='I';
	for (ll casenum = 1; casenum <= cases; casenum++) {
		string s;
		cin>>s;
		ll n=s.length();
		map<char,ll> h;
		for (ll i=0;i<n;i++) {
			char c=s[i];
			h[c]++;
		}
		for (ll d=0;d<10;d++) {
			ans[d]=0;
		}
		for (ll i=0;i<10;i++) {
			ll digit=order[i];
			char special=sp[digit];
			for (ll j=i+1;j<10;j++) {
				for (auto &c:word[order[j]]) {
					assert(special!=c);
				}	
			}
			ans[digit]=h[special];
			for (auto &c:word[digit]) {
				h[c]-=ans[digit];
				assert(h[c]>=0);
			}
		}
		for (auto &w:h) {
			assert(w.second==0);
		}
		string final;
		for (ll d=0;d<10;d++) {
			char c='0'+d;
			for (ll i=0;i<ans[d];i++) {
				final+=c;
			}
		}
		cout << "Case #" << casenum << ": " << final << endl;
	}
}
