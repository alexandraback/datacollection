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

int a, b, k, res, test;

int main()
{
    ios::sync_with_stdio(false);
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
    cin >> test;
    FOR(oo,1,test){
        cin >> a >> b >> k;
        res = 0;
        FOR(i,0,a-1)
        FOR(j,0,b-1)
            if ((i & j) < k) res++;
        cout << "Case #" << oo << ": " << res << endl;
    }
    return 0;
}
