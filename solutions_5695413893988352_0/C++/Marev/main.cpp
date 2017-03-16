#include <iostream>
#include <sstream>
#include <string>
#include <cmath>

#include "BigInteger.hh"

using namespace std;

stringstream out;

string c, j;
string resultC, resultJ;

//0: C = J
//1: C > J
//2: C < J


void nextNumber(int t, bool positions[])
{
	if (t == 0)
	{
		bool changed = false;
		if (positions[1] && c.length() > 1 && resultC[1] == '?') { resultC[1] = '0'; changed = true; }
		if (positions[0] && c.length() > 0 && resultC[0] == '?') { resultC[0] = '0'; changed = true;
		}
		if (positions[2] && c.length() > 2 && resultC[2] == '?') { resultC[2] = '0'; changed = true;
		}
		if (changed)
			return;

		if (positions[0]) {
			if (resultC[0] == '9') {
				resultC[0] = '0';
				if (positions[1]) {
					if (resultC[1] == '9') {
						resultC[1] = '0';
						resultC[2]++;
					}
					else
						resultC[1]++;
				}
				else
					resultC[2]++;
			}
			else
				resultC[0]++;
		}
		else if (positions[1]) {
			if (resultC[1] == '9') {
				resultC[1] = '0';
				resultC[2]++;
			}
			else
				resultC[1]++;
		}
		else if (positions[2]) {
			resultC[2]++;
		}
	}
	else
	{
		bool changed = false;
		if (positions[1] && c.length() > 1 && resultJ[1] == '?') { resultJ[1] = '0'; changed = true; }
		if (positions[0] && c.length() > 0 && resultJ[0] == '?') { resultJ[0] = '0'; changed = true;
		}
		if (positions[2] && c.length() > 2 && resultJ[2] == '?') { resultJ[2] = '0'; changed = true;
		}
		if (changed)
			return;
		if (positions[0]) {
			if (resultJ[0] == '9') {
				resultJ[0] = '0';
				if (positions[1]) {
					if (resultJ[1] == '9') {
						resultJ[1] = '0';
						resultJ[2]++;
					}
					else
						resultJ[1]++;
				}
				else
					resultJ[2]++;
			}
			else
				resultJ[0]++;
		}
		else if (positions[1]) {
			if (resultJ[1] == '9') {
				resultJ[1] = '0';
				resultJ[2]++;
			}
			else
				resultJ[1]++;
		}
		else if (positions[2]) {
			resultJ[2]++;
		}
	}
}

void function()
{
	cin >> c >> j;
	resultC = c;
	resultJ = j;
	bool *posC = new bool[3];
	bool *posJ = new bool[3];
	int counterC = 0, counterJ = 0;


	for (int i = 0; i < c.length(); i++) {
		if (c[i] == '?') {
			posC[i] = true;
			counterC++;
		}
		else {
			posC[i] = false;
		}
	}
	for (int i = 0; i < c.length(); i++) {
		if (j[i] == '?') {
				posJ[i] = true;
				counterJ++;
			}
		else {
				posJ[i] = false;
			}
		}

	int totalC = pow(10, counterC);
	int totalJ = pow(10, counterJ);

	int minDiff = 2000;
	int minC = 2000;
	int minJ = 2000;
	string sC = "";
	string sJ = "";

	for (int i = 0; i < totalC; i++)
	{
		nextNumber(0, posC);
		resultJ = j;
		for (int j = 0; j < totalJ; j++)
		{
			nextNumber(1, posJ);
			int nC = stoi(resultC);
			int nJ = stoi(resultJ);

			if (abs(nC - nJ) < minDiff)
			{
				minC = nC;
				minJ = nJ;
				sC = resultC;
				sJ = resultJ;
				minDiff = abs(nC - nJ);
			}
			else if (abs(nC - nJ) == minDiff)
			{
				if (nC < minC) {
					minC = nC;
					minJ = nJ;
					sC = resultC;
					sJ = resultJ;
				}
				else if (nC == minC) {
					if (nJ < minJ) {
						minC = nC;
						minJ = nJ;
						sC = resultC;
						sJ = resultJ;
					}
				}
			}
		}
	}


	out << sC << " " << sJ << endl;
}

int main()
{
	ios_base::sync_with_stdio(0);
	int t;
	cin >> t;

	for (int i = 1; i <= t; i++)
	{
		out << "Case #" << i << ": ";
		function();
	}
	cout << out.str();

	return 0;
}