#include <iostream>
#include <vector>
#include <set>
using namespace std;



bool process()
{
	int N;
	int	path[1001][1001];
	set<int> seen;
	
	memset(path, 0, sizeof(path));
	
	cin >> N;
	int i,j;
	for (i=1; i<=N; i++)
	{
		int M;
		cin >> M;
		for (j=0; j<M;j++)
		{
			int c;
			cin >> c;
			path[i][c]=1;
		}
	}
#ifdef DEBUG
	for (i=1; i<=N; i++)
	{
		for(j=1; j<=N; j++)
			cout << path[i][j] << " ";
		cout << endl;
	}
#endif
	
	for (i=1; i<=N; i++)
	{
		seen.clear();
		vector<int> nodes;
		nodes.push_back(i);
		int pos = 0;
		while(pos < nodes.size())
		{
			int curr = nodes[pos];
#ifdef DEBUG
			cout << "processing node " << curr << ", seen: " << seen.count(curr) << endl;
#endif
			if (seen.find(curr) != seen.end())
				return true;
			seen.insert(curr);
			for(j=1;j<=N;j++)
				if (path[curr][j])
					nodes.push_back(j);
			pos++;
		}
	}
	return false;
}


int main (int argc, char * const argv[]) {
	int T;
	cin >> T;
	for(int i=1; i<=T; i++)
	{
		bool ret = process();
		if (ret)
			cout << "Case #" << i << ": Yes" << endl;
		else
			cout << "Case #" << i << ": No" << endl;
	}
    return 0;
}
