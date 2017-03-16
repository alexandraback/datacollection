//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define _sz(x) ((int)(x).size())    
typedef long long ll;    
typedef long double ld;

const int maxN = 100 + 10; 
string state[maxN];

int nxt[maxN][26]; 
ld cnt[maxN]; 
bool canDo[maxN];
ld dp[maxN][maxN];

ld solve() { 
    memset( nxt , 0 , sizeof nxt ) ; 
    memset( cnt , 0 , sizeof cnt ) ; 
    memset( dp , 0 , sizeof dp ) ; 
    memset( canDo , 0 , sizeof canDo ) ; 
    int n; 
    cin >> n >> n >> n; 
    string s , t ; 
    cin >> s >> t; 

    int m = _sz(t) ; 
    for( int i = 0 ; i <= m ; i++ ) 
	state[i] = t.substr( 0 , i ) ; 

    for( int i = 0 ; i <= m ; i++ ) 
	for( int j = 0 ; j < 26 ; j++ ) 
	    for( int k = min(m,i+1) ; k >= 0 ; k-- ) 
		if ( state[k] == ( state[i] + char(j+'A') ).substr( i + 1 - k , k ) ) { 
		    nxt[i][j] = k;
		    break;
		}
    for( int i = 0 ; i < _sz(s) ; i++ ) {
	cnt[s[i]-'A'] += 1/ld(_sz(s)); 
	canDo[s[i]-'A'] = true; 
    }

    dp[0][0] = 1; 
    for( int k = 0 ; k < n ; k++ ) 
	for( int i = 0 ; i <= m ; i++ ) 
	    for( int j = 0 ; j < 26 ; j++ ) 
		dp[k+1][nxt[i][j]] += cnt[j] * dp[k][i]; 
    ld ans = 0; 
    for( int i = 0 ; i <= n ; i++ ) 
	ans += dp[i][m]; 
    int counter = 0, mx = 0;
    for( int i = 0 ; i < n ; i++ ) {
	if( canDo[t[counter]-'A'] ) { 
	    counter++;
	    if (counter == m) { 
		mx++;
		counter = 0;
		for( int j = 0 ; j < m ; j++ ) 
		    if( state[j] == state[m].substr( m - j , j ) )
			counter = j;
	    }
	}
    }
 //   cout << mx << ' ' << ans << endl;
    return mx - ans;
}

int main() { 
    int t; 
    cin >> t; 
    cout << fixed << setprecision(8) ;
    for( int i = 1 ; i <= t ; i++ ) 
	cout << "Case #" << i << ": " << solve() << endl;
}
