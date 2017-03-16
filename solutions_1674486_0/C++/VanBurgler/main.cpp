#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>

using namespace std;

struct Node
{
	int			visited;
	vector<int> inherits;
	vector<int>	children;
};

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		int N;
		cin >> N;

		vector<Node*> nodes;
		nodes.reserve(N + 1);

		for (int n = 1; n <= N; n++)
		{
			int K;
			cin >> K;

			nodes[n] = new Node();
			nodes[n]->visited = 0;

			for (int k = 0; k < K; k++)
			{
				int j;
				cin >> j;
				nodes[n]->inherits.push_back(j);
			}
		}

		for (int n = 1; n <= N; n++)
			for (int k : nodes[n]->inherits)
				nodes[k]->children.push_back(n);

		bool diamond = false;

		for (int n = 1; n <= N; n++)
			if (nodes[n]->inherits.empty())
			{
				list<int> st;
				st.push_back(n);

				while (!st.empty())
				{
					int index = st.front();
					//cout << "Visiting: " << index << endl;

					Node* node = nodes[index];
					st.pop_front();

					if (node->visited == n)
					{
						diamond = true;
						break;
					}

					node->visited = n;

					for (int other : node->children)
						st.push_back(other);
				}

				if (diamond) break;
			}

		cout << "Case #" << t << ": " << (diamond ? "Yes" : "No") << endl;
	}
}
