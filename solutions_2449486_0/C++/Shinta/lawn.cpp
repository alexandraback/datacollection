#include<cassert>
#include<queue>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<iostream>
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
#define f(i,x,y) for(int i = x; i<y; i++)
#define FOR(it,A) for(typeof A.begin() it = A.begin(); it!= A.end(); it++)
#define quad(x) (x) * (x)
#define mp make_pair
#define clr(x, y) memset(x, y, sizeof x)
#define fst first
#define snd second
typedef pair<int, int> pii;
typedef long long ll;
typedef long long ld;
int mat[100][100];
int row[100], col[100];
int x[100][100];
int main(){
    int t; cin >> t;
    f(tt, 1, t + 1){
        int n, m; cin >> n >> m;
        f(i, 0, n) f(j, 0, m) cin >> mat[i][j];
        vector<pii> events;
        f(i, 0, n){
            row[i] = mat[i][0];
            f(j, 0, m) row[i] = max(row[i], mat[i][j]);
            events.push_back(mp(row[i], i + 1));
        }
        f(j, 0, m){
            col[j] = mat[0][j];
            f(i, 0, n) col[j] = max(col[j], mat[i][j]);
            events.push_back(mp(col[j], -j - 1));
        }
        sort(rall(events));
        f(i, 0, n) f(j, 0, m) x[i][j] = 100;
        f(ii, 0, events.size()){
            pii e = events[ii];
            if(e.snd > 0){
                int r = e.snd - 1;
                f(i, 0, m) x[r][i] = min(x[r][i], row[r]);
            }else{
                int c = -e.snd - 1;
                f(i, 0, n) x[i][c] = min(x[i][c], col[c]);
            }
        }
        bool sirve = true;
        f(i, 0, n) f(j, 0, m) if(x[i][j] != mat[i][j]) sirve = false;
        printf("Case #%d: %s\n", tt, sirve ? "YES" : "NO");
    }       
}
