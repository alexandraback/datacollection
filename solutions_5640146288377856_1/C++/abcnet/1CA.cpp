// 1CA.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//#include "stdio.h"
//#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <fstream>
#include <algorithm>
#include <queue>
using namespace std;

int T,R,C,W;
int divv(int a, int b){
	return a / b;
}

long long calc(int R,int C,int W){
	//int tmp = 2 * W - 1;
	int res = (int(C/W))*(R - 1);
	if (C == W){
		res += W;
	}
	else{
		res += C / W + W-(C%W==0);
	}
	return res;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int t, mi;
	//cout << "eee" << int(4 / 3);
	//cout << argc << argv;
	ifstream in("D:\\!!GoogleCodeJam\\Debug\\A-large.in");
	cout << in.is_open() << endl;
	ofstream out("D:\\!!GoogleCodeJam\\Debug\\1CA.out");
	//freopen_s("data.txt", "r", stdin);
	//freopen_s("b.txt", "w", stdout);
	//fstream fout("boutput.txt", fstream::out);
	//cin.rdbuf(in.rdbuf());
	//cout.rdbuf(out.rdbuf());
	in >> T;

	for (t = 1; t <= T; t++){
		in >> R>>C>>W;


		cout << t << endl;
		out << "Case #" << t << ": " << calc(R,C,W) << "\r";

	}
	in.close();
	out.close();
}

