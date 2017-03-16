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
int digits(long long N){
	int a=0;
	while(N>0){
		a++;
		N/=10;
	}
	return a;
}
int right(long long N,int dig){
	int tenpower=1;
	while(dig>0){
		tenpower*=10;
		dig--;
	}
	return N%tenpower;
}
int left(long long N,int dig){
	int d=digits(N);
	int remove=d-dig;
	int tenpower=1;
	while(remove>0){
		tenpower*=10;
		remove--;
	}
	return N/tenpower;
}
int pow10(int dig){
	int a=1;
	while(dig>0){
		a*=10;
		dig--;
	}
	return a;
}
int solve(long long N){
	if(N<21) return N;
	int dig=digits(N);
	int L=left(N,dig/2);
	int R=right(N,(dig+1)/2);
	if(L>pow10(dig/2-1) && R>=1) return R+solve(reverse(N-R+1));
	if(R==0) return 1+solve(N-1);
	return R+solve(N-R);
}
int main()
{
	int T;
	scanf("%d",&T);  
	for(int t=1; t<=T; t++)
	{		
		long long N;
		scanf("%llu",&N);
		printf("Case #%d: %d\n",t,solve(N));
	}
  return 0;
}
