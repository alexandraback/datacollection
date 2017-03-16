#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

/*bool isprime[1000000000];

void Sieve()
{
	memset(isprime,true,sizeof(isprime));
	isprime[0]=isprime[1]=false;
	for(int i=2;i<=sqrt(1000000000);++i)
		if(isprime[i])
			for(int j=i+i;j<1000000000;j+=i)
				isprime[j]=false;
}*/ 


int main(){
//	Sieve();
//	for(int i=0;i<1000000000;++i)
//	if(isprime[i])
//	printf("%d\n",i);
	int eee;
	scanf("%d",&eee);
	scanf("%d",&eee);
	scanf("%d",&eee);
	printf("Case #1:\n");
	int cs=0;
	long long a=32769;
	int rrr=0;
	bool num[20];
	int kk[15];
	int count;
	for(long long i=a;i<65536;++i){
		memset(num,false,sizeof(num));
		count=0;
		long long x=i;
		if(x%2==0) continue;
		for(int j=0;j<16;++j){
			if(x%2){
				num[j]=true;
			}
			x=x/2;
		}
		int flag=0;
		for(int j=2;j<11;++j){
			long long y=0;
			for(int h=0;h<16;++h){
				if(num[h]){
					y=y+pow(j,h);
				}
			}
			for(int d=100;d<1000;++d){
				if(y%d==0){
	//				printf("d=%d\t",d);
					kk[flag]=d;
					++flag;
					break;
				}
			}
		}
		//printf("i=%lld %d:",i,++cs);
		if(flag==9){
			for(int z=15;z>=0;--z){
				printf("%d",num[z]?1:0);
			}
			for(int z=0;z<9;++z){
				printf(" %d",kk[z]);
			}
			printf("\n");
			++rrr;
		}
		if(rrr>49) break;
	}
	return 0;
}
