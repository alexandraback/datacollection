#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	int T;
	cin>>T;
	for (int t = 1; t <= T; ++t)
	{
		int N;
		cin>>N;
		map<int,int> count;
		for (int i = 0; i < 2*N-1; ++i)
		{
			int a;
			for (int j = 0; j < N; ++j)
			{
				cin>>a;
				count[a]++;
			}
		}
		vector<int> toSort;
		for (map<int,int>::iterator it = count.begin(); it != count.end(); ++it)
		{
			if (it->second % 2 == 1)
				toSort.push_back(it->first);
		}
		sort(toSort.begin(), toSort.end());
		cout<<"Case #"<<t<<": ";
		for (int i = 0; i < toSort.size(); ++i)
		{
			cout<<toSort[i]<<" ";
		}
		cout<<'\n';
	}
}