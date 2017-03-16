// esta3anna 3al sha2a belAllah ..
#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<algorithm>
#include<sstream>
#include<limits.h>
#include<iomanip>
#include<cstring>
#include<bitset>
#include<fstream>
#include<cmath>
#include<cassert>
#include <stdio.h>
#include<ctype.h>
using namespace std ;
#define rep(i,n,m) for(int i = (int)(n), _m = (int)(m); i < _m; ++ i)
#define	rrep(i,n,m) for(int i = (int)(n), _m = (int)(m); i >= _m; -- i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz size()
#define pb push_back
#define mp make_pair
#define mems(arr, v) memset(arr, v, sizeof arr)
#define setBit(mask, bit) ((mask) | (1LL << (bit)))
#define resetBit(mask, bit) ((mask) & (~(1LL << (bit))))
#define flipBit(mask, bit) ((mask) ^ (1LL << (bit)))
#define is0(mask, bit)(((mask) & (1LL << (bit))) == 0)
#define is1(mask, bit)(((mask) & (1LL << (bit))) != 0)
#define removeLastBit(mask) ((mask) & ((mask) - 1LL))
#define firstBitOn(mask) ((mask) & ~((mask) - 1LL))
#define grayCode(mask) ((mask) ^ ((mask) << 1LL))
#define repSubMasks(subMask, mask) for(ll subMask = (ll)(mask), _mask = subMask; subMask; subMask = _mask & (subMask - 1))
int countBits(int mask) {int res = 0; while(mask) mask &= (mask - 1), ++ res; return res;}
#define INT_MAX  2000000000
#define INT_MIN -INT_MAX
#define EPS 1e-9
#define debug(x) cout << #x << " : " << x << endl
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
#define Read() freopen("input.txt","r",stdin)
#define Write() freopen("output.txt","w",stdout)
#define PI acos(-1.0)
string SUM ( string a , string b )
{
	int sum , carry = 0 ;
	string output = "" ;
	while ( a.size() < b.size() )
		a.insert( 0 , "0" );
	while ( b.size() < a.size() )
		b.insert( 0 , "0" );
	for ( int i = a.size() - 1 ; i >= 0 ; i -- )
	{
		sum = 0 ;
		sum += a [ i ] - '0' ;
		sum += b [ i ] - '0' ;
		sum += carry ;
		if ( sum >= 10 )
		{
			sum -= 10 ;
			output += sum + '0' ;
			carry = 1 ;
		}
		else
		{
			output += sum + '0' ;
			carry = 0 ;
		}
	}
	if ( carry == 1 )
		output += '1' ;
	reverse ( output.begin() , output.end() );
	return output ;
}
string PRODUCT ( string a , string b )
{
	reverse ( a.begin() , a.end() );
	reverse ( b.begin() , b.end() );
	string sum , output = "" ;
	int asfaar = 0 , carry = 0 , product ;
	for ( int i = 0 ; i < a.size() ; i ++ )
	{
		sum = "" ;
		for ( int i = 0 ; i < asfaar ; i ++ )
		{
			sum.insert(0 , "0");
		}
		asfaar ++ ;
		for ( int j = 0 ; j < b.size() ; j ++ )
		{
			product = ( a [ i ] - '0' ) * ( b [ j ] - '0' ) ;
			product += carry ;
			carry = 0 ;
			stringstream temp ;
			temp << product ;
			if ( product < 10 )
			{
				sum.insert( 0 , temp.str() );
			}
			else if ( product >= 10 )
			{
				carry = ( temp.str()[ 0 ] - '0' ) ;
				string taha = "" ;
				taha += temp.str()[1];
				sum.insert( 0 , taha );
			}
			temp.clear();
		}
		if ( carry != 0 )
		{
			stringstream tenno ;
			tenno << carry ;
			sum.insert(0 , tenno.str());
				tenno.clear();
				carry = 0 ;
		}
		output = SUM ( output , sum );
	}
	while ( output [ 0 ] == '0' )
		output.erase(0 , 1);
	if ( output == "" )
		return "0" ;
	return output ;
}

bool ok(ll t, ll mid, ll rad) {
//	return (mid * ((2 * rad) + 1)) + (2 * mid * (mid - 1)) <= t;
	string MID, RAD, T, MID_1;
	stringstream aa, bb, cc, dd;
	aa << mid;
	aa >> MID;
	bb << rad;
	bb >> RAD;
	cc << t;
	cc >> T;
	dd << (int)(mid - 1);
	dd >> MID_1;
	string res = PRODUCT(MID, SUM(PRODUCT("2", RAD), "1"));
	res = SUM(res, PRODUCT("2", PRODUCT(MID, MID_1)));
	if(res.size() < T.size())
		return true;
	else if(res.size() > T.size())
		return false;
	return res <= T;
}

int main() {
	Read();
	Write();
	ll cases, cnt;
	cin >> cases;
	ll t, rad;
	rep(C, 1, cases + 1) {
		cin >> rad >> t;
		cnt = 0;
		ll low = 1;
		ll high = 707106780;
		while(low <= high) {
			ll mid = low + ((high - low) / 2);
			if(ok(t, mid, rad)) {
				cnt = mid;
				low = mid + 1;
			}
			else {
				high = mid - 1;
			}
		}
		cout << "Case #" << C << ": " << cnt << endl;
	}
}