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

int n;
int target;
vector <int> v[1005];
int visit[1005];

int dfs(int a){
    FOR (i, 0, v[a].size()) {
        int next = v[a][i];
        if ( visit[next] == 0 ) {
           visit[next]++;
           dfs(next);     
        }
        else visit[next]++;       
    }
}

bool cek() {
          FOR (i, 1, n+1) {
              memset(visit, 0, sizeof visit);
              dfs(i);
              FOR (i, 1, n+1) {
                  if ( visit[i] > 1 ) return true;     
              }    
          }   
          return false;       
}

int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    int tcase = 0;
    int t; scanf("%d", &t);
    
    while (t--) {
          FOR (i, 0, 1005) v[i].clear();
          scanf("%d", &n);
          FOR (i, 1, n+1) {
              int x; scanf("%d", &x);
              FOR (j, 0, x) {
                  int a; scanf("%d", &a);
                  v[i].push_back(a);    
              }   
          } 
          
          bool ret = cek();
          
          printf("Case #%d: ", ++tcase);
          if ( ret ) puts("Yes");
          else puts("No");
    }
    return 0;
}
