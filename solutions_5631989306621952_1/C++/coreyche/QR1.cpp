// QR1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string input;
string ori;
void process(int i)
{
	if (input[i] < ori[0])
	{
		ori = ori + input[i];
	}
	else
	{
		ori = input[i] + ori;
	}
}

int main()
{
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		cin >> input;
		ori = string(1, input[0]);
		for (int i = 1; i < input.length(); i++)
		{
			process(i);
		}
		cout << "Case #" << i << ": " << ori << endl;
	}
}

