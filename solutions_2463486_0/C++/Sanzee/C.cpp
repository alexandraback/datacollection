// Author : Muhammad Rifayat Samee
// Problem : C
// Algorithm:
#pragma warning (disable : 4786)
#pragma comment(linker, "/STACK:16777216")

#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cctype>
#include<cstring>
#include<algorithm>
#include<string>
#include<set>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#define MAX(a,b) (a>b)?a:b
#define MIN(a,b) (a<b)?a:b
#define INF 987654321
#define pi (2*acos(0.0))
#define eps 1e-7

#ifdef ONLINE_JUDGE
#define i64 long long
#else
#define i64 __int64
#endif

using namespace std;
i64 number[100000],tot;
__int64 ispalin(i64 n){
	i64 r,i,j,k;
	char str[17];
	i = 0;
	while(n!=0){
		r = n%10;
		n = n/10;
		str[i] = r + '0';
		i++;
	}
	str[i] = NULL;
	for(j=0,k=i-1;j<=k;j++,k--){
		if(str[j] != str[k])return 0;
	}
	return 1;
}


void preposs(){
	i64 i,j,k;
	tot  = 0;
	for(i=1;i<=10000000;i++){
		if(ispalin(i)){
			if(ispalin(i*i)){
				number[tot] = i*i;
				//printf("%I64d\n",i*i);
				tot++;
			}
		}
	}
	//printf("%I64d\n",tot);
}
int main(){

	//freopen("C.in","r",stdin);
	//freopen("C.out","w",stdout);
	preposs();
	i64 cases,i,j,k,a,b,ct=1;
	scanf("%I64d",&cases);
	while(cases--){
		scanf("%I64d %I64d",&a,&b);
		__int64 res = 0;
		for(i=0;i<tot;i++){
			if(number[i]>=a && number[i]<=b){
				res++;
			}
		}
		printf("Case #%I64d: %I64d\n",ct++,res);
	}
	return 0;
}
