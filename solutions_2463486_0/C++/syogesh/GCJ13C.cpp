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
#define MAX 10000001

template <class T>inline string itos( T n ) {return (n)< 0?"-"+itos(-(n)):(n)<10?(string)("")+(char('0'+(n))):itos((n)/10)+itos((n)%10);}

ll ans[] = { 1,4,9,121,484,10201,12321,14641,40804,44944,1002001,1234321,4008004,100020001,102030201,104060401,121242121,123454321,125686521,400080004,404090404,10000200001,10221412201,12102420121,12345654321,40000800004,1000002000001,1002003002001,1004006004001,1020304030201,1022325232201,1024348434201,1210024200121,1212225222121,1214428244121,1232346432321,1234567654321,4000008000004,4004009004004};

void Solve() {
	ll a , b;cin >> a >> b;
	int ret = 0;
	rep( i , 0 , 39 ) if( ans[i] >= a && ans[i] <= b ) ret++;
	cout << ret << "\n";
}
int main() {
	int T  , cs = 1;
	cin >> T;
	while( cs <= T ) {
		cout << "Case #" << cs++ <<": ";
		Solve();
	}
	return 0;
}