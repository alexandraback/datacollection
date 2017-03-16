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
	fin.open("A-large.in");
	ofstream fout;
	fout.open("A-large.txt");
	int t;
	fin >> t;
	for (int T = 1; T <= t; T++){
		fout << "Case #" << T << ": ";
		long long a;
		fin >> a;
		if (a == 0) fout << "INSOMNIA" << endl;
		else{
			bool count[10];
			for (int i = 0; i < 10; i++) count[i] = false;
			long long m = 1;
			int res = 0;
			while (true){
				long long b = a*m;
				while (b>0){
					int c = b % 10;
					if (count[c] == false){
						count[c] = true;
						res++;
					}
					b /= 10;
				}
				if (res == 10) break;
				else m++;
			}
			fout << m*a << endl;
		}
	}
	system("PAUSE");
	return 0;
}