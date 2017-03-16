#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int test,N,M,a[105][105],b[105][105],row[105],col[105];

int main(){
	freopen("i.txt","r",stdin);
	scanf("%d",&test);
	int cnt=1;
	for (;test--;cnt++){
		printf("Case #%d: ",cnt);
		scanf("%d%d",&N,&M);
		for (int i=1;i<=N;i++)
			for (int j=1;j<=M;j++)
				scanf("%d",&a[i][j]);
		for (int i=1;i<=N;i++){
			row[i]=0;
			for (int j=1;j<=M;j++) 
				if (a[i][j]>row[i])
					row[i]=a[i][j];
		}
		for (int j=1;j<=M;j++){
			col[j]=0;
			for (int i=1;i<=N;i++)
				if (a[i][j]>col[j])
					col[j]=a[i][j];
		}
		for (int i=1;i<=N;i++)
			for (int j=1;j<=M;j++) b[i][j]=100;
		for (int i=1;i<=N;i++)
			for (int j=1;j<=M;j++) if (b[i][j]>row[i]) b[i][j]=row[i];
		for (int j=1;j<=M;j++)
			for (int i=1;i<=N;i++) if (b[i][j]>col[j]) b[i][j]=col[j];
		bool ok=true;
		for (int i=1;i<=N;i++)
			for (int j=1;j<=M;j++) if (a[i][j]!=b[i][j]){
				ok=false;
			}
		if (!ok) puts("NO");
			else puts("YES");
	}
	return 0;
}
