// CodeJam2015_1B.cpp : Defines the entry point for the console application.
//

#include "vector"
#include "string"
#include "set"
#include "map"
#include "sstream"
#include "algorithm"
#include "cmath"
#include "cassert"
#include "iostream"
#include "numeric"
#include "fstream"
#include "queue"
#include <functional>
#include  <climits>

#ifdef __GNUC__
#include  <tr1/unordered_map>
#define unordered_map tr1::unordered_map
#else
#include <unordered_map>
#endif

using namespace std;

#define int64 long long
#define F(vec, index) for (int index = 0; index  < vec.size(); ++index)
#define F2(index, vec) for (int index = 0; index  < vec.size(); ++index)
#define F3(index, from, vec) for (int index = from + 1; index  < vec.size(); ++index)

int64 mi;

/*int64 rec(int64 target, int64 c)
{

	str.clear();

}*/

int main(int argc, char* argv[])
{
	int T; 
	fstream cin("input.txt");
	fstream cout("out.txt", fstream::out);
	cin >> T;
	
	for (int t = 0; t < T; ++t)
	{
		std::cout << t << endl;
		int64 n;
		cin >> n;

		vector<int64> dp(n + 1, n);
		F2(i, dp) dp[i] = i;
		stringstream str;

		for (int64 i = 1; i <= n; ++i)
		{

			stringstream str;
			str << i;
			string s = str.str();
			reverse(s.begin(), s.end());

			stringstream str2;
			str2 << s;
			int64 rI;
			str2 >> rI;

			dp[i] = min(dp[i], dp[i - 1] + 1);
			if (rI <= n)
			{
				dp[rI] = min(dp[i] + 1, dp[rI]);
			}
		}
		

		//rec(n, 0);
		cout << "Case #" << t + 1 << ": " << dp[n] << endl;
	}
	return 0;
}