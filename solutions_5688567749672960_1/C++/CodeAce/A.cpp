#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

typedef long long LL;
ifstream fin("A-large.in");
ofstream fout("A-large.out");


#define MAX 1000000

long dist(LL x)
{
	if (x <= 19)
		return x;

	LL c = 0;
	if (x % 10 == 0) {
		x--;
		c++;
	}

	stringstream ss;
	ss << x;
	string str = ss.str();
	
	int len = str.length();

	LL a = 0, b = 0;
	for (int i = len / 2 - 1; i >= 0; i--)
		a = a * 10 + (str.at(i) - '0');
	for (int i = len / 2; i < len; i++)
		b = b * 10 + (str.at(i) - '0');

	LL y = 1;

	for (int i = 1; i < len; i++)
		y *= 10;

	if (a == 1)
		c--;
	
	return a + b + c + dist(y);
}

void solve()
{
	LL n;

	fin >> n;
	fout << dist(n) << endl;
}

int main()
{

	int tests, ct;

	fin >> tests;

	for (ct = 1; ct <= tests; ct++) {
		fout << "Case #" << ct << ": ";
		solve();
	}

	return 0;
}