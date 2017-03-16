#include <bits/stdc++.h>
#define rep(x,n) for(int x = 0; x < n; ++x)
#define print(x) cout << x << endl
#define dbg(x) cerr << #x << " == " << x << endl
#define _ << " , " <<
#define mp make_pair
#define x first
#define y second
using namespace std;

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << endl; }

typedef long long ll;
typedef pair<int,int> pii;

const int maxe=1e6+10;

int A;
int N;
int mote[111];
char f[1111111][111];

void up(char &a, int b) {
	if(b<a)a=b;
}

int main() {
  int T;
	cin>>T;
	for(int testcase=1;testcase<=T;++testcase) {
		printf("Case #%d: ",testcase);
		cin>>A>>N;
		rep(i,N) cin>>mote[i];mote[N]=1e9;
		sort(mote,mote+N);
		memset(f,111,sizeof f);
		f[A][0]=0;
		for(int a=A;a<=maxe;++a)
			for(int j=0;j<N;++j)
				if(f[a][j]<111){
					if(a>mote[j])
						up(f[min(a+mote[j],maxe)][j+1],f[a][j]);
					up(f[min(2*a-1,maxe)][j],f[a][j]+1);
					up(f[a][j+1], f[a][j]+1);
				}
		int ret=111;
		rep(i,maxe+1) if(f[i][N]<ret) ret=f[i][N];
		assert(ret<111);
		printf("%d\n",ret);
	}
	return 0;
}

