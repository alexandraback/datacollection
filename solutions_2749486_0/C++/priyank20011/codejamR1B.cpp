// for small test case only

#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
int main()
{
	int t,n,a,b,i,j;
	freopen("D:\\input2.txt","r",stdin);
    freopen("D:\\output2.txt","w",stdout);
	scanf("%d",&t);
	for(j=1;j<=t;j++){
		scanf("%d%d",&a,&b);
		printf("Case #%d: ",j);
		if(a>=0 && b>=0){
			for(i=0;i<a;i++) printf("WE");
			for(i=0;i<b;i++) printf("SN");
		}
		else if(a<=0 && b>=0){
			for(i=0;i<(-1)*a;i++) printf("EW");
			for(i=0;i<b;i++) printf("SN");
		}
		else if(a<=0 && b<=0){
			for(i=0;i<(-1)*a;i++) printf("EW");
			for(i=0;i<(-1)*b;i++) printf("NS");
		}
		else {
			for(i=0;i<a;i++) printf("WE");
			for(i=0;i<(-1)*b;i++) printf("NS");
		}
		printf("\n");
	}
	return 0;
}

