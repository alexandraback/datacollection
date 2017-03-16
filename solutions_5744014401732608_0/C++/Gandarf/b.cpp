#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<unordered_map>
using namespace std;

int testn;
long long int n, m;
int g[51][51];
long long int a[51];

int main()
{
	ifstream in("B-small-attempt1.in");
	//ifstream in("input.txt");
	ofstream out("output.txt");

	a[1] = a[2] = 1;
	for (int i = 3; i <= 50; ++i)
		a[i] = a[i-1] * 2;
	
	in >> testn;
	for (int test = 1; test <= testn; ++test) 
	{
		// input
		in >> n >> m;

		// impossible
		if (m > a[n])
		{
			out << "Case #" << test << ": " << "IMPOSSIBLE" << endl;
			continue;
		}

		out << "Case #" << test << ": " << "POSSIBLE" << endl;

		// init
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				g[i][j] = (j > i) ? 1 : 0;
			

		vector<int> tt;
		if (m < a[n])
		{
			// 1->n Àº »«´Ù.
			g[1][n] = 0;

			int index = 0;
			int idx = 2;
			long long int mm = m;
			while (mm > 0)
			{
				if (mm % 2 == 1)
					tt.push_back(idx);
				
				mm /= 2;
				idx++;
			}

			for (int i = 2; i < n; ++i)
			{
				bool has = false;
				for (int j = 0; j < tt.size(); ++j)
					if (tt[j] == i)
					{
						has = true;
						break;
					}
				if (!has)
					g[i][n] = 0;
			}
		}

		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
				out << g[i][j];
			out << endl;
		}
	}

	in.close();
	out.close();
	return 0;
}