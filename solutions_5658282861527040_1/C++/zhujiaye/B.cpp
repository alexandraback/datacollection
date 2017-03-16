#include<cstdio>
#include<algorithm>
#include<iostream>
typedef long long LL;

using namespace std;

int test,AA,BB,KK,N,lenA,lenB,lenK,A[50],B[50],K[50];
LL F[50][2][2][2];
bool vis[50][2][2][2];

void cut(int number,int A[],int &len){
	len=0;
	for (;number;number>>=1)
		A[len++]=(number&1);
}
LL calc(int i,int k1,int k2,int k3){
	if (i==-1){
		if (k1==1 || k2==1 || k3==1)
			return 0LL;
		return 1LL;
	}
	if (vis[i][k1][k2][k3]) 
		return F[i][k1][k2][k3];
	vis[i][k1][k2][k3]=true;
	LL res=0;
	int a=A[i],b=B[i],k=K[i];
	res+=calc(i-1,(!a)&k1,(!b)&k2,(!k)&k3);
	if (k1==0 || a==1)
		res+=calc(i-1,a&k1,(!b)&k2,(!k)&k3);
	if (k2==0 || b==1)
		res+=calc(i-1,(!a)&k1,b&k2,(!k)&k3);
	if ((k1==0 || a==1)&&(k2==0 || b==1)&&(k3==0 || k==1)){
		res+=calc(i-1,a&k1,b&k2,k&k3);
	}
	F[i][k1][k2][k3]=res;
	return res;
}
int main(){
	freopen("i.txt","r",stdin);
	scanf("%d",&test);
	for (int testcase=1;test--;testcase++){
		printf("Case #%d: ",testcase);
		scanf("%d%d%d",&AA,&BB,&KK);
		memset(A,0,sizeof(A));
		memset(B,0,sizeof(B));
		memset(K,0,sizeof(K));
		memset(F,0,sizeof(F));
		memset(vis,0,sizeof(vis));
		cut(AA,A,lenA);
		cut(BB,B,lenB);
		cut(KK,K,lenK);
		N=lenA;
		if (lenB>N) N=lenB;
		if (lenK>N) N=lenK;
		LL ans;
		ans=calc(N-1,1,1,1);
		cout<<ans<<endl;
	}
	return 0;
}

