#include <cstring>
#include <set>
#include <queue>
#include <iostream>
#include <cstdio>
using namespace std;

typedef long long Int;
using namespace std;

Int dp[40][4][4][4];
int bit[4][40];

int g(int p,int upper,int cmp){
  if(p == 1){
    if( upper == 1 ){
      if ( upper > cmp) return 0;
      return 1;
    }else {
		if(upper == cmp ) return 1;
	    return 2;
    }
  }
  return 0;
}
Int f(int u,int A,int B,int K){
  if (u < 0){
    if( A == 0 && B == 0 & K == 0)   return 1LL;
    return 0LL;
  }

  if(dp[u][A][B][K] != -1) return dp[u][A][B][K];
  Int res = 0;
  for( int a = 0; a < 2; a++){
  	for( int b = 0; b < 2; b++){
	    int c = (a & b);
	    int p1 = g(A,bit[0][u],a);
    	int p2 = g(B,bit[1][u],b);
	    int p3 = g(K,bit[2][u],c);
	    if(p1 > 1 || p2 > 1 || p3 > 1)continue;
    	res  += f(u - 1,p1,p2,p3); 
	}
  }
  return dp[u][A][B][K] = res;
} 
void binrep(int mask,int k){
  for(int i = 30; i >= 0 ; i--)
    if( mask & (1 << i) )
		bit[k][i] = 1; 
  
}
int main(){

    int runs;
    cin >> runs;
	for( int r = 1; r <= runs; r++){	
	  printf("Case #%d: ",r);
  	  int A,B,K;
	  cin >> A >> B >> K;
	  memset( bit, 0, sizeof bit);
	  binrep(A , 0); binrep(B , 1); binrep(K , 2);
	  memset( dp, -1, sizeof dp);
	  Int res = f(30,1,1,1);
	  cout << res <<endl;
    }
    return 0;
  }
