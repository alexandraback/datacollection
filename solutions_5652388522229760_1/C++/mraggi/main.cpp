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


vector<string> readfromstdin()
{
	clock_t start = clock();
	string bla = "";
	vector<string> toreturn;
//  	toreturn.reserve(10000);
	while (cin)
	{
		getline(cin,bla);
		toreturn.push_back(bla);
	}
	return toreturn;
}

vector<short> GetDigits(int t)
{
// 	cout << "digits of " << t << "; ";
	vector<short> digits;
	while (t != 0)
	{
		digits.push_back(t%10);
		t /= 10;
	}
// 	cout << digits << endl;
	return digits;
}

long int PerformTest(long int t)
{
	vector<short> digits(10,0);
	for (int i = 1; i < 100; ++i)
	{
		for (auto x : GetDigits(i*t))
		{
			digits[x] = 1;
		}
		if (digits[0] && digits[1] &&digits[2] && digits[3] &&digits[4] && digits[5] &&digits[6] && digits[7] && digits[8] && digits[9])
		{
			return i*t;
		}
	}
	return -1;
}

int main() 
{
	int num;
	cin >> num;
	for (int i = 0; i < num; ++i)
	{
		int t;
		cin >> t;
		cout << "Case #" << i+1 << ": ";
		if (t == 0)
		{
			cout << "INSOMNIA" << endl;
		} else
		{
			cout << PerformTest(t) << endl;
		}
	}
	
	
	return 0;
}
