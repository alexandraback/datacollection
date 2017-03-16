#include <bits/stdc++.h>
using namespace std;

#define fru(j,n) for(int j=0; j<(n); ++j)
#define tr(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
//#define tr(it,v) for(auto it=(v).begin(); it!=(v).end(); ++it)
#define x first
#define y second
#define pb push_back
#define ALL(G) (G).begin(),(G).end()

#if 1
#define DEB printf
#else
#define DEB(...)
#endif

typedef long long ll;
typedef long long LL;
typedef double D;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int mod = 1000000007;
const int MAXN = 1000006;
const ll inft=1LL*mod*mod;
ll A,B;
char s1[20],s2[20];
int n;
void go(ll a,ll b,int nr,int gre){
	if(a<b)return;
	if(nr==n){
		if(abs(a-b)<abs(A-B)){
			A=a;B=b;
		}
		else{
			if(gre==0){
				if(abs(a-b)==abs(A-B) && a<A){
					A=a;B=b;
				}
				else if(abs(a-b)==abs(A-B) && a==A && b<B){
					A=a;B=b;
				}
			}else{
				if(abs(a-b)==abs(A-B) && b<B){
					A=a;B=b;
				}
				else if(abs(a-b)==abs(A-B) && b==B && a<A){
					A=a;B=b;
				}
			}
		}
		return;
	}
	//fill next digit
	if(a>b){
		if(s1[nr]=='?')a*=10;
		else a=a*10+s1[nr]-'0';
		if(s2[nr]=='?')b=b*10+9;
		else b=b*10+s2[nr]-'0';
		go(a,b,nr+1,gre);
	}
	if(a==b){
		if(s1[nr]=='?' && s2[nr]=='?'){
			go(10*a+1,10*b,nr+1,gre);
			go(10*a,10*b,nr+1,gre);
		}
		else if(s1[nr]=='?'){
			go(10*a+s2[nr]-'0',10*b+s2[nr]-'0',nr+1,gre);
			if(s2[nr]<'9')go(10*a+s2[nr]-'0'+1,10*b+s2[nr]-'0',nr+1,gre);
		}
		else if(s2[nr]=='?'){
			go(10*a+s1[nr]-'0',10*b+s1[nr]-'0',nr+1,gre);
			if(s1[nr]>'0')go(10*a+s1[nr]-'0',10*b+s1[nr]-'0'-1,nr+1,gre);
		}
		else go(10*a+s1[nr]-'0',10*b+s2[nr]-'0',nr+1,gre);
	}
}
void solve() {
	A=-inft;B=inft;
	scanf("%s %s",s1,s2);
	n=strlen(s1);
	go(0,0,0,0);
	swap(A,B);
	swap(s1,s2);
	go(0,0,0,1);
	swap(A,B);
	printf("%0*lld %0*lld\n",n,A,n,B);
}

int main() {
	int te = 1;
	scanf("%d",&te);
	fru(ti,te) {
		printf("Case #%d: ",ti+1);
		solve();
	}
	return 0;
}
