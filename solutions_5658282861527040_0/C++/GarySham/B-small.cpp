#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<set>
using namespace std;
#define INF (1<<29)
#define min(x,y) (((x)<(y))?(x):(y))
#define max(x,y) (((x)>(y))?(x):(y))
#define FOR(i,x,y) for(int i=(x);i<(y);++i)
#define FOE(i,x,y) for(int i=(x);i<=(y);++i)
#define CLR(i) memset(i,0,sizeof(i))
#define ll long long

int T;

int main(){
	scanf("%d",&T);
	FOE(t,1,T){
		int A,B,K;

		scanf("%d%d%d",&A,&B,&K);

		int c=0;
		FOR(i,0,A){
			FOR(j,0,B){
				int tar = (i & j);
				if (tar < K) ++c;
			}
		}

		printf("Case #%d: %d\n",t,c);
	}
	return 0;
}
