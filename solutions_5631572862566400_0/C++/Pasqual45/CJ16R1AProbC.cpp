#include<fstream>
#include<iostream>
#include<sstream>
#include<iomanip>
#include<string>
#include<vector>
#include<list>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#include<functional>
#include<numeric>
#include<bitset>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define mp make_pair

namespace
{
	int N, v[1005];
	vector<int> preds[1005];
	vector<int> twos;

	int t[1005];
	int getCycle(int x)
	{
		memset(t, -1, sizeof(t));
		t[x] = 0;
		int cur = x;
		while (t[v[cur]] < 0)
		{
			t[v[cur]] = t[cur] + 1;
			cur = v[cur];
		}

		int ret = t[cur] - t[v[cur]] + 1;
		return ret;
	}

	int curRes = 0;
	void go(int x)
	{
		const vector<int>& cur = preds[x];
		for (int i = 0; i < cur.size(); ++i)
		{
			int myPred = cur[i];
			if (t[myPred] < 0)
			{
				t[myPred] = t[x] + 1;
				curRes = max(curRes, t[x] + 1);
				go(myPred);
			}
		}
	}

	int chain(int x)
	{
		memset(t, -1, sizeof(t));
		t[x] = t[v[x]] = 0;

		curRes = 0;
		go(x);

		int res = curRes;
		curRes = 0;
		go(v[x]);
		return res + curRes;
	}
}

//int main16R1A_C()
int main()
{
	ifstream fin("C-small-attempt0.in");
	ofstream fout("C-small-attempt0.out");
	//ifstream fin("test.in");
	//ofstream fout("test.out");

	unsigned int numberOfCases;
	fin >> numberOfCases;

	for (unsigned int zz = 1; zz <= numberOfCases; ++zz)
	{
		fin >> N;
		fill(v, v + 1005, 0);
		fill(preds, preds + 1005, vector<int>());
		twos.clear();

		for (int i = 0; i < N; ++i)
		{
			fin >> v[i];
			--v[i];
			preds[v[i]].push_back(i);
		}

		int result = 0;
		for (int i = 0; i < N; ++i)
		{
			int next = getCycle(i);
			result = max(result, next);
		}

		for (int i = 0; i < N; ++i)
		{
			if (v[v[i]] == i && v[i] > i)
				twos.push_back(i);
		}

		int resTwos = twos.size() * 2;
		for (int i = 0; i < twos.size(); ++i)
			resTwos += chain(twos[i]);

		result = max(result, resTwos);
		fout << "Case #" << zz << ": " << result << endl;
	}

	return 0;
}
