#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <queue>
#include <math.h>
#include <map>
#include <stdlib.h>
using namespace std;
#define ACCEPTED 0
#define F first
#define S second
#define PI (acos(-1.0))
#define EPS (1e-11)
#define INF (1<<30)
int dx[] = {1,0,-1,0}, dy[] = {0,1,0,-1};
/* ============================================== */
bool isPalindrome(long long n){
  long long a=n, b=0;
  while(n){
    b*=10LL;
    b+=n%(10LL);
    n/=10LL;
  }
  return a==b;
}
int main(){
  int t, T;
  long long A, B;
  vector<long long> v;
  for(long long i=1LL; i*i<=100000000000000LL; i++){
    if(isPalindrome(i) && isPalindrome(i*i))
      v.push_back(i*i);
  }
  scanf("%d", &T);
  for(t=1; t<=T; t++){
    scanf("%Ld %Ld", &A, &B);
    printf("Case #%d: %d\n", t, (int)(upper_bound(v.begin(), v.end(), B)-lower_bound(v.begin(), v.end(), A)));
  }
  
  return ACCEPTED;
}
/* ============================================== */
