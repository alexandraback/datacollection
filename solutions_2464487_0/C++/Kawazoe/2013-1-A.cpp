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

s64 R, T;

s64 F(s64 m) 
{
    return (m+1)*(2*m+2*R+1);
}

void Smart()
{
    s64 l = 0, r = 1000000000LL, m;
    if ((R+1)*(R+1) - R*R > T) {
        cout << 0;
        return;
    }
    while (true) {
        if (l+1 == r && (2*l+2*R+1) <= T/(l+1) && (2*r+2*R+1) > T/(r+1)) {
            break;
        }
        m = (l+r)/2;
        if ((2*m+2*R+1) > T/(m+1)) r = m;
        else l = m;
    }
    cout << l+1;
}

void Naive()
{
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
        cin >> R >> T;
		Smart();
		cout << endl;
	}

	return 0;
}
