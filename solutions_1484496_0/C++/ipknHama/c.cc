#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
using namespace std;
unordered_map<int,set<int>> m;
int main()
{
	int tn;
	cin >> tn;
	for(int loop = 0; loop < tn; loop++)
	{
		vector<int> v;
		int N;
		cin >> N;
		v.resize(N);
		m.clear();
		for(int i = 0; i < N; i ++)
		{
			cin >> v[i];
		}
		bool done = false;
		int a, b;
		for(int i = 0; i < 1<<20; i ++)
		{
			int s = 0;
			for(int j = 0; j < 20; j ++)
			{
				if (i & (1<<j))
					s += v[j];
			}
			if (m.count(s))
			{
				set<int>& ss = m[s];
				for(set<int>::iterator it = ss.begin(); it != ss.end(); ++it)
				{
					if ((*it & i) == 0)
					done=true;
					a=i;
					b=*it;
					break;
				}
				if (done)
					break;
			}
			m[s].insert(i);
		}
		cout << "Case #" << loop+1 <<":"<<endl;
		if (done)
		{
			for(int i = 0; i < 20; i++)
			{
				if (a&(1<<i))
					cout << v[i] << ' ';
			}
			cout << endl;
			for(int i = 0; i < 20; i++)
			{
				if (b&(1<<i))
					cout << v[i] << ' ';
			}
			cout << endl;
		}
		else
		{
			cout << "Impossible" <<endl;
		}
	}
	return 0;
}
