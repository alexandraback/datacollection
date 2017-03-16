#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <bitset>
#include <algorithm>
#include <sstream>

using namespace std;

template<int N>
int FirstBit(const bitset<N> &s, bool value)
{
	for(int i = 0; i < N; ++i)
		if(s[i] == value)
			return i;

	return -1;
}

template<class T>
struct array2d
{
	vector<T> data;
	int rows, columns;

	array2d() {}

	array2d(int size):rows(size), columns(size)
	{
		data.resize(rows * columns);
	}

	array2d(int _rows, int _columns):rows(_rows), columns(_columns)
	{
		data.resize(rows * columns);
	}

	typename vector<T>::iterator operator[](int r)
	{
		return data.begin() + r * columns;
	}
};

void SolveCase()
{
	int A, B;
	cin >> A >> B;

	int recycled = 0;
	int digits[10], pairs[10];
	for(int n = A; n <= B; ++n)
	{
		int ds = 0, r = n;
		while(r > 0)
		{
			digits[ds++] = r % 10;
			r /= 10;
		}

		int ps = 0;
		for(int s = 1; s < ds; ++s)
		{
			if(digits[ds - 1 - s] == 0)
				continue;

			int pair = 0;
			for(int i = 0; i < ds; ++i)
				pair = pair * 10 + digits[(ds * 2 - 1 - s - i) % ds];

			if(pair <= n || pair > B)
				continue;

			bool dejavu = false;
			for(int i = 0; i < ps; ++i)
				if(pair == pairs[i])
				{
					dejavu = true;
					break;
				}

			if(!dejavu)
			{
				pairs[ps++] = pair;
				++recycled;

				//cerr << "(" << n << ", " << pair << ")";
			}
		}
	}

	cout << recycled;
}

void main()
{
	int testCases;
	cin >> testCases;
	for(int i = 0; i < testCases; ++i)
	{
		cout << "Case #" << (i + 1) << ": ";
		SolveCase();
		cout << endl;
	}
}