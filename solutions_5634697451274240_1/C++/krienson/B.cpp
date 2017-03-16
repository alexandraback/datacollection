#include<iostream>
#include<string>

using namespace std;

int main(){
	int kases; cin >> kases;
	for( int kase = 1; kase <= kases; kase++ ){
		string s; cin >> s;
		int rev = 0;
		for( int i = int( s.size() ) - 1 ; i >= 0; i-- ){
			if( s[ i ] == '-' && ((rev&1) == 0 ) ){
				rev++;
			}
			else if( s[ i ] == '+' && ((rev&1) == 1 ) ){
				rev++;
			}
		}
		cout << "Case #" << kase << ": " << rev << endl;
		
	}
}
