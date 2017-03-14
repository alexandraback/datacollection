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

#define N 100
s32 H,W,D,X,Y;
char c[N];
vector<pair<s32,s32>> v;

void Smart()
{
}

s32 GCD(s32 x, s32 y){
	return x ? GCD(y % x, x) : y;
}

s32 Calc(s32 p, s32 q)
{
	s32 x,y;
	x = p*(W-2)+X;
	if (abs(p%2)==1) x += W-3-2*X;
	y = q*(H-2)+Y;
	if (abs(q%2)==1) y += H-3-2*Y;
	FOR (i,0,v.size()) {
		if ((v[i].first-X)*(y-Y)==(v[i].second-Y)*(x-X)) {
			return 0;
		}
	}
	s32 r = (X-x)*(X-x)+(Y-y)*(Y-y) <= D*D ? 1 : 0;
	if (r==1) v.push_back(pair<s32,s32>(x,y));
	return r;
}

void Naive()
{
	cin >> H >> W >> D;
	FOR (h,0,H) {
		cin >> c;
		FOR (w,0,W) {
			if (c[w]=='X') {
				X=w-1; Y=h-1;
			}
		}
	}
	v.clear();
	s32 r=0;
	r += Calc(0,1);
	v.clear();r += Calc(1,0);
	v.clear();r += Calc(0,-1);
	v.clear();r += Calc(-1,0);
	v.clear();
	for (s32 p=1; p<=D; p++) for (s32 q=1; q<=D; q++) {
		r += Calc(p,q);
	}
	v.clear();
	for (s32 p=1; p<=D; p++) for (s32 q=-1; q>=-D; q--) {
		r += Calc(p,q);
	}
	v.clear();
	for (s32 p=-1; p>=-D; p--) for (s32 q=1; q<=D; q++) {
		r += Calc(p,q);
	}
	v.clear();
	for (s32 p=-1; p>=-D; p--) for (s32 q=-1; q>=-D; q--) {
		r += Calc(p,q);
	}
	cout << r;
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
