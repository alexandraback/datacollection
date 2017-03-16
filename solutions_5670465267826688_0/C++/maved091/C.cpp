#include <bits/stdc++.h>

#define FILE 	1
#define INPUT 	"CSmall.in"
#define OUTPUT 	"CSmall.out"

#define MP 	    make_pair
#define MT 	    make_tuple
#define PB 	    push_back
#define FI 	    first
#define SE 	    second

#define MAX 	int(1e5+10)
#define INF 	INT_MAX
#define EPS 	int(1e-7)
#define MOD 	int(1e7+7)
#define PI 	    acos(-1)

#define I       2
#define J       3
#define K       4

typedef long long ll;

using namespace std;

map< char, int > id;
int result[5][5] = { {  0  ,  0  ,  0  ,  0  ,  0  },
                     {  0  ,  1  ,  I  ,  J  ,  K  },
                     {  0  ,  I  , -1  ,  K  , -J  },
                     {  0  ,  J  , -K  , -1  ,  I  },
                     {  0  ,  K  ,  J  , -I  , -1  } };
long long nTest, L, X;
string S;

int main( ) {

    if( FILE ) {
        freopen( INPUT , "r", stdin  );
        freopen( OUTPUT, "w", stdout );
    }

    id[ 'i' ] = I; id[ 'j' ] = J; id[ 'k' ] = K;

    cin >> nTest;

    for( int t = 1; t <= nTest; t++ ) {
        cin >> L >> X >> S;
        bool foundI = false, foundJ = false, foundK = false;
        int cur = 0, ans = 0;
        for( int i = 0; i < int(min( (long long)(1e5), L*X )); i++ ) {
            if( foundI && foundJ && i >= L ) break;
            int curNum = id[ S[ i%L ] ];
            if( i ) cur = result[ abs(cur) ][ curNum ] * (cur < 0 ? -1 : 1);
            else cur = curNum;
            if( i < L ) ans = cur;
            if( !foundI ) foundI = ( cur == I );
            else if( !foundJ ) foundJ = ( cur == K );
        }
        X--;
        int aux = ans;
        for( int i = 0; i < (X%4); i++ )
            ans = result[ abs(ans) ][ abs(aux) ] * ( ans < 0 ? -1 : 1 ) * ( aux < 0 ? -1 : 1 );

        cout << "Case #" << t << ": ";
        if( ans == -1 && foundI && foundJ ) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
