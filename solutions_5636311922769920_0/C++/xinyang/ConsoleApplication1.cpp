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
	fin.open("D-small-attempt0.in");
	ofstream fout;
	fout.open("D-small.txt");
	int t;
	fin >> t;
	for (int T = 1; T <= t; T++){
		fout << "Case #" << T << ": ";

		long long k, c, s;
		fin >> k>>c>>s;
		long long base = 1;
		for (int i = 0; i < c - 1; i++) base *= k;
		for (int i = 0; i < k; i++) fout << i*base + 1 << " ";
		fout <<endl;

	}
	
	system("PAUSE");
	return 0;
}