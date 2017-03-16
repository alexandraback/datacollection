#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

vector<bool> mark;
vector< vector<int> > G;
int flag;

void dfs(int v)
{
		if(mark[v] == true)	{
			flag = 1;
			return;
		}
		mark[v] = true;
		//curcnt++;
		for(int i = 0; i < G[v].size(); i++)
				dfs(G[v][i] - 1);
}

void main()	{
	char fi[300] = "D:\\Study\\Topcoder\\GCJ\\A-small-practice-Diamond Inheritance0.in";	//1	smal
	char ouci[300] = {"results_A-small-practice-Diamond Inheritance.txt"};//large

	ifstream ifs(fi);
	if(!ifs) {
		cout << "File open error!" << endl;
		return;
	}
	ofstream ou(ouci);  
    if(!ou)	{
		cout << "file open error!\n";
		return;
	}

	int T;
	ifs >> T;

	for(int i = 0; i < T; i++)	{
		int N;
		ifs >> N;
		
		G.clear();
		G.resize(N);

		for(int j = 0; j < N; j++)	{
			int neighbors;
			ifs >> neighbors;

			for(int k = 0; k < neighbors; k++)	{
				int temp;
				ifs >> temp;
				G[j].push_back(temp);
			}
		}

		flag = 0;
		for(int j = 0; j < N; j++)	{
			
			
			if(flag == 0)	{
				mark.assign(N, false);
				dfs(j);
			}
			else
				break;
		}
		
		if(flag == 1)	{
			ou << "Case #" << i + 1 <<": Yes" << endl;
			cout << "Case #" << i + 1 <<": Yes" << endl;
		}
		else	{
			ou << "Case #" << i + 1 <<": No" << endl;
			cout << "Case #" << i + 1 <<": No" << endl;
		}
	}
}