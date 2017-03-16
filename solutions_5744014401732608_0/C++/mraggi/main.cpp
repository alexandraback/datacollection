#include <iostream>
#include <vector>
#include <string>
#include <ostream>
#include <algorithm>
#include <iterator>
#include <array>
// #include <discreture/discreture.hpp>

using namespace std;
// using namespace dscr;

template <class T> 
std::ostream& operator<<(std::ostream& os, const vector<T>& rhs)
{
	for (const auto& x : rhs)
		os << x << "";
	return os;
}

using ullong = unsigned long long;

vector<unsigned short> NumberBaseB(ullong n, short b)
{
	vector<unsigned short> toReturn;
	while (n != 0)
	{
		toReturn.push_back(n%b);
		n /= b;
	}
	std::reverse(toReturn.begin(), toReturn.end());
	return toReturn;
}

ullong Count(const vector<vector<bool>>& G)
{
	int n = G.size();
	vector<ullong> dp(n,0);
	dp[0] = 1;
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (G[j][i])
				dp[i] += dp[j];
		}
	}
	return dp[n-1];
}

void Solve(ullong B,ullong M)
{
	ullong tpBm2 = 1;
	
	if (B > 1)
		tpBm2 = ullong(1) << (B-2);
	if (tpBm2 < M)
	{
		cout << "IMPOSSIBLE" << endl;
		return;
	}
	
	cout << "POSSIBLE" << endl;
	vector<vector<bool>> G(B,vector<bool>(B,0));
	for (int i = 0; i < B; ++i)
	{
		for (int j = i+1; j < B; ++j)
		{
			G[i][j] = 1;
		}
	}
	
	for (int i = 0; i < B; ++i)
	{
		for (int j = i+1; j < B; ++j)
		{
			G[i][j] = 1;
		}
	}
	
	auto V = NumberBaseB(tpBm2 - M, 2);
	std::reverse(V.begin(), V.end());
// 	cout << "tpBm2 = " << tpBm2 << endl;
// 	cout << "V = " << V << endl;
	for (int i = 0; i < V.size(); ++i)
	{
		if (V[i])
			G[i+1][B-1] = 0;
	}
	
	for (int i = 0; i < B; ++i)
		cout << G[i] << endl;

	
	if (M != Count(G))
		cout << "ERRORRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR" << endl;
	

	
}

int main() 
{
	int Total;
	cin >> Total;
	for (int i = 0; i < Total; ++i)
	{
		int M,B;
		cin >> B;
		cin >> M;
		cout << "Case #" << i+1 << ": ";
        Solve(B,M);
// 		cout << endl;
		
	}
	
	
	return 0;
}
