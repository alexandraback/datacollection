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
s64 E,R,N,V[100000];

s64 gbest=0;
vector<s64> w, wbest;

void Smart()
{
    vector<s64> should(N), must(N), can(N);
    vector<s64> done(N);
    FOR (i,0,N) {
        should[i] = 0;
        must[i] = E;
    }
    s64 g=0;
    FOR (i,0,N) {
        s32 jmax = 0;
        s64 gmax = 0;
        FOR (j,0,N) {
            if (!done[j] && gmax < V[j]*(must[j]-should[j])) {
                gmax = V[j]*(must[j]-should[j]);
                jmax = j;
            }
        }
        done[jmax] = 1;
        g += gmax;
        for (s32 j=1; ; j++) {
            s32 k = jmax-j;
            if (k<0) break;
            should[k] = max(should[k], (must[jmax]-should[jmax])-R*j);
        }
        for (s32 j=1; ; j++) {
            s32 k = jmax+j;
            if (k>=N) break;
            must[k] = min(must[k], R*j);
        }
    }
    cout << g;
}

void Next(s32 i, s64 e, s64 g)
{
    if (i==N) {
        gbest = max(gbest,g);
        wbest = w;
    } else {
        FOR (j,0,e+1) {
            s64 enew = min(E, e-j+R);
            w.push_back(j);
            Next(i+1, enew, g+V[i]*j);
            w.pop_back();
        }
    }
}

void Naive()
{
    gbest=0;
    Next(0,E,0);
    cout << gbest;
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
    //num_of_trial = 100;
	FOR (tt,0,num_of_trial) {
        cin >> E >> R >> N;
        FOR (i,0,N) cin >> V[i];
        //E=5;R=rand()%E+1; N=10;
        //FOR (i,0,N) V[i] = rand()%10+1;
        //E=5;R=rand()%E+1; N=6;
        //FOR (i,0,N) V[i] = rand()%10+1;
		cout << "Case #" << tt+1 << ": ";
//        Smart();
		Naive();
		cout << endl;
	}

	return 0;
}
