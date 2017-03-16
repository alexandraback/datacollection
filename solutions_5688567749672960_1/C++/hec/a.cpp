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

const int nmax=1000010;
int dp[nmax+1];


void init(){
	rep(i,nmax+1) dp[i]=inf;
	dp[0]=0;
	for(int i=0;i<=nmax;++i){
		if(i%100000==0) dump(i)
		if(i+1<=nmax) dp[i+1]=min(dp[i+1],dp[i]+1);
		string tmp=to_string(i);
		reverse(tmp.begin(),tmp.end());
		int rev=stoi(tmp);
		if(rev<=nmax) dp[rev]=min(dp[rev],dp[i]+1);
	}
	return ;
}

ll digit[15];

void init2(){
	digit[1]=0;
	for(int i=1;i<14;++i){
		digit[i+1]+=digit[i];
		digit[i+1]+=(ll)pow(10LL,i/2)-1;
		digit[i+1]++;
		if(i&1) digit[i+1]+=9LL*(ll)pow(10LL,(i+1)/2-1);
		digit[i+1]+=(ll)pow(10LL,i/2)-1;
	}
	return ;
}

ll cnt(ll n){

	string tmp=to_string(n);
	ll num=tmp.size();
	reverse(tmp.begin(),tmp.end());
	ll res=digit[num];

	if( (n%((ll)pow(10LL,(num+1)/2))) ==0){
		return cnt(n-1)+1;
	}


	if( (n-(n%((ll)pow(10LL,(num+1)/2)))) != pow(10LL,num-1)){
		res++;
		res+=(stoll(tmp)%((ll)pow(10LL,num/2)));
		res+=(n%((ll)pow(10LL,(num+1)/2)))-1;
	}else{
		res+=(n%((ll)pow(10LL,(num+1)/2)));
	}
	return res;
}

int main(void){
	int TestCase;
	cin >> TestCase;
	// init();
	init2();

	// range(i,1,nmax) if(dp[i]!=cnt(i)) cout << i << endl;

	range(Number,1,TestCase+1){
		ll n;
		cin >> n;
		cout << "Case #"<< Number << ": ";
		cout << cnt(n) << endl;
	}
	return 0;
}