#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>

using namespace std;

const char a[] = {'y','h','e','s','o','c','v',	//abcdefg
				  'x','d','u','i','g','l','b',	//hijklmn
				  'k','r','z','t','n','w',		//opqrst
				  'j','p','f','m','a','q'};		//uvwxyz

int main(){
	int t;
	cin >> t;
	string s;
	getline(cin, s);
	for (int i = 0;i < t; ++i){
		getline(cin, s);
		for (int j = 0; j < s.length(); ++j){
			s[j] = a[s[j]-'a'];
		}
		cout << "Case #" << (i+1) << ": " << s << endl;
	}
	return 0;
}
