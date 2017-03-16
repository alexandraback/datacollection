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
#define LIMIT 0.0000001
#define inf 2000000001
using namespace std;
typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;

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

set<int> test;

int main(){
     freopen("C-small-attempt0.in", "r", stdin);
     freopen("C-small-attempt0.out","w", stdout);

     int T, a, b, mul, x;
     cin >> T;
     for(int t = 1; t <= T; t++){
          cin >> a >> b;
          int ans = 0;
          b++;
          for(int i = max(10, a); i < min(100, b); i++){
               mul = 10;
               x = i;
               for(int j = 0; j < 1; j++){
                    x = x/10 + (x%10) * mul;
                    if(x >= a && x <= b && x < i)
                         test.insert(x);
               }
               ans += test.size();
               test.clear();
          }
          for(int i = max(100, a); i < min(1000, b); i++){
               mul = 100;
               x = i;
               for(int j = 0; j < 2; j++){
                    x = x/10 + (x%10) * mul;
                    if(x >= a && x <= b && x < i)
                         test.insert(x);
               }
               ans += test.size();
               test.clear();
          }
          for(int i = max(1000, a); i < min(10000, b); i++){
               mul = 1000;
               x = i;
               for(int j = 0; j < 3; j++){
                    x = x/10 + (x%10) * mul;
                    if(x >= a && x <= b && x < i)
                         test.insert(x);
               }
               ans += test.size();
               test.clear();
          }
          for(int i = max(10000, a); i < min(100000, b); i++){
               mul = 10000;
               x = i;
               for(int j = 0; j < 4; j++){
                    x = x/10 + (x%10) * mul;
                    if(x >= a && x <= b && x < i)
                         test.insert(x);
               }
               ans += test.size();
               test.clear();
          }
          for(int i = max(100000, a); i < min(1000000, b); i++){
               mul = 100000;
               x = i;
               for(int j = 0; j < 5; j++){
                    x = x/10 + (x%10) * mul;
                    if(x >= a && x <= b && x < i)
                         test.insert(x);
               }
               ans += test.size();
               test.clear();
          }
          for(int i = max(1000000, a); i < min(10000000, b); i++){
               mul = 1000000;
               x = i;
               for(int j = 0; j < 6; j++){
                    x = x/10 + (x%10) * mul;
                    if(x >= a && x <= b && x < i)
                         test.insert(x);
               }
               ans += test.size();
               test.clear();
          }
          cout << "Case #" << t << ": " << ans << endl;
     }

     //system("pause");
     return 0;
}
