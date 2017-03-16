#include <stdio.h>
#include <string.h>
#include <algorithm>
#define maxn 110
#define inf 100000

using namespace std;

int f[maxn][maxn];
int a[maxn];
int n,s,p;
int main(){
	int tn,cp;
	for (scanf("%d",&tn),cp=1;cp<=tn;cp++){
		scanf("%d%d%d",&n,&s,&p);
		for (int i=1;i<=n;i++) scanf("%d",a+i);
		for (int i=0;i<=n;i++)
			for (int j=0;j<=s;j++) f[i][j]=-inf;
		f[0][0]=0;
		for (int i=1;i<=n;i++){
			for (int j=0;j<=s;j++)
				if (f[i-1][j]>=0){
					for (int x=0;x<=10;x++)
						for (int y=0;y<=10;y++) if (abs(x-y)<=2)
							for (int z=0;z<=10;z++) if (abs(x-z)<=2 && abs(y-z)<=2 && x+y+z==a[i]){
								int t=max(abs(x-y),max(abs(x-z),abs(y-z)));
								int v=max(x,max(y,z));
								if (v>=p) v=1;else v=0;
								if (t==2){
									if (j<s) f[i][j+1]=max(f[i][j+1],f[i-1][j]+v);
								}else{
									f[i][j]=max(f[i][j],f[i-1][j]+v);
								}
							}
				}
		}
		printf("Case #%d: %d\n",cp,f[n][s]);
	}
	return 0;
}
