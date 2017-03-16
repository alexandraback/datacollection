#include <iostream>
#include <cstdio>
using namespace std;
long long hcf(long long a,long long b){
	if(a==0)return b;
	 if(a==1)return 1;
	 if(a==b)return a;
	 if(a>b)return hcf(b,a);
	 else return hcf(a,b%a);
}
int main(){
freopen("A-small-attempt0 (2).in","r",stdin); 
 freopen("A-small-attempt0 (2).out","w",stdout);
long long e[70];
e[0]=1;
for(int k=1;k<=50;k++)e[k]=e[k-1]*2;
int tc,ii;
scanf("%d",&tc);
for(ii=1;ii<=tc;ii++){
	long long i,j,a,b,d;
	scanf("%lld/%lld",&a,&b);
   printf("Case #%d: ",ii);
		 long long x=hcf(a,b),y=0;
		 a/=x;
		 b/=x;
		 for(i=1;i<=45;i++){
			if(b==e[i]){
					 y=i;
			}
		}
		if(y==0)printf("impossible\n");
		else {
			for(i=y-1;i>=1;i--){//printf("%d\n",a);
				if(a>=e[i]){
					break;
				}
				
			}
			printf("%lld\n",y-i);
		}
	
}
return 0;
}
		
