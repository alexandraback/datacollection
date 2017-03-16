#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <bitset>
using namespace std;

bitset<30> conf;
set<int> all;
map<int, bitset<30> > dict;
bitset<30> res1;
bitset<30> res2;
bool flag;

void solve(int pos, int N, vector<int>& vi)
{
	if(pos == N)
	{
		int sum = 0;
		for(int i = 0; i < vi.size(); ++i)
			if(conf[i])
				sum += vi[i];
		pair<set<int>::iterator, bool> p = all.insert(sum);
		if(p.second == false)
		{
			res1 = conf;
			res2 = dict.find(sum)->second;
			flag = true;
		}
		else
		{
			dict.insert(make_pair(sum, conf));
		}
		return ;
	}

	solve(pos+1, N, vi);
	if(flag) return;

	conf[pos] = true;
	solve(pos+1, N, vi);
	if(flag) return;

	conf[pos] = false;
}

int main()
{
	int T;
	cin>>T;

	for(int i = 1; i <= T; ++i)
	{
		int N;
		cin>>N;

		vector<int> vi;
		for(int j = 0; j < N; ++j)
		{
			int temp;
			cin>>temp;
			vi.push_back(temp);
		}

		solve(0, N, vi);

		if(flag)
		{
			cout<<"Case #"<<i<<":"<<endl;
			for(int j = 0; j < N; ++j)
				if(res1[j])
					cout<<vi[j]<<" ";
			cout<<endl;
			for(int j = 0; j < N; ++j)
				if(res2[j])
					cout<<vi[j]<<" ";
			cout<<endl;

		}
		else
			cout<<"Impossible"<<endl;

		flag = false;
		res1.reset();
		res2.reset();
		all.clear();
		dict.clear();
		conf.reset();
	}
}