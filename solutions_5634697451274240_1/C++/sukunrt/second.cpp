
#include <bits/stdc++.h>
using namespace std;

int a[105];
int cnt;
void flip( int i, int j ){
    for( int k = i, m = j; k <= m; k++, m-- ){
	int temp = a[k];
	a[k] = a[m];
	a[m] = temp;
	a[k] = a[k] ^ 1;
	if( k != m ) a[m] = a[m] ^ 1;
    }
    return;
}

void solve( int n ){
    if( n == 0 ) return;
    if( a[n] == 1 ) return( solve( n-1 ) );

    if( a[1] == 1 ){
	
	cnt++;
	int j;
	for( j = 1; j <= n; j++ )
	    if( a[j] == 0 ) break;
	j--;
	flip( 1, j );
    }
    flip( 1, n );
    cnt++;
    return( solve( n-1 ) );
}

int main(){
    int t;
    cin >> t;
    for( int c = 1; c <= t; c++){
	for( int i = 0; i <= 103; i++) a[i] = 0;
	cnt = 0;
	string s;
	cin >> s;
//	cout << s << endl;
	
	for( int i = 0; i < s.length() ; i++ ){
	    if( s[i] == '+' ) a[i+1] = 1;
	    else a[i+1] = 0;
	}
	solve( s.length() );
	cout << "Case #" << c << ": " << cnt << endl;
    }
    return 0;
}
	

	
	
