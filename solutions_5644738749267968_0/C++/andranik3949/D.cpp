#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ifstream cin("D-small-attempt0.in");
	ofstream cout("D-small-attempt0.out");
	int num;
	cin >> num;
	for ( int i = 0; i < num; i++ )
	{
		int blocks, winOpt = 0, winDec = 0;
		cin >> blocks;
		vector <double> firstBlocks( blocks, 0. );
		vector <double> secondBlocks( blocks, 0. );
		for ( int j = 0; j < blocks; j++ )
			cin >> firstBlocks[j];
		for ( int j = 0; j < blocks; j++ )
			cin >> secondBlocks[j];
		sort( firstBlocks.begin(), firstBlocks.end() );
		sort( secondBlocks.begin(), secondBlocks.end() );
		for ( int j = 0, k = 0, c = 1; j < blocks; j++ )
		{
			if( firstBlocks[j] - secondBlocks[k] > 0 )
			{
				winDec++;
				k++;
			}
			if( firstBlocks[blocks - j - 1] - secondBlocks[blocks - c] > 0 )
				winOpt++;
			else
				c++;
		}
		cout << "Case #" << i + 1 << ": " << winDec << ' ' << winOpt << endl; 
	}
	return 0;
}