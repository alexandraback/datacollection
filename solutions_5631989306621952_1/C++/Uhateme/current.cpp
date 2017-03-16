#include <bits/stdc++.h>

using namespace std;
//memset
#define MEMSET_INF 127 // about 2B
#define set0(a) memset(a,0,sizeof(a));
#define setminus1(a) memset(a,-1,sizeof(a));
#define setinf(a) memset(a,MEMSET_INF,sizeof(a));

//stl
#define mp make_pair
#define pb push_back
//#define pc(x) putchar_unlocked(x)
//#define gc() getchar_unlocked()

//Loops
#define REP(i,n) for(int i = 0;i < (int)(n); i++)
#define REP1(i,a,b) for(int i = (int)(a);i <= (int)(b); i++)
#define REPMAP(i,mm) for(auto i = mm.begin();i !=mm.end(); i++)

//Sort
#define sortvec(vec) sort(vec.begin(), sort.end())

//Misc
#define LSOne(i) (i & (-i))	// the first Least Significant One-bit in i

//modulo
#define mod %
#define NUM 1000000007


#define LMAX LONG_LONG_MAX
#define LMIN LONG_LONG_MIN
#define IMAX INT_MAX
#define IMIN INT_MIN
#define PI M_PI
#define EPS 1e-9
#define INF 1e9
#define M_PI		3.14159265358979323846

//typedef
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
typedef map<int, int> mii;

#define MAX_N 100005

void solve(){
	string s;
	cin>>s;
	vector<char> v1,v2;
	v2.pb(s[0]);
	char first = s[0];
	for(int i = 1; i < s.length(); i++){
		char c = s[i];
		if(c >= first){
			v1.pb(c);
			first = c;
		}else{
			v2.pb(c);
		}
	}

	for(int i = v1.size()-1; i>=0; i--){
		cout<<v1[i];
	}
	for(int i = 0; i < v2.size(); i++){
		cout<<v2[i];
	}
//	string s1;
//	s1.resize(s.length());
//	s1[0] = s[0];
}

int main(){

	cin.tie(0);
	cout.tie(0);
	cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);

	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);

	int TC = 1;
	cin>>TC;
	for(int ZZ=1;ZZ<=TC;ZZ++){
		cout<<"Case #"<<ZZ<<": ";
//		double ans;
//		cout.precision(10);
//		cout<<fixed<<ans<<endl;
		solve();
		cout<<endl;
	}
	return 0;
}
