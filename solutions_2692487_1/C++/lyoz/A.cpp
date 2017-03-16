#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cassert>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <complex>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <functional>
#include <iterator>

using namespace std;

#define dump(n) cout<<"# "<<#n<<'='<<(n)<<endl
#define repi(i,a,b) for(int i=int(a);i<int(b);i++)
#define peri(i,a,b) for(int i=int(b);i-->int(a);)
#define rep(i,n) repi(i,0,n)
#define per(i,n) peri(i,0,n)
#define all(c) begin(c),end(c)
#define mp make_pair

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<string> vs;
typedef pair<int,int> pii;

const int INFTY=1<<29;
const double EPS=1e-9;

template<typename T1,typename T2>
ostream& operator<<(ostream& os,const pair<T1,T2>& p){
	return os<<'('<<p.first<<','<<p.second<<')';
}
template<typename T>
ostream& operator<<(ostream& os,const vector<T>& a){
	os<<'[';
	rep(i,a.size()) os<<(i?" ":"")<<a[i];
	return os<<']';
}

int solve_naive(int a,const vi& ms,int i)
{
	int n=ms.size();
	if(i==n) return 0;
	if(a>ms[i]) return solve_naive(a+ms[i],ms,i+1);
	return 1+min(solve_naive(a,ms,i+1),solve_naive(a+a-1,ms,i));
}

void solve()
{
	int a,n; cin>>a>>n;
	vi ms(n);
	rep(i,n) cin>>ms[i];
	
	if(a==1){ // armin can't absorb
		cout<<n<<endl;
		return;
	}

	sort(all(ms));
	
	ll cur=a,cnt=0,res=n;
	rep(i,n){
		while(cur<=ms[i]){
			cur+=cur-1;
			cnt++;
		}
		cur+=ms[i];
		res=min(res,cnt+n-(i+1));
	}
	
	//assert(res==solve_naive(a,ms,0));
	cout<<res<<endl;
}

int main()
{
	int T; scanf("%d",&T);
	rep(i,T){
		printf("Case #%d: ",i+1);
		solve();
	}
	
	return 0;
}
