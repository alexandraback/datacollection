#include <stdio.h>
#include<stdio.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <iostream>
using namespace std;

__int64 table[]={1,4,9,121,484,10201,12321,14641,40804,44944,1002001,1234321,4008004,100020001,102030201,104060401,121242121,123454321,125686521,400080004,404090404,10000200001,10221412201,12102420121,12345654321,40000800004,1000002000001,1002003002001,1004006004001,1020304030201,1022325232201,1024348434201,1210024200121,1212225222121,1214428244121,1232346432321,1234567654321,4000008000004,4004009004004,10000000000000000};
int cal( __int64 a ){
	int ans = 0 ;
	while( table[ans]<=a )ans ++ ;
	return ans ;
}

int main(){
	freopen("C-small-attempt0.in","rt",stdin);
	freopen("C-small-attempt0.out","wt",stdout);
	int cas , casn = 1;
	scanf("%d",&cas);
	while(cas--){
		__int64 a , b ;
		scanf("%I64d%I64d",&a,&b);
		printf("Case #%d: %d\n",casn ++ , cal(b)-cal(a-1));
	}
	return 0;
}