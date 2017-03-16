#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
using namespace std;
#define INF (1<<29)
#define min(x,y) (((x)<(y))?(x):(y))
#define max(x,y) (((x)>(y))?(x):(y))
#define FOR(i,x,y) for(int i=(x);i<(y);++i)
#define FOE(i,x,y) for(int i=(x);i<=(y);++i)
#define CLR(i) memset(i,0,sizeof(i))
#define ll long long

int T,N,M;
char s[15][10],tmp[15],ans[1005];
bool e[15][15];

int per[105];

stack<int> q;

int main(){
	scanf("%d",&T);
	FOE(t,1,T){
		CLR(e);

		scanf("%d%d",&N,&M); gets(tmp);
		FOE(i,1,N) gets(s[i]);

		FOR(i,0,M){
			int x,y;
			scanf("%d%d",&x,&y);
			e[x][y] = e[y][x] = 1;
		}

		FOE(i,1,N) per[i-1]  = i;

		bool flag=1;
		do{
			while (!q.empty()) q.pop();
			char code[1005];

			int m=0;
			FOR(i,0,N){
				FOR(j,0,5) code[m++] = s[per[i]][j];
			}

			int pos = per[0],k = 0;
			bool ok = 0;

			//FOR(i,0,N) printf("%d ",per[i]);
			//puts("");

			q.push(pos);
			while (1){
				//printf("%d %d!\n",k,pos);
				if (k == N-1){ ok=1; break;}

				if (e[pos][per[k+1]]){
					q.push(per[k+1]); pos = per[k+1];
					++k;
				}
				else{
					q.pop();
					if (q.empty()){ ok=0; break;}
					else pos = q.top();
				}
			}

			//if (ok) puts("ok!");

			bool cm=1;
			if (!flag){
				code[m] = 0; ans[m] = 0;
				//puts(code); puts(ans);
				FOR(i,0,m){
					if (code[i] > ans[i]){cm=0; break;}
					else if (code[i] < ans[i]){cm=1; break;}
				}
			}

			if (cm && ok){
				//puts("up");
				flag=0;
				FOR(i,0,m) ans[i] = code[i];
				ans[m] = 0;
			}

		}while(next_permutation(per,per+N));

		printf("Case #%d: %s\n",t,ans);
	}
	return 0;
}
