#include<iostream>
#include<string>
using namespace std;

void check_pancakes( string s, int casenum )
{
	int f = 0, l = s.size() - 1;
	int num_transitions = 0;
	while ( l >= 0 && s[l] == '+' )
		l--;
	if ( l < f )
	{
		cout << "Case #" << casenum << ": " << num_transitions << endl;
		return;
	}
	int i = f;
	for ( ; i < l ; i++ )
		if ( s[i] != s[i+1] )
			num_transitions++;
	cout << "Case #" << casenum << ": " << (num_transitions+1) << endl;
}
int main( int argc, char * argv[] )
{
	int t, n;
	cin >> t;
	int casenum = 1;
	while ( t-- )
	{
		string str;
		cin >> str;
		check_pancakes( str, casenum++ );
	}
}
