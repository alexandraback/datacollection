#include <bits/stdc++.h>

using namespace std;

ifstream fin("A-small-attempt0.in");
ofstream fout("output.txt");

// #define fin cin
// #define fout cout

long long int FindCost(vector<short>& num)
{
	if(num.size() == 1 )return num[0];
	long long int val = 0;
	vector<short> zero(num.size(), 0);
	zero[0] = 1;
	bool flip = false;
	for (int i = 0; i < num.size(); ++i)
	{
		int pow = 1;
		int to = min(i, (int)num.size() - i - 1);
		for (int j = 0; j < to; ++j)
		{
			pow *= 10;
		}
		int offset = num[i] - zero[i];
		if(offset != 0 && i < num.size() / 2)flip = true;
		val += offset * pow;
	}
	cerr<<endl;
	vector<short> newVec(num.size() - 1, 9);
	val += 1;
	if(flip)val += 1;
	val += FindCost(newVec);
	return val;
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	int t;
	fin>>t;
	int u = 0;
	while(u++ < t)
	{
		long long int n;
		fin>>n;
		vector<short> vec;
		while(n > 0)
		{
			vec.push_back(n % 10);
			n /= 10;
		}
		reverse(vec.begin(), vec.end());
		fout<<"Case #"<<u<<": "<<FindCost(vec)<<endl;
	}
	return 0;
}
