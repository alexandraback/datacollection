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

long long cur, c, v, a[111];
int test, n, res;

int main()
{
    ios::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> test;
    FOR(o,1,test){
        cout << "Case #" << o << ": ";
        cin >> c >> n >> v;
        FOR(i,1,n) cin >> a[i];
        sort(a+1, a+n+1);
        cur = 0;
        res = 0;
        FOR(i,1,n){
            //cout << cur << endl;
            if (cur >= v) break;
            while (a[i] > cur + 1) {
                res++;
                cur += (cur + 1) * c;
                //cout << cur << endl;
                if (cur >= v) break;
            }
            cur += a[i] * c;
            //cout << cur << endl;
        }
        while (cur < v) {
            res++;
            cur += (cur + 1) * c;
        }
        cout << res << endl;
    }

    return 0;
}
