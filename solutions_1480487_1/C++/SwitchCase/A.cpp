// <-------------------[sWitCHcAsE]---------------------->
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<cassert>
#include<vector>
#include<map>
#include<cstring>
#include<cassert>
#include<queue>

#define FOR(i,n) for(int i=0;i<n;i++)
#define FORS(i,a,n) for(int i=a;i<n;i++)
#define ERR(x) cerr<<#x<<" "<<x<<endl
#define pb push_back

using namespace std;

typedef vector<int> VI;
typedef long long ll;
typedef long double ld;

int J[255];
int N;
int X;
int iseliminated(int a, ld Y) {
	ld sum = 0;
	ld F = J[a] + X*Y;
	vector<ld> all;
	int ans = 1;
	FOR(i,N) {
		if ( i==a)continue;
		if ( fabs(X*Y - (F-J[i])) < 1e-8) {
			ans = 0;
		}
	}
	return ans;
}

ld solve(int curr) {
	ld low = 0;
	ld high = 1.0;
	ld mid;
	while(fabs(low-high)>1e-8) {
		mid = (low+high)/2.0;
		if ( !iseliminated(curr,mid)) {
			high = mid;
		}
		else low = mid;
	}
	return mid;
}

int main(int argc,char** args) {
	int T;
	int kases=0;
	for(scanf("%d",&T);T--;) {
		X=0;
		kases++;
		scanf("%d",&N);
		FOR(i,N) {
			scanf("%d",&J[i]);
			X+=J[i];
		}
		vector<ld> ans(N);
		int tot = N;
		FOR(i,N) {
			ld tmp = 100.0*(2.0*X-N*J[i])/(N*X);
			if ( tmp<0) {
				ans[i]=-1;
				tot--;
			}
			else ans[i]=(J[i]);
		}
		int sum=0;
		FOR(i,N) if ( ans[i]!=-1)sum+=ans[i];
		cout<<"Case #"<<kases<<":";
		ld perc;
		FOR(i,N) {
			if ( ans[i]==-1)perc=0.0;
			else if ( tot==0 || X==0)perc=100.0;
			else perc = 100.0*(X + sum - tot*J[i])/(tot*X);
			printf(" %.6Lf",perc);
		}
		cout<<endl;
	}
}
