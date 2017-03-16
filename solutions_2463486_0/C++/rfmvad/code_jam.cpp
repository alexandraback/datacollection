#include <algorithm>
#include "BigIntegerLibrary.hh"
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

bool paly(long long n)
{
	long long inv = 0;
	for (long long tmp = n; tmp > 0; tmp /= 10)
		inv = inv * 10 + tmp % 10;
	return n == inv;
}

int main()
{
	ifstream in;
	in.open("D:\\code_jam_in.txt");
	ofstream out;
	out.open ("D:\\code_jam_out.txt");

	int T, ind = 0, ia, ib;
	long long A, B;
	long long arr[40];

	for (long long i = 1; i <= 10000000; i++)
		if (paly(i) && paly(i * i))
			arr[ind++] = i * i;
	
	//for (int i = 0; i < ind; i++)
		//cout << arr[i] << endl;

	in >> T;
	for (int t = 1; t <= T; t++)
	{
		in >> A >> B;

		for (ia = 0; arr[ia] < A && ia < ind; ia++);
		for (ib = ind - 1; arr[ib] > B && ib >= 0; ib--);
		
		out << "Case #" << t << ": " << ib - ia + 1 << endl;
	}

	in.close();
	out.close();
	
	return 0;
}