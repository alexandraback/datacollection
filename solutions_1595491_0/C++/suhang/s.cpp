#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const	int N=110;

int		test,n,S,P,Min,Max;
int		v[N],f[N][N];

int main(){
	freopen("s.in","r",stdin);
	freopen("s.out","w",stdout);
	
	int test;
	scanf("%d",&test);
	
	for (int t=1;t<=test;t++){
		printf("Case #%d: ",t);
		
		scanf("%d%d%d",&n,&S,&P);
		for (int i=1;i<=n;i++)
			scanf("%d",&v[i]);
		memset(f,0,sizeof(f));
		f[0][0]=1;
		for (int i=1;i<=n;i++)
		for (int c=0;c<=S;c++)
		if (f[i-1][c]){
			int tp=v[i]/3;
			for (int j=0;j<=10;j++)
			for (int k=0;k<=10;k++){
				int q=v[i]-j-k;
				if (q<0 || q>10)	continue;
				Max=max(max(j,k),q);
				Min=min(min(j,k),q);
				if (Max-Min<=1){
					if (Max>=P)
						f[i][c]=max(f[i-1][c]+1,f[i][c]);
					else
						f[i][c]=max(f[i-1][c],f[i][c]);
				}
				if (Max-Min==2){
					if (Max>=P)
						f[i][c+1]=max(f[i-1][c]+1,f[i][c+1]);
					else
						f[i][c+1]=max(f[i-1][c],f[i][c+1]);
				}
			}
		}
		
		printf("%d\n",f[n][S]-1);
		
	}
	
	return 0;
}
