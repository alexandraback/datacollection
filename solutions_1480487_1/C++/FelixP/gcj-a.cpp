#include <cstdio>
#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
using namespace std;

typedef pair<int,int> ii;
typedef long long LL;
typedef vector <int> vi;

#define INF 2000000000
#define PI 3.14159265

#define FOR(i,a,n) for(int i=a,_n=n; i<_n; ++i)
#define FOREACH(it,arr) for (__typeof((arr).begin()) it=(arr).begin(); it!=(arr).end(); it++)

#define DEBUG(x) cout << '>' << #x << ':' << x << '\n';

int main() {
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    int tcase = 1;
    int t; scanf("%d", &t);
    
    while (t--) {
          int arr[250];
          int n; scanf("%d", &n);
          int sum = 0;
          FOR (i, 0, n) scanf("%d", &arr[i]), sum += arr[i];
          
          int winner = n;
          bool alreadyWin[250]; memset(alreadyWin, false, sizeof alreadyWin);
          double ans[250];
          
          
          bool masuk = false;
          double sumWin = 0.00;
          double atLeast = (double)sum*2 / winner;
    
          FOR (i, 0, n){
              double mustGet = (double)atLeast-arr[i];
              if ( !alreadyWin[i] ) ans[i] = mustGet / sum * 100;  
              else ans[i] = 0.000000; 
              if ( ans[i] < 0.000000 ){
                 alreadyWin[i] = true;
                 masuk = true;
                 sumWin += arr[i];
                 winner--;
              }   
          }
          
          if ( masuk ){
             atLeast = (double)(sum*2-sumWin)/winner;
             
             FOR (i, 0, n){
                 double mustGet = (double)atLeast-arr[i];
                 if ( !alreadyWin[i] ) ans[i] = mustGet/sum*100;
                 else ans[i] = 0.000000;    
             }
          }
          
          printf("Case #%d:", tcase++);
          FOR (i, 0, n){
              printf(" %.6lf", ans[i]);    
          }
          puts("");
    }
    return 0;
}
