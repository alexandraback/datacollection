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

int bff[1001];
int visited[1001];
int id[1001];
int dis[1001];
int best[1001];
vector<int> group[1001];

int main() {

	std::ios_base::sync_with_stdio(false);
	


	ifstream fin;
	fin.open("A-small.in");
	ofstream fout;
	fout.open("A-small.out");
	int t;
	fin >> t;
	for (int T = 1; T <= t; T++){
		fout << "Case #" << T << ": ";

		string s;
		fin >> s;
		int l = s.length();
		int num[26];
		int letter[10];
		for (int i = 0; i < 26; i++) num[i] = 0;
		for (int i = 0; i < 10; i++) letter[i] = 0;
		for (int i = 0; i < l; i++){
			num[int(s[i] - 'A')]++;
		}
		letter[0] = num['Z' - 'A'];
		letter[6] = num['X' - 'A'];
		letter[8] = num['G' - 'A'];
		letter[3] = num['H' - 'A'] - letter[8];
		letter[2] = num['W' - 'A'];
		letter[4] = num['U' - 'A'];
		letter[5] = num['F' - 'A'] - letter[4];
		letter[7] = num['V' - 'A'] - letter[5];
		letter[9] = num['I' - 'A'] - letter[5] - letter[6] - letter[8];
		letter[1] = num['O' - 'A'] - letter[0] - letter[2] - letter[4];

		for (int i = 0; i < 10; i++){
			for (int j = 0; j < letter[i]; j++) fout << i;
		}
		fout << endl;
	}
	
	system("PAUSE");
	return 0;
}