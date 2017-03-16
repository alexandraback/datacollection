#include<iostream>
#include<string>
using namespace std;

int main(){
	int kases; cin >> kases;
	for( int kase = 1; kase <= kases; kase++ ){
		string s, res = "", a, b;
		cin >> s;
		for( int i = 0; i < s.length(); i++ ){
			a = res + s.substr(i,1);
			b = s.substr(i,1) + res;
			if( a > b ) res = a;
			else res = b;
		}
		cout << "Case #" << kase <<": " << res << endl;	
	}
}
