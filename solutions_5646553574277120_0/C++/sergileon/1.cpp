#include <cstring>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <vector>
typedef long long LL;
using namespace std;
vector<int> p;
bool used[100];
void Go(int pos)
{
	if (pos == p.size())
		return;
	for(int i = 40; i >= 0; i --)
		if (used[i])
			used[i + p[pos]] = true;
	Go(pos + 1);
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	int t;
	cin >> t;
	for ( int i = 0 ; i < t; i ++)
	{
		p.clear();
		int c , d, v;
		cin >> c >> d >> v;
		for (int j = 0; j < d; j ++)
		{
			int val;
			cin >> val;
			p.push_back(val);
		}
		sort(p.begin(),p.end());
		int cnt = 0;
		while(true)
		{
			memset(used,false,sizeof(used));
			used[0] = true;
			Go(0);
			bool ok = true;
			for( int ii = 1; ii <= v; ii++)
			{
				ok&=used[ii];
			}
			if(!ok)
			{
				for(int ii = 1; ii <= v; ii ++)
				{
					if(!used[ii])
					{
						p.push_back(ii);
						cnt++;
						break;
					}
				}
			}
			else break;
		}
		printf("Case #%d: %d\n", i + 1, cnt);
	}
	return 0;
}