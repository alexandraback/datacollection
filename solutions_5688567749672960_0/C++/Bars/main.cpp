#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <functional>
#include <map>
#include <memory>
#include <sstream>
#include <string.h>
#include <cstring>


using namespace std;

int dp[1000010];
const int INF = 100001100;

long long reverse (long long n)
{
	if (n % 10 == 0) 
		return INF;

    int n0 = n;
    int m = 0;
    while (n > 0)
    {
        m = m * 10 + n % 10;
        n /= 10;
    }

    if (m<n0) 
		return dp[m];

    else return INF;
}

int main () 
{
	ifstream in("in.in");
	ofstream out("out.txt");

	int T;

	in >> T;

	for (int i = 0; i <= 10; i++)
		dp[i]= i;

	for (int i = 11; i <= 1000000; ++i)
	{
		dp[i] = min(dp[i-1], (int)reverse(i)) + 1;
	}

	for (int t = 1; t <= T; ++t)
	{
		out << "Case #" << t << ": ";

		long long n;
		stringstream ss;
		string num;

		in >> n;

		out << dp[n] << endl;
	}


	in.close();
	out.close();

	return 0;
}