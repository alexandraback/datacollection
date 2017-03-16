#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;

int in[1005];
int out[1005];
bool t[1005][1005];
int v[1005];
int flg;
void bfs(int st, int ed, int step, int N)
{
    //printf("%d %d %d %d\n", st, ed, step, N);
    if(step>N) return;
    if(st==ed) {
	flg++;
	return;
    }
    int i;
    for(i=1;i<=N;i++){
	if((v[i]==0 || i== ed) && t[st][i]==1){
	    v[i]=1;
	    bfs(i, ed, step+1, N);
	    v[i]=0;
	}
    }
}

int main()
{
    int i, T, N, j, k, M, val;
    int is_d;
    scanf("%d", &T);
    for(i=1;i<=T;i++){
	scanf("%d", &N);
	memset(in, 0, sizeof(in));
	memset(t, 0, sizeof(t));
	memset(out,0,sizeof(out));
	for(j=1;j<=N;j++){
	    scanf("%d", &M);
	    for(k=1;k<=M;k++){
		scanf("%d", &val);
		t[j][val]=1;
		in[val]++;
		out[j]++;
	    }
	}
	is_d = 0;

	for(j=1;j<=N;j++){
	    if(out[j]<1) continue;
	    for(k=1;k<=N;k++){
		if(k==j) continue;
		if(in[k]<2) continue;
		flg = 0;
		memset(v,0,sizeof(v));
		v[j]=1;
		bfs(j, k, 1, N);
		if(flg > 1) {
		    is_d = 1;
		    break;
		}
	    }
	    if(is_d ==1) break;
	}
	printf("Case #%d: ",i);
	if(is_d==0)
	    printf("No\n");
	else
	    printf("Yes\n");
    }
    return 0;
}
