#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
long long f[33][2][2][2];
int get(int k,int x){
	return (k>>(x-1))&1;
}
void solve(int cas){
	printf("Case #%d: ",cas);
	int A,B,K;
	scanf("%d%d%d",&A,&B,&K);
	f[0][0][0][0]=1;
	for(int i=1;i<=32;++i)
		for(int j=0;j<2;++j)
			for(int k=0;k<2;++k)
				for(int l=0;l<2;++l){
					f[i][j][k][l]=0;
					for(int a=0;a<2;++a)
						for(int b=0;b<2;++b){
							if(j&&a>get(A,i))continue;
							if(k&&b>get(B,i))continue;
							if(l&&(a&b)>get(K,i))continue;
							int j1,k1,l1;
							j1=j&(a>=get(A,i));
							k1=k&(b>=get(B,i));
							l1=l&((a&b)>=get(K,i));
							f[i][j][k][l]+=f[i-1][j1][k1][l1];
						}
				}
	printf("%lld\n",f[32][1][1][1]);
}

int main(){
	freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int i=1;i<=T;++i)solve(i);
	return 0;
}
