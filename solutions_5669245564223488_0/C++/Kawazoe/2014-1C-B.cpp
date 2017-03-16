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

vector<string> s;

void Smart()
{
}

s64 Naive(s32 n)
{
    s64 r = 0;
    vector<s32> v(n);
    FOR (i,0,n) v[i]=i;
    do {
        string t;
        FOR (i,0,s.size()) t += s[v[i]];
        bool u[26];
        FOR (i,0,26) u[i]=false;
        char c = t[0];
        u[c-'a'] = true;
        bool ok = true;
        FOR (i,1,t.size()) {
            if (c == t[i]) continue;
            c = t[i];
            if (u[c-'a']) {
                ok= false;
                break;
            }
            u[c-'a'] = true;
        }
        if (ok) r ++;
    } while (next_permutation(v.begin(), v.end()));
    cout << r;
    return r;
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

        s.clear();
        s32 n;
        cin >> n;
        FOR (i,0,n) {
            string tmp;
            cin  >> tmp;
            s.push_back(tmp);
        }
		Naive(n);
		cout << endl;
	}

	return 0;
}
