#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

void main(){
	ifstream inp("E:\\Note\\input.txt");
	cin.rdbuf(inp.rdbuf());
	ofstream outp("E:\\Note\\output.txt");
	cout.rdbuf(outp.rdbuf());
	int t;
	cin >> t;
	for (int cas = 0; cas < t; cas++){
		int n;
		int ans = 0;
		cin >> n;
		cin.ignore();
		bool next = false;
		vector<vector<int>> v(n);
		vector<char> check;
		for (int i = 0; i < n; i++){
			string s;
			getline(cin, s);
			int j = 0;
			while (j != s.length()){
				int c = 1;
				while ((j + 1) != s.length() && s[j + 1] == s[j]){
					j++;
					c++;
				}
				v[i].push_back(c);
				if (i == 0)
					check.push_back(s[j]);
				else
					if (v[i].size() -1 >= check.size() || check[v[i].size() - 1] != s[j])
					{
						next = true;
						cout << "Case #" << cas + 1 << ": " << "Fegla Won" << endl;
						break;
					}
				j++;
			}
		}
		if (next) continue;

		int p = v[0].size();
		for (int i = 1; i < n; i++)
			if (v[i].size() != p){
				next = true;
				cout << "Case #" << cas + 1 << ": " << "Fegla Won" << endl;
				break;
			}
		if (next)
			continue;

		for (int i = 0; i < v[0].size(); i++)
		{

			int min_sum = INT_MAX;
			int sum = INT_MAX - 1;;
			for (int j = 1; j <= 100; j++)	{
				sum = 0;
				for (int k = 0; k < n; k++){
					sum += abs(v[k][i] - j);
				}
				if (min_sum>sum) min_sum = sum;
			}
			ans += min_sum;
		}

		if (!next)
			cout << "Case #" << cas + 1 << ": " << ans << endl;
	}
}