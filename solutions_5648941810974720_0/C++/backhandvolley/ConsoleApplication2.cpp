// fbhc.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

// fbhc.cpp : Defines the entry point for the console application.
//



#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<limits>
#include<climits>
#include<cmath>
#include<functional>
#include<ctime>
#include<cstdlib>
#include<fstream>
#include<typeinfo>
using namespace std;

typedef long long int ll;
typedef short int i16;
typedef unsigned long long int u64;
typedef unsigned int u32;
typedef unsigned short int u16;
typedef unsigned char u8;

string u[10] = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };
int maint()
{
	ofstream cout("out.txt");
	ifstream cin("b.in");

	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {

		string s;
		cin >> s;
		int l = s.length();
		//cout << s << endl;
		int h[256] = { 0 };
		int d[10] = { 0 };
		for (int i = 0; i < l; i++) {

			h[s[i]]++;
		}
		if (h['Z']) {

			int x = h['Z'];
			d[0] += h['Z'];
			for (int j = 0; j < u[0].length(); j++) h[u[0][j]] -= x;

		}
		if (h['W']) {

			int x = h['W'];
			d[2] += h['W'];
			for (int j = 0; j < u[2].length(); j++) h[u[2][j]] -= x;
		}

		if (h['X']) {

			int x = h['X'];
			d[6] += h['X'];
			for (int j = 0; j < u[6].length(); j++) h[u[6][j]] -= x;
		}

		if (h['G']) {

			int x = h['G'];
			d[8] += h['G'];
			for (int j = 0; j < u[8].length(); j++) h[u[8][j]] -= x;
		}

		if (h['U']) {

			int x = h['U'];
			d[4] += h['U'];
			for (int j = 0; j < u[4].length(); j++) h[u[4][j]] -= x;
		}
		if (h['O']) {

			int x = h['O'];
			d[1] += h['O'];
			for (int j = 0; j < u[1].length(); j++) h[u[1][j]] -= x;
		}

		

		if (h['F']) {

			int x = h['F'];
			d[5] += h['F'];
			for (int j = 0; j < u[5].length(); j++) h[u[5][j]] -= x;
		}

		if (h['V']) {

			int x = h['V'];
			d[7] += h['V'];
			for (int j = 0; j < u[7].length(); j++) h[u[7][j]] -= x;
		}


		

		if (h['I']) {

			int x = h['I'];
			d[9] += h['I'];
			for (int j = 0; j < u[9].length(); j++) h[u[9][j]] -= x;
		}

		

		

	

	

		if (h['H']) {

			int x = h['H'];
			d[3] += h['H'];
			for (int j = 0; j < u[3].length(); j++) h[u[3][j]] -= x;
		}

		


		//for (int i = 0; i <= 9; i++) cout << i << " "<< d[i] << endl;


		cout << "Case #" << tc << ": ";
		
		string v;
		//char v[3000];
		char z[11] = "0123456789";
		for (int i = 0; i < 10; i++)  {
			if (d[i]) {
				for (int j = 0; j < d[i]; j++) v += z[i];
			}
		}

		cout <<v<< '\n';
	}

	return 0;
}




int _tmain(int argc, _TCHAR* argv[])
{
	return maint();
	return 0;
}

