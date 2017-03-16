#include <iostream>
#include <iomanip>
#include <queue>

using namespace std;

int main()
{
	freopen("inp.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int t;
	int mem[1111];
	vector< int > dep[1111];
	cin >> t;
	for (int i=1;i<=t;i++)
	{		
		int n;
		cin >> n;		
		for (int j=0;j<n;j++)
		{
			dep[j+1].clear();
			int x;
			cin >> x;
			for (int h=0;h<x;h++)
			{				
				int z;
				cin >> z;	
				dep[j+1].push_back(z);
			}
		}		
		int bry = 0;
		for (int j=1;j<=n;j++)			
		{
			memset(mem, 0, sizeof(mem));
			queue<int> q;
			q.push(j);
			mem[j] = 0;
			for (;!q.empty();)
			{
				int z = q.front();
				q.pop();										
				for (int h=0;h<dep[z].size();h++)
				{
					int vm = dep[z][h];
					if (!mem[vm])
					{
						q.push(vm);
						mem[vm] = mem[z]+1;
					}
					else
						bry = 1;
				}				
			}
		}
		if (bry)
			cout << "Case #" << i << ": " << "Yes" << endl;
		else
			cout << "Case #" << i << ": " << "No" << endl;
	}
	return 0;
}