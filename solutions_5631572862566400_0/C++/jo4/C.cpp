#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
#ifdef _DEBUG_
	#define debug(...) printf(__VA_ARGS__)
#else
	#define debug(...) (void)0
#endif
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;

const int MAXN=1010;
int F[MAXN];
int N;

int t[MAXN];
int ans=0;
bool c[MAXN];

void check() {
	int z=0;
	for(int i=1;i<=N;i++)
		if(c[i])
			t[z++]=i;
	do {
		bool yes=1;
		for(int i=0;i<z;i++) {
			int lst=(i-1+z)%z;
			int nxt=(i+1)%z;
			if(t[lst]!=F[t[i]] && t[nxt]!=F[t[i]]) {
				yes=0;
				break;
			}
		}
		if(yes) {
			ans=max(ans,z);
			return;
		}
	} while(next_permutation(t,t+z));
}

void go(int x) {
	if(x>N) {
		check();
		return;
	}
	c[x]=1;
	go(x+1);
	c[x]=0;
	go(x+1);
}

int main() {
	int all_kase;
	scanf("%d",&all_kase);
	for(int num_kase=1;num_kase<=all_kase;num_kase++) {
		scanf("%d",&N);
		for(int i=1;i<=N;i++)
			scanf("%d",F+i), c[i]=0;
		ans=0;
		go(1);
		printf("Case #%d: ",num_kase);
		printf("%d\n",ans);
	}
	return 0;
}
