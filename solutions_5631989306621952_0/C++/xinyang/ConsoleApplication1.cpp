// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>
#include <queue>
#include<set>
#include<stack>
#include<cstdio>
#include <unordered_map>
#include <functional>
#define PI 3.14159265
using namespace std;




int main() {

	std::ios_base::sync_with_stdio(false);
	


	ifstream fin;
	fin.open("A-small.in");
	ofstream fout;
	fout.open("A-small.txt");
	int t;
	fin >> t;
	for (int T = 1; T <= t; T++){
		fout << "Case #" << T << ": ";

		string s;
		fin >> s;
		string ans = string();
		ans+=s[0];
		for (int i = 1; i < s.length(); i++){
			string s1 =string();
			s1 += s[i];
			s1 = s1.append(ans);
			string s2 = ans;
			s2 += s[i];
			if (s1 < s2) ans = s2;
			else ans = s1;
		}
		fout << ans << endl;

	}
	
	system("PAUSE");
	return 0;
}