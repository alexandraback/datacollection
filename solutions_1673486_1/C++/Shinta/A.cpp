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
ld p[N];
ld cor[N];
int main(){
  int t; scanf("%d", &t);
  f(tt, 1, t + 1){
    int A, B; scanf("%d %d", &A, &B);
    f(i, 0, A) cin >> p[i];
    cor[0] = 1;
    f(i, 1, A + 1) cor[i] = cor[i - 1] * p[i - 1];
    ld res = B + 2;
    f(del, 0, A + 1) res = min(res, 2 * del + B - A + 1 + (1 - cor[A - del]) * (B + 1));
    printf("Case #%d: %.08f\n", tt, double(res));
  }
}
