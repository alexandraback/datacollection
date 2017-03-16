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
	

	int count = 0;
	int N = 500;
	ofstream ot;
	ot.open("list.txt");
	int length = 30;
	for (int i = 1; i < (1 << (length)); i++){
		int a1 = 0, a2 = 0;
		for (int j = 0; j < length; j++){
			int a = ((i&(1 << j))!=0);
			if (a == 1){
				a1++;
				if (j % 2 == 0) a2--;
				else a2++;
			}
		}
		a1 += 2;
	
		bool ok = false;
		if (a1 % 3 == 0 && a2 == 0) ok = true;
		if (ok){
			cout << "done!" << endl;
			ot << 1;
			for (int j = 0; j < length; j++){
				if (i&(1 << (length - 1 - j))) ot << 1;
				else ot << 0;
			}
			ot << 1<<" 3 2 3 2 7 2 3 2 3";
			ot << endl;
			count++;
		}
		if (count >= N) break;
	}




	/*ifstream fin;
	fin.open("testin.in");
	ofstream fout;
	fout.open("testout.txt");
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
	*/
	system("PAUSE");
	return 0;
}