#include <bits/stdc++.h>
#define rep(x,n) for(int x = 0; x < n; ++x)
#define print(x) cout << x << endl
#define dbg(x) cerr << #x << " == " << x << endl
#define _ << " , " <<
#define mp make_pair
#define x first
#define y second
using namespace std;

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }

typedef long long ll;
typedef pair<int,int> pii;

long long q[1<<20];

double go(int H, int have, int h, int L, int R) {
	if(L>h) return 1.0;
	if(have<=0) return 0;
	if(L+1>=H) return go(H,have-1,h,L,R+1);
	if(R+1>=H) return go(H,have-1,h,L+1,R);
	return (go(H,have-1,h,L+1,R) + go(H,have-1,h,L,R+1))/2.0;
}

int main() {
	q[1]=1;
	for(int i=2;i<1<<20;i++)q[i]=q[i-1]+i;
  int T;
	cin>>T;
	for(int testcase=1;testcase<=T;++testcase) {
		printf("Case #%d: ",testcase);
		int N,X,Y;
		cin>>N>>X>>Y;
		int L=1;
		while(N>=q[L]) {
			L+=2;
		}
		L-=2;
		N-=q[L];
		int d=abs(X)+abs(Y);
		if(d<=L-1) puts("1.00000000000000");
		else if(d>L+1) puts("0.0000000000000");
		else {
			int h=abs(Y);
			//dbg(L);
			printf("%.8lf\n",go(L+2,N,h,0,0));
		}
	}
	return 0;
}

