#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define X first
#define Y second
#define REP(i,a) for(int i=0;i<a;++i)
#define REPP(i,a,b) for(int i=a;i<b;++i)
#define FILL(a,x) memset(a,x,sizeof(a))
#define	foreach( gg,itit )	for( typeof(gg.begin()) itit=gg.begin();itit!=gg.end();itit++ )
#define	mp make_pair
#define	pb push_back
#define sz(a) int((a).size())
#define all(a)  a.begin(), a.end()
#define	debug(ccc)	cout << #ccc << " = " << ccc << endl;
#define present(c,x) ((c).find(x) != (c).end())
const double eps = 1e-8;
#define EQ(a,b) (fabs((a)-(b))<eps)
inline int max(int a,int b){return a<b?b:a;}
inline int min(int a,int b){return a>b?b:a;}
inline ll max(ll a,ll b){return a<b?b:a;}
inline ll min(ll a,ll b){return a>b?b:a;}
const int mod = 1e9+7;
const int N = 1e6+10;
const ll inf = 1e18;

ll power(ll a,ll n){
	if(n==0){
		return 1;
	}
	ll b = power(a,n/2);
	b = b*b%mod;
	if(n%2) b= b*a%mod;
	return b;
}

int add(int a,int b){ return (a+b)%mod;}
int mul(int a,int b){ return (ll)a*b%mod;}

int A[26],B[10];
string s[ ] ={ "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int C[ ] = { 0,2,4,6,8,7,5,3,1,9};
char D[ ] = { 'Z','W','U','X','G','S','V','R','O','N'};


int main(){
 // 	freopen("nice.in","r",stdin);
 // freopen("nice.out","w",stdout);
	int t;
	scanf("%d",&t);
	REP(tt,t){
		FILL(A,0);
		FILL(B,0);
		string str;
		cin>>str;
		REP(i,str.size()){
			A[str[i]-'A']++;
		}
		REP(i,10){
			while(A[ D[i]-'A' ]>0){
				REP(j,s[C[i]].size()){
					A[s[C[i]][j]-'A']--;
				}
				B[C[i]]++;
			}
		}
		printf("Case #%d: ",tt+1);
		REP(i,10){
			while(B[i]>0){
				printf("%d",i);B[i]--;
			}
		}
		printf("\n");
	}
	return 0;
}


