#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;



int is_pal(__int64 num){
if(num>=4004009004004) return 39;
if(num>=4000008000004) return 38;
if(num>=1234567654321) return 37;
if(num>=1232346432321) return 36;
if(num>=1214428244121) return 35;
if(num>=1212225222121) return 34;
if(num>=1210024200121) return 33;
if(num>=1024348434201) return 32;
if(num>=1022325232201) return 31;
if(num>=1020304030201) return 30;
if(num>=1004006004001) return 29;
if(num>=1002003002001) return 28;
if(num>=1000002000001) return 27;
if(num>=40000800004) return 26;
if(num>=12345654321) return 25;
if(num>=12102420121) return 24;
if(num>=10221412201) return 23;
if(num>=10000200001) return 22;
if(num>=404090404) return 21;
if(num>=400080004) return 20;
if(num>=125686521) return 19;
if(num>=123454321) return 18;
if(num>=121242121) return 17;
if(num>=104060401) return 16;
if(num>=102030201) return 15;
if(num>=100020001) return 14;
if(num>=4008004) return 13;
if(num>=1234321) return 12;
if(num>=1002001) return 11;
if(num>=44944) return 10;
if(num>=40804) return 9;
if(num>=14641) return 8;
if(num>=12321) return 7;
if(num>=10201) return 6;
if(num>=484) return 5;
if(num>=121) return 4;
if(num>=9) return 3;
if(num>=4) return 2;
if(num>=1) return 1;

return 0;

}

int main(){
	
	__int64 x,y;
	int n,i;

//	freopen("C-large-1.in","r",stdin);
//	freopen("CL1.txt","w",stdout);
	

	scanf("%d",&n);

	for(i=1;i<=n;i++){
		printf("Case #%d: ",i);

		scanf("%I64d%I64d",&x,&y);

		printf("%d\n",is_pal(y)-is_pal(x-1));

	}


return 0;
}
