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

const int MAXK=105;
const int MAXL=MAXK*MAXK;
int K,C,S;

int main() {
	int all_kase;
	scanf("%d",&all_kase);
	for(int num_kase=1;num_kase<=all_kase;num_kase++) {
		scanf("%d%d%d",&K,&C,&S);
		printf("Case #%d:",num_kase);
		if(C*S<K) {
			puts(" IMPOSSIBLE");
			continue;
		}
		int cnt=0;
		int check=0;
		ll maxn=1;
		for(int i=0;i<C;i++)
			maxn*=K;
		while(cnt<K) {
			ll out=0;
			for(int i=0;i<C && cnt<K;i++) {
				out*=K;
				out+=cnt++;
			}
			assert(out<maxn);
			printf(" %lld",out+1);
			check++;
		}
		puts("");
		assert(check<=S);
		assert(cnt==K);
	}
	return 0;
}
