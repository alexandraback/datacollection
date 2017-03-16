#include <cstdio>
#include <cstring>
#include <cmath>


using namespace std;

int main(){
	int eee;
	scanf("%d",&eee);
	scanf("%d",&eee);
	scanf("%d",&eee);
	bool num[20];
	int rrr=0;
	printf("Case #1:\n");
	for(long long i=32769;i<65536;++i){
		memset(num,false,sizeof(num));
		long long x=i;
		if(x%2==0) continue;
		for(int j=0;j<16;++j){
			if(x%2){
				num[j]=true;
			}
			x=x/2;
		}
		++rrr;
		for(int j=15;j>=0;--j){
			printf("%d",num[j]?1:0);
		}
		for(int j=15;j>=0;--j){
			printf("%d",num[j]?1:0);
		}
		for(int j=2;j<11;++j){
			long long sum=0;
			for(int h=0;h<16;++h){
				if(num[h]){
					sum=sum+pow(j,h);
				}
			}
			printf(" %lld",sum);
		}
		printf("\n");
		if(rrr==500) break;
	}
	return 0;
}
