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
vector<string> v,v2;
string s1,s2;
void go(int idx, string s) {
	if(idx==sz(s1)) {
		v.pb(s);
		return;
	}
	if(s1[idx]!='?') go(idx+1,s+s1[idx]);
	else {
		for(int i=0;i<=9;i++) {
			string p=s;
			p+=i+48;
			go(idx+1,p);
		}
	}
}
void go2(int idx, string s) {
	if(idx==sz(s2)) {
		v2.pb(s);
		return;
	}
	if(s2[idx]!='?') go2(idx+1,s+s2[idx]);
	else {
		for(int i=0;i<=9;i++) {
			string p=s;
			p+=i+48;
			go2(idx+1,p);
		}
	}
}
int main() {
//	freopen("TASK.in","r",stdin);	
//	freopen("TASK.out","w",stdout);
	int cc=0;
	int t;
	cin>>t;
	while(t--) {
		cin>>s1>>s2;
		string ans1,ans2;
		v.clear();
		v2.clear();
		go(0,"");
		go2(0,"");

		int mini=1e9+3,ansNum=1e9+3,ansSecNum=1e9+3;
		for(int i=0;i<sz(v);i++) {
			for(int j=0;j<sz(v2);j++) {
				int num=0;
				for(int k=0;k<sz(v[i]);k++) {
					num*=10;
					num+=v[i][k]-48;
				}
				int num2=0;
				for(int k=0;k<sz(v2[j]);k++) {
					num2*=10;
					num2+=v2[j][k]-48;
				}
				if(abs(num-num2)<mini) {
					mini=abs(num-num2);
					ans1=v[i];
					ans2=v2[j];
					ansNum=num;
					ansSecNum=num2;
				}
				else if(abs(num-num2)==mini) {
					if(num<ansNum) {
						ans1=v[i];
						ans2=v2[j];
						ansNum=num;
						ansSecNum=num2;
					}
					else if(num==ansNum and num2<ansSecNum) {
						ans1=v[i];
						ans2=v2[j];
						ansNum=num;
						ansSecNum=num2;
					}
				}
			}
		}
		cc++;
		cout<<"Case #"<<cc<<": "<<ans1<<" "<<ans2<<endl;
	}
	return 0;
}