#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<set>
#include<queue>
#include<list>
#include<vector>
#define LL long long
#define INF 0x7fffffff
#define For(i,a,b) for(int i=a; i<b; ++i)
using namespace std;
typedef pair<int,int> ii;
queue<int> q;
int dp[1000002];
int v[1000002];

int rev(int number){
  int reverse = 0;
  for( ; number!= 0 ; )
   {
      reverse = reverse * 10;
      reverse = reverse + number%10;
      number = number/10;
   }
   return reverse;
}


int main(){

  for(int i=1; i<=1000000; ++i){
    dp[i] = 10000000;
  }
  dp[1] = 1;
  q.push(1);
  while(!q.empty()) {
    int num = q.front();
    q.pop();
    int reverse = rev(num);
    if(dp[reverse] == 10000000){
      dp[reverse] = dp[num] + 1;
      q.push(reverse);
    }
    if(num+1<=1000000 && dp[num+1] == 10000000) {
      dp[num+1] = dp[num] + 1;
      q.push(num+1);
    }
  }


  int T;
  cin>>T;
  for(int cas=1; cas<=T; ++cas ) {
    int n;
    cin>>n;
    printf("Case #%d: %d\n", cas, dp[n]);
  }
	return 0;
}
