/*
 * CODEJAM
 * Problem A: Standing Ovation
 * By: maved091 - mavd09
 */

#include <bits/stdc++.h>

#define FILE 	1
#define INPUT 	"ALarge.in"
#define OUTPUT 	"ALarge.out"

#define MP 	    make_pair
#define MT 	    make_tuple
#define PB 	    push_back
#define FI 	    first
#define SE 	    second

#define MAX 	int(1e7+10)
#define INF 	INT_MAX
#define EPS 	int(1e-7)
#define MOD 	int(1e7+7)
#define PI 	    acos(-1)

typedef long long ll;

using namespace std;

int nTest, S, ans;
string A;

int main( ) {

    if( FILE ) {
        freopen( INPUT , "r", stdin  );
        freopen( OUTPUT, "w", stdout );
    }

    cin >> nTest;

    for( int t = 1; t <= nTest; t++ ) {
        cin >> S >> A;
        ans = 0;
        int curS = A[0]-'0';
        for( int i = 1; i <= S; i++ ) {
            int cur = A[i]-'0';
            if( cur == 0 ) continue;
            if( curS < i ) ans += i-curS, curS += i-curS;
            curS += cur;
        }
        cout << "Case #" << t << ": " << ans << "\n";
    }

    return 0;
}
