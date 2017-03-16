#include<bits/stdc++.h>
#define LOCAL
#define DEBUG
#define si(n) scanf("%d",&n)
#define sl(n) cin>>n
#define sf(n) scanf("%f",&n)
#define pn(n) printf("%d\n",n)
#define ps(n) printf("%d ",n)
#define pln(n) cout<<n<<endl
#define pnl() printf("\n")
#define pls(n) cout<<n<<" "
#define pl(n) cout<<n
#define FOR(i,j,n) for(i=j;i<=n;i++)
#define FORR(i,j,n) for(i=j;i>=n;i--)
#define SORT(n) std::sort(n.begin(),n.end())
#define FILL(n,a) std::fill(n.begin(),n.end(),a)
#define ALL(n) n.begin(),n.end()
#define rsz resize
#define pb push_back
#define MAXINT std::numeric_limits<int>::max()
#define MININT std::numeric_limits<int>::min()
#define getchar gc
#define putchar pc
#define iOS std::ios_base::sync_with_stdio(false)
#define endl "\n"
#define INF 1000000000000000005LL
#ifdef DEBUG
    #define debug(x) cout << #x << " = " << x << endl
#else
    #define debug(x)
#endif
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<vector<int> > vvi;
typedef vector<vector<ll> > vvl;
typedef pair<int,int> pii;
 
/**************** TEMPLATE ENDS HERE *************************/
ll ans;
pair<string,string> ap;
void updateAns(string c,string j) {
	//debug(c);
	//debug(j);
	istringstream iss(c);
	ll nc,nj;
	iss>>nc;
	istringstream iss2(j);
	//iss.str(j);
	//debug(iss.str());
	iss2>>nj;
	//debug(nc);
	//debug(nj);
	ll newAns = abs(nc-nj);
	if(newAns<ans) {
		ans = newAns;
		ap.first=c;
		ap.second=j;
	}
	else if(newAns==ans) {
		if(c<ap.first) {
			ap.first=c;
			ap.second=j;
		}
		else if(c==ap.first) {
			if(j<ap.second) {
				ap.second=j;
			}
		}
	}
}
void initAP(string c,string j) {
	string tc,tj;
	int i;
	tc=c;
	tj=j;
	int n=c.size();
	FOR(i,0,n-1) if(tc[i]=='?') tc[i]='9';
	FOR(i,0,n-1) if(tj[i]=='?') tj[i]='9';
	ap.first=tc;
	ap.second=tj;
}
int main() {
	int t,tt,i,k;si(t);
	string c,j,tc,tj;
	FOR(tt,1,t) {
		cin>>c>>j;
		int n=c.size();
		ans=INF;
		initAP(c,j);
		bool flag=false;
		FOR(i,0,n-1) {
			//debug(i);
			if(c[i]!='?' && j[i]!='?') {
				//cout<<"1"<<endl;
				if(c[i]==j[i]) continue;
				tc=c;
				tj=j;
				if(c[i]<j[i]) {
					FOR(k,i+1,n-1) {
						if(tc[k]=='?') tc[k]='9';
					}
					FOR(k,i+1,n-1) {
						if(tj[k]=='?') tj[k] = '0';
					}
				}
				else {
					FOR(k,i+1,n-1) {
						if(tj[k]=='?') tj[k]='9';
					}
					FOR(k,i+1,n-1) {
						if(tc[k]=='?') tc[k] = '0';
					}
				}
				updateAns(tc,tj);
				flag=true;
				break;
			}
			else if(c[i]=='?' && j[i]=='?') {
				//cout<<"2"<<endl;
				tc=c;
				tj=j;
				tc[i]='0';
				tj[i]='1';
				FOR(k,i+1,n-1) if(tc[k]=='?') tc[k]='9';
				FOR(k,i+1,n-1) if(tj[k]=='?') tj[k]='0';
				updateAns(tc,tj);
				tc=c;
				tj=j;
				tc[i]='1';
				tj[i]='0';
				FOR(k,i+1,n-1) if(tc[k]=='?') tc[k]='0';
				FOR(k,i+1,n-1) if(tj[k]=='?') tj[k]='9';
				updateAns(tc,tj);
				c[i]='0';
				j[i]='0';
			}
			else if(c[i]=='?') {
				//cout<<"3"<<endl;
				tc=c;
				tj=j;
				if(tj[i]!='9') {
					tc[i]=tj[i]+1;
					FOR(k,i+1,n-1) if(tc[k]=='?') tc[k]='0';
					FOR(k,i+1,n-1) if(tj[k]=='?') tj[k]='9';
					updateAns(tc,tj);
				}
				tc=c;
				tj=j;
				if(tj[i]!='0') {
					tc[i]=tj[i]-1;
					FOR(k,i+1,n-1) if(tc[k]=='?') tc[k]='9';
					FOR(k,i+1,n-1) if(tj[k]=='?') tj[k]='0';
					//debug(tc);
					//debug(tj);
					updateAns(tc,tj);
				}
				c[i]=j[i];
			}
			else if(j[i]=='?') {
				//cout<<"4"<<endl;
				tc=c;
				tj=j;
				if(tc[i]!='9') {
					tj[i]=tc[i]+1;
					FOR(k,i+1,n-1) if(tc[k]=='?') tc[k]='9';
					FOR(k,i+1,n-1) if(tj[k]=='?') tj[k]='0';
					updateAns(tc,tj);
				}
				tc=c;
				tj=j;
				if(tc[i]!='0') {
					tj[i]=tc[i]-1;
					FOR(k,i+1,n-1) if(tc[k]=='?') tc[k]='0';
					FOR(k,i+1,n-1) if(tj[k]=='?') tj[k]='9';
					updateAns(tc,tj);
				}
				j[i]=c[i];
			}
			else assert(false);
		}
		if(!flag)
			updateAns(c,j);
		cout<<"Case #"<<tt<<": "<<ap.first<<" "<<ap.second<<endl;
	}
	return 0;
}