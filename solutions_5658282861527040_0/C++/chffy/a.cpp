#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main(){
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	int T,Tnum=0;
	scanf("%d",&T);
	for (;T;--T){
		int A,B,K;
		scanf("%d%d%d",&A,&B,&K);
		int ans=0;
		for (int i=0; i<A; ++i)
			for (int j=0; j<B; ++j)
				if ( (i & j)<K) ++ans;
		printf("Case #%d: %d\n",++Tnum,ans);
	}
	return 0;
}
