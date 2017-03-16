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

int test;
long long res, n, mu[20];

long long rev(long long n){
    long long res = 0;
    while (n){
        res = res * 10 + n % 10;
        n = n / 10;
    }
    return res;
}

int scs(long long n){
    int res = 0;
    while (n){
        res++;
        n = n / 10;
    }
    return res;
}

long long cal(long long n){
    if (n < 10) return n;
    int k = scs(n);
    long long a, b;
    if (k % 2 == 0) {
        a = n % mu[k/2];
        b = rev(n) % mu[k/2];
    }
    else {
        a = n % mu[k/2];
        b = rev(n) % mu[k/2 + 1];
    }
    if (a == 0) return cal(n-9) + 9;
    if (b == 1) return cal(mu[k-1] - 1) + n - mu[k-1] + 1;
    return a + b + cal(mu[k-1] - 1) + 1;
}

int main()
{
    ios::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    mu[0] = 1;
    FOR(i,1,15) mu[i] = mu[i-1] * 10;


    cin >> test;
    FOR(t,1,test){
        cout << "Case #" << t << ": ";
        cin >> n;
        cout << cal(n) << endl;
    }

    return 0;
}
