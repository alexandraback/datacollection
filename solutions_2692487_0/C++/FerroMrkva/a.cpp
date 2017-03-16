#include<cstdio>
#include<algorithm>

using namespace std;

#define MX 1001001

int A,N;
int M[MX];

int main()
{
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;++t){
		printf("Case #%d: ",t);
		scanf("%d %d",&A,&N);
		for(int i=0;i<N;++i){
			scanf("%d",M+i);
		}
		long long S=A;
		if (S==1){
			printf("%d\n",N);
			continue;
		}
		sort(M,M+N);
		int vys=N,p=0;
		for(int i=0;i<N;++i){
			while(S<=M[i]){
				S+=S-1;
				++p;
			}
			S+=M[i];
			vys=min(vys,p+N-i-1);
		}
		printf("%d\n",vys);
	}
	return 0;
}
