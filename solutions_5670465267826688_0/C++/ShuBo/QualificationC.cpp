// CodeJam.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>
#include <assert.h>
#include <unordered_map>
#include <algorithm>
#include <queue>

using namespace std;
typedef long long ll;

void mul(const char cur_ch, const bool neg, const char ch2, char& ret, bool& ret_neg) {
	if (cur_ch == ch2) {
		ret = '1';
		ret_neg = !neg;
		return;
	}

	if (ch2 == '1') {
		ret = cur_ch;
		ret_neg = neg;
		return;
	}

	switch (cur_ch) {
	case '1':
		ret = ch2;
		ret_neg = neg;
		break;
	case 'i':
		switch (ch2) {
		case 'j':
			ret = 'k';
			ret_neg = neg;
			break;
		case 'k':
			ret = 'j';
			ret_neg = !neg;
			break;
		}
		break;
	case 'j':
		switch (ch2) {
		case 'i':
			ret = 'k';
			ret_neg = !neg;
			break;
		case 'k':
			ret = 'i';
			ret_neg = neg;
			break;
		}
		break;
	case 'k':
		switch (ch2) {
		case 'i':
			ret = 'j';
			ret_neg = neg;
			break;
		case 'j':
			ret = 'i';
			ret_neg = !neg;
			break;
		}
		break;
	}
}

bool solve(const string& tok, ll repeat) {
	repeat = repeat >= 4 ? 4 + (repeat % 4) : repeat;
	ll size = tok.size() * repeat;

	if (size < 3) return false;

	vector<ll> is, js;
	char ch = '1', new_ch, toFind = 'i';
	bool neg = false, new_neg = false;

	for (ll i = 0; i < size; ++i) {
		mul(ch, neg, tok[i % tok.size()], new_ch, new_neg);
		ch = new_ch;
		neg = new_neg;

		if (!neg && ch == 'i') is.push_back(i);
		if (!neg && ch == 'k') js.push_back(i);
	}
	
	if (!(ch == '1' && neg)) return false;
	for (ll i : is) {
		if (js.empty()) 
			return false;
		vector<ll>::iterator j = upper_bound(js.begin(), js.end(), i);
		if (j == js.end()) 
			return false;
		//cout << "i: " << i << " j: " << *j << endl;
		if (i < *j) 
			return true;
	}

	return false;
}

int _tmain(int argc, _TCHAR* argv[])
{
	ifstream infile("C-small-attempt0.in");
	ofstream outfile("C-small-attempt0.out");

	string line;
	int numCase;
	getline(infile, line);
	istringstream iss(line);
	iss >> numCase;
	cout << "numCase: " << numCase << endl;

	int curCase = 0;
	while (getline(infile, line)) {
		ll len, repeat;
		stringstream ss2(line);
		ss2 >> len >> repeat;
		printf("Len: %lld, Repeat: %lld\n", len, repeat);

		string tok, str;
		getline(infile, line);
		stringstream ss3(line);
		ss3 >> tok;

		bool ans = 0;
		ans = solve(tok, repeat);
		outfile << "Case #" << ++curCase << ": " << (ans ? "YES" : "NO") << endl;
		//system("pause");
	}

	assert(curCase == numCase);
	infile.close();
	outfile.close();

	system("pause");
	return 0;
}

