#include<fstream>
#include<string>
#include<map>
#include<iostream>

using namespace std;

int main ()
{
	//ifstream cin ( "input.txt" );
	//ofstream cout ( "output.txt" );
	int n;
	cin >> n >> ws;
/*	map < char, char > m;
	m [ 'z' ] = 'q';
	m [ 'q' ] = 'z';
	while ( !cin.eof () )
	{
		string s1, s2;
		cin >> s1;
		cin1 >> s2;
		for ( int i = 0; i < s1.size (); ++i )
			m [ s1 [ i ] ] = s2 [ i ];
	}
	for ( map < char, char > :: iterator it = m.begin (); it != m.end (); ++it )
	{
		cout << "if ( s [ i ] == '";
		cout << it->first << "' )" << endl;
		cout << "	decode [ i ] = '" << it->second << "';"<< endl;
	}*/
	for ( int j = 0; j < n; ++j )
	{
		string s;
		getline ( cin ,s );
		string decode = s;
		for ( int i = 0; i < s.size (); ++i )
		{
			if ( s [ i ] == ' ' )
				decode [ i ] = ' ';
			if ( s [ i ] == 'a' )
				decode [ i ] = 'y';
			if ( s [ i ] == 'b' )
				decode [ i ] = 'h';
			if ( s [ i ] == 'c' )
				decode [ i ] = 'e';
			if ( s [ i ] == 'd' )
				decode [ i ] = 's';
			if ( s [ i ] == 'e' )
				decode [ i ] = 'o';
			if ( s [ i ] == 'f' )
				decode [ i ] = 'c';
			if ( s [ i ] == 'g' )
				decode [ i ] = 'v';
			if ( s [ i ] == 'h' )
				decode [ i ] = 'x';
			if ( s [ i ] == 'i' )
				decode [ i ] = 'd';
			if ( s [ i ] == 'j' )
				decode [ i ] = 'u';
			if ( s [ i ] == 'k' )
				decode [ i ] = 'i';
			if ( s [ i ] == 'l' )
				decode [ i ] = 'g';
			if ( s [ i ] == 'm' )
				decode [ i ] = 'l';
			if ( s [ i ] == 'n' )
				decode [ i ] = 'b';
			if ( s [ i ] == 'o' )
				decode [ i ] = 'k';
			if ( s [ i ] == 'p' )
				decode [ i ] = 'r';
			if ( s [ i ] == 'q' )
				decode [ i ] = 'z';
			if ( s [ i ] == 'r' )
				decode [ i ] = 't';
			if ( s [ i ] == 's' )
				decode [ i ] = 'n';
			if ( s [ i ] == 't' )
				decode [ i ] = 'w';
			if ( s [ i ] == 'u' )
				decode [ i ] = 'j';
			if ( s [ i ] == 'v' )
				decode [ i ] = 'p';
			if ( s [ i ] == 'w' )
				decode [ i ] = 'f';
			if ( s [ i ] == 'x' )
				decode [ i ] = 'm';
			if ( s [ i ] == 'y' )
				decode [ i ] = 'a';
			if ( s [ i ] == 'z' )
				decode [ i ] = 'q';
		}
		cout << "Case #" << j + 1 << ": " << decode << endl;
	}
}