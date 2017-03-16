#include <iostream>
#include <stack>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

#define A first
#define B second

class comp
{
	public:
	bool operator() (const int& a, const int& b) const
	{
		return a > b;
	}
};

map<int, set<int> > a;
priority_queue<int, vector<int>, comp> Q;

int main()
{
	int i, j, k, N, T;
	int num[500];
	set<int>::iterator itr;
	cin >> T;
	for (int t=1; t<=T; ++t)
	{
		vector<int> res;
		a.clear();
		scanf("%d", &N);
		for (i=0; i<N; ++i)
			scanf("%d", &num[i]);
		Q.push(0);
		k = 1;
		while (!Q.empty())
		{
			j = Q.top();
			Q.pop();
			//cout << "elemen = " << j << endl;
			for (i=0; i<N; ++i)
			{
				//cout << "num[i]+j = " << num[i]+j << endl;
				if (a.find(num[i]+j) == a.end())
				{
					set<int> S = a[j];
					if (S.find(num[i]) == S.end())
					{
						S.insert(num[i]);
						a[num[i]+j] = S;
						Q.push(num[i]+j);
						//cout << "push " << num[i]+j << endl;
					}
				}
				else
				{
					set<int> S = a[j], S2 = a[num[i]+j];
					if (S.find(num[i]) == S.end())
					{
						for (itr = S.begin(); itr!=S.end(); ++itr)
							if (S2.find(*itr)!=S2.end())
								S2.erase(*itr);
							else
								res.push_back(*itr);
						if (S2.find(num[i])!=S2.end())
							S2.erase(num[i]);
						else
							res.push_back(num[i]);
						sort(res.begin(), res.end());
						if (S2.size() && res.size())
						{
							printf("Case #%d:\n", t);
							printf("%d", res[0]);
							for (i=1; i<res.size(); ++i)
								printf(" %d", res[i]);
							printf("\n");
							res.clear();
							for (itr = S2.begin(); itr!=S2.end(); ++itr)
								res.push_back(*itr);
							sort(res.begin(), res.end());
							printf("%d", res[0]);
							for (i=1; i<res.size(); ++i)
								printf(" %d", res[i]);
							printf("\n");
							while (!Q.empty())
								Q.pop();
							k = 0;
							break;
						}
					}
				}
			}
		}
		if (k)
			printf("Case #%d: Impossible\n", t);
	}
	return 0;
}
