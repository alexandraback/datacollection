#define _CRT_SECURE_NO_DEPRECATE
#include <cstring>
#include <fstream>
#include <string.h>
#include <sstream>
#include <string>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <list>

using namespace std;
string operator*(const string& s, unsigned int n) {
	stringstream out;
	while (n--)
		out << s;
	return out.str();
}

bool operator==(const pair<int, char>& p1, const pair<int, char>& p2) {
	return p1.first == p2.first && p1.second == p2.second;
}

pair<int, char> multiply(pair<int, char> p1, pair<int, char> p2)
{
	char c = '1';
	int s = p1.first * p2.first;
	if (p1.second == '1'){
		c = p2.second;
	}
	else if (p2.second == '1'){
		c = p1.second;
	}
	else if (p1.second == p2.second){
		s *= -1;
		c = '1';
	}
	else if (p1.second == 'i' && p2.second == 'j'){
		c = 'k';
	}
	else if (p1.second == 'i' && p2.second == 'k'){
		s *= -1;
		c = 'j';
	}
	else if (p1.second == 'j' && p2.second == 'k'){
		c = 'i';
	}
	else if (p1.second == 'j' && p2.second == 'i'){
		s *= -1;
		c = 'k';
	}
	else if (p1.second == 'k' && p2.second == 'i'){
		c = 'j';
	}
	else if (p1.second == 'k' && p2.second == 'j'){
		s *= -1;
		c = 'i';
	}
	pair<int, char> val = { s, c };
	return val;
}

int main(int argc, char *args[]) {
	std::ifstream infile("input.in");
	freopen("output.out", "w", stdout);
	int t;

	string line;
	std::getline(infile, line);
	t = std::stoi(line);

	for (int k = 0; k < t; ++k)
	{
		int L, X;
		infile >> L >> X;
		string single;
		infile >> single;

		pair<int, char> val = std::make_pair<int, char>(1, '1');
		for (char c : single * (X % 4))
		{
			pair<int, char> curr = { 1, c };
			val = multiply(val, curr);
		}

		pair<int, char> tmp = { -1, '1' };
		bool result = (val == tmp);

		if (result)
		{
			int len = (X % 4 + (X >= 4 ? 4 : 0));
			string S = single * len;
			int p1 = -1, p2 = -1;

			pair<int, char> n1 = { 1, '1' };
			for (int i = 0; i < S.size(); ++i)
			{
				pair<int, char> tmp1 = { 1, S[i] };
				n1 = multiply(n1, tmp1);
				pair<int, char> tmp2 = { 1, 'i' };
				if (n1 == tmp2)
				{
					p1 = i;
					break;
				}
			}

			pair<int, char> n2 = { 1, '1' };
			for (int i = S.size() - 1; i >= 0; --i)
			{
				pair<int, char> tmp1 = { 1, S[i] };
				n2 = multiply(tmp1, n2);
				pair<int, char> tmp2 = { 1, 'k' };
				if (n2 == tmp2)
				{
					p2 = i;
					break;
				}
			}

			result = (p1 > -1 && p2 > -1) && p1 < p2 + (X * L - S.size());
		}

		printf("Case #%d: %s\n", k + 1, result ? "YES" : "NO");
	}

	return 0;
}