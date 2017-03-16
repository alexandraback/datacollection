#include<cstdio>
#include<string.h>
#include<algorithm>

using namespace std;

int E,R,N,V[100];
int mem[100][100];

int f(int kde,int mam){
	if (mem[kde][mam]!=-1)
		return mem[kde][mam];
	if (kde==N)
		return 0;
	int vys=0;
	for(int i=0;i<=mam;++i){
		vys=max(vys,i*V[kde]+f(kde+1,min(E,mam-i+R)));
	}
	return mem[kde][mam]=vys;
}

int main()
{
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;++t){
		printf("Case #%d: ",t);
		scanf("%d%d%d",&E,&R,&N);
		for(int i=0;i<N;++i){
			scanf("%d",V+i);
		}
		memset(mem,-1,sizeof mem);
		printf("%d\n",f(0,E));
	}
	return 0;
}
