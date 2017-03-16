#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int case_num = 1; case_num <= T; ++case_num)
	{
		int N;
		cin >> N;
		vector<int> F(N + 1);
		for (int i = 1; i <= N; ++i)
			cin >> F[i];

		vector< vector< vector<int> > > loops(N + 1);
		vector<int> in_loop(N + 1, 0);
		vector< vector<int> > max_tail(N + 1);
		for (int start = 1; start <= N; ++start)
		{
			if (in_loop[start])
				continue;
			vector<int> visited(N + 1, -1);
			int i = start;
			int step = 0;
			while (!in_loop[i] && (visited[i] < 0))
			{
				visited[i] = step;
				++step;
				i = F[i];
			}

			int loop_start = i;
			if (!in_loop[i])
			{
				int loop_size = step - visited[i];
				if (visited[i] > 0)
				{
					if (max_tail[loop_start].empty() || (visited[i] > (max_tail[loop_start].size())))
					{
						cerr << "New max tail ending at " << loop_start << ":";
						max_tail[loop_start] = vector<int>();
						i = start;
						while (i != loop_start) {
							cerr << " " << i;
							max_tail[loop_start].push_back(i);
							i = F[i];
						}
						cerr << endl;
					}
				}

				loops[loop_size].resize(loops[loop_size].size() + 1);
				// loops[loop_size].push_back(vector< vector<int> >());
				cerr << "Loop of size " << loop_size << ": " << loop_start;
				loops[loop_size].back().push_back(loop_start);
				in_loop[loop_start] = loop_size;
				i = F[loop_start];
				while (i != loop_start)
				{
					cerr << " " << i;
					loops[loop_size].back().push_back(i);
					in_loop[i] = loop_size;
					i = F[i];
				}
				cerr << endl;
			}
			else
			{
				if (max_tail[loop_start].empty() || (step > (max_tail[loop_start].size())))
				{
					cerr << "New max tail ending at " << loop_start << ":";
					max_tail[loop_start] = vector<int>();
					i = start;
					while (i != loop_start) {
						cerr << " " << i;
						max_tail[loop_start].push_back(i);
						i = F[i];
					}
					cerr << endl;
				}
			}
		}

		int max_circle = -1;
		for (int size = 1; size <= N; ++size)
			if (!loops[size].empty())
			{
				cerr << "Loop of size " << size << " exists" << endl;
				max_circle = size;
			}

		int recip_size = 0;
		for (int k = 0; k < loops[2].size(); ++k)
		{
			recip_size += 2 + max_tail[loops[2][k][0]].size() + max_tail[loops[2][k][1]].size();
		}
		if (recip_size > max_circle)
			max_circle = recip_size;

		cout << "Case #" << case_num << ": " << max_circle << endl;
	}
	return 0;
}
