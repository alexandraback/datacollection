#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <iostream>

using namespace std;
typedef long long unsigned ll;

string binaryStr( ll binary ) {
    string s;
    while ( binary > 0 ) {
	s += '0' + (binary % 2);
	binary /= 2;
    }

    string ret;
    for ( int i = 0; i < s.size(); i++ ) {
	ret += s[s.size()-1 - i];
    }

    return ret;
}

ll strToNum( string str, ll base ) {
    ll ret = 0;
    for ( int i = 0; i < str.size(); i++ ) {
	ret *= base;
	ret += (str[i] - '0');
    }

    return ret;
}

int main()
{
    int T;
    scanf("%d", &T);

    for ( int t = 0; t < T; t++ ) {
	int N, J;
	scanf("%d %d", &N, &J);

	printf("Case #%d:\n", t+1);
	
	int half = N / 2;
	int count = 0;
	for ( ll mid = 0; mid < (1 << (half - 2)); mid++ ) {
	    ll base = (mid << 1);
	    base += 1;
	    base += (1 << ( half - 1) );
	    ll binary = (base << half) + base;
	    string binary_str = binaryStr( binary );
	    string base_str = binaryStr( base );
	    cout << binary_str;
	    

	    for ( int b = 2; b <= 10; b++ ) {
		ll num = strToNum( base_str, b );
		printf(" %lld", num);
	    }
	    
	    printf("\n");

	    count++;
	    if ( count == J ) break;
	}
    }
    return 0;
}
