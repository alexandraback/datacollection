#include "stdio.h"
#include "string.h"
#include <algorithm>
#include <queue>
#include <map>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
void Process(){
	
}
long long Min(long long a, long long b){
	if(a<b) return a;
	else return b;
}
void Solve(){
	long long r, t;
	scanf("%lld %lld",&r,&t);
	long long left=1,right=Min(2000000000L,t/r);
	while(left<right){
		long long mid = (left+right+1)/2;
		if((mid*2*r+(1+mid*4-3)*mid/2)<=t){
			left=mid;
		}
		else{
			right=mid-1;
		}
	}
	printf("%lld\n",left);
}
int main(){
	freopen("D:\\Test\\in.txt","r",stdin);
	freopen("D:\\Test\\out.txt","w",stdout);
	Process();
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++){			
		printf("Case #%d: ",t);
		Solve();
	}
    return 0;
}