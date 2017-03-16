#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector < vector<int> > g, gr;
vector<char> used, used3;
vector<int> order, component;

void dfs1(int v) {
	used[v] = true;
	for (size_t i = 0; i<g[v].size(); ++i)
	if (!used[g[v][i]])
		dfs1(g[v][i]);
	order.push_back(v);
}

void dfs2(int v) {
	used[v] = true;
	component.push_back(v);
	for (size_t i = 0; i < gr[v].size(); ++i)
	if (!used[gr[v][i]])
		dfs2(gr[v][i]);
}

int dfs3(int v) {
	used3[v] = true;
	int m = 0;
	for (size_t i = 0; i < g[v].size(); ++i)
	{
		if (!used3[g[v][i]])
			m = max(m, dfs3(g[v][i]) + 1 );
	}
	return m;
}


int main()
{
	ofstream output;
	ifstream input;
	input.open("input.txt");
	output.open("output.txt");

	//	FILE * input;
	//	input = fopen("input.txt","r");

	int T;

	//	fread(&n, sizeof(int), 1, input);cout<<n<<endl; char cc=getchar();

	input >> T;// cout<<n<<endl;
	//cin >> T;


	int n;

	unsigned ans;
	int tmp;
	int maxsize, maxdepth, curdepth;

	for (int t = 0; t < T; ++t)
	{
		input >> n;

		maxsize = 0;
		ans = 0;

		g.clear();
		gr.clear();
		g.resize(n);
		gr.resize(n);
		order.clear();

		for (int i = 0; i < n; ++i)
		{
			input >> tmp;
			g[tmp-1].push_back(i);
			gr[i].push_back(tmp-1);
		}

		used.assign(n, false);
		for (int i = 0; i<n; ++i)
		if (!used[i])
			dfs1(i);
		used.assign(n, false);
		for (int i = 0; i<n; ++i) {
			int v = order[n - 1 - i];
			if (!used[v]) {
				dfs2(v);
				
				
				maxdepth = 0;
				if (component.size() == 2)
				{
					/*for (int j = 0; j < component.size(); ++j)
					{
						//curdepth = 0;
						used3.assign(n, false);
						for (int k = 0; k < component.size(); ++k)
						{
							used3[component[k]] = true;
						}
						//curdepth = max(curdepth, dfs3(component[j]));
						maxdepth = max(maxdepth, dfs3(component[j]));

					}*/

					for (int j = 0; j < component.size(); ++j)
					{
						//curdepth = 0;
						used3.assign(n, false);
						for (int k = 0; k < component.size(); ++k)
						{
							used3[component[k]] = true;
						}
						//curdepth = max(curdepth, dfs3(component[j]));
						maxdepth += dfs3(component[j]);

					}
					
				}
				if (component.size()!=1)
					ans = max(ans, maxdepth + component.size());

				component.clear();
			}
		}

		output << "Case #" << t + 1 << ": " << ans << endl;

		//cout << ans;

	}
	//	fclose(input);
	input.close();
	output.close();
	//	system("pause");
	return 0;
}
