#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
#include<cstring>

using namespace std;

int num[2510];

int main(){
	freopen("B-small-attempt0.in","r",stdin);
	freopen("A.out","w",stdout);
	int t,n;
	scanf("%d",&t);
	for(int cas=1;cas<=t;cas++){
		scanf("%d",&n);
		for(int i=0;i<=2500;i++)
			num[i]=0;
		int lim=2*n-1;
		for(int i=1;i<=lim;i++){
			int tmp;
			for(int j=1;j<=n;j++){
				scanf("%d",&tmp);
				num[tmp]++;
			}
		}
		printf("Case #%d: ",cas);
		int tail=0;
		for(int i=0;i<=2500;i++)
			if(num[i]%2!=0){
				tail++;
				if(tail==n)
					printf("%d\n",i);
				else
					printf("%d ",i);
			}
	}
	return 0;
}
