#include<iostream>
#include<queue>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<string>
#include<cstring>
#include<bitset>
#include<map>
#include<numeric>
#include<sstream>
#include<cmath>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define pb push_back
#define f(i,x,y) for(int i = x; i<y; i++)
#define FOR(it,A) for(typeof A.begin() it = A.begin(); it!= A.end(); it++)
#define quad(x) (x) * (x)
#define mp make_pair
#define clr(x, y) memset(x, y, sizeof x)
#define fst first
#define snd second
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
#define inf (1 << 28)
#define N 2000001
int par[N];
vector<int> in[N];
    
int main(){
    clr(par, -1);
    f(i, 1, N){
         char s[10]; sprintf(s, "%d", i);
         
         int rep = strlen(s);
         f(j, 0, rep){
              int x; sscanf(s, "%d", &x);
              if(s[0] != '0' && x < N && x > i) in[i].pb(x);
              rotate(s, s + 1, s + rep);      
         }
    }
    f(i, 1, N){
         sort(all(in[i]));
         in[i].erase(unique(all(in[i])), in[i].end());
    }
    int t; cin >> t;
    for(int cc = 1; cc <= t; cc++){
            int a, b; scanf("%d %d", &a, &b);
            int res = 0;
            f(i, a, b + 1){
                 f(j, 0, in[i].size()) 
                      if(in[i][j] <= b) res++;
            }
            cout << "Case #" << cc << ": " << res << endl; 
    }
}
