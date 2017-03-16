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


int prime[100000000];

void initprime(){
	
	for (int i = 2; i < 100000000; i++){
		if (prime[i] == 0)
		{
			prime[i] = 1;
			for (int j = 2 * i; j < 100000000; j += i){
				prime[j] = -1;
			}
		}
	}
}

int main() {

	std::ios_base::sync_with_stdio(false);
	
	initprime();

	int count = 0;
	int N = 50;
	ofstream ot;
	ot.open("list.txt");
	int length = 14;
	for (int i = 1; i < (1 << (length)); i++){
		long long t[9];
		for (int j = 0; j < 9; j++) t[j] = 0;
		for (int j = 0; j < length; j++){
			int a = ((i&(1 << j))!=0);
			for (long long k = 0; k < 9; k++){
				long long base = 1;
				for (int m = 0; m < j; m++) base *= (k + 2);
				t[k] += a*base;
			}
		}
		for (long long k = 0; k < 9; k++){
			t[k] = t[k] * (k + 2) + 1;
			long long base = 1;
			for (int m = 0; m < (length+1); m++) base *= (k + 2);
			t[k] += base;
		}
		bool ok = true;
		for (int j = 0; j < 9; j++){
			long long tt = t[j];
			bool okk = true;
			for (long long k = 2; k*k <= tt; k++){
				if (tt%k == 0){
					okk = false;
					break;
				}
			}
			if (okk == true) ok = false;
		}
		if (ok){
			cout << "done!" << endl;
			ot << 1;
			for (int j = 0; j < length; j++){
				if (i&(1 << (length - 1 - j))) ot << 1;
				else ot << 0;
			}
			ot << 1<<" ";
			for (int j = 2; j <= 10; j++){
				long long tt = t[j - 2];
				for (long long k = 2; k*k <= tt; k++){
					if (tt%k == 0){
						ot << k << " ";
						break;
					}
				}
			}
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