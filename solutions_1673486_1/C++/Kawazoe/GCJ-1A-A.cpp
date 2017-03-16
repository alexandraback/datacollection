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
#define M 100001
s64 A,B;
double P[M];

double Smart()
{
	double em=B+2.0;
	double p=1.0;
	for (s64 n=A-1; n>=0; n--) {	// BSの数
		p *= P[A-n-1];
		double e=0.0;
		e += p * (2*n+B-A+1);
		e += (1-p) * (2*n+2*B-A+2);
		if (em>e) {
			em = e;
		}
	}
	return em;
}

double Naive()
{
	double em=B+2.0;
	for (s64 n=0; n<=A; n++) {	// BSの数
		double e=0.0;
		for (s64 m=0; m<(1LL<<A); m++) {	// bitmap、i番目がミスなら1
			// 0～A-n-1の中に誤りがあれば、BSの数+再タイプのコスト
			double p=1.0;
			bool ok=true;
			FOR (i,0,A) {
				if (m&(1LL<<i)) {
					if (i<A-n) ok=false;
					p *= 1-P[i];
				} else {
					p *= P[i];
				}
			}
			if (ok) {	// ミスなし
				e += p * (2*n+B-A+1);
			} else {
				e += p * (2*n+2*B-A+2);
			}
		}
		if (em>e) {
			em = e;
		}
	}
	return em;
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
		cin >> A >> B;
		FOR (i,0,A) cin >> P[i];
		//double r0 = Naive();
		double r1 = Smart();
		cout << r1 << endl;
	}

	return 0;
}
