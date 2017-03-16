#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <list>
#include <algorithm>
#include <queue>

using namespace std;

#define MAX 10000;
typedef int ARR[10000];

int main()
{
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);

	int Tnum;
	cin >> Tnum;
	for (int i=1; i<=Tnum; i++)
	{
		cout << "Case #" << i << ": ";
		int N;
		cin >> N;
		bool ver[1001];
		vector<int> link[1001];
		for (int j=1; j<=N; j++)
		{
			ver[j]=0;
		}
		for (int j=1; j<=N; j++)
		{
			int num;
			cin >> num;
			for (int k=1; k<=num; k++)
			{
				int ind;
				cin >> ind;
				link[j].push_back(ind);
			}
		}
		bool endflag=0;
		for (int j=1; j<=N; j++)
		{
			if (link[j].size()>1 && !ver[j])
			{
				ver[j]=1;
				bool tmp[1001];
				for (int i=1; i<=N; i++)
					tmp[i]=0;
				queue <int> q;
				q.push(j);tmp[j]=1;
				while (!q.empty() && !endflag)
				{
					int now=q.front();
					for (int k=0; k<link[now].size(); k++)
					{
						if (!tmp[link[now][k]])
						{
							int val=link[now][k];
							q.push(val);
							tmp[val]=1;
							if (link[val].size()>1 && !ver[val])
								ver[val]=1;
						}
						else
						{
							endflag=1;
							break;
						}
					}
					q.pop();
				}
				if (endflag)
					break;
			}
		}
		if (endflag)
			cout << "Yes";
		else
			cout << "No";

		cout << endl;
	}

	return 0;
}