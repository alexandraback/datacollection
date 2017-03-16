
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <list>
#include <queue>
#include <cstring>
using namespace std;

struct node
{
	int val;
	int x;
	int y;
	bool f;
};

vector< vector< node > > v;

bool check( node& n )
{
	int x = n.x, y = n.y, val = n.val;
	bool f = true;
	for ( int i = 0; i < v.size(); ++i )
		if ( !v[i][y].f && v[i][y].val != val )
		{
			f = false;
			break;
		}

	if (f)
	{
		for ( int i = 0; i < v.size(); ++i )
			v[i][y].f = true;
	}

	for ( int i = 0; i < v[0].size(); ++i )
		if ( !v[x][i].f && v[x][i].val != val )
				return f;

	for ( int i = 0; i < v[0].size(); ++i )
		v[x][i].f = true;
	return true;
}

bool ndless( const node* n1, const node* n2 )
{
	return n1->val < n2->val;
}

int main()
{
	ifstream cin("in.txt");
	ofstream cout("out.txt");

	int t;
	cin >> t;

	for ( int q = 0; q < t; ++q )
	{
		int m, n;
		cin >> n >> m;

		v.resize(n);
		for ( int i = 0; i < n; ++i )
			v[i].resize(m);

		vector< node* > nodes;
		nodes.reserve( n*m );

		for ( int i = 0; i < n; ++i )
		{
			for ( int j = 0; j < m; ++j )
			{
				cin >> v[i][j].val;
				v[i][j].f = false;
				v[i][j].x = i;
				v[i][j].y = j;
				nodes.push_back( &v[i][j] );
			}
		}

		sort( nodes.begin(), nodes.end(), ndless );

		bool test = true;
		for ( int i = 0; i < nodes.size(); ++i )
		{
			if ( nodes[i]->f )
				continue;

			if ( !check( *nodes[i] ) )
			{
				test = false;
				cout << "Case #" << q+1 << ": NO\n";
				break;
			}
		}

		if ( test )
			cout << "Case #" << q+1 << ": YES\n";
	}

	return 0;
}


