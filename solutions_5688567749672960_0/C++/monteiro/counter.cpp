#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <valarray>
#include <vector>

#define pb push_back
#define pf push_front
#define sz size
#define f() first
#define s() second
#define b() begin()
#define e() end()

#define pairii pair< int,int >
#define vint vector< int >
#define vchar vector< char >
#define vbool vector< bool >
#define vstring vector< string >
#define int64 long long
#define Uint64 unsigned long long
#define Uint unsigned int
#define Uchar unsigned char

#define fori(n) for(int i=0;i<n;i++)
#define forj(n) for(int j=0;j<n;j++)
#define fork(n) for(int k=0;k<n;k++)
#define forir(n) for(int i=n-1;i>=0;i--)
#define forr(i, a, b) for ( int i = (a); i <= (b); ++i )
#define ford(i, a, b) for ( int i = (a); i >= (b); --i )
#define forit(v) for(it = v.begin();it != v.end();it++)

#define trace(x...) x
#define print(x...) trace(printf(x))
#define watch(x) trace(cout << #x" = " << x << "\n")

#define INF 0x3F3F3F3F // Signed int
//#define INF 0x3F3F3F3F3F3F3F3FLL // Signed int64
#define EPS 1e-10
#define PI 3.14159265358979323846

int cmpD(double a, double b){
	return (a <= b + EPS) ? (a + EPS < b) ? -1 : 0 : 1;
}

using namespace std;

int strtoint(string & str){
	bool ok = false;
	int ret = 0;
	fori(str.sz()){
		if( !ok && str[i] == '0' ) return -1;
		ok = true;
		ret = ret*10 + (str[i]-'0');
	}
	return ret;
}

string inttostring(int t){
	string ret;
	char buffer[100];
	int size = 0;;
	if( t == 0 ) return "0";
	while(t != 0){
		buffer[size] = '0'+t%10;
		size++;
		t = t/10;
	}
	buffer[size] = '\0';
	ret = string(buffer);
	reverse(ret.b(),ret.e());
	return ret;
}

int main(){

	int games;

	cin >> games;

	int dp[1000100];

	fork(games){

		int n;
		cin >> n;
		int ret = 0;

		fori(10) dp[i] = i;

		for(int i = 1;i <= n;i++){
			string str = inttostring(i);
			reverse(str.b(), str.e());
			int newi = strtoint( str );
//			cout << newi << endl;
			if( newi < i && newi > 0)
				dp[i] = min(dp[i-1] + 1, dp[newi] + 1);
			else
				dp[i] = dp[i-1] + 1;
//			cout << "-> " << dp[i] << endl;
		}

/*
		for(int i = n;i >= 1;i--){
			ret++;
			string str = inttostring(i);
	//		cout << "str: " << str << endl;
			reverse(str.b(),str.e());
			int newi = strtoint( str );
	//		cout << "int: " <<newi << endl;
			if( newi < i && newi >= 1 ){ ret++; i = newi; }
//			cout << i << endl;
		}
		for(int i = 1;i <= n;i++){
			ret++;
			string str = inttostring(i);
	//		cout << "str: " << str << endl;
			reverse(str.b(),str.e());
			int newi = strtoint( str );
	//		cout << "int: " <<newi << endl;
			if( newi > i && newi <= n ){ ret++; i = newi; }
//			cout << i << endl;
		}
		*/
		cout << "Case #" << k+1 << ": " << dp[n] << endl;


	}

	


}
