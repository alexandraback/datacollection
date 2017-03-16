#include<bits/stdc++.h>

using namespace std;

pair < char , int > a[2000];
bool pos[2000];

bool cmp( pair < char , int > x , pair < char , int > y ) {
	return x > y;
}

int main() {
	int t;
	cin >> t;
	for( int ca = 1 ; ca <= t ; ca++ ) {
		string s;
		cin >> s;
		int len = s.length();
		for( int i = 0 ; i < len ; i++ )
			a[i] = make_pair( s[i] , i );
		sort( a , a+len , cmp );
		pos[a[0].second] = 0;
		for( int i = 1 , j = a[0].second ; i < len ; i++ ) {
			if( a[i].second < j ) {
				pos[a[i].second] = 0;
				j = a[i].second;
			}
			else
				pos[a[i].second] = 1;
		}
		string ans = "";
		for( int i = 0 ; i < len ; i++ )
			if( pos[i] )
				ans = ans+s[i];
			else
				ans = s[i]+ans;
		cout << "Case #" << ca << ": " << ans << endl;
	}
	return 0;
}
