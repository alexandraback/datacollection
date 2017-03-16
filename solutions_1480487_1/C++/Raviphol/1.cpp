/*
LANG: C++
TASK:
author: Raviphol Sukhajoti
*/
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <numeric>
#include <stack>
#include <queue>
#include <set>
#include <utility>
#define LIMIT 0.0000001
#define inf 2000000001
using namespace std;
typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;
typedef pair<int,int> pii;

#define For(i,n) for(int i = 0; i < n; i++)
#define pb push_back
#define Sz(v) v.size()
#define It(v) typeof(v.begin())
#define Forit(it,v) for(It(v) it = v.begin(); it != v.end(); it++)
#define All(v) v.begin(), b.end()
#define getI(n) scanf("%d",&n)
#define getD(n) scanf("%lf",&n)
#define nl cout << endl
#define LL long long

int main(){
     freopen("A-large.in", "r", stdin);
     freopen("A-large.out","w", stdout);

     int T;
     cin >> T;
     for(int t = 1; t <= T; t++){
          int N;
          cin >> N;
          double p[N], total = 0;
          for(int i = 0; i < N; i++){
               cin >> p[i];
               total += p[i];
          }
          For(i, N)
               p[i] *= 100.0 / total;
          printf("Case #%d:", t);
          
          For(i, N){
               double m, l = 0, h = 100;
               while(h - l > 0.0000001){
                    m = (l + h) / 2;
                    bool status = true;
                    double target = p[i] + m;
                    double left = 100 - m;
                    for(int j = 0; j < N; j++){
                         if(j != i && p[j] < target){
                              left -= target - p[j];
                         }
                         if(left < 0) break;
                         else if(j == N-1)
                              status = false;
                    }
                    if(status) h = m;
                    else l = m;
                    //cout << l << ' ' << h << ' ' << status << endl;
               }
               printf(" %.6lf",m);
          }
          printf("\n");
     }

     //system("pause");
     return 0;
}
