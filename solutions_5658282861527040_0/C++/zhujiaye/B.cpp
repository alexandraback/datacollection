#include<cstdio>
#include<algorithm>
using namespace std;

int A,B,K,test;

int main(){
	freopen("i.txt","r",stdin);
	scanf("%d",&test);
	for (int testcase=1;test--;testcase++){
		printf("Case #%d: ",testcase);
		scanf("%d%d%d",&A,&B,&K);
		int ans=0;
		for (int i=0;i<A;i++)
			for (int j=0;j<B;j++) if ((i&j)<K) ans++;
		printf("%d\n",ans);
	}
	return 0;
}

