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
int maxi[31][2];
int sum[100], p, n;
int dp[100][101];
int g(int pos, int want){
    if(want < 0) return -100000;
    if(pos == n) return want == 0 ? 0 : -100000;
    int &res = dp[pos][want];
    if(res != -1) return res;
    res = -100000;
    if(maxi[sum[pos]][0] != -1)
                         res = max(res, g(pos + 1, want) + (maxi[sum[pos]][0] >= p));
    if(maxi[sum[pos]][1] != -1)
                         res = max(res, g(pos + 1, want - 1) + (maxi[sum[pos]][1] >= p));
    if(res < 0) res = -100000;
    return res;
}
    
int main(){
    clr(maxi, -1);
    for(int i = 0; i <= 10; i++)
    for(int j = i; j <= i + 2; j++)
    for(int k = j; k <= i + 2; k++){
            int s = i + j + k;
            if(k - i == 2) maxi[s][1] = max(maxi[s][1], k);
            else maxi[s][0] = max(maxi[s][0], k);
    }
    int t; cin >> t;
    for(int cc = 1; cc <= t; cc++){
            int s;
            cin >> n >> s >> p;
            f(i, 0, n) cin >> sum[i];
            clr(dp, -1);
            cout << "Case #" << cc << ": " << max(0, g(0, s)) << endl;
    }
}
