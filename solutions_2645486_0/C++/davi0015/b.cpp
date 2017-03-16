#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int T;
	cin >> T;
	
	for (int i=0; i<T; i++)
	{
		int E, R, N;
		cin >> E >> R >> N;
		
		vector <int> v(N);
		priority_queue <pair<int, int> > order;
		
		vector <bool> visited(N);
		vector <int> e(N);
		vector <int> f(N);
		
		for (int j=0; j<N; j++)
		{
			cin >> v[j];
			order.push(make_pair(v[j], j));
		}
		
		int max = 0;
		while (order.size())
		{
			if (!visited[order.top().second])
			{
				int ind = order.top().second;
				int ctLeft = ind-1;
				int refresh = 0;
				while (ctLeft>=0 && refresh<E)
				{
					refresh += R;
					if (visited[ctLeft])
					{
						break;
					}
					ctLeft--;
				}
				
				int Eleft;
				if (refresh>=E || ctLeft==-1)
					Eleft = E;
				else if (refresh+e[ctLeft]>=E)
					Eleft = E;
				else
					Eleft = refresh + e[ctLeft];
					
				int ctRight = ind + 1;
				refresh = 0;
				
				while (ctRight<N && refresh<E)
				{
					refresh += R;
					if (visited[ctRight])
						break;
					ctRight++;
				}
				
				int Eright;
				if (refresh>=E || ctRight==N)
					Eright = 0;
				else if (refresh+Eleft-f[ctRight]>=0)
					Eright = f[ctRight] - refresh;
				else
					Eright = Eleft;
					
				max += v[ind] * (Eleft - Eright);
				e[ind] = Eright;
				f[ind] = Eleft;
				visited[ind] = true;
				
				//cout << ind << " " << order.top().second << " " << e[ind] << " " << f[ind] << endl;
			}
			
			visited[order.top().second] = true;
			order.pop();
		}
		
		cout << "Case #" << i+1 << ": " << max << endl;
	}
}