#include <bits/stdc++.h>

using namespace std;

inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}
template<class T> inline T sqr(T x) {return x*x;}

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef long long ll;

#define all(a)  (a).begin(),(a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define pb push_back
#define mp make_pair
#define each(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define exist(s,e) ((s).find(e)!=(s).end())
#define range(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)  range(i,0,n)
#define clr(a,b) memset((a), (b) ,sizeof(a))
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

const double eps = 1e-10;
const double pi  = acos(-1.0);
const ll INF =1LL << 62;
const int inf =1 << 29;

string S;
const int lmax=10000*30;
int sum[lmax+10];

int table[5][5]={
	{0,0,0,0,0},
	{0,1,2,3,4},
	{0,2,-1,4,-3},
	{0,3,-4,-1,2},
	{0,4,3,-2,-1}
};

inline int calc(int a,int b){
	int sign=a*b/abs(a*b);
	a=abs(a);
	b=abs(b);
	return sign*table[a][b];
}

int main(void){
	int TestCase;
	cin >> TestCase;
	range(Number,1,TestCase+1){
		ll L,X;
		cin >> L >>X;
		string in;
		cin >> in;
		if(X>=25) X-=(X-25)/4*4;

		S="";
		rep(loop,X) S+=in;
		int n=S.size();
		sum[0]=1;
		rep(i,n){
			int cur=0;
			if(S[i]=='i') cur=2;
			if(S[i]=='j') cur=3;
			if(S[i]=='k') cur=4;
			sum[i+1]=calc(sum[i],cur);
		}
		int _i=-1;
		int _ij=-1;
		for(int i=0;i<=n;++i){
			if(sum[i]==2){
				_i=i;
				break;
			}
		}
		for(int i=n;i>=0;--i){
			if(sum[i]==4){
				_ij=i;
				break;
			}
		}
		bool ok=false;
		if(sum[n]==-1&&_i!=-1&&_ij!=-1&&_i<_ij) ok=true;
		cout << "Case #"<< Number << ": ";
		if(ok)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}

// (LLLLL)(MMMMM)(RRRRR)