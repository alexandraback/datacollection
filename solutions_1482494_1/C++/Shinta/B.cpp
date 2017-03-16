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
#define N 100000
int n, a[N], b[N];
pii x[N];
int hay[N];
int main(){
  int t; scanf("%d", &t);
  f(tt, 1, t + 1){
    cin >> n;
    f(i, 0, n) cin >> x[i].snd >> x[i].fst;
    sort(x, x + n);
    f(i, 0, n) a[i] = x[i].snd, b[i] = x[i].fst;
    f(i, 0, n) hay[i] = true;
    int res = 0, pt = 0;
    f(i, 0, n){
     if(pt >= b[i]) res++, pt += (hay[i] ? 2 : 1);
     else{
       bool dead = false;
       while(pt < b[i] && !dead){
        int who = -1;
        for(int j = i; j < n; j++) if(hay[j] && pt >= a[j]) who = j;
        if(who == -1) dead = true;
        else hay[who] = false, res++, pt++;
       } 
       if(dead) break;
       else i--; 
     } 
    }
    
    printf("Case #%d: ", tt);
    if(pt != 2 * n) cout << "Too Bad" << endl;
    else cout << res << endl;
  }
}
