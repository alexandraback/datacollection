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

const int MAXS=110;
int dp[MAXS][2];
char in[MAXS];

int main() {
	int all_kase;
	scanf("%d",&all_kase);
	for(int num_kase=1;num_kase<=all_kase;num_kase++) {
		scanf("%s",in+1);
		int S=strlen(in+1);
		for(int i=1;in[i];i++)
			in[i]=(in[i]=='+')?1:0;
		dp[0][0]=dp[0][1]=0;
		for(int i=1;i<=S;i++) {
			for(int j=0;j<=1;j++) {
				if(in[i]==j)
					dp[i][j]=dp[i-1][j];
				else
					dp[i][j]=dp[i-1][j^1]+1;
			}
		}
		printf("Case #%d: ",num_kase);
		printf("%d\n",dp[S][1]);
	}
	return 0;
}
