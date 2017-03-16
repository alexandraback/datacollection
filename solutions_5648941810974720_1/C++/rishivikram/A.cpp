#include<bits/stdc++.h>

using namespace std;

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define eps 1e-9
#define sqr(x) ((x)*(x))
#define SET(a,b) memset((a),(b),sizeof((a)))
#define pw(x) (1ll<<(x))
#define buli(x) __builtin_popcountll(x)
#define endl "\n"

const int MOD = 1e9+7;

typedef long long ll;
typedef vector<int> vi;
typedef map<int,int> mii;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

inline bool EQ(double a,double b) { return fabs(a - b) < 1e-9; }
inline void set_bit(int & n, int b) { n |= pw(b); }
inline void unset_bit(int & n, int b) { n &= ~pw(b); }

inline void check(ll &x) {
	if(x>=MOD)
		x%=MOD;
}
int main() {
//	freopen("TASK.in","r",stdin);	
//	freopen("TASK.out","w",stdout);
	int t;
	int cc=0;
	scanf("%d ",&t);
	while(t--) {
		string str;
		cin>>str;
		int len=sz(str);
		for(int i=0;i<len;i++) str[i]+=32;
		map<char,int> m;
		for(int i=0;i<len;i++) {
			m[str[i]]++;
		}
		int ans[15];
		for(int i=0;i<10;i++) ans[i]=0;
		if(m.find('z')!=m.end()) {
			ans[0]=m['z'];
			m['e']-=m['z'];
			m['r']-=m['z'];
			m['o']-=m['z'];
			m['z']-=m['z'];
		}
		if(m.find('u')!=m.end()) {
			ans[4]=m['u'];
			m['f']-=m['u'];
			m['o']-=m['u'];
			m['r']-=m['u'];
			m['u']-=m['u'];
		}
		if(m.find('f')!=m.end()) {
			ans[5]=m['f'];
			m['i']-=m['f'];
			m['v']-=m['f'];
			m['e']-=m['f'];
			m['f']-=m['f'];
		}
		if(m.find('x')!=m.end()) {
			ans[6]=m['x'];
			m['s']-=m['x'];
			m['i']-=m['x'];
			m['x']-=m['x'];
		}
		if(m.find('s')!=m.end()) {
			ans[7]=m['s'];
			m['e']-=m['s'];
			m['v']-=m['s'];
			m['e']-=m['s'];
			m['n']-=m['s'];
			m['s']-=m['s'];
		}
		if(m.find('r')!=m.end()) {
			ans[3]=m['r'];
			m['t']-=m['r'];
			m['h']-=m['r'];
			m['e']-=m['r'];
			m['e']-=m['r'];
			m['r']-=m['r'];
		}
		if(m.find('g')!=m.end()) {
			ans[8]=m['g'];
			m['e']-=m['g'];
			m['i']-=m['g'];
			m['h']-=m['g'];
			m['t']-=m['g'];
			m['g']-=m['g'];
		}
		if(m.find('t')!=m.end()) {
			ans[2]=m['t'];
			m['w']-=m['t'];
			m['o']-=m['t'];
			m['t']-=m['t'];
		}
		if(m.find('o')!=m.end()) {
			ans[1]=m['o'];
			m['n']-=m['o'];
			m['e']-=m['o'];
			m['o']-=m['o'];
		}
		if(m.find('e')!=m.end()) {
			ans[9]=m['e'];
			m['n']-=m['e'];
			m['i']-=m['e'];
			m['n']-=m['e'];
			m['e']-=m['e'];
		}
		string p="";
		for(int i=0;i<10;i++) {
			for(int j=1;j<=ans[i];j++) p+=(i+48);
		}
		cc++;
		cout<<"Case #"<<cc<<": "<<p<<endl;
	}
	return 0;
}