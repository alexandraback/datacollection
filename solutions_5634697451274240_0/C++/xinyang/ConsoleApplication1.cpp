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
	fin.open("B-small-attempt0.in");
	ofstream fout;
	fout.open("B-small.txt");
	int t;
	fin >> t;
	for (int T = 1; T <= t; T++){
		fout << "Case #" << T << ": ";

		string s;
		fin >> s;
		int l = s.length();
		int ans = 0;
		for (int i = 0; i < l - 1; i++){
			if (s[i] != s[i + 1]) ans++;
		}
		if (s[l-1] == '-') ans++;
		fout << ans << endl;

	}
	system("PAUSE");
	return 0;
}