// 1BA.cpp 


#include "stdafx.h"
//#include "stdio.h"
//#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <fstream>
#include <algorithm>

using namespace std;

int T;
long long N;
//int digits[16];
vector<int> toDigits(long long N){
	vector<int> digits;
	while (N > 0){
		digits.insert(digits.begin(), N % 10);
		N = N / 10;
	}
	return digits;
}
vector<int> reverse(vector<int>& origin){
	vector<int> digits;
	for (int i = 0; i < origin.size(); i++){
		digits.insert(digits.begin(), origin[i]);
	}
	return digits;
}
long long toNumber(vector<int>& digits){
	long long n = 0;
	for (int i = 0; i < digits.size(); i++){
		n = n * 10 + digits[i];
	}
	return n;
}
long long calc(long long N){
	long long n = N;
	vector<int> digits;
	long long tmp,need=0,have=1,remain;
	int i;
	while (N > 0){
		digits.insert(digits.begin(), N % 10);
		N = N / 10;
	}
	if (digits.back() == 0){
		return calc(n - 1)+1;
	}
	if (digits.size() == 1){
		return n;
	}
	for (i = 0; i < (digits.size()-1)/2; i++){
		have *= 10;
	}
	for (i = (digits.size()) / 2-1; i >= 0; i--){
		
		have = have * 10 + digits[i];
	}
	tmp =  toNumber(reverse(toDigits(have)));
	
	remain = powl(10, digits.size()-1) - 1;

	need += n - tmp + (tmp != have) + have - remain ;
	long long made = calc(remain);
	need += made;
	return need;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int t, mi;
	//cout << argc << argv;
	ifstream in("L:\\!!GoogleCodeJam\\Debug\\A-small-attempt1.in");
	cout << in.is_open() << endl;
	ofstream out("L:\\!!GoogleCodeJam\\Debug\\a.out");
	//freopen_s("data.txt", "r", stdin);
	//freopen_s("b.txt", "w", stdout);
	//fstream fout("boutput.txt", fstream::out);
	//cin.rdbuf(in.rdbuf());
	//cout.rdbuf(out.rdbuf());
	in >> T;

	for (t = 1; t <= T; t++){
		in >> N;
		
		
		cout << t << endl;
		out << "Case #" << t << ": " << calc(N) << "\r";

	}
	in.close();
	out.close();
}

