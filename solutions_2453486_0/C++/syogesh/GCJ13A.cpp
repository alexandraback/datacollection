/*****************/
/*  Halla Bol    */
/*****************/

#include <vector>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>

using namespace std;

#define rep(i,a,b) for(typeof(a) i=(a);i<(b);i++)
#define ll long long int
#define ii pair<int,int>
#define CLEAR(x,val) memset(x,val,sizeof(x))
#define SZ(v) (v).size()
#define pb push_back
#define inf 0x7f7f7f7f


bool iswon( char ch , char a[4][4] ) {
	rep( i , 0 , 4 ) {
		bool won = true;
		rep( j , 0 , 4 ) if( a[i][j] != ch && a[i][j] != 'T' ) won = false;
		if( won ) return true;
	}
	rep( j , 0 , 4 ) {
		bool won = true;
		rep( i , 0 , 4 ) if( a[i][j] != ch && a[i][j] != 'T' ) won = false;
		if( won ) return true;
	}
	bool won = true;int x = 0 , y= 0;
	rep( i , 0 , 4 ) { if( a[x][y] != ch && a[x][y] != 'T' ) won = false; x += 1; y += 1; }
	if( won ) return true;
	x = 0 , y = 3;
	won = true;	
	rep( i , 0 , 4 ) { if( a[x][y] != ch && a[x][y] != 'T' ) won = false; x += 1; y -= 1; }	
	if( won ) return true;
	return false;
}
void Solve() {
	char a[4][4];char ch;
	rep( i , 0 , 4 ) rep( j , 0 , 4 ){ cin >> ch; a[i][j]=ch; }
	if( iswon( 'X' , a ) ) cout << "X won\n";
	else if( iswon( 'O' , a) ) cout << "O won\n";
	else{
		int emptycells = 0;
		rep( i , 0 , 4 ) rep( j , 0 , 4 ) if( a[i][j] == '.' ) emptycells++;
		if(emptycells>0) cout << "Game has not completed\n";
		else cout << "Draw\n";
	}
}
int main() {
	int T  , cs = 1;cin >> T;
	while( cs <= T ) {
		cout << "Case #" << cs++ <<": ";
		Solve();
	}
	return 0;
}