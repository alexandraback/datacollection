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

string s, res;
int test, n;

void xuly(){
    res = "";
    n = s.length();
    FOR(i,0,n-1)
        if (res + s[i] > s[i] + res) res = res + s[i];
        else res = s[i] + res;
    cout << res << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> test;
    FOR(i,1,test){
        cout << "Case #" << i << ": ";
        cin >> s;
        xuly();
    }
    return 0;
}
