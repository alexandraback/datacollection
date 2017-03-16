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
	fin.open("B-small.in");
	ofstream fout;
	fout.open("B-small.txt");
	int t;
	fin >> t;
	for (int T = 1; T <= t; T++){
		fout << "Case #" << T << ": ";

		int n;
		fin >> n;
		map<int, int> table;
		for (int i = 0; i < 2 * n - 1; i++){
			for (int j = 0; j < n; j++){
				int a;
				fin >> a;
				if (table.find(a) == table.end()){
					table[a] = 1;
				}
				else table[a] += 1;
			}
		}
		for (map<int, int>::iterator it = table.begin(); it != table.end(); it++){
			if (it->second % 2 == 1){
				fout << it->first << " ";
			}
		}
		fout << endl;


	}
	
	system("PAUSE");
	return 0;
}