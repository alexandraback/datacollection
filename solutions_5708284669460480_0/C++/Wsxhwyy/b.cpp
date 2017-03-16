#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <queue>

using namespace std;
//ofstream fout("a.out");

string k, l;
int K,L,S;

int tot = 0;
int cor = 0;
int cnt = 0;

void dfs(string s)
{
	if (s.length() == S)
	{
		int cntd = 0;
		for (int i = 0; i < s.length(); i++)
		{
			if (s.substr(i, L) == l)
				cntd++;
		}
		cnt = max(cnt, cntd);
		cor += cntd;
		tot++;
		return;
	}
	for (int i = 0; i < K; i++)
	{
		dfs(s + k[i]);
	}
}

int main()
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> K >> L >> S;
		cin >> k >> l;
		tot = cor = cnt = 0;
		dfs("");
		cout << "Case #" << t << ": " << setprecision(10) << cnt - (cor + 0.0) / tot << endl;
	}
}
