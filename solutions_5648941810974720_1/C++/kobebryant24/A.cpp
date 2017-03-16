#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<string> vs;
typedef vector<pi> vpi;

#define fi          first
#define se          second
#define mp 			make_pair
#define pb          push_back
#define forall(i,a,b)               for(int i=a;i<b;++i)
#define max(a,b)                    ( (a) > (b) ? (a) : (b))
#define min(a,b)                    ( (a) < (b) ? (a) : (b))
#define mes(a,b)					memset(a,b,sizeof a)
#define endl			    		"\n"
#define ll 							long long
const int oo = 1000000009;
const double eps = 1e-9;
const int mod = 1000000007;

int gcd(int a, int b) {
	return a ? gcd(b % a, a) : b;
}

bool isPalindrome(string s){
	return (s == string(s.rbegin(),s.rend()));
}

int main(){
	int t;cin >> t;
	forall(test,0,t){
		cout << "Case #" << test+1 << ": ";
		string s; cin >> s;
		int a[26];
		memset(a,0,sizeof a);
		forall(i,0,s.size()) a[s[i]-'A']++;
		int x[15];
		memset(x,0,sizeof x);
		if(a['Z'-'A']) {
			x[0]=a['Z'-'A'];
			a['E'-'A']-=a['Z'-'A'];
			a['R'-'A']-=a['Z'-'A'];
			a['O'-'A']-=a['Z'-'A'];
			a['Z'-'A']=0;
		}
		if(a['X'-'A']) {
			x[6]=a['X'-'A'];
			a['I'-'A']-=a['X'-'A'];
			a['S'-'A']-=a['X'-'A'];
			a['X'-'A']=0;
		}
		if(a['U'-'A']) {
			x[4]=a['U'-'A'];
			a['F'-'A']-=a['U'-'A'];
			a['R'-'A']-=a['U'-'A'];
			a['O'-'A']-=a['U'-'A'];
			a['U'-'A']=0;
		}
		if(a['W'-'A']) {
			x[2]=a['W'-'A'];
			a['T'-'A']-=a['W'-'A'];
			a['O'-'A']-=a['W'-'A'];
			a['W'-'A']=0;
		}
		if(a['G'-'A']) {
			x[8]=a['G'-'A'];
			a['E'-'A']-=a['G'-'A'];
			a['I'-'A']-=a['G'-'A'];
			a['H'-'A']-=a['G'-'A'];
			a['T'-'A']-=a['G'-'A'];
			a['G'-'A']=0;
		}
		if(a['O'-'A']) {
			x[1]=a['O'-'A'];
			a['N'-'A']-=a['O'-'A'];
			a['E'-'A']-=a['O'-'A'];
			a['O'-'A']=0;
		}
		if(a['F'-'A']) {
			x[5]=a['F'-'A'];
			a['I'-'A']-=a['F'-'A'];
			a['V'-'A']-=a['F'-'A'];
			a['E'-'A']-=a['F'-'A'];
			a['F'-'A']=0;
		}
		if(a['H'-'A']) {
			x[3]=a['H'-'A'];
			a['T'-'A']-=a['H'-'A'];
			a['R'-'A']-=a['H'-'A'];
			a['E'-'A']-=2*a['H'-'A'];
			a['H'-'A']=0;
		}
		if(a['I'-'A']) {
			x[9]=a['I'-'A'];
			a['N'-'A']-=2*a['I'-'A'];
			a['E'-'A']-=a['I'-'A'];
			a['I'-'A']=0;
		}
		if(a['S'-'A']) x[7]=a['S'-'A'];
		forall(i,0,10){
			if(x[i]){
				forall(j,0,x[i]) cout << i;
			}
		}
		cout << endl;
	}
}