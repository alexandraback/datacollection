#include<fstream>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

int main ()
{
	ifstream cin ( "input.txt" );
	ofstream cout ( "output.txt" );
	int t;
	cin >> t;
	for ( int q = 0; q < t; ++q )
	{
		long long a, b;
		cin >> a >> b;
		long long result = 0;
		for ( int i = a; i <= b; ++i )
		{
			set < int > st;
			vector < int > figure;
			int temp = i;
			while ( temp > 0 )
			{
				figure.push_back ( temp % 10 );
				temp /= 10;
			}
			long long ten = 1;
			long long temp_num = i;
			for ( int p = 0; p < figure.size () - 1; ++p )
				ten *= 10;
			for ( int j = 0; j < figure.size () - 1; ++j )
			{
				temp_num /= 10;
				temp_num += figure [ j ] * ten;
				if ( temp_num > i && temp_num <= b && figure [ j ] != 0 )
					st.insert ( temp_num );
			}
			result += st.size ();
		}
		cout << "Case #" << q + 1 << ": " << result << endl;
	}
}