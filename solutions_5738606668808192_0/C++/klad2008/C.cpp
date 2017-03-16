#include <bits/stdc++.h>
using namespace std;
#define LL long long
int T,N,M;
int s[40],num[11];
const int prim[5]={2,3,5,7,11};
int main(){
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	scanf("%d%d%d",&T,&N,&M);
	printf("Case #1:\n");
	for (int i=0;i<1<<(N-2);i++){
//		i=178;
		s[0]=s[N-1]=1;
		int x=i;
		for (int j=1;j<N-1;j++)s[j]=x&1,x>>=1;
//		if (i==180)
//			printf("= =");
		bool flag=1;
		memset(num,0,sizeof(num));
		for (int k=2;k<=10;k++){
			x=0;
			bool ok=0;
			for (int j=0;j<5;j++){
//				LL tt=0;
//				for (int t=N-1;t>=0;t--)
//					tt=tt*k+s[t];
				x=0;
				for (int t=N-1;t>=0;t--)
					x=(x*k+s[t])%prim[j];
				if (!x){num[k]=prim[j];ok=1;break;}
			}
			if (!ok){flag=0;break;}
		}
		if (flag){
//			if (M==2)
//				printf("= =");
			for (int j=N-1;j>=0;j--)printf("%d",s[j]);
			for (int k=2;k<=10;k++)printf(" %d",num[k]);
			printf("\n");
			M--;
			if (!M)break;
		}
	}
}