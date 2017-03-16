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

int test, n, x;
int f[3000];

int main()
{
    ios::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> test;
    FOR(i,1,test){
        cout << "Case #" << i << ": ";
        FOR(i,0,2500) f[i] = 0;
        cin >> n;
        FOR(j,1,2*n-1)
        FOR(k,1,n){
            cin >> x;
            f[x]++;
        }
        FOR(i,1,2500)
            if (f[i] % 2 == 1) cout << i << " ";
        cout << endl;
    }
    return 0;
}
