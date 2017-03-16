#include <iostream>
#include <vector>
#include <ostream>
#include <algorithm> // for copy
#include <iterator>
#include <array>

using namespace std;

template <class T> 
std::ostream& operator<<(std::ostream& os, const vector<T>& rhs)
{
	for (const auto& x : rhs)
		os << x << " ";
	return os;
}
using ullong = unsigned long long int;

// Get s+C-1 s+C-2 ... s in base K
ullong ToNumber(int K, int C, int startingat)
{
	ullong p = 1;
	ullong suma = 0;
	for (int i = startingat; i < startingat+C && i < K; ++i)
	{
		suma += p*i;
		p *= K;
	}
	return suma;
}

vector<ullong> Solve(int K, int C, int S)
{
	vector<ullong> toReturn;
	for (int i = 0; i < S && i*C < K; ++i)
	{
		toReturn.push_back(ToNumber(K,C,i*C)+1);
	}
	return toReturn;
}

int main() 
{
	int num;
	cin >> num;
	for (int i = 0; i < num; ++i)
	{
		int K, C, S;
		cin >> K;
		cin >> C;
		cin >> S;
		if (K < C)
			C = K;
		cout << "Case #" << i+1 << ": ";
		if (S*C < K)
			cout << "IMPOSSIBLE" << endl;
		else
			cout << Solve(K,C,S) << endl;
		
	}
	
	
	return 0;
}
