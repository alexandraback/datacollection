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

template<class T>
vector<T> getline(istream &str)
{
	str >> ws;
	string line;
	getline(str, line);
	stringstream linestr(line);
	vector<T> res;
	T elem;
	while(!linestr.eof())
	{
		linestr >> elem;
		res.push_back(elem);
	}

	//cerr << line << endl;

	return res;
}
//               abcdefghijklmnopqrstuvwxyz
string cypher = "yhesocvxduiglbkrztnwjpfmaq";


void SolveCase()
{
	vector<string> words = getline<string>(cin);
	
	for(int i = 0; i < words.size(); ++i)
	{
		string decrypted = words[i];
		for(int j = 0; j < decrypted.size(); ++j)
			decrypted[j] = cypher[decrypted[j] - 'a'];

		cout << decrypted << (i == words.size() - 1 ? "" : " ");
	}
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