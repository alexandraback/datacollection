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

const int MAXH=2550;
int cnt[MAXH];

int main() {
	int all_kase;
	scanf("%d",&all_kase);
	for(int num_kase=1;num_kase<=all_kase;num_kase++) {
		memset(cnt,0,sizeof(cnt));
		int N;
		scanf("%d",&N);
		for(int i=1;i<2*N;i++)
			for(int j=0;j<N;j++) {
				int in;
				scanf("%d",&in);
				cnt[in]++;
			}
		VI ans;
		for(int i=0;i<MAXH;i++)
			if(cnt[i]%2==1)
				ans.PB(i);
		assert(SZ(ans)==N);
		printf("Case #%d: ",num_kase);
		for(int i=0;i<SZ(ans);i++)
			printf("%d%c",ans[i]," \n"[i==SZ(ans)-1]);
	}
	return 0;
}
