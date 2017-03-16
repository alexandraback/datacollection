#include<iostream>
#include<stack>
#include<queue>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<string>
#include<cstring>
#include<map>
#include<numeric>
#include<sstream>
#include<cmath>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define pb push_back
#define f(i,x,y) for(int i = x; i<y; i++ )
#define FORV(it,A) for(vector<int>::iterator it = A.begin(); it!= A.end(); it++)
#define FORS(it,A) for(set<int>::iterator it = A.begin(); it!= A.end(); it++)
#define quad(x) (x) * (x)
#define mp make_pair
#define clr(x, y) memset(x, y, sizeof x)
#define fst first
#define snd second
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

#define N 20
map <int, int> wall;
int n;
int d[N], a[N], w[N], e[N], s[N], dd[N], dp[N], ds[N];
int qnts[N];


int main (){
    int t; cin >> t;
    f (tt, 1, t+1){
        cin >> n;
        f (i, 0, n){
            cin >> d[i] >> a[i] >> w[i] >> e[i] >> s[i] >> dd[i] >> dp[i] >> ds[i];
        }
        wall.clear();
        clr (qnts, 0);
        int ans = 0;
        vector <pii > at;
        for (int tempo = 0; tempo < 1000000; tempo++){
            at.clear();
            f (i, 0, n){
                if (qnts[i] < a[i]){
                    if (tempo >= d[i] && (tempo-d[i])%dd[i] == 0){
                        int str = s[i] + qnts[i]*(ds[i]);
                        int ini = w[i] + qnts[i]*dp[i];
                        int fim = e[i] + qnts[i]*dp[i];
                        int mn = str+1;
                        //printf("i = %d (%d %d)\n", i, ini, fim);
                        f (j, ini, fim){
                            mn = min (mn, wall[j]);
                        }
                        if (mn < str) ans++;
                        //printf("ans = %d\n", ans);
                        f (j, ini, fim){
                            at.pb(mp(j, str));
                        }
                        qnts[i]++;
                    }
                }
            }
            f (i, 0, at.size()){
                wall[at[i].fst] = max (wall[at[i].fst], at[i].snd);
            }
        }
        printf("Case #%d: %d\n", tt, ans);
    }
    return 0;
}

