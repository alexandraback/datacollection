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

int test, n, k1, k2, x;
bool check;
int a[1010], f[1010];
int q[1010][1010];

void xuly(int x, int y){
    if (x == y + 1){
        FOR(i,1,y){
            k1 = i - 1;
            k2 = i + 1;
            if (k1 == 0) k1 = y;
            if (k2 == y + 1) k2 = 1;
            if (q[a[i]][a[k1]] == false && q[a[i]][a[k2]] == false) return;
        }
        //FOR(i,1,y) cout << a[i] << " "; cout << endl;
        check = true;
        return;
    }
    if (check == true) return;
    FOR(i,1,n)
        if (f[i] == false){
            f[i] = true;
            a[x] = i;
            xuly(x + 1, y);
            f[i] = false;
        }
}

int main()
{
    ios::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> test;
    FOR(i,1,test){
        cout << "Case #" << i << ": ";
        cin >> n;
        FOR(j,1,n)
        FOR(k,1,n) q[j][k] = 0;
        FOR(k,1,n) {
            cin >> x;
            q[k][x] = 1;
        }
        check = false;
        DOW(k,n,2){
            xuly(1,k);
            if (check == true){
                cout << k << endl;
                break;
            }
        }
    }
    return 0;
}
