#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define eps 1e-10
double f[15][1<<9][10];
int cnt[100][1<<10];
int K,L,S;
char key[10],tar[10];
int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
	int t,cas;
	int i,j,k,m,l;
	scanf("%d",&t);
	for(cas=1;cas<=t;cas++){
		scanf("%d%d%d",&K,&L,&S);
		scanf("%s%s",key,tar);
		for(i=0;i<=10;i++){
			for(j=0;j<(1<<9);j++){
				for(k=0;k<10;k++){
					f[i][j][k]=0;
				}
			}
		}
		f[0][1][0]=1;
		int res=0;
		for(i=0;i<=S;i++){
			//f[i+1][1]=1;
			for(j=1;j<(1<<(L+1));j++){
				for(l=0;l<=S;l++){
					if(f[i][j][l]<eps)continue;
				//	printf("%d %d %lf\n",i,j,f[i][j]);
					if(i==S)continue;
					for(k=0;k<K;k++){
						int tmp=1;
						for(m=0;m<L;m++){
							if(!(j&(1<<m)))continue;
							if(key[k]==tar[m])tmp+=1<<(m+1);
						}
						if(tmp&(1<<L))f[i+1][tmp][l+1]+=f[i][j][l]/K;
						else f[i+1][tmp][l]+=f[i][j][l]/K;
						//printf("%d %d %d %d %d\n",i,j,k,cnt[i][j],cnt[i+1][tmp]);
					}
				}
			}
		}
		double ans=0;
		for(j=1;j<(1<<(L+1));j++){
			for(k=0;k<=S;k++){
				if(f[S][j][k]>eps)res=max(res,k);
				ans+=f[S][j][k]*k;
			}
		}
		printf("Case #%d: %.8lf\n", cas,res-ans);
	//	printf("%d %lf\n",res,res-ans);
	}
	return 0;
}
							
		
