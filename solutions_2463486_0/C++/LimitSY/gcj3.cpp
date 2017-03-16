#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
__int64 f[100]={1,4,9,121,484,10201,12321,14641,40804,44944,1002001,1234321,4008004,100020001,102030201,104060401,121242121,123454321,125686521,400080004,404090404,10000200001,10221412201,12102420121,12345654321,40000800004,1000002000001,1002003002001,1004006004001,1020304030201,1022325232201,1024348434201,1210024200121,1212225222121,1214428244121,1232346432321,1234567654321,4000008000004,4004009004004};
int main(){
	int n=39;
	int t,cas=1;
	__int64 a,b;
#ifndef ONLINE_JUDGE
	freopen("E://C-small-attempt0.in","r",stdin);
	freopen("E://C-small-attempt0.out","w+",stdout);
#endif
	scanf("%d",&t);
	while(t--){
		scanf("%I64d%I64d",&a,&b);
		int num=0;
		for(int i=0;i<n;++i){
			if(f[i]<a)
				continue;
			if(f[i]>b)
				break;
			++num;
		}
		printf("Case #%d: %d\n",cas++,num);
	}return 0;
}