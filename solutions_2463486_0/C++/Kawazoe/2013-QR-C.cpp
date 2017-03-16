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

typedef s64 Int;
s64 A, B;

s64 Sqrt(s64 n)
{
//	return (u64)( sqrt((long double)n + DEL) );
  s64 s, t;

  if (n <= 0) return 0;

  s = 1;  t = n;
  while (s < t) {  s <<= 1;  t >>= 1;  }
  do {
    t = s;
    s = (n / s + s) >> 1;
  } while (s < t);

  return t;
}

void Smart()
{
}

bool Ok(Int n)
{
    char s[100];
    _i64toa(n, s, 10);
    s64 len = strlen(s);
    FOR (i,0,len) if (s[i] != s[len-i-1]) return false;
    return true;
}

vector<Int> v;
bool init=false;
void Init()
{
    if (init) return ;
    Int l = 100000000000000LL;
    Int ls = Sqrt(l);
    for (Int n=1; n<=ls; n++) {
        if (!Ok(n)) continue;
        s64 s = n*n;
        if (Ok(s)) {
            v.push_back(s);
        }
    }
    init = true;
}

void Naive()
{
    Init();

    vector<Int>::iterator i0=lower_bound(v.begin(), v.end(), A);
    vector<Int>::iterator i1=upper_bound(v.begin(), v.end(), B);
    s64 a  =0;
    while (i0 != i1) {
        a ++;
        i0 ++;
    }
    cout << a;
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
        cin >> A >> B;
		cout << "Case #" << tt+1 << ": ";
		Naive();
		cout << endl;
	}

	return 0;
}
