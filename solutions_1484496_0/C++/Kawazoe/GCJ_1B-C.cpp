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
#define M 501
#define L 3000000
s32 s[M];
bool b[L];
s32 N, a;
bool end;
vector<s32> v;

void Smart()
{
}

void Next(s32 i, s32 p)
{
	if (i==N) {
		if (b[p]) {
			FOR (i,0,v.size()) cout << s[v[i]] << " ";
			cout << endl;
			a=p;
			end=true;
		}
		b[p]=true;
	} else {
		if (!end) Next(i+1, p);
		if (!end) {
			v.push_back(i);
			Next(i+1, p+s[i]);
			v.pop_back();
		}
	}
}

void Find(s32 i, s32 p)
{
	if (i==N) {
		if (p==a) {
			FOR (i,0,v.size()) cout << s[v[i]] << " ";
			cout << endl;
			end=true;
		}
	} else {
		
		if (!end) Find(i+1, p);
		if (!end) {
			v.push_back(i);
			Find(i+1, p+s[i]);
			v.pop_back();
		}
	}
}

void Naive()
{
	a=-1;
	memset(b,0,L);
	cout << endl;

	v.clear();
	end=false;
	Next(0,0);
	
	if (!end) {
		cout << "Impossible" << endl;
		return;
	}

	v.clear();
	end=false;
	Find(0,0);
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
		cin >> N;
		FOR (i,0,N) cin >> s[i];
		Naive();
//		cout << endl;
	}

	return 0;
}
