#include <iostream>
#include <string>
using namespace std;

char multi(char x, char y, bool &sign) {
	switch(x) {
		case '1': return y;
		case 'i': 
			switch(y) {
				case '1': return x;
				case 'i': sign = !sign; return '1';
				case 'j': return 'k';
				case 'k': sign = !sign; return 'j';
			}
		case 'j':
			switch(y) {
				case '1': return x;
				case 'i': sign = !sign; return 'k';
				case 'j': sign = !sign; return '1';
				case 'k': return 'i';
			}
		case 'k':
			switch(y) {
				case '1': return x;
				case 'i': return 'j';
				case 'j': sign = !sign; return 'i';
				case 'k': sign = !sign; return '1';
			}
	}
	return 0;
}

int main() {
	int T, L, X;
	string s;
	cin >> T;
	
	for( int t = 1; t <= T; ++ t) {
		cin >> L >> X;
		cin >> s;
		bool sign = true;
		char c = '1';
		int flag = 0;
		for( int i = 0; i < X; ++ i)
			for( int j = 0; j < L; ++ j ) {
				c = multi(c, s[j], sign);
				if( sign ) {
					if( c == 'i' && flag == 0 ) {
						c = '1';
						flag = 1;
					}
					else if( c == 'j' && flag == 1) {
						c = '1';
						flag = 2;
					}
				}
			}
		if( sign && c == 'k' && flag == 2 )
			cout << "Case #" << t << ": YES" << endl;
		else
			cout << "Case #" << t << ": NO" << endl;
	}
	return 0;
}
