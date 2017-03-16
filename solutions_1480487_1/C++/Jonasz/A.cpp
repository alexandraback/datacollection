#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<iostream>
#include<sstream>
#include<set>
#include<cctype>
#include<cassert>
using namespace std;

#ifdef ONLINE_JUDGE

#define assert(x)
#define dbg(x)
#define dbgline()

#else

#define dbg(x) do { cout << "DEBUG, line " << __LINE__ << " (" << __func__ << "), " << #x << ": " << x << endl; } while(0)
#define trace() do { cout << "TRACE, line " << __LINE__ << " (" << __func__ << ")" << endl; } while(0)

#endif

const int N = 210;
int s[N];
double eps = 1e-8;
int n;

bool check(int nr, double A, double B){
	double h = s[nr]+A;
	double z = 0.;
	for(int i=0; i<n; i++) if(i!=nr){
		z += max(0., h-s[i]);
	}
	return z>B;
}

void solve(){
	scanf("%d",&n);
	int X = 0;
	for(int i=0; i<n; i++) {
		scanf("%d",&s[i]);
		X+=s[i];
	}
	for(int i=0; i<n; i++){
		double L = 0., R = 1., mid;
		while(R-L>eps){
			mid = (L+R)/2.;
			if(check(i, mid*X, (1.-mid)*X)){
				R = mid;
			} else {
				L = mid;
			}
		}
		printf("%.10lf ", 100.*(L+R)/2.);
	}
	printf("\n");
}

int main(){
	int z;
	scanf("%d",&z);
	for(int testc=1; testc<=z; testc++){
		printf("Case #%d: ", testc);
		solve();
	}
}
