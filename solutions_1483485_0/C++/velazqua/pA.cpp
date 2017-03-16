#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main ()
{
	map<char,char> M;
	vector<string> before, after;
	before.push_back( "ejp mysljylc kd kxveddknmc re jsicpdrysi" );
	before.push_back( "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd" );
	before.push_back( "de kr kd eoya kw aej tysr re ujdr lkgc jv" );
	after.push_back( "our language is impossible to understand" );
	after.push_back( "there are twenty six factorial possibilities" );
	after.push_back( "so it is okay if you want to just give up" ); 
	for( int i=0; i<3; ++i )
		for( int j=0; j<(int)before[i].size(); ++j )
			M[before[i][j]] = after[i][j];
	
	M['z'] = 'q';
	M['q'] = 'z';
	M[' '] = ' ';
	//for( map<char,char>::iterator it=M.begin(); it!= M.end(); ++it )
	//	cout << it->first << " " << it->second << endl;
	int T;
	cin >> T;
	string msg;
	for( int i=0; i<T; ++i )
	{
		if( i == 0 )
			cin.ignore();
		getline( cin, msg );
		int size = msg.size();
		for( int j=0; j<size; ++j )
			if( M[msg[j]] )
				msg[j] = M[msg[j]];
		cout << "Case #" << i+1 << ": " << msg << endl;
	}
}
