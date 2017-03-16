#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
char st[100005];
int P[100005],S[100005];
int G[5][5];
int cal(int x,int y){
	int fl=1;
	if(x<0){
		fl*=-1;
		x*=-1;
	}
	if(y<0){
		fl*=-1;
		y*=-1;
	}
	return fl*G[x][y];
}
int sss[256];
int main(){
	int T,tt,n,i,j,k,l;
	long long m;
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	G[1][1]=1;
	G[1][2]=2;
	G[1][3]=3;
	G[1][4]=4;
	G[2][1]=2;
	G[2][2]=-1;
	G[2][3]=4;
	G[2][4]=-3;
	G[3][1]=3;
	G[3][2]=-4;
	G[3][3]=-1;
	G[3][4]=2;
	G[4][1]=4;
	G[4][2]=3;
	G[4][3]=-2;
	G[4][4]=-1;
	sss['1']=1;
	sss['i']=2;
	sss['j']=3;
	sss['k']=4;
	scanf("%d",&T);
	for(tt=1;tt<=T;tt++){
		scanf("%d%I64d",&n,&m);
		if(m>=4)m=m%4+4;
		scanf("%s",st);
		int s=0;
		for(i=0;i<n;i++){
			for(j=1;j<m;j++)st[i+j*n]=st[i];
		}
		st[n*(m)]='\0';
		//printf("%s\n",st);
		n=n*(m);
		P[1]=sss[st[0]];
		for(i=1;i<n;i++){
			P[i+1]=cal(P[i],sss[st[i]]);
		//	printf("%d\n",P[i+1]);
		}
		S[n]=sss[st[n-1]];
		for(i=n-1;i>=1;i--){
			S[i]=cal(sss[st[i-1]],S[i+1]);
		}
		int a1=100000000,a2=-1;
		for(i=1;i<=n;i++){
			if(P[i]==2){
				a1=min(a1,i);
			}
			if(S[i]==4){
				a2=i;
			}
		}
		printf("Case #%d: ",tt);
		if(P[n]==-1&&a1<a2){
			printf("YES\n");
		}else printf("NO\n");
	}
	return 0;
}
