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
	int n;
	cin>>n;
	map<int,int> mm;
	REP(i,n){
		REP(j, n*2 - 1){
			int x;
			cin>>x;
			mm[x]++;
		}
	}
	vi vec;
	REPMAP(i,mm){
		if(i->second % 2!= 0){
			vec.pb(i->first);
		}
	}
	sort(vec.begin(), vec.end());
//	if(n != vec.size())
//		abort();
	REP(i,vec.size()){
		cout<<vec[i]<<" ";
	}

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
