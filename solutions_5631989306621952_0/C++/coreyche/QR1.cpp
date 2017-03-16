// QR1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> words;
string input;
void process(string ori, int i)
{
	if (i == input.length() - 1)
	{
		words.push_back(ori + input[i]);
		words.push_back(input[i] + ori);
	}
	else 
	{
		process(ori + input[i], i + 1);
		process(input[i] + ori, i + 1);
	}
}

int main()
{
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		words.clear();
		cin >> input;
		process("", 0);
		sort(words.begin(), words.begin()+words.size());
		cout << "Case #" << i << ": " << words[words.size()-1] << endl;
	}
}

