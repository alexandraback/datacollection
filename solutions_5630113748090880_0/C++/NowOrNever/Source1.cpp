#include <cstdio>
#include <iostream>
#include <map>
using namespace std;

int main()
{
//	freopen("")
	string a;
	map<string, int> mapp;
	while (cin >> a)
	{
		if (mapp[a] == 1)
			cout << a << endl;
		else
			mapp[a] = 1;
	}
	return 0;
}