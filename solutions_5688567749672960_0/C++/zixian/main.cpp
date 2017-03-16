#include <cstdio>
#include <algorithm>
#include <map>
#include <utility>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

map<int, int> memo;

int flip(int);
int f(int);

int main(){
  int numTC, TC = 1, N;
  scanf("%d", &numTC);
  while(numTC--){
    scanf("%d", &N);
    printf("Case #%d: %d\n", TC++, f(N));
  }
  return 0;
}

int flip(int n){
  int ans = 0;
  while(n){ ans = 10*ans+n%10; n/=10; }
  return ans;
}

int f(int n){
  if(n==1) return 1;
  if(memo.find(n)!=memo.end()) return memo[n];
  if(!(n%10)){ memo.insert(ii(n, 1+f(n-1))); return memo[n]; }
  int rev = flip(n);
  if(rev>=n)memo.insert(ii(n, 1+f(n-1)));
  else memo.insert(ii(n, 1+min(f(rev), f(n-1))));
  return memo[n];
}
