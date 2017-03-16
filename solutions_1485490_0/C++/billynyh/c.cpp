#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>
#include <queue>
#include <iostream>
using namespace std;

bool fless(double a,double b){ return b-a>1e-6; }
bool fequal(double a,double b){ return fabs(b-a)<=1e-6; }


#define N 110
long long f[N][N];
int prev_a[N], prev_b[N];
long long a[N], A[N], b[N], B[N];


int main(){
  int tt; scanf("%d",&tt);
  for (int ti=1;ti<=tt;ti++){
    int n,m; scanf("%d%d", &n, &m);
    for (int i=0;i<n;i++){
      scanf("%lld%lld", &a[i], &A[i]);
    }
    for (int i=0;i<m;i++){
      scanf("%lld%lld", &b[i], &B[i]);
    }
    memset(f, 0, sizeof(f));
    //cal prev
    for (int i=0;i<n;i++){
      prev_a[i] = -1;
      for (int j=i-1;j>=0;j--){
        if (A[i]==A[j]){
          prev_a[i] = j;
          break;
        }
      }
    }
    for (int i=0;i<m;i++){
      prev_b[i] = -1;
      for (int j=i-1;j>=0;j--){
        if (B[i]==B[j]){
          prev_b[i] = j;
          break;
        }
      }
    }
    //dp
    for (int i=0;i<n;i++){
      for (int j=0;j<m;j++){
        if (A[i]!=B[j]){
          f[i][j] = 0;
          if (i>0){
            f[i][j] = max(f[i][j], f[i-1][j]);
          }
          if (j>0){
            f[i][j] = max(f[i][j], f[i][j-1]);
          }
        }else{
          //printf("ij %d %d\n", i,j);
          long long sumA = 0;
          for (int p=i; p>=0; p=prev_a[p]){
            sumA += a[p];
            long long sumB = 0;
            for (int q=j; q>=0; q=prev_b[q]){
              sumB += b[q];

              //printf("pq %d %d, %d %d\n", p,q, sumA, sumB);
              
              long long tmp;
              if (p==0 || q==0)tmp = 0;
              else tmp = f[p-1][q-1];

              tmp += min(sumA, sumB);
              f[i][j] = max(f[i][j], tmp);

            }
          }

        }

      }
    }

  /*
    for (int i=0;i<n;i++){
      for (int j=0;j<m;j++){
        printf("%3d ", f[i][j]);
      }
      puts("");
    }
    */

    long long ans = f[n-1][m-1];

    printf("Case #%d: %lld\n",ti,ans);
  }
  return 0;
}

