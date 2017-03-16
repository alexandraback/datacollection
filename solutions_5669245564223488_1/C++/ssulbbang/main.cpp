#include <iostream>
#include <fstream>
#include <set>
#include <vector>

using namespace std;



long long get_number_of_possibilities(vector<string>& trains)
{
	vector< vector<int> > count;
	vector<int> prev, next;

	count.resize(26);
	prev.resize(26);
	next.resize(26);
	for(int i = 0; i < 26; i++)
	{
		count[i].resize(4);
		prev[i] = -1;
		next[i] = -1;
	}

	for(int i = 0; i < trains.size(); i++)
	{
		set<int> chr;
		int prev_chr = -1;
		for(int j = 0; j < trains[i].size(); j++)
		{
			if(trains[i][j] - 'a' != prev_chr)
			{
				prev_chr = trains[i][j] - 'a';
				if(chr.count(prev_chr) > 0) return 0;
			}

			chr.insert(trains[i][j] - 'a');
		}

		for(set<int>::iterator it = chr.begin(); it != chr.end(); it++)
		{
			int index = 0;
			if(*it != trains[i][0] - 'a')
			{
				index += 1;
				prev[*it] = trains[i][0] - 'a';
			}

			if(*it != trains[i][trains[i].size() - 1] - 'a')
			{
				index += 2;
				next[*it] = trains[i][trains[i].size() - 1] - 'a';
			}

			if(index == 3)
			{
				next[*it] = prev[*it] = -1;
			}
			count[*it][index]++;
		}
	}

	for(int i = 0; i < 26; i++)
	{
		if(count[i][3] > 0 && (count[i][0] > 0 || count[i][1] > 0 || count[i][2] > 0)) return 0;
		if(count[i][1] > 1 || count[i][2] > 1 || count[i][3] > 1) return 0;
	}

	long long ret = 1;
	long long m = 1000000007;
	for(int i = 0; i < 26; i++)
	{
		for(int j = 1; j <= count[i][0]; j++)
		{
			ret = ((ret * j) % m);
		}
	}


	vector<int> visited;
	visited.resize(26);
	for(int i = 0; i < 26; i++)
	{
		if(count[i][0] + count[i][1] + count[i][2] + count[i][3] == 0) visited[i] = 1;
		if(count[i][3] == 1) visited[i] = 1;
	}

	int group_count = 0;
	while(true)
	{
		int start = -1;
		for(int i = 0; i < 26; i++)
		{
			if(!visited[i])
			{
				start = i;
				break;
			}
		}
		if(start == -1) break;
		visited[start] = 1;

		int node;
		node = start;
		while(prev[node] != -1)
		{
			node = prev[node];
			if(visited[node]) return 0;
			visited[node] = 1;
		}
		node = start;
		while(next[node] != -1)
		{
			node = next[node];
			if(visited[node]) return 0;
			visited[node] = 1;
		}
		group_count++;
	}

	for(int i = 1; i <= group_count; i++)
	{
		ret = ((ret * i) % m);
	}
	return ret;
}

int main(int argc, char** argv)
{
	int T, N;

	cin >> T;
	for(int i = 1; i <= T; i++)
	{
		cin >> N;
		vector<string> trains;
		trains.resize(N);
		for(int j = 0; j < N; j++)
		{
			cin >> trains[j];
		}

		cout << "Case #" << i << ": " << get_number_of_possibilities(trains) << endl;
	}
	return 0;
}

