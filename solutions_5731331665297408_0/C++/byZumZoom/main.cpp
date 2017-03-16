#include <vector>
#include <list>
#include <map>
#include <set>
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

using namespace std;

int n, m;
vector <string> zips;
vector < vector <bool> > G;
string global_min_zip, cur_zip;
vector <int> path, parent;

bool check(int next_ind)
{
	if(next_ind == n)
		return true;
    
	if(parent.empty())
		return false;
    
	int v = parent.back(), to = path[next_ind];
//    cout << parent.size() << " " << v << " " << to << endl;
    
	if(G[v][to])
	{
//        cout << "Push back " << to << endl;
        vector <int> old_parent = parent;
		parent.push_back(to);
		if(check(next_ind + 1))
			return true;
//        cout << "Pop back" << endl;
        parent = old_parent;
	}

//    cout << "Pop back" << endl;
	parent.pop_back();
	return check(next_ind);
}

int main() {
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	int T;
	cin >> T;
    
	for(int t = 1; t <= T; ++t)
	{
		cin >> n >> m;
		zips.clear();
		G.clear();
		path.clear();
		zips.resize(n);
		path.resize(n);
		G.resize(n, vector<bool>(n));
		global_min_zip = "";

		for(int i = 0; i < n; ++i)
			cin >> zips[i];

		for(int i = 0; i < m; ++i)
		{
			int a, b;
			cin >> a >> b;
			G[a-1][b-1] = true;
			G[b-1][a-1] = true;
		}

		string minzip = zips[0];
		int begin = 0;
		for(int i = 1; i < n; ++i)
			if(zips[i] < minzip)
			{
				begin = i;
				minzip = zips[i];
			}

		for(int i = 0; i < n; ++i)
			path[i] = i;
		swap(path[0], path[begin]);
        sort(path.begin() + 1, path.end());

		do
		{
			cur_zip = "";
			for(int i = 0; i < n; ++i)
				cur_zip += zips[path[i]];
            parent.clear();
			parent.push_back(path[0]);

//            cout << "Start checking" << endl;
			if(check(1))
			{
				if(global_min_zip == "")
					global_min_zip = cur_zip;
				else
					global_min_zip = min(global_min_zip, cur_zip);
			}
		} while(next_permutation(path.begin() + 1, path.end()));

        cout << "Case #" << t << ": " << global_min_zip << endl;
	}
    
	return 0;
}
