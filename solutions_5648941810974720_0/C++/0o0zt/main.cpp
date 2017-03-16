#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

void print(int cases, vector<int> output)
{
	sort(output.begin(), output.end());
	printf("Case #%d: ", cases);
	for (int i = 0; i < output.size(); i++)
		printf("%d", output[i]);
	printf("\n");
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int cases = 1; cases <= T; cases++)
	{
		string input;
		cin >> input;
		map<char, int> m;
		for (char c : input) m[c]++;
		vector<int> output;
		while (m['X'])//SIX
		{
			output.push_back(6);
			m['S']--;
			m['I']--;
			m['X']--;
		}
		while (m['S'])//SEVEN
		{
			output.push_back(7);
			m['S']--;
			m['E']--;
			m['V']--;
			m['E']--;
			m['N']--;
		}
		while (m['V'])//FIVE
		{
			output.push_back(5);
			m['F']--;
			m['I']--;
			m['V']--;
			m['E']--;
		}
		while (m['F'])//FOUR
		{
			output.push_back(4);
			m['F']--;
			m['O']--;
			m['U']--;
			m['R']--;
		}
		while (m['G'])//EIGHT
		{
			output.push_back(8);
			m['E']--;
			m['I']--;
			m['G']--;
			m['H']--;
			m['T']--;
		}
		while (m['H'])//THREE
		{
			output.push_back(3);
			m['T']--;
			m['H']--;
			m['R']--;
			m['E']--;
			m['E']--;
		}
		while (m['Z'])//ZERO
		{
			output.push_back(0);
			m['Z']--;
			m['E']--;
			m['R']--;
			m['O']--;
		}
		while (m['W'])//TWO
		{
			output.push_back(2);
			m['T']--;
			m['W']--;
			m['O']--;
		}
		while (m['O'])//ONE
		{
			output.push_back(1);
			m['O']--;
			m['N']--;
			m['E']--;
		}
		while (m['N'])//NINE
		{
			output.push_back(9);
			m['N']--;
			m['I']--;
			m['N']--;
			m['E']--;
		}
		print(cases, output);
	}
	return 0;
}