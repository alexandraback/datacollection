// Author: Nguyen Duy Khanh
#include<bits/stdc++.h>
#define FOR(i,a,b) for( int i=(a),_b=(b);i<=_b;i++)
#define DOW(i,b,a) for( int i=(b),_a=(a);i>=_a;i--)
#define DEBUG(x) { printf << #x << " = " << x << endl; }
#define DEBUGARR(a,n) {cout << #a << " = " ; FOR(_,1,n) cout << a[_] << ' '; cout <<endl;}
#define CHECK printf("OK\n");
#define FILL(a, b) memset((a), (b), sizeof((a)))
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define Nmax 35000
using namespace std;

int res, test, n, cnt, x, res2;
int bff[1010], f[1010];
vector<int> _bff[1010];
bool visited[1010];

void dfs(int x, int y){
    if (visited[x] == true) return;
    cnt++;
    visited[x] = true;
    if (x == y) {
        f[x] = cnt;
        return;
    }
    dfs(bff[x], y);
}

void chutrinh(){
    FOR(i,1,n) {
        f[i] = 0;
        cnt = 0;
        FOR(j,1,n) visited[j] = false;
        dfs(bff[i], i);
    }
    res = 0;
    FOR(i,1,n) res = max(res, f[i]);
    //FOR(i,1,n) cout << f[i] << " "; cout << endl;
}

int dem(int x, int y){
    if (_bff[x].size() == 0) return 1;
    int res = 0;
    int v;
    FOR(i,0,_bff[x].size()-1){
        v = _bff[x][i];
        if (v != y) res = max(res, dem(v, y));
    }
    return res + 1;
}

void expand(){
    cnt = 0;
    FOR(i,1,n)
        if (f[i] == 2) cnt++;
    res2 = 0;
    FOR(i,1,n)
        if (f[i] == 2) {
            //cout << i << " " << dem(i, bff[i]) << endl;
            //cout << bff[i] << " " << dem(bff[i], i) << endl;
            //res = max(res, dem(i, bff[i]) + dem(bff[i], i) + cnt - 2);
            res2 += dem(i, bff[i]) + dem(bff[i], i);
        }
    res2 /= 2;
    res = max(res, res2);
}

int main()
{
    ios::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> test;
    FOR(o,1,test){
        cout << "Case #" << o << ": ";
        cin >> n;
        FOR(i,1,n) _bff[i].clear();
        FOR(i,1,n){
            cin >> x;
            bff[i] = x;
            _bff[x].pb(i);
        }
        res = 0;
        chutrinh();
        expand();
        cout << res << endl;
    }
    return 0;
}
