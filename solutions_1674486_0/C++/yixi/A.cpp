#include <iostream>
using namespace std;

#define N 1010

int tim, n;
int c[N][N],b[N][N],a[N][N],in[N], q[N];

int work()
{	
		tim++;
		int tail = 0,head=0;
		scanf("%d",&n);
		for (int i=1; i<=n; i++) { b[i][0]=0; c[i][i]=tim;}
		for (int i=1; i<=n; i++)
		{
			scanf("%d",&a[i][0]);
			in[i]=a[i][0];
			for (int j=1; j<=a[i][0]; j++) {
				scanf("%d",&a[i][j]);
				b[a[i][j]][++b[a[i][j]][0]] = i;
			}
			if (a[i][0]==0){
				q[tail++]=i;
			}
		}
		
	//	printf("%d %d\n",head,tail);
		while (head<tail){
		
			int i = q[head++];
	//	printf("%d\n",i);
		for (int k=1; k<=b[i][0]; k++){
				int j = b[i][k];
		//		printf("   %d\n",j);
				in[j]--;
				if (in[j]==0) {
					q[tail++]=j;
				}
				for (int x=1; x<=n; x++)
					if (c[i][x]==tim){
						if (c[j][x]==tim) return 1;
						c[j][x]=tim;
					}
			}
		}
		return 0;
}


int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	int T;
	scanf("%d",&T);
	for (int ttt=1; ttt<=T; ttt++){
		printf("Case #%d: ",ttt);
		if (work()) printf("Yes\n");
		else printf("No\n");
		
	}	
}