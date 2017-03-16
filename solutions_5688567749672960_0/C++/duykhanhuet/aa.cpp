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

int test, n, res, f[1000100];

int rev(int n){
    int res = 0;
    while (n){
        res = res * 10 + n % 10;
        n = n / 10;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    FOR(i,1,1000000)
        if (i % 10 == 0) f[i] = f[i-1] + 1;
        else if (i > rev(i)) f[i] = min(f[i-1] + 1, f[rev(i)] + 1);
        else f[i] = f[i-1] + 1;

    cin >> test;
    FOR(t,1,test){
        cout << "Case #" << t << ": ";
        cin >> n;
        cout << f[n] << endl;
    }

    return 0;
}
