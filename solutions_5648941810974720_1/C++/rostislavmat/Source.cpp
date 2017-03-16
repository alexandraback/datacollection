#include <cstdio>
#include <vector>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <fstream>
using namespace std;



int main()
{
	ifstream cin("input.txt");
	ofstream cout("output.txt");


	int qq;
	cin >> qq;
	for (int qqq = 0; qqq < qq; qqq++)
	{
		cout << "Case #" << qqq + 1 << ": ";
		string s;
		cin >> s;
		vector <int> x(255, 0);
		for (int i = 0; i < s.length(); i++)
		{
			x[s[i]]++;
		}
		vector <int> ans;
		while (x['Z']>0)
		{
			ans.push_back(0);
			x['E']--;
			x['R']--;
			x['O']--;
			x['Z']--;
		}
		while (x['W']>0)
		{
			ans.push_back(2);
			x['T']--;
			x['O']--;
			x['W']--;
		}
		while (x['G']>0)
		{
			ans.push_back(8);
			x['E']--;
			x['I']--;
			x['G']--;
			x['H']--;
			x['T']--;
		}
		while (x['X']>0)
		{
			ans.push_back(6);
			x['S']--;
			x['I']--;
			x['X']--;
		}
		while (x['S']>0)
		{
			ans.push_back(7);
			x['E']-=2;
			x['S']--;
			x['V']--;
			x['N']--;
		}
		while (x['H']>0)
		{
			ans.push_back(3);
			x['E']-=2;
			x['T']--;
			x['H']--;
			x['R']--;
		}
		while (x['R']>0)
		{
			ans.push_back(4);
			x['F']--;
			x['R']--;
			x['O']--;
			x['U']--;
		}
		while (x['F']>0)
		{
			ans.push_back(5);
			x['E']--;
			x['F']--;
			x['I']--;
			x['V']--;
		}
		while (x['O']>0)
		{
			ans.push_back(1);
			x['E']--;
			x['N']--;
			x['O']--;
		}
		while (x['I'] > 0)
		{
			ans.push_back(9);
			x['I']--;
		}
		sort(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i];
		cout << endl;
	}






	return 0;
}