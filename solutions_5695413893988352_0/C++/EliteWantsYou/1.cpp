#include <bits/stdc++.h>

#define lli long long int
#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin freopen( "input.txt", "r", stdin );
#define fout freopen( "output.txt", "w", stdout );

using namespace std;

string s, t, sx, tx;
int x, y = 1e9;

void rec( int i, int j, string a, string b, int c, int d )
{
    if( a.size() == s.size() ){
        if( abs(c - d) < abs(x - y) ){
            x = c, y = d;
            sx = a, tx = b;
        }
        return;
    }
    for( int h = 0; h < 10; h++ ){
        for( int k = 0; k < 10; k++ ){
            int f1 = h;
            int f2 = k;
            if( s[i] != '?' )
                f1 = s[i] - '0';
            if( t[j] != '?' )
                f2 = t[j] - '0';
            rec(i + 1, j + 1, a + char(f1 + '0'), b + char(f2 + '0'), c * 10 + f1, d * 10 + f2);
            if( t[j] != '?' )
                break;
        }
        if( s[i] != '?' )
            break;
    }
}

int main()
{
    int T;
    cin >> T;
    for( int i = 1; i <= T; i++ ){
        cin >> s >> t;
        y = 1e9;
        rec(0, 0, "", "", 0, 0);
        cout << "Case #" << i << ": " << sx << " " << tx << endl;
    }
}
