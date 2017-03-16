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

int N;
int a = 0, b = 0;
int number[20];
int state[20];

bool gen(int index){
     if(index == 20)
          return a == b && a > 0 && b > 0; 
     
     state[index] = 2;
     if(gen(index + 1)) return true;
     
     state[index] = 0;
     a += number[index];
     if(gen(index + 1)) return true;
     a -= number[index];
     
     state[index] = 1;
     b += number[index];
     if(gen(index + 1)) return true;
     b -= number[index];
      
     return false;
}

int main(){
     freopen("C-small-attempt0.in", "r", stdin);
     freopen("C-small-attempt0.out","w", stdout);

     int T;
     cin >> T;
     for(int t = 1; t <= T; t++){
          cin >> N;
          For(i, N)
               scanf("%d", &number[i]);
          printf("Case #%d:", t);
          a = 0, b = 0;
          if(gen(0)){
               cout << endl;
               For(i, N)
                    if(state[i] == 0)
                         printf("%d ", number[i]);
               cout << endl;
               For(i, N)
                    if(state[i] == 1)
                         printf("%d ", number[i]);
               cout << endl;
          }
          else printf(" Impossible\n");
     }

     //system("pause");
     return 0;
}
