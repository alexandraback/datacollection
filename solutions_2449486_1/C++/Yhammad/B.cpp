#include<iostream>
#include<fstream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<stack>
#include<queue>
#include<cmath>
#include<string>
#include<string.h>
#include<utility>
#include<stdlib.h>
#include<cstdio>
using namespace std;

int main()
{
	ifstream in ("B-large.in");
	ofstream out ("output.txt");
	int t, n, m;
	int lawn[110][110];
	int rows[110], cols[110];
	in >> t;
	for (int z = 1; z <= t; ++ z)
	{
		in >> n >> m;
		memset(rows, 0, sizeof(rows));
		memset(cols, 0, sizeof(cols));
		for (int i = 0; i < n; ++ i)
		{
			for (int j = 0; j < m; ++ j)
			{
				in >> lawn[i][j];
				rows[i] = max(rows[i], lawn[i][j]);
				cols[j] = max(cols[j], lawn[i][j]);
			}
		}
		bool yes = true;
		for (int i = 0; i < n; ++ i)
		{
			for (int j = 0; j < m; ++ j)
			{
				if(lawn[i][j] < rows[i] && lawn[i][j] < cols[j])
				{
					yes = false;
					break;
				}
			}
			if(!yes)
				break;
		}
		out << "Case #" << z << ": " << (yes? "YES" : "NO") << endl;
	}
	return 0;
}