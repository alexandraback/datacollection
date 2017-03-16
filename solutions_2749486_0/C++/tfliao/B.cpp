#include <iostream>
#include <string>
#include <cstring>
#include <map>
using namespace std;

int T, nCase = 1;
int X, Y;

string solv()
{
	int step = 1;
	string NSPAT = (Y<0?"NS":"SN") ;
	string WEPAT = (X<0?"EW":"WE");
	string ans = ""; 
	
	if ( X < 0 ) X = -X ;
	if ( Y < 0 ) Y = -Y ;
	
	for ( int i=0;i<X;++i ) ans += WEPAT;
	for ( int i=0;i<Y;++i ) ans += NSPAT;
	
	return ans;
}

int main()
{
	cin >> T;
	while ( T-- ) {
		cin >> X >> Y;
		cout << "Case #" << nCase ++ << ": " << solv() << endl;
	}
	return 0;
}