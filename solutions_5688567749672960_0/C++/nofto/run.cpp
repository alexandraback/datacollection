#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
#include <deque>

using namespace std;

long long reverse(long long N){
	long long A=0;
	while(N>0){
		A*=10;
		A+=N%10;
		N/=10;
	}
	return A;
}

vector <int> ans(1000001,0);


int main()
{
	ans[1]=1;
	for(int i=2;i<=1000000;i++){
		int j=reverse(i);
		if(j>=i || i%10==0) ans[i]=1+ans[i-1];
		else ans[i]=1+min(ans[i-1],ans[j]);
	}
	int T;
	scanf("%d",&T);  
	for(int t=1; t<=T; t++)
	{		
		long long N;
		scanf("%llu",&N);
		printf("Case #%d: %d\n",t,ans[N]);
	}
  return 0;
}
