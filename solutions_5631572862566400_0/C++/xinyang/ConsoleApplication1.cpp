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

bool visited[11];
int counter;
int bff[11];
vector<int> test;
void dfs(int l,int n,int v){
	if (l == 0){
		bool ok = true;
		
		for (int i = 1; i < v-1; i++){
			if ((bff[test[i]] != test[i + 1]) && (bff[test[i]] != test[i-1])){
				ok = false;
				break;
			}
		}
		if ((bff[test[0]] != test[1]) && (bff[test[0]] != test[v - 1])){
			ok = false;
		}
			if (v>=2 && (bff[test[v - 1]] != test[0]) && (bff[test[v - 1]] != test[v - 2])){
				ok = false;
			}
		if (ok) counter = v;
	}
	else{
		for (int i = 1; i <= n; i++){
			if (visited[i] == false){
				visited[i] = true;
				test.push_back(i);
				dfs(l - 1, n, v);
				test.pop_back();
				visited[i] = false;
			}
		}
	}
}


int main() {

	std::ios_base::sync_with_stdio(false);
	


	ifstream fin;
	fin.open("C-small-attempt0 (1).in");
	ofstream fout;
	fout.open("c-small.txt");
	int t;
	fin >> t;
	for (int T = 1; T <= t; T++){
		fout << "Case #" << T << ": ";

		int n;
		fin >> n;		
		counter = 0;
		for (int i = 0; i < 11; i++) {
			bff[i] = -1;
			visited[i] = false;
		}
		for (int i = 1; i <= n; i++) fin >> bff[i];
		
		for (int i = 1; i <= n; i++){
			test = vector<int>();
			dfs(i, n, i);
		}
		fout <<max(1, counter)<<endl;


	}
	
	system("PAUSE");
	return 0;
}