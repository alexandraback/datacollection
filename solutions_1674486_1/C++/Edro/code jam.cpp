
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;



int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);

	int t;
	cin >> t;

	for (int i = 0; i < t; i++){
		int n;
		cin >> n;

		// graph
		vector<pair<int, int> > graph;
		for (int j = 0; j < n; j++){
			int m;
			cin>> m;

			for(int k = 0; k < m; k++){
				int tmp;
				cin >> tmp;

				//graph.push_back(make_pair(j+1, tmp));
				graph.push_back(make_pair(tmp, j+1));
			}
		}

		// obh
		bool found = false;
		for (int j = 0; j < n; j++)
		{
			vector<bool> mark;
			mark.resize(n);

			queue<int> q;
			q.push(j+1);
			found = false;
			while(!q.empty() && !found){
				int cur = q.front();
				q.pop();
				
				if (mark[cur-1]) {
					found = true;
					break;
				}

				mark[cur-1] = true;
				for(int k = 0; k < graph.size(); k++){
					if (graph[k].first == cur){
						q.push(graph[k].second);
					}
				}
			}
			if (found) break;
		}

		if (found) 
			cout << "Case #" << (i+1) << ": Yes" << endl;
		else
			cout << "Case #" << (i+1) << ": No" << endl;
	}



	return 0;
}

