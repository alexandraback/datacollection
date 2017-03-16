#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

FILE *in = fopen("A.in", "r");
FILE *out = fopen("A.out", "w");

int n, a[111], SS;

int main(){
  
  int ntest;
  fscanf(in, "%d", &ntest);
  for(int test = 1; test <= ntest ; test++){
    fscanf(in, "%d%d", &SS, &n);
    for(int q = 0; q < n; q++){
      fscanf(in, "%d", &a[q]);
    }
    int  S = SS;
    sort(a, a + n);
    int res = n, op = 0;
    for(int q = 0; q < n; q++){
      while(q < n && a[q] < S){
        S += a[q];
        q ++;
      } 
      res = min(res, n - q + op);
      if(S == 1 || q == n){
        goto end;
      }
      while(S <= a[q]){
        op ++;
        S += S - 1;
      }
      S += a[q];
    }
    res = min(res, op);
    end:;
    fprintf(out, "Case #%d: %d\n", test, res);
  }
  
  return 0;
}
