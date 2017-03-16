#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

vector<vector<int>> g;
vector<string> index;
vector<bool> used;
string s;
void rec(int x){
	for (int i = 0; i < g[x].size();i++)
		if (!used[g[x][i]]){		
			used[g[x][i]] = true;
			s= s+ index[g[x][i]];
			rec(g[x][i]);
		}
}

void main(){
	ifstream inp("E:\\Note\\input.txt");
	cin.rdbuf(inp.rdbuf());
	ofstream outp("E:\\Note\\output.txt");
	cout.rdbuf(outp.rdbuf());
	int t;
	cin >> t;
	
	for (int x = 0; x < t; x++){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> tempg;
		g = tempg;
		vector<string> temp1;
		index = temp1;
		cin.ignore();
		for (int i = 0; i < n; i++)
		{
			string q;
			getline(cin, q);
			index.push_back(q);
		}
		g.resize(n);
		for (int i = 0; i < m; i++)
		{
			int q, w;
			cin >> q >> w;
			q--; w--;
			g[q].push_back(w);
			g[w].push_back(q);
		}
		vector<bool> temp(n, false);
		vector<string> bla;
		for (int i = 0; i < n; i++){
			used = temp;
			s = index[i];
			rec(i);
			bla.push_back(s);
		}
		sort(bla.begin(), bla.end());
		cout << "Case #" << x + 1 << ": " << bla[0] << endl;
	}
}