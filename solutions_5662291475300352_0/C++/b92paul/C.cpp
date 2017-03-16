#include <cstdio>
#include <algorithm>
#include <cassert>
using namespace std;
const int N = 1010;
typedef long long LL;
LL H[N];
LL D[N];
LL M[N];
int main(){
	int T;
	scanf("%d",&T);
	int count= 0 ;
	while(count++ <T){
		int N;
		scanf("%d",&N);
		for(int i=0;i<N;i++){
			scanf("%lld %lld %lld",&D[i],&H[i],&M[i]);
		}
		int ans = 0;
		if(N==2){
			if(D[0] > D[1]){
				int tmp;
				tmp = D[0],D[0] = D[1],D[1]=tmp;
				tmp = M[0],M[0] = M[1],M[1]=tmp;
			}
			if(D[0] == D[1] && M[0] < M[1]){
				swap(M[0],M[1]);
			}
			LL a = LL(360-D[0])*M[0];
			LL b = LL(720-D[1])*M[1];
			if(a>=b)ans=1;
		}
		printf("Case #%d: %d\n",count,ans);
	}

}
