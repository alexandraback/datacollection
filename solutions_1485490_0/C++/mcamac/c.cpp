#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<cmath>
#define MAX(x,y) x < y ? y : x
#define MIN(x,y) x < y ? x : y

typedef signed long long int __int64;
using namespace std;

int main() {
  ifstream fin("c-small.in");
  ofstream fout("c-small.out");

  int tests; fin >> tests;
  for(int test = 1; test <= tests; test++) {
    
    int n,m;
    fin >> n >> m;
    __int64 dp[n+1][m+1];
    __int64 left[n+1][m+1];
    int box_type[n+1];
    __int64 box_ct[n+1];
    int toy_type[m+1];
    __int64 toy_ct[m+1];
    int last_box[n][m];

    for(int i=1;i<=n;i++) {
      fin >> box_ct[i] >> box_type[i];
    }
    for(int j=1;j<=m;j++) {
      fin >> toy_ct[j] >> toy_type[j];
    }
    for(int i=0;i<n+1;i++){
      for(int j=0;j<m+1;j++) { 
        dp[i][j] = 0;
        left[i][j] = box_ct[i];
      }
    }

    for(int i=1;i<=n;i++) {
      for(int j=1;j<=m;j++) {
        if(toy_type[j] == box_type[i]) {
          // toy j is first toy in box i
          for(int i2=0;i2<i;i2++) {
            for(int j2=0; j2<j;j2++) {
              // fill previous boxes if can
              if(box_type[i2] == toy_type[j]) {
                __int64 lprev = left[i2][j2];
                __int64 rem = MAX(0, toy_ct[j] - lprev);
                __int64 c = dp[i2][j2];
                __int64 l = MAX(0, box_ct[i] - rem);
                __int64 a = MIN(box_ct[i], rem);
                //cout << c + a << endl;
                if(dp[i][j] < c + rem + a) {
                  left[i][j] = l;
                  dp[i][j] = c + rem +  a;
                }
              } else {
                __int64 c = dp[i2][j2];
                __int64 l = MAX(0, box_ct[i] - toy_ct[j]);
                __int64 a = MIN(box_ct[i], toy_ct[j]);
                //cout << c + a << endl;
                if(dp[i][j] < c + a) {
                  left[i][j] = l;
                  dp[i][j] = c + a;
                }
              }
            }
          }
          // toy j is not first toy in box i
          for(int j2=0;j2 < j; j2++) {
            if(toy_type[j2] == toy_type[j]) {
              __int64 c = dp[i][j2];
              __int64 l = MAX(0, left[i][j2] - toy_ct[j]);
              __int64 a = MIN(left[i][j2], toy_ct[j]);
              if(dp[i][j] < c + a) {
                left[i][j] = l;
                dp[i][j] = c + a;
              }
            }
          }
        }
      }
    }

    __int64 ret = 0;
    for(int i=1;i<=n;i++) {
      for(int j=1;j<=m;j++) {
        //cout << dp[i][j] << " ";
        if(dp[i][j] > ret) ret = dp[i][j];
      }
     // cout << endl;
    }

    fout << "Case #" << test << ": " << ret << endl;
  }
}