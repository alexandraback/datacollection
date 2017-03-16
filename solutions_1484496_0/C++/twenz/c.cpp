#include <iostream>
#include <algorithm>
using namespace std;
#define N 502
typedef int INT;
INT s[N];
int n,tag[2000000],q[2000000],p[25];
void dfs(int k,int x)
{
	int m = 0;
	q[m ++] = 0;
	int i,j;
	for(i=0;i<n;i++){
		int t = m;
		for(j = 0;j < t;j ++){
			if(tag[q[j]+s[i]] == 0){
				q[m ++] = q[j]+s[i];
				tag[q[m-1]] = tag[q[j]]+p[i];
			}
			else{
				int x = tag[q[j]+s[i]];
				int y = 0;
				bool flag = true;
				while(x){
					if(x%2){
						if(!flag)printf(" ");
						printf("%d",s[y]);
						flag = false;
					}
					y ++;
					x /= 2;
				}
				printf("\n");
				x = tag[q[j]]+p[i];
				y = 0;
				flag = true;
				while(x){
					if(x%2){
						if(!flag)printf(" ");
						printf("%d",s[y]);
						flag = false;
					}
					y ++;
					x /= 2;
				}
				printf("\n");
				return;
			}
		}
	}
	printf("Impossible\n");
}
int main()
{
	freopen("C-small-attempt0.in","r",stdin);
//	freopen("C-large.in","r",stdin);
	freopen("out.txt","w",stdout);
	int i,j,t;
	p[0] = 1;
	for(i = 1;i < 22;i ++)
		p[i] = p[i-1]*2;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		scanf("%d",&n);
		for(j=0;j<n;j++){
			scanf("%d",&s[j]);
		}
		sort(s,s+n);
		printf("Case #%d:\n",i);
		memset(tag,0,sizeof(tag));
		dfs(0,0);
	}
	return 0;
}
