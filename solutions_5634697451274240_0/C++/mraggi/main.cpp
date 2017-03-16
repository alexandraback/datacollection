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
	os << "[ ";
	for (const auto& x : rhs)
		os << x << " ";
	os << "]";
	return os;
}

// int NumFlips(const string& bla)
// {
// 	if (bla.size() > 3)
// 		return bla.size();
// 	auto first = bla[0];
// 	if (bla.size() == 1)
// 		return first == '-';
// 	if (bla.size() == 2)
// 		return 1+int(first == '+');
// 	if (bla.size() == 3)
// 		return 2+int(first == '-');
// }

int main() 
{
	int num;
	cin >> num;
// 	getline(cin);
	for (int i = 0; i < num; ++i)
	{
		string bla;
		cin >> bla;
		auto first = bla[0];
		auto current = first;
		int numchanges = 1;
		for (int i = 1; i < bla.size(); ++i)
		{
			if (current != bla[i])
			{
				current = bla[i];
				++numchanges;
			}
		}
		if ((numchanges%2 == 1 && first == '+') || ((numchanges%2 == 0 && first == '-')) )
			--numchanges;
		cout << "Case #" << i+1 << ": " << numchanges << endl;
	}
	
	
	return 0;
}
