#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
using namespace std;

int v[105];


map <string, int> M;
map <string, double> prob;


string getS(vector <int> x)
{
	string ans;
	ans.resize(x.size() );
	for (int i = 0; i < x.size(); i++)
		ans[i] = x[i] + '0';
	return ans;
}
vector <int> getV(string s)
{
	vector <int> ans;
	ans.resize(s.length() );
	for (int i = 0; i < s.length(); i++)
		ans[i] = s[i] - '0';
	return ans;
}

void genAll(int k, int x, vector <int> v)
{
	if (k == 0)
	{
		sort(v.begin(), v.end() );
		string S = getS(v);
		M[S]++;
		return;
	}
	for (int i = 2; i <= x; i++)
	{
		v.push_back(i);
		genAll(k - 1, x, v);
		v.pop_back();
	}
}

int getAns(vector <int> v, int x, int pos, int cur = 1)
{
	if (pos == v.size() )
	{
		if (cur == x)
			return 1;
		return 0;
	}
	int ans = getAns(v, x, pos + 1, cur);
	ans += getAns(v, x, pos + 1, cur * v[pos] );
	return ans;
}

double getProb(vector <int> v, int x)
{
	int len = v.size();
	int all = 1 << len;
	double ans = (double) getAns(v, x, 0) / (double) all;
	return ans;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++)
	{
		printf("Case #%d: \n", t + 1);
		int r, n, m, k;
		scanf("%d%d%d%d", &r, &n, &m, &k);

		genAll(n, m, vector <int> () );

		for (int i = 0; i < r; i++)
		{
			prob.clear();

			for (int j = 0; j < k; j++)
			{
				scanf("%d", &v[i] );
				for (auto it = M.begin(); it != M.end(); it++)
				{
					vector <int> ve = getV(it->first);
					int cnt = it->second;

					double x = getProb(ve, v[i] ) * cnt;
					if (!prob.count(it->first) )
						prob[it->first] = 1;
					prob[it->first] *= x;
				}
			}
			string ans = "";
			double ansp = -1;
			for (auto it = prob.begin(); it != prob.end(); it++)
			{
				if (it->second > ansp)
				{
					ansp = it->second;
					ans = it->first;
				}
			}
			printf("%s\n", ans.c_str() );
		}


	}



	return 0;
}