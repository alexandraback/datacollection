#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;


void test( int _case, FILE* pf, ifstream& cin )
{
	int n;
	cin >> n;

	vector<vector<int> > v;
	v.resize(n);

	for ( int i = 0; i < n; i++ )
	{
		int m;
		cin >> m;
		v[i].resize(m);
		for ( int j = 0; j < m; j++ )
		{
			cin >> v[i][j];
			v[i][j]-=1;
		}
	}

	for ( int i = 0; i < n; i++ )
	{
		vector<int> f, nf;
		f.push_back(i);
		set<int> was;
		was.insert(i);

		while ( !f.empty() )
		{

			for ( int j = 0; j < f.size(); j++ )
			{
				int cur = f[j];
				for ( int k = 0; k < v[cur].size(); k++ )
				{
					nf.push_back(v[cur][k]);
					if ( !was.insert(v[cur][k]).second )
					{
						fprintf(pf, "Case #%d: Yes\n", _case );
						return;
					}
				}
			}
			swap(f, nf);
			nf.clear();
		}
	}


	fprintf(pf, "Case #%d: No\n", _case );
}

int main()
{
	ifstream cin("a.in");
	FILE* pf = fopen( "out.txt", "w");
	
	int t;
	cin >> t;

	for ( int i = 0; i < t; i++ )
	{
		test(i+1, pf, cin);		
	}

	return 0;
}