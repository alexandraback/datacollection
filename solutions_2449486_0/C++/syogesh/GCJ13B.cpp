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
#define MAX 109

int desH[MAX][MAX];
int rowM[MAX] , colM[MAX];


void Solve() {
	CLEAR( desH , 0 );CLEAR(rowM , 0 );CLEAR( colM , 0 );
	int N , M; cin >> N >> M;
	rep( i , 0 , N ) rep( j , 0 , M ) cin >> desH[i][j];
	rep( i , 0 , N ) rep( j , 0 , M ) rowM[i] = max( rowM[i] , desH[i][j] );
	rep( j , 0 , M ) rep( i , 0 , N ) colM[j] = max( colM[j] , desH[i][j] );
	bool pos = true;
	rep( i , 0 , N ) rep( j , 0 , M ) if( ( desH[i][j] != rowM[i] ) && (desH[i][j] != colM[j]) ) pos = false;
	if( pos ) cout << "YES\n";
	else cout << "NO\n";
}
int main() {
	int T  , cs = 1;cin >> T;
	while( cs <= T ) {
		cout << "Case #" << cs++ <<": ";
		Solve();
	}
	return 0;
}
