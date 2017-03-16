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

vector<vector<s32> > f;

void Smart()
{
}

bool End()
{
    FOR (i,0,4) FOR (j,0,4) if (f[i][j]==0) return false;
    return true;
}

void Print()
{
    FOR (i,0,4) {
        FOR (j,0,4) {
            if (f[i][j]==0) cout << ".";
            if (f[i][j]==1) cout << "X";
            if (f[i][j]==2) cout << "O";
            if (f[i][j]==3) cout << "T";
        }
        cout << endl;
    }
}

bool Check(s32 m)
{
    bool ok=true;
    FOR (i,0,4) {
        ok=true;
        FOR (j,0,4) if (!(f[i][j]==m || f[i][j]==3)) ok=false;
        if (ok) return true;
    }
    FOR (i,0,4) {
        ok=true;
        FOR (j,0,4) if (!(f[j][i]==m || f[j][i]==3)) ok=false;
        if (ok) return true;
    }
    ok=true;
    FOR (i,0,4) if (!(f[i][i]==m || f[i][i]==3)) ok=false;
    if (ok) return true;
    ok=true;
    FOR (i,0,4) if (!(f[3-i][i]==m || f[3-i][i]==3)) ok=false;
    if (ok) return true;
    return false;
}

void Naive()
{
  //  Print();
    if (Check(1)) {
        cout << "X won";
        return;
    }
    if (Check(2)) {
        cout << "O won";
        return;
    }
    if (End()) {
        cout << "Draw";
        return;
    }
    cout << "Game has not completed";
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
        FOR (i,0,4) {
            char tmp[10];
            cin >> tmp;
            vector<s32> u;
            FOR (j,0,4) {
                if (tmp[j] == 'X') u.push_back(1);
                if (tmp[j] == 'O') u.push_back(2);
                if (tmp[j] == 'T') u.push_back(3);
                if (tmp[j] == '.') u.push_back(0);
            }
            f.push_back(u);
        }
		cout << "Case #" << tt+1 << ": ";
		Naive();
        f.clear();
		cout << endl;
	}

	return 0;
}
