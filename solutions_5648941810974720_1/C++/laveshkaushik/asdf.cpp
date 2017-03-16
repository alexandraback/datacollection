#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define mp make_pair
#define ll long long
#define fi(filename) freopen(filename, "r", stdin)
#define fo(filename) freopen(filename, "w", stdout)
#define popcount(i) __builtin_popcount(i)      //count one. in long long use __builtin_popcountll(i)
#define gcd __gcd
//debug
#define debug(args...) cout<<__FUNCTION__<<":"<<__LINE__<<" ";do{cout<<#args<<": ";dbg,args;cout<<endl;} while(0)
struct debugger
{template<typename T> debugger& operator ,(const T& v){cout<<v<<" ";return *this;}}dbg;
#define dbgarr(a,start,end) cout<<__FUNCTION__<<":"<<__LINE__<<"\n";for(ll i=start;i<end;i++) cout<<#a<<"["<<i<<"] -> "<<a[i]<<" "<<endl;
#define dbgmat(mat,row,col) cout<<__FUNCTION__<<":"<<__LINE__<<"\n";for(ll i=0;i<row;i++) {for(ll j=0;j<col;j++) cout<<mat[i][j]<<" ";cout<<endl;}
#define F(i,a,n) for(typeof(a) i=(a);i<(n);++i)
#define R(i,a,n) for(typeof(a) i=(a);i>=(n);--i)
#define tr(it,container) for(typeof(container.begin()) it = container.begin(); it != container.end(); ++it)
//scan
#define fastio	  ios_base::sync_with_stdio(0);cin.tie()
#define SS(args...) do{input,args;} while(0)
struct scanner
{template<typename T> scanner& operator ,(T& v){cin>>v;return *this;}}input;
#define S(x) scanf("%d",&x)
#define Sl(x) scanf("%lld",&x)
#define P(x) printf("%d\n",x)
#define Pl(x) printf("%lld\n",x)
#define M(x,i) memset(x,i,sizeof(x))      // useful to clear array of integer
#define fr first
#define se second
#define INF 2147483647
#define MOD 1000000007   //	(int)1e9+7
#define all(x)    x.begin(),x.end()
#define get getchar//_unlocked
#define put putchar//_unlocked
inline void scan(int &n) {
	n=0;
	register char p;
	do {p=get();}while(p<'0');
	while(p>='0') {
		n = (n<<3) + (n<<1) + (p - '0');
		p=get();
	}
}
inline void print(int X)
{
	int Len=-1;
	char Data[10];
	do {
		Data[++Len]=X%10+'0';
		X/=10;
	} while(X);
	while(Len>=0) put(Data[Len--]);
//	put('\n');
}
inline void scanll(ll &n) {
	n=0;
	register char p;
	do {p=get();}while(p<'0');
	while(p>='0') {
		n = (n<<3) + (n<<1) + (p - '0');
		p=get();
	}
}
inline void printll(ll X)
{
	int Len=-1;
	char Data[20];
	do {
		Data[++Len]=X%10+'0';
		X/=10;
	} while(X);
	while(Len>=0) put(Data[Len--]);
	put('\n');
}
int main() {
	fi("A-large.in");
	fo("out.txt");
	int t,no=0,n,i;
	char s[2005];
	int a[26],ct[10];
	S(t);
	while(t--) {
		scanf("%s",s);
		n=strlen(s);
		++no;
		M(a,0);M(ct,0);
		for(i=0;i<n;++i) {
			a[s[i]-'A']++;
		}
		while(a['Z'-'A']>0) {
			ct[0]++;
			a['Z'-'A']--;
			a['E'-'A']--;
			a['R'-'A']--;
			a['O'-'A']--;
		}
		while(a['X'-'A']>0) {
			ct[6]++;
			a['S'-'A']--;
			a['I'-'A']--;
			a['X'-'A']--;
		}
		while(a['G'-'A']>0) {
			ct[8]++;
			a['E'-'A']--;
			a['I'-'A']--;
			a['G'-'A']--;
			a['H'-'A']--;
			a['T'-'A']--;
		}
		while(a['W'-'A']>0) {
			ct[2]++;
			a['T'-'A']--;
			a['W'-'A']--;
			a['O'-'A']--;
		}
		while(a['S'-'A']>0) {
			ct[7]++;
			a['S'-'A']--;
			a['E'-'A']--;
			a['V'-'A']--;
			a['E'-'A']--;
			a['N'-'A']--;
		}
		while(a['U'-'A']>0) {
			ct[4]++;
			a['F'-'A']--;
			a['O'-'A']--;
			a['U'-'A']--;
			a['R'-'A']--;
		}
		while(a['R'-'A']>0) {
			ct[3]++;
			a['T'-'A']--;
			a['H'-'A']--;
			a['R'-'A']--;
			a['E'-'A']--;
			a['E'-'A']--;
		}
		while(a['V'-'A']>0) {
			ct[5]++;
			a['F'-'A']--;
			a['I'-'A']--;
			a['V'-'A']--;
			a['E'-'A']--;
		}
		while(a['O'-'A']>0) {
			ct[1]++;
			a['O'-'A']--;
			a['N'-'A']--;
			a['E'-'A']--;
		}
		while(a['I'-'A']>0) {
			ct[9]++;
			a['N'-'A']--;
			a['I'-'A']--;
			a['N'-'A']--;
			a['E'-'A']--;
		}
		printf("Case #%d: ",no);
		for(i=0;i<10;++i) {
			while(ct[i]>0) {
				printf("%d",i);
				ct[i]--;
			}
		}
		printf("\n");
	}
	return 0;
}
