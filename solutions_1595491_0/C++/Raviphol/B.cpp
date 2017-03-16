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

int main(){
     freopen("B-small-attempt0.in", "r", stdin);
     freopen("B-small-attempt0.out","w", stdout);

     int T, n, s, p, x;
     cin >> T;
     for(int t = 1; t <= T; t++){
          cin >> n >> s >> p;
          int ans1 = 0, ans2 = 0;
          for(int i = 0; i < n; i++){
               cin >> x;
               if(x >= p * 3 - 2 && x >= p)
                    ans1++;
               else if(x >= p * 3 - 4 && s-- > 0 && x >= p)
                    ans2++;
          }
          cout << "Case #" << t << ": " << ans1 + ans2 << endl;
     }

     //system("pause");
     return 0;
}
