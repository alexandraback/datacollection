#include<bits/stdc++.h>

using namespace std;

int t , a[200] , ans[20];
string s;

void process( int x , string s ) {
	for( int i = 0 , len = s.length() ; i < len ; i++ )
		a[s[i]] -= x;
}

int main() {
	cin >> t;
	for( int ca = 1 ; ca <= t ; ca++ ) {
		cin >> s;
		memset( a , 0 , sizeof a );
		memset( ans , 0 , sizeof ans );
		for( int i = 0 , len = s.length() ; i < len ; i++ )
			a[s[i]]++;
		ans[0] = a['Z'];
		process( a['Z'] , "ZERO" );
		ans[2] = a['W'];
		process( a['W'] , "TWO" );
		ans[6] = a['X'];
		process( a['X'] , "SIX" );
		ans[8] = a['G'];
		process( a['G'] , "EIGHT" );
		ans[3] = a['H'];
		process( a['H'] , "THREE" );
		ans[4] = a['R'];
		process( a['R'] , "FOUR" );
		ans[1] = a['O'];
		process( a['O'] , "ONE" );
		ans[7] = a['S'];
		process( a['S'] , "SEVEN" );
		ans[5] = a['F'];
		process( a['F'] , "FIVE" );
		ans[9] = a['I'];
		process( a['I'] , "NINE" );
		cout << "Case #" << ca << ": ";
		for( int i = 0 ; i < 10 ; i++ )
			while( ans[i]-- )
				cout << i;
		cout << endl;
	}
	return 0;
}
