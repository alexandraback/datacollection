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

int ma, pay, d, h, test, l, k, s;
double res;
string a, b;
char f[100];

bool check(int pos){
    FOR(i,0,l-1)
        if (f[pos + i] != b[i]) return false;
    return true;
}

int cnt(){
    int res = 0;
    FOR(i,1,s-l+1)
        if (check(i)) res++;
    return res;
}

void xuly(int x){
    if (x > s) {
        d++;
        h = cnt();
        pay += h;
        ma = max(ma, h);
        return;
    }
    FOR(i,0,k-1) {
        f[x] = a[i];
        xuly(x+1);
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> test;
    FOR(o,1,test){
        cin >> k >> l >> s;
        cin >> a;
        cin >> b;

        ma = 0;
        pay = 0;
        d = 0;
        xuly(1);

        res = (double)ma - (double)pay / (double)d;
        printf("Case #%d: %.6f\n", o, res);
    }

    return 0;
}
