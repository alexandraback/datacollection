#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

void fill_row( vector<vector<int>> &table, vector<int> &row_or_column, int row )
{
  for( int i = 0; i < row_or_column.size(); i++ )
  {
	table[row][i] = row_or_column[i];
  }
}

void fill_col( vector<vector<int>> &table, vector<int> &row_or_column, int col )
{
  for( int i = 0; i < row_or_column.size(); i++ )
  {
	table[i][col] = row_or_column[i];
  }
}

int main()
{
  int T;
  cin >> T;
  for ( int t = 1; t <= T; t++ )
  {
	int N;
	cin >> N;
	map<int, int> maps;

	for( int i = 0; i < N * (2 * N - 1); i++ )
	{
	  int num;
	  cin >> num;
	  if ( maps.find( num ) != maps.end() )
	  {
		maps[ num ] = maps[ num ] + 1;
	  }
	  else
	  {
		maps[ num ] = 1;
	  }
	}
	vector<int> ans;
	for ( auto v : maps )
	{
	  if ( v.second % 2 == 1 )
	  {
		ans.push_back( v.first );
	  }
	}
	sort( ans.begin(), ans.end() );

	cout << "Case #" << t << ":";
	for ( auto v : ans )
	{
	  cout << " " << v;
	}
	cout << endl;
  }
}
