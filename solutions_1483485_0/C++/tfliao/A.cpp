#include <iostream>
#include <string>
using namespace std;

char mp[128] ;

void setMapping ( string from, string to) {
	for ( int i=0;i<from.length();++i ) {
		mp[from[i]] = to[i] ;
	}
}

void init () {
	setMapping ( "ejp mysljylc kd kxveddknmc re jsicpdrysi",
				  "our language is impossible to understand" ) ;
	setMapping ( "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
				  "there are twenty six factorial possibilities" ) ;
	setMapping ( "de kr kd eoya kw aej tysr re ujdr lkgc jv",
				  "so it is okay if you want to just give up" ) ;
	setMapping ( "zq", "qz" ) ;
	
}

string decode ( string line ) {
	string ret = "";
	for ( int i=0;i<line.length();++i ) {
		ret += mp[line[i]];
	}
	return ret;
}

int main()
{
	init();
	int T, nCase = 1 ;
	string line ;
	cin >> T ; getline ( cin, line ) ;
	while ( T-- > 0 ) {
		getline ( cin, line ) ;
		cout << "Case #" << nCase++ << ": " << decode(line) << endl;
	}
	
	return 0; 
}