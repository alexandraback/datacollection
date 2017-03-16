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

map <int, vector<int> > m;
vector <int> v1, v2;
int n;
int arr[200];
bool bit[200];
bool ketemu = false;

void f(int x){
     if ( ketemu ) return;
     if ( x == n-1 ) {
        int sum = 0;
        vector <int> v;
        FOR (i, 0, n) {
            //printf("%d", bit[i]);
            
            if ( bit[i] ) {
               sum += arr[i];
               v.push_back(arr[i]);     
            }    
        }  
                    if ( v.size() == 0 ) return;
            if ( m.count(sum) ){
               v1 = m[sum];
               v2 = v;
               ketemu = true;     
            }
            else m[sum] = v;
        //puts("");
        return;     
     }
     bit[x+1] = false;
     f(x+1);
     bit[x+1] = true;
     f(x+1);             
}

int main() {
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);
    int tcase = 0;
    int t; scanf("%d", &t);
    
    while (t--) {
          m.clear(); v1.clear(); v2.clear(); ketemu = false;
          memset(bit, false, sizeof bit);
          scanf("%d", &n);
          FOR (i, 0, n) scanf("%d", &arr[i]);
          
          f(-1);
          printf("Case #%d:\n", ++tcase);
          if ( v1.size() == 0 && v2.size() == 0 ) puts("Impossible");
          else{
               FOR (i, 0, v1.size()){
                   if ( i != 0 ) printf(" ");
                   printf("%d", v1[i]);    
               }     
               puts("");
               FOR (i, 0, v2.size()){
                   if ( i != 0 ) printf(" ");
                   printf("%d", v2[i]);        
               }
               puts("");
          }     
          
    }
    return 0;
}
