#include <iostream>
#include <fstream>
#include <string>
#include <map>

#include <algorithm>

using namespace std;

char cTable[ 26] = {
	'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', // a..h
	'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', // i..p
	'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', // q..x
	'a', 'q' };								// y..z

// dummy
void doInsert( map< char, char> &cList, string s1, string s2)
{
	for( const char *i1 = s1.c_str(), *i2 = s2.c_str(); ( *i1) != '\0'; i1++, i2++)
		cList.insert( pair< char, char>( *i2, *i1));
}

void compare()
{
	map< char, char> cList;

	doInsert( cList, "ejp mysljylc kd kxveddknmc re jsicpdrysi", "our language is impossible to understand");
	doInsert( cList, "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "there are twenty six factorial possibilities");
	doInsert( cList, "de kr kd eoya kw aej tysr re ujdr lkgc jv", "so it is okay if you want to just give up");

	for( auto it = cList.begin(); it != cList.end(); ++it)
		cout << ( *it).first << " => " << ( *it).second << endl;
}

// main
string doIt( string &line)
{
	string result = "";
	for( const char *index = line.c_str(); ( *index) != '\0'; index++)
		if( ( *index) >= 'a' && ( *index) <= 'z')
			result += cTable[ ( *index) - 'a'];
		else
			result += ' ';

	return result;
}

int main( const int argc, const char **argv)
{
	if( argc < 2)
		return 0;

	ifstream f( argv[ 1], ifstream::in);

	// get 'T'
	size_t TestCases, i = 1;
	f >> TestCases;

	f.ignore( 256, '\n');

	for( string line; getline( f, line), i <= TestCases; i++)
		cout << "Case #" << i << ": " << doIt( line) << endl;
	
	// compare();

	f.close();
	return 0;
}
