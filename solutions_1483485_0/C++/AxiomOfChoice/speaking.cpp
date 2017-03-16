#include <iostream>
#include <string>

using namespace std;

#define N 105

char map[] = "yhesocvxduiglbkrztnwjpfmaq";
bool ok0[26], ok1[26];
string line;

int main()
{
	int T;
	cin >> T;
	getline( cin, line );
	for( int t = 1; t <= T; t++ )
	{
		getline( cin, line );
		for( int i = 0; line[i]; i++ ) if( line[i] >= 'a' && line[i] <= 'z' ) line[i] = map[line[i]-'a'];
		cout << "Case #" << t << ": " << line << endl;
	}
	return 0;
}
