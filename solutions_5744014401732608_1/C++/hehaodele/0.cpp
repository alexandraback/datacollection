#include "iostream"
#include "cstdio"
#include "cstdlib"
#include "cstring"
#include "cmath"
#include "algorithm"
#include "set"
#include "map"
#include "queue"
#include "vector"
using namespace std;
#define rep(i,n) for(int i=0; i<n; ++i)
#define repp(i,a,b) for(int i=a; i<a+b; ++i)
#define sz size()
#define X first
#define Y second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int,int> pii;
int a[100];
void run(){
	int n;
	ll m;
	cin >> n >> m;
	if(m > 1ll << (n-2)){
		puts("IMPOSSIBLE");
		return;
	}else{
		puts("POSSIBLE");		
	}
	memset(a, 0, sizeof a);
	for(int i=n-2; i>=0; --i){
		ll r = 1;
		if(i) r = 1ll << (i-1);
		if(m >= r){
			m -= r;
			a[i] = 1;
		}
	}
	rep(i,n){
		rep(j,n-1) printf("%d", i<j);
		printf("%d\n", a[i]);
	}
}

int main(int argc, char const *argv[])
{
	int cas;
	cin >> cas;
	rep(ca,cas){
		printf("Case #%d: ", ca+1);
		run();
	}
	return 0;
}