#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<fstream>
#include<numeric>
using namespace std;

typedef unsigned long long ulong;

class Solution{
public:
	bool solve(int K, int C,int S)
	{
		if (S < static_cast<ulong>(ceil(static_cast<double>(K) / C)))
			return false;
		if (K > C)
		{
			int n = static_cast<int>(ceil(static_cast<double>(K) / C));
			ulong x = 1;
			for (int i = 1; i <= n - 1; ++i)
			{
				ulong y = static_cast<ulong>(i - 1)*C;
				for (int j = 1; j <= C; ++j)
				{
					x = (x - 1)*K + y + j;
				}
				res.push_back(x);
				x = 1;
			}
			for (int j = (n - 1)*C + 1; j <= K; ++j)
				x = (x - 1)*K + j;
			res.push_back(x);
		}
		else
		{
			ulong x = 1;
			for (int i = 1; i <= K; ++i)
				x = (x - 1) * K + i;
			res.push_back(x);
		}
		return true;
	}
	const vector<ulong>& getResult()const
	{
		return res;
	}
private:
	vector<ulong> res;
};

int main()
{
	//ifstream in("input.txt");
	//ofstream out("large_output.out");
	istream& in = cin;
	ostream& out = cout;
	int T;
	in >> T;
	int K,C,S;
	for (int i = 1; i <= T; ++i)
	{
		Solution A;
		in >> K >> C >> S;
		out << "Case #" << i << ": ";
		if (!A.solve(K, C, S))
			out << "IMPOSSIBLE" << endl;
		else
		{
			const vector<ulong>& res = A.getResult();
			for (int i = 0; i < res.size(); ++i)
				out << res[i] << (i + 1 == res.size() ? '\n' : ' ');
		}
	}
	return 0;
}