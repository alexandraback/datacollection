#include <bits/stdc++.h>
#define maxn 55
using namespace std;
int a[maxn][maxn];
int main(){
	int n,cot=1;
	long long m;
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	int tt;
	scanf("%d",&tt);
	while(tt--){
		cin>>n>>m;
		if(m>(1LL<<(n-2))){
			printf("Case #%d: IMPOSSIBLE\n",cot++);
			continue;
		}
		memset(a,0,sizeof(a));
		for(int i=0;i<n-1;i++){
			for(int j=0;j<i;j++)
				a[j][i]=1;
		}
		if(m==(1LL<<(n-2))){
			for(int j=0;j<n-1;j++)
				a[j][n-1]=1;
		}
		else{
			for(int j=1;j<n-1;j++){
				if((1LL<<(j-1))&m)
					a[j][n-1]=1;
			}
		}
		printf("Case #%d: POSSIBLE\n",cot++);
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)
				printf("%d",a[i][j]);
			puts("");
		}
	}
	//system("pause");
	return 0;
}