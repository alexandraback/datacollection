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

int T,x,y;
//bool visit[15000][15000];
char ans[555];

int main(){
	scanf("%d",&T);
	FOE(t,1,T){
		scanf("%d%d",&x,&y);
		printf("Case #%d: ",t,ans);

		int count = 0;
		int px = 0;
		while (px != x){
			if (px > x){
				printf("EW");
				--px;
			}
			else{
				printf("WE");
				++px;
			}
		}

		int py = 0;
		while (py != y){
			if (py > y){
				printf("NS");
				--py;
			}
			else{
				printf("SN");
				++py;
			}
		}

		puts("");
	}
	return 0;
}
