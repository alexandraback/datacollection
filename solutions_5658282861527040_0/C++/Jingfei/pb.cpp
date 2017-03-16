#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int T; scanf("%d",&T);
	int A,B,K;
	for(int Case=1; Case<=T; ++Case){
		scanf("%d%d%d",&A,&B,&K);
		int ans=0;
		for(int i=0; i<A; ++i)
			for(int j=0; j<B; ++j)
				if((i&j)<K) ++ans;
		printf("Case #%d: %d\n",Case,ans);
	}
	return 0;
}
