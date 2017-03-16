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
using namespace std;

int n, m, a[55], f[55], z[55], res[55], test, top, xx, yy;
bool c[55][55], fr[55];

void xuly(int x){
    if (x == n+1){
        //FOR(i,1,n) cout << f[i] << " "; cout << endl;
        top = 1;
        while (res[top] == a[f[top]]) top++;
        if (res[top] < a[f[top]]) return;
        top = 1;
        z[top] = f[1];
        FOR(i,2,n){
            while (c[z[top]][f[i]] == false && top > 0) top--;
            if (top == 0) return;
            z[++top] = f[i];
        }
        FOR(i,1,n) res[i] = a[f[i]];
        return;
    }
    FOR(i,1,n)
        if (fr[i] == true){
            //cout << x << " " << i << endl;
            f[x] = i;
            fr[i] = false;
            xuly(x+1);
            fr[i] = true;
        }
}

int main()
{
    ios::sync_with_stdio(false);
    freopen("c.in","r",stdin);
    freopen("c.out","w",stdout);
    cin >> test;
    FOR(oo,1,test){
        cin >> n >> m;
        FOR(i,1,n) cin >> a[i];
        FOR(i,0,n)
        FOR(j,0,n) c[i][j] = false;
        FOR(i,1,n) fr[i] = true;
        FOR(i,0,n) res[i] = 99999;
        FOR(i,1,m){
            cin >> xx >> yy;
            c[xx][yy] = true;
            c[yy][xx] = true;
        }
        xuly(1);
        cout << "Case #" << oo << ": ";
        FOR(i,1,n) cout << res[i];
        cout << endl;
    }
    return 0;
}
