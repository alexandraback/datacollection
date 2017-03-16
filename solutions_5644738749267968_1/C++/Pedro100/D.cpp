#include <cstdio>
#include <algorithm>
#define fr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,b) fr(i,0,b)

using namespace std;
#define N 1010

int cnt=0;
int mk[N][N];
int pd[N][N];
double g[2][N];

int rec(int a, int b){
	if(a<0 || b<0) return 0;
	
	if(mk[a][b]!=cnt){
		mk[a][b]=cnt;
		pd[a][b] = 0;
		if(a) pd[a][b] = max(pd[a][b], rec(a-1,b));
		if(b) pd[a][b] = max(pd[a][b], rec(a,b-1));
		if(g[0][a] > g[1][b]) pd[a][b] = max(pd[a][b], rec(a-1,b-1)+1);
	}
	
	return pd[a][b];
}

bool ms[N];

int main(){
	int cas;
	scanf("%d",&cas);
	fr(u,1,cas+1){
		int n;
		scanf("%d",&n);
		rep(i,2){
			rep(j,n) scanf("%lf",&g[i][j]);
			sort(g[i],g[i]+n);
		}
		rep(i,n) ms[i]=false;
		
		int rsp2=0;
		rep(i,n){
				
				
			int ind=-1, f=-1;
			rep(j,n){
				if(!ms[j]){
					if(f==-1) f = j;
					if(g[1][j]>g[0][i]){
						ind=j;
						break;
					}
				}
			}
			
			if(ind==-1)rsp2++,ind=f;
			ms[ind]=true;
		}
		cnt++;
		printf("Case #%d: %d %d\n",u,rec(n-1,n-1),rsp2);
	}
	
	return 0;
}


