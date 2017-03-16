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
	fin.open("C-small-attempt0 (2).in");
	ofstream fout;
	fout.open("C-small-attempt0 (2).out");
	int t;
	fin >> t;
	for (int T = 1; T <= t; T++){
		fout << "Case #" << T << ": ";

		int n;
		fin >> n;
		set<string> firstH;
		set<string> secondH;
		string data[18][2] ;
		for (int i = 0; i < n; i++){
			string s1, s2;
			fin >> s1 >> s2;
			data[i][0] = s1;
			data[i][1] = s2;
			firstH.insert(s1);
			secondH.insert(s2);
		}
		int nF = firstH.size();
		int nS = secondH.size();
		int maxsize = n;
		for (int mask = 1; mask < (1 << n); mask++){
			set<string> firstS;
			set<string> secondS;
			firstS.clear();
			secondS.clear();
			
			int temp = 0;
			for (int i = 0; i < n; i++){
				if ((1 << i)&mask){
					firstS.insert((data[i][0]));
					secondS.insert((data[i][1]));
					temp++;
				}
			}
			if (firstS.size() == nF && secondS.size() == nS){
				if (temp < maxsize){
					maxsize = temp;
				}
			}
		}
		fout << n - maxsize << endl;
	

	}
	
	system("PAUSE");
	return 0;
}