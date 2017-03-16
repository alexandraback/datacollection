#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include <map>
#include <iostream>
#include <sstream>
#include <queue>
#include <cstring>
#include <ctime>
#include <cfloat>
#include <stack>

using namespace std;

vector<pair<int, int> > infs;
int mat[15][15];
char buff[15];

bool posble(int n)
{
	int i, j;
	bool flag;
	stack<int> stc;
	stc.push(infs[0].second);
	for(j = 1; j < n; j++)
	{
		while(!stc.empty())
		{
			int cc = stc.top();
			if(mat[cc][infs[j].second] == 1)
			{
				stc.push(infs[j].second);
				break;
			}
			else
			{
				stc.pop();
			}
		}
		if(stc.empty())
			return false;
	}
	return true;
}

int main()
{
	freopen("C-small-attempt1.in", "rt", stdin);
	freopen("C-small1.out", "wt", stdout);

	//freopen("C-large-1.in", "rt", stdin);
	//freopen("C-large-1.out", "wt", stdout);

	int i, j, k, kase, inp;
	int n, m;
	int tmp;
	string ret;
	
	scanf("%d", &inp);
	
	for(kase = 1; kase <= inp; kase++)
	{
		ret = "";
		scanf("%d %d", &n, &m);
		memset(mat, 0, sizeof(mat));
		infs.clear();
		for(i = 1; i <= n; i++)
		{
			scanf("%d", &tmp);
			infs.push_back(make_pair(tmp, i));
		}
		for(i = 0; i < m; i++)
		{
			int st, en;
			scanf("%d %d", &st, &en);
			mat[st][en] = mat[en][st] = 1;
		}
		sort(infs.begin(), infs.end());
		do{
			if(posble(n))
			{
				break;
			}
		}while(next_permutation(infs.begin(), infs.end()));

		for(i = 0; i < n; i++)
		{
			sprintf(buff, "%d", infs[i].first);
			ret += buff;
		}

		printf("Case #%d: %s\n", kase, ret.c_str());
	}

	return 0;
}
