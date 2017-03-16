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

std::ostream& operator<<(std::ostream& os, const vector<bool>& rhs)
{
	for (const auto& x : rhs)
		os << x;
	return os;
}

using ullong = unsigned long long int;

ullong InterpretBaseK(ullong k, const vector<bool>& bla)
{
	ullong suma = 0;
	ullong power = 1;
	for (auto it = bla.rbegin(); it != bla.rend(); ++it)
	{
		suma += power*static_cast<ullong>(*it);
		power *= k;
	}
	return suma;
}

ullong GetDivisor(ullong n)
{
	auto m = sqrt(n);
	for (ullong i = 3; i < m; ++i)
	{
		if (n%i == 0)
			return i;
	}
	return -1;
}

vector<ullong> GetCertificates(const vector<bool>& v)
{
	vector<ullong> toReturn(9,-1);
	for (int i = 2; i < 11; ++i)
	{
		int j = i-2;
		auto t = InterpretBaseK(i,v);
		
// 		cout << w << " is " << t << " in base " << i << endl;

		toReturn[j] = GetDivisor(t);
		if (toReturn[j] == -1)
		{
// 			cout << "\t but it's fucking prime!" << endl;
			return toReturn;
		}
	}
	return toReturn;
}

void printAllBases(const vector<bool>& A)
{
	cout << A << endl;
	for (int i = 2; i < 11; ++i)
	{
		cout << "In base " << i << " it is " << InterpretBaseK(i,A) << endl;
	}
}

void next(vector<bool>& uchus)
{
	auto N = uchus.size();
	
	for (int i = 2; i < N-2; i += 2)
	{
		if (uchus[i] == 0)
		{
			uchus[i] = 1;
			uchus[i+1] = 1;
			for (int w = 2; w < i; ++w)
				uchus[w] = 0;
			break;
		}
	}
}


void printSolution(int N, int J)
{
	vector<bool> uchus(N,0);
	uchus[0] = 1;
	uchus[1] = 1;
	uchus[N-1] = 1;
	uchus[N-2] = 1;
	for (int j = 0; j < J; ++j)
	{
		cout << uchus << " 3 4 5 6 7 8 9 10 11" << endl;
// 		for (int b = 2; b < 11; ++b)
// 		{
// 			auto t = InterpretBaseK(b,uchus);
// 			if (t % (b+1) != 0)
// 			{
// 				cout << "FUCKING EROR at base " << b << endl;
// 				cout << "\tbecause t = " << t << endl;
// 				cout << "\tand uchus = " << uchus << endl;
// 			}
// 		}
		next(uchus);
	}
}

int main() 
{
	int num;
	cin >> num;
// 	getline(cin);
	for (int i = 0; i < num; ++i)
	{
		int N,J;
		cin >> N;
		cin >> J;
		
		cout << "Case #" << i+1 << ": " << endl;
		printSolution(N,J);
	}
	
	
	return 0;
}
