#include <iostream>
#include <string>
#include <cstring>
using namespace std;

#define MAXL 1000001

typedef long long LL;

int T, nCase = 1;

string name;
int n;

bool consonant[128];

LL solv()
{
	LL ans = 0;
	int last = 0 ;
	int cnt = 0;
	for ( int i=0;i<name.length();++i ) {
		if ( consonant[name[i]] ) {
			++ cnt ;
		} else {
			cnt = 0;
		}
		if ( cnt >= n ) {
			last = i-n+2 ;
		}
		ans += last ;
	}
	return ans ;
}

int main()
{
	memset(consonant, false, sizeof consonant);
	for ( int c='a';c<='z';++c ) {
		if ( c=='a' || c=='e' || c=='i' || c=='o' || c=='u' ) continue;
		consonant[c] = true;
	}

	cin >> T;
	while ( T-- ) {
		cin >> name >> n ;
		cout << "Case #" << nCase ++ << ": " << solv() << endl;
	}
	return 0;
}