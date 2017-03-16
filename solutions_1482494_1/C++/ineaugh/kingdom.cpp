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

int NO = 1000000;

int PlayR(vector<int> &one, vector<int> &two, vector<int> got, int stars)
{
	int N = got.size();
	if(stars == 2 * N)
		return 0;

	int minp = NO;
	int toPlay = -1;

	for(int i = 0; i < N && toPlay == -1; ++i)
		if(got[i] == 0 && two[i] <= stars)
		{
			got[i] = 2;
			int rest = PlayR(one, two, got, stars + 2);
			if(rest != NO)
				minp = min(minp, rest + 1);
			got[i] = 0;
		}

	for(int i = 0; i < N && toPlay == -1; ++i)
		if(got[i] == 0 && one[i] <= stars || got[i] == 1 && two[i] <= stars)
		{
			++got[i];
			int rest = PlayR(one, two, got, stars + 1);
			if(rest != NO)
				minp = min(minp, rest + 1);
			--got[i];
		}

	return minp;
}

void SolveCase()
{
	int N;
	cin >> N;
	cerr << N << " ";
	vector<int> one(N), two(N);
	for(int i = 0; i < N; ++i)
		cin >> one[i] >> two[i];

	int stars = 0, played = 0;
	vector<int> got(N, 0);

	//int minp = PlayR(one, two, got, 0);
	//if(minp == NO)
	//	cout << "Too Bad";
	//else
	//	cout << minp;

	//return;

	while(stars < 2 * N)
	{
		int toPlay = -1;
		for(int i = 0; i < N && toPlay == -1; ++i)
			if(got[i] == 0 && two[i] <= stars)
				toPlay = i;

		if(toPlay != -1)
		{
			got[toPlay] = 2;
			stars += 2;
			++played;
			continue;
		}

		for(int i = 0; i < N && toPlay == -1; ++i)
			if(got[i] == 1 && two[i] <= stars)
				toPlay = i;

		if(toPlay != -1)
		{
			++got[toPlay];
			stars += 1;
			++played;
			continue;
		}

		int max2 = -1;

		for(int i = 0; i < N; ++i)
			if(got[i] == 0 && one[i] <= stars && two[i] > max2)
			{
				toPlay = i;
				max2 = two[i];
			}

		if(toPlay != -1)
		{
			++got[toPlay];
			stars += 1;
			++played;
			continue;
		}

		cout << "Too Bad";
		return;
	}

	cout << played;
}

void main()
{
	int testCases;
	cin >> testCases;
	for(int i = 0; i < testCases; ++i)
	{
		cout << "Case #" << (i + 1) << ": ";
		SolveCase();
//		cerr << i << " ";
		cout << endl;
	}
}