#include <iostream>
#include <vector>
#include <string>
#include <ostream>
#include <algorithm>
#include <iterator>
#include <array>
#include <set>
#include <discreture/discreture.hpp>

using namespace std;
using namespace dscr;

using combo = std::array<int,3>;
std::ostream& operator<<(std::ostream& os, const combo rhs)
{
	for (const auto& x : rhs)
		os << x+1 << " ";
	return os;
}

// template <class T> 
// std::ostream& operator<<(std::ostream& os, const vector<T>& rhs)
// {
// 	for (const auto& x : rhs)
// 		os << x << " ";
// 	return os;
// }




using ullong = unsigned long long int;

bool IsGood(const vector<combo>& A, int J, int P, int S, int K)
{
	for (int i = 0; i < A.size(); ++i)
	{
		int totalJP = 0;
		int totalJS = 0;
		int totalPS = 0;
		int b = A[i][0];
		int p = A[i][1];
		int s = A[i][2];
		for (int j = i; j < A.size(); ++j)
		{
			if (A[j][0] == b && A[j][1] == p)
				++totalJP;
			if (A[j][0] == b && A[j][2] == s)
				++totalJS;
			if (A[j][1] == p && A[j][2] == s)
				++totalPS;
		}
		
		if (totalJP >= K+1 || totalJS >= K+1 || totalPS >= K+1)
			return false;
	}
	return true;
}

void Solve(int J, int P, int S, int K)
{
	vector<combo> AllCombos;
	for (int j = 0; j < J; ++j)
	{
		for (int p = 0; p < P; ++p)
		{
			for (int s = 0; s < S; ++s)
			{
				combo A = {j,p,s};
				AllCombos.push_back(A);
			}
		}
	}
	
	vector<combo> BestCombo;
	for (int i = 0; i < J; ++i)
	{
		BestCombo.push_back({i,i,i});
	}
	if (S >= 3 && P >= 2)
	{
		BestCombo.push_back({0,1,2});
	}
	
	int best = BestCombo.size();
	for (int i = best+1; i < AllCombos.size()+1; ++i)
	{
// 		cout << "i = " << i << endl;
// 		cout << "Allcombos.size() = " << AllCombos.size() << endl;
		combinations X(AllCombos.size(),i);
		for (auto& x : X)
		{
			auto A = compose(AllCombos,x);
			if (IsGood(A,J,P,S,K))
			{
// 				cout << "new best found" << endl;
				best = i;
				BestCombo = A;
				break;
			}
		}
	}
	cout << best << endl;
	for (auto& a : BestCombo)
	{
		cout << a[0]+1 << " " << a[1]+1 << " "  << a[2]+1 << endl;
	}
	
}

int main() 
{
	int Total;
	cin >> Total;
	for (int i = 0; i < Total; ++i)
	{
		int J,P,S,K;
		cin >> J >> P >> S >> K;
   		cout << "Case #" << i+1 << ": ";
        Solve(J,P,S,K);
	}
	
	
	return 0;
}
