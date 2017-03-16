#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int T,N;
	cin >> T;
	vector< vector<int> > lists;
	vector< vector<int> > rows;
	vector< vector<int> > cols;
	vector<int> counts;
	for( int i = 1 ; i <= T ; i++ )
	{
		lists.clear();
		rows.clear();
		cols.clear();
		counts.clear();
		counts.resize(2501,0);
		cin >> N;
		lists.resize(2*N-1);
		cout << "Case #" << i << ":";
		for( int j = 0 ; j < (2*N - 1) ; j++ )
		{
			lists[j].resize(N);
			for( int k = 0 ; k < N ; k++ )
			{
				cin >> lists[j][k];
				counts[lists[j][k]]++;
			}
		}
		for( int j = 1 ; j < 2501 ; j++ )
		{
			if( counts[j]%2 )
				cout << " " << j;
		}
		cout << endl;
	}
	return 0;
}
