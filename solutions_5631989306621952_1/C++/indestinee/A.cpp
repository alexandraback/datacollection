/*
 *	Author:
 *		Indestinee
 *	Date:
 *		2016/04/16
 */
#include <map>
#include <set>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
string s, ans;
int cas;
int main(){
	freopen( "A-large.in"  , "r" , stdin  );
	freopen( "A-large.out" , "w" , stdout );
	cin >> cas;
	for( int T = 1 ; T <= cas ; T ++ ){
		cin >> s;
		ans = "";
		for( int i = 0 , sz = s.size() ; i < sz ; i ++ ){
			if( ans.empty() || ans[0] > s[i] )
				ans += s[i];
			else
				ans = s[i] + ans;
		}
		cout << "Case #" << T << ": " << ans << endl;		
	}
	return 0;
}
