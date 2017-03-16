// QR1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool tried[10];
int bffs[10];
vector<int> track[10];
int c_start[10];
int main()
{
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i) 
	{
		int N;
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			int a;
			cin >> a;
			bffs[i] = a;
		}
		for (int i = 0; i < 10; i++)
		{
			track[i].clear();
			c_start[i] = -1;
		}
		for (int i = 0; i < 10; i++)
		{
			tried[i] = false;
		}
		vector<int> curr;
		int n_start = 0;
		while (true)
		{
			if (n_start >= N)break;
			curr.clear();
			curr.push_back(n_start);
			tried[n_start] = true;
			while (true)
			{
				int next = bffs[curr[curr.size() - 1]] - 1;
				tried[next] = true;
				for (int i = 0; i<curr.size(); i++)
				{
					if (next == curr[i])
					{
						c_start[n_start] = i;
					}
				}
				if (c_start[n_start] !=-1)
				{
					vector<int> add;
					for (int i = 0; i<curr.size(); i++)
					{
						add.push_back(curr[i]);
					}
					add.push_back(next);
					track[n_start] = add;
					//if (curr.size() + 1>max) max = curr.size()-temp;
					break;
				}
				curr.push_back(next);
			}
			n_start++;
		}
		int max = 0;
		for (int i = 0; i < N; i++)
		{
			if (c_start[i] != -1) {
				int count = track[i].size() - c_start[i];
				for (int j = 0; j < N; j++)
				{
					int c = 0;
					bool found = false;
					for (int k = 0; k < track[j].size(); k++)
					{
						if (find(track[i].begin(), track[i].end(), track[j][k]) == track[i].end())
						{
							c++;
						}
						else {
							found = true;
							break;
						}
					}
					if(found)
					if (c + count > max)max = c + count;
				}
			}
		}
		cout << "Case #" << i << ": "<<max<<endl;
	}
	return 0;
}

