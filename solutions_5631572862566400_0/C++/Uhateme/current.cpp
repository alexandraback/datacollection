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

vi kiska[1005];
int n;
int glob[1005];
int getl(int x){
//	cout<<" ::: "<<x<<endl;
	glob[x] = 1;
	int ans = 0;
	for(int i = 0; i < (int)kiska[x].size();i++){
		int u = kiska[x][i];
		if(glob[u] == 0){
			ans = max( ans , 1 +getl(u));
		}
	}
	return ans;
}

//int A1, A2;

void brute(int ar[]){
	int br[n];
	REP(i,n){
		br[i] = i;
	}
	int ans = 0;
	do{
		int loc = 0;
		for(int i = 0; i < n; i++){
			// if pre wala bff h.. to update loc.. else
			// if next wala bff h to continue
			// else break
			if(ar[br[i]] == br[0]){
				loc = i + 1;
				if(i!= 1)
				break;
			}
			else if(i-1 >= 0 && ar[br[i]] == br[i-1]){
				loc = i + 1;
			}else if( i+1 < n && ar[br[i]] == br[i+1]){
				continue;
			}else{
				break;
			}
		}
//					REP(i,n){
//						cout<<br[i]<<" ";
//					}
//					cout<<loc<<" ";
//					cout<<endl;
//		if(loc == 10){
//			REP(i,n){
//				cout<<br[i]<<" ";
//			}
//			cout<<endl;
//		}
		ans = max(ans , loc);
	}while(next_permutation(br,br+n));
//	A2 = ans;
//	cout<<ans<<endl;
}

void solve(){
	cin>>n;
	int ar[n];
	int vis[n];
	REP(i,n){
		kiska[i].clear();
	}
	REP(i,n){
		cin>>ar[i];
		ar[i]--;
		kiska[ar[i]].pb(i);
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		int loc = 0;
		set0(vis);
		int x = i;
		while(vis[x] == 0){
//			cout<<x+1<<" ";
			vis[x] = 1;
			x = ar[x];
			loc++;
		}
//		cout<<endl;
		if(x == i)
		ans = max(ans , loc);
	}
//	cout<<ans<<endl;
	int chains = 0;
//	int max1 = -1;
//	int max2 = -2;
	int sum = 0;
	for(int i = 0; i < n; i++){
		if(ar[ar[i]] == i ){
			chains ++;
			set0(glob);
			glob[ar[i]] = 1;
			int l = getl(i);
			sum += l;
		}
	}
	ans = max(ans , chains + sum);
	cout<<ans;
//	A1 = ans;
//	cout<<ans<<" :::: ";
//	brute(ar);

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
//		brute();
//		if(A1 != A2){
//			cout<<ZZ<<" "<<A1<<" ::: "<<A2;
//		}
		cout<<endl;
	}
	return 0;
}
