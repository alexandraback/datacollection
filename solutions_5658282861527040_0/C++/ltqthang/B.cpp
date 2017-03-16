//-----------------------------------------
// Le Truong Quoc Thang
// ltqthang@gmail.com
// Problem:
// ----------------------------------------

#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define write(a) printf("%d", a)
#define writes(a) printf("%d ", a)
#define writeln(a) printf("%d\n", a)
#define read(a) scanf("%d", &a)
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector <int>
#define mii map <int, int>
#define INF 2000000000
#define maxN 1000005

int TC;
int A, B, K;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("test.out", "w", stdout);
    #endif // ONLINE_JUDGE

    read(TC);
    rep(caseNo, TC){
        int cnt = 0;
        scanf("%d %d %d", &A, &B, &K);
        rep(i, A) rep(j, B){
            //cout << i << " and " << j <<  " = " << (i & j) << " = " << K << endl;
            if ((i & j) < K) cnt++;
        }
        printf("Case #%d: %d\n", caseNo + 1, cnt);
    }

    return 0;
}
