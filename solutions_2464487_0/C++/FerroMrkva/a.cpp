#include<cstdio>

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;++t){
		long long r,c;
		scanf("%lli%lli",&r,&c);
		long long vys=0;
		while(1){
			long long x=(r+1)*(r+1)-r*r;
			if (x<=c){
				c-=x;
				vys++;
				r+=2;
			}
			else break;
		}
		printf("Case #%d: ",t);
		printf("%lli\n",vys);
	}
	return 0;
}
