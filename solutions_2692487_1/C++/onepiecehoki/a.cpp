#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>


using namespace std;


int main()
{
	int T;
	cin >> T;
	for (int t=1;t<=T;++t)
	{
		int A, N;
		vector <int> p;
		
		cin >> A >> N;
		for (int i=0;i<N;++i)
		{
			int temp;
			cin >> temp;
			p.push_back(temp);
		}
		
		vector <int> best_move;
		best_move.push_back(p.size());
		int cur_move = 0;
		int cur_size = A;
		sort(p.begin(), p.end());
		int pos = 0;	

		while (pos < p.size())
		{		
			
			while (pos < p.size() && cur_size > p[pos])
			{
				cur_size += p[pos];
				pos++;
			}
			best_move.push_back(p.size() - pos + cur_move);
			
			cur_size += cur_size-1;
			cur_move++;
			if (cur_move > 1000) break;
		}
		
		int min = 10000;
		for (int i=0;i<best_move.size();++i)
		{
			if (best_move[i] < min)
				min = best_move[i];
		}
		
		cout << "Case #" << t << ": " << min << endl;
		
	}
	
	return 0;
}