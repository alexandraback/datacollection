#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

/*struct result {
	bool suprizing;
	int maxscore;
};*/

struct result {
	int supmax;
	int nonsupmax;
};

result calc(int total)
{
	result res;
	int n = total/3;
	switch (total - 3*n) 
	{
	case 0:
		if (n-1 >= 0 && n+1 <= 10)
		{
			res.supmax = n+1;
		}
		else
		{
			res.supmax = -1;
		}
		res.nonsupmax = n;
		return res;
	case 1:
		if (n-1 >= 0)
		{
			res.supmax = n+1;
		}
		else
		{
			res.supmax = -1;
		}
		res.nonsupmax = n+1;
		return res;
	case 2:
		if (n+2 <= 10)
		{
			res.supmax = n+2;
		}
		else
		{
			res.supmax = -1;
		}
		res.nonsupmax = n+1;
		return res;
	default:
		cout<<"wrong!"<<endl;
	}
}

int main()
{
	int T;
	ifstream fin("input.txt");
	
	fin>>T;
	string space;
	getline(fin, space, '\n');
	ofstream fout("output.txt");
	for (int i = 1; i <= T;++i)
	{
		int N,S,P;
		fin>>N>>S>>P;
		int total;
		vector<result> results;
		for (int j = 0; j < N; ++j)
		{
			fin>>total;
			results.push_back(calc(total));
		}
		result cur;
		int ans = 0;
		for (vector<result>::iterator it = results.begin(); it != results.end(); ++it)
		{
			cur = (*it);
			if (cur.nonsupmax >= P)
			{
				++ans;
			}
			else
			{
				if (S > 0 && cur.supmax >= P)
				{
					++ans;
					--S;
				}
			}
		}
		fout<<"Case #"<<i<<": "<<ans<<endl;
	}
}