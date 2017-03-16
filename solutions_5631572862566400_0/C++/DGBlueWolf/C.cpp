#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct back_edge
{
	vector<int> back_list;
};

vector<int> bffs;
vector<back_edge> back_bffs;
vector< bool > visited;
int N;

int back_traverse( int start )
{
	int len = 0,tmp = 0;
	if( visited[start] )
		return 0;
	
	//cout << " " << start;
	visited[start] = true;
	
	for( int i = 0 ; i < back_bffs[start].back_list.size() ; i++ )
	{
		if( visited[back_bffs[start].back_list[i]] )
			tmp = 0;
		else
			tmp = back_traverse( back_bffs[start].back_list[i] )+1;
		if( tmp > len )
			len = tmp;
	}
	
	visited[start] = false;
	
	return len;
}
int traverse( int start , int prev , int begin)
{
	int len = 0;
	if( visited[start] )
		return 0;
	
	//cout << " " << start;
	visited[start] = true;
	if( bffs[start] == prev )
	{
		visited[start] = false;
		len = back_traverse( start ) + 1;
		return len;
	}
	else if( visited[bffs[start]] )
		{
			if( bffs[start] == begin )
			{
				visited[start] = false;
				return 1;
			}
			//cout << " again";
			visited[start] = false;
			return 0;
		}
	len = traverse( bffs[start] , start , begin) + 1;
	visited[start] = false;
	return len;
}
		
int main()
{
	int T;
	int len,tmp;
	cin >> T;
	for( int i = 1; i <= T ; i++ )
	{
	 	len = 0;
		bffs.clear();
		back_bffs.clear();
		visited.clear();
		cin >> N;
		bffs.resize(N);
		back_bffs.resize(N);
		visited.resize(N,0);
		//cout << "Testing " << i << endl;
		for( int j = 0 ; j < N ; j++ )
		{
			cin >> bffs[j];
			bffs[j]--;
			back_bffs[bffs[j]].back_list.push_back(j);
		}
		for( int j = 0 ; j < N ; j++ )
		{
			//cout<< j << ":";
			tmp = traverse(j,-1 , j);
			if( tmp > len )
				len = tmp;
			//cout << " len = " << len << endl;
		}
		cout << "Case #" << i << ": " << len << endl;			
	}
	return 0;
}
