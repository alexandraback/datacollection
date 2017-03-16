#include<iostream>
#include<string>
#include<vector>
using namespace std;

void check_fractiles( int casenum, uint64_t k, uint64_t c, uint64_t s )
{
	cout << "Case #" << casenum << ":";
	vector<uint64_t> pos_list;
	uint64_t k_ctr = 0;
	if ( c > k )
		c = k;
	while ( k_ctr < k && s-- )
	{
		uint64_t k_radix = 1;
		uint64_t pos = 0;
		for ( int i = 0; k_ctr < k && i < c ; k_ctr++, i++ )
		{
			pos += k_ctr * k_radix;
			k_radix *= k;
		}
		pos_list.push_back(pos);
	}
	if ( k_ctr == k )
	{
		for ( int i = 0 ; i < pos_list.size() ; i++ )
			cout << " " << (pos_list[i]+1);
		cout << endl;
	}
	else
		cout << " IMPOSSIBLE" << endl;
}
int main( int argc, char * argv[] )
{
	uint64_t t, k, c, s;
	cin >> t;
	int casenum = 1;
	while ( t-- )
	{
		cin >> k >> c >> s;
		check_fractiles( casenum++, k, c, s );
	}
}
