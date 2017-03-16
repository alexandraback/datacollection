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
#define M 100
s32 N,S,p,t[M];
s32 Smart()
{
	s32 a=0,b=0,c=0,r=0;
	cin >> N >> S >> p;
	FOR (i,0,N) cin >> t[i];
	FOR (i,0,N) {
		if (t[i]==0) {
			if (p==0) r ++;
			continue;
		}
		if (t[i]>=29) {
			r ++;
			continue;
		}
		if (t[i]>=3*p-2) a ++;
		else if (t[i]>=3*p-4) b ++;
		else c ++;
	}
	r += a + min(S,b);
	cout << r;
	return r;
}

s32 Naive()
{
	s32 rmax=0;
	FOR (t1,0,11) FOR (t2,max(0,t1-2),min(11,t1+3)) FOR (t3,max(0,t1-2),min(11,t1+3)) {
		if (abs(t2-t3)>2) continue;
		if (t1+t2+t3!=t[0]) continue;
		FOR (t4,0,11) FOR (t5,max(0,t4-2),min(11,t4+3)) FOR (t6,max(0,t4-2),min(11,t4+3)) {
			if (abs(t5-t6)>2) continue;
			if (t4+t5+t6!=t[1]) continue;
			FOR (t7,0,11) FOR (t8,max(0,t7-2),min(11,t7+3)) FOR (t9,max(0,t7-2),min(11,t7+3)) {
				if (abs(t8-t9)>2) continue;
				if (t7+t8+t9!=t[2]) continue;
				s32 s=0,r=0;
				if (abs(t1-t2)==2 || abs(t3-t2)==2 || abs(t1-t3)==2) s ++;
				if (abs(t4-t5)==2 || abs(t5-t6)==2 || abs(t6-t4)==2) s ++;
				if (abs(t7-t8)==2 || abs(t8-t9)==2 || abs(t9-t7)==2) s ++;
				if (s!=S) continue;
				if (t1>=p||t2>=p||t3>=p) r++;
				if (t4>=p||t5>=p||t6>=p) r++;
				if (t7>=p||t8>=p||t9>=p) r++;
				rmax = max(rmax,r);
			}
		}
	}
	return rmax;
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
		s32 r0 = Smart();
		//s32 r1 = Naive();
		cout << endl;
	}

	return 0;
}
