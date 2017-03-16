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
int glo=0;
string ar[1002][5],temp[1002][5];
bool check(string x, string y) {
	for(int i=1;i<=glo;i++) {
		if(x==temp[i][1] and y==temp[i][2]) return false;
	}
	return true;
}
int main() {
//	freopen("TASK.in","r",stdin);	
//	freopen("TASK.out","w",stdout);
	int t;
	int cc=0;
	cin>>t;
	while(t--) {
		int n;;
		cin>>n;
		int ans=0;
		for(int i=1;i<=n;i++) cin>>ar[i][1]>>ar[i][2];
//		for(int i=1;i<=n;i++) cout<<ar[i][1]<<" "<<ar[i][2]<<endl;

		for(int i=1;i<=n;i++) {
			glo=0;
			map<string,int> fir,sec;
			for(int j=1;j<=i;j++) {
				fir[ar[j][1]]++;
				sec[ar[j][2]]++;
				temp[++glo][1]=ar[j][1];
				temp[glo][2]=ar[j][2];

			}
			bool f=false;
			for(int j=i+1;!f and j<=n;j++) {
				if(fir.find(ar[j][1])!=fir.end() and sec.find(ar[j][2])!=sec.end() and check(ar[j][1],ar[j][2])) {
					temp[++glo][1]=ar[j][1];
					temp[glo][2]=ar[j][2];
					fir[ar[j][1]]++;
					sec[ar[j][2]]++;
				}
				else f=true;
			}
			if(!f) {
				ans=n-i;
				break;
			}
		}
		++cc;
		cout<<"Case #"<<cc<<": "<<ans<<endl;
	}
	return 0;
}