#include <stdio.h>
#include <cstdlib>
#include <string.h>
#include <math.h>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include "windows.h"
//#include "../../gmp_int.h"
//#include "../../common.h"
#define MAX(a, b)		((a)>(b)?(a):(b))
#define MAX3(a, b, c)	(MAX((a),MAX((b),(c))))
#define FOR(a,b,c)		for (s32(a)=(b);(a)<(s32)(c);(a)++)
#define BL				{char bl[10];cin.getline(bl, 10);}
#define GL(c)			cin.getline(c, sizeof(c))
typedef char					s8;
typedef unsigned char			u8;
typedef short					s16;
typedef unsigned short			u16;
typedef int						s32;
typedef unsigned int			u32;
typedef long long int			s64;
typedef unsigned long long int	u64;
using namespace std;

ifstream test_input;
#define cin test_input

s64 GCD(s64 x, s64 y){
	return x ? GCD(y % x, x) : y;
}

void Smart()
{
}

bool Check(s64 x) {
    while (x!=1) {
        if (x%2==1) return false;
        x /= 2;
    }
    return true;
}

s64 Next(s64 n, s64 d) {
    if (n >= d/2) return 1;
    s64 r = Next(n, d/2);
    return r+1;
}

void Naive()
{
    string s;
    cin >> s;
    s32 i=s.find("/");
    s64 n = atoi(s.substr(0, i).c_str());
    s64 d = atoi(s.substr(i+1).c_str());
    s64 g = GCD(n,d);
    n /= g; d /= g;
    if (!Check(d)) {
        cout << "impossible";
        return;
    }
    cout << Next(n, d);
}

int main(int argc, char* argv[])
{
	cout.precision(15);
	if (argc!=2) {
		cout << "Need input file name." << endl;
		return 0;
	}
	test_input.open(argv[1]);
	if (test_input.fail()) {
		cout << "Cannot open input file " << argv[1] << "." << endl;
		return 0;
	}

	s32 num_of_trial;
	cin >> num_of_trial;
	FOR (tt,0,num_of_trial) {
		cout << "Case #" << tt+1 << ": ";
		Naive();
		cout << endl;
	}

	return 0;
}
