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
	vector<double> ps(A), logps(A), neglogps(A);
	for(int i = 0; i < A; ++i)
	{
		cin >> ps[i];
		logps[i] = log(ps[i]);
		neglogps[i] = log(1 - ps[i]);
	}

	double expectation = 2 + B;
	
	double tot = 0;
	for(int i = 0; i < A; ++i)
		tot += logps[i];

	cout.precision(10);

	for(int bs = 0; bs < A; ++bs)
	{
		int strokesCorr = B - A + 1 + 2 * bs, strokesIncorr = strokesCorr + B + 1;
		double pcorr = exp(tot);
		expectation = min(expectation, pcorr * strokesCorr + (1 - pcorr) * strokesIncorr);
		tot -= logps[A - bs - 1];
	}

	cout << expectation;
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