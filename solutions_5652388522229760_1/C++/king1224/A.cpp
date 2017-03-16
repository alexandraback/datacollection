#include <cstdio>
#include <cstring>

using namespace std;

int main(){
	long long T,N,tmp;
	int cs=0;
	int count;
	int ddd;
	bool dig[12];
	scanf("%lld",&T);
	while(T--){
		memset(dig,true,sizeof(dig));
		scanf("%lld",&N);
		if(N==0){
			printf("Case #%d: INSOMNIA\n",++cs);
			continue;
		}
		count=0;
		ddd=10;
		while(++count){
			tmp=N*count;
			while(tmp){
				if(dig[tmp%10]){
					dig[tmp%10]=false;
					--ddd;
				}
				tmp=tmp/10;
			}
			if(ddd==0) break;
		}

		printf("Case #%d: %lld\n",++cs,N*count);
	}
	return 0;
}
