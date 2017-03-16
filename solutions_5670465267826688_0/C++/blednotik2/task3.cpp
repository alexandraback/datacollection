// g++ v4.8.3
// Flags: -O2

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cassert>

using namespace std;

#define forall(i,n) for(int i=0; i<(int)(n); i++)

template<class T, class T1, class T2> inline bool Within(T x, T1 xMin, T2 xMax)
    {return (x >= xMin && x <= xMax);}
template<class T, class T1> inline bool Within(T x, T1 xMax)
    {return (x >= 0 && x < xMax);}

typedef vector<int> IntVec;

typedef unsigned long long ull;

const char* sym[] = {"1", "i", "j", "k", "-1", "-i", "-j", "-k"};

int Table[8][8];
int Code[256];

void FillTable() {
    forall (a, 8)
	Table[0][a] = Table[a][0] = a;
    for (int a=1; a<=3; a++)
	Table[a][a] = 4;
    Table[1][2]=3;
    Table[2][3]=1;
    Table[3][1]=2;
    Table[2][1]=7;
    Table[3][2]=5;
    Table[1][3]=6;
    forall (a, 4) {
	forall (b, 4) {
	    Table[a][b+4] = Table[a+4][b] = (Table[a][b] + 4) % 8;
	    Table[a+4][b+4] = Table[a][b];
	}
    }

    forall (i, 256)
	Code[i] = -1;
    Code['i'] = 1;
    Code['j'] = 2;
    Code['k'] = 3;
}

bool TestTotal(const string& s, ull nRep) {
    int prod = 0;
    forall (i, s.size()) {
	int c = Code[s[i]];
	assert(Within(c, 1, 3));
	prod = Table[prod][c];
    }
    if (prod == 0)
	return false;
    else if (prod == 4)
	return nRep % 2 == 1;
    else
	return nRep % 4 == 2;
}

int TestI(const string& s, ull nRep) {
    int prod = 0;
    const int nRep4 = (nRep > 4 ? 4 : (int)nRep);
    forall (iRep, nRep4) {
	forall (i, s.size()) {
	    int c = Code[s[i]];
	    assert(Within(c, 1, 3));
	    prod = Table[prod][c];
	    if (prod == 1)
		return iRep * (int)s.size() + i + 1;
	}
    }
    return -1;
}
	    
int TestK(const string& s, ull nRep) {
    int prod = 0;
    const int nRep4 = (nRep > 4 ? 4 : (int)nRep);
    forall (iRep, nRep4) {
	for (int i=(int)s.size()-1; i>=0; i--) {
	    int c = Code[s[i]];
	    assert(Within(c, 1, 3));
	    prod = Table[c][prod];
	    if (prod == 3)
		return (iRep + 1) * (int)s.size() - i;
	}
    }
    return -1;
}
	    
bool Test(const string& s, ull nRep) {
    bool b = TestTotal(s, nRep);
    if (!b)
	return false;
    int i = TestI(s, nRep);
    if (i < 0)
	return false;
    int k = TestK(s, nRep);
    if (k < 0)
	return false;
    return (ull)(i + k) < (ull)s.size() * nRep;
}

int SubProd(const string& s, int start, int end) {
    int prod = 0;
    for (int i=start; i<end; i++) {
	int c = Code[s[i%s.size()]];
	assert(Within(c, 1, 3));
	prod = Table[prod][c];
    }
    return prod;
}

bool SimpleTest(const string& s, ull nRep) {
    bool b = TestTotal(s, nRep);
    if (!b)
	return false;
    const int totlen = (ull)s.size() * nRep;
    assert(totlen < 100000000);
    int prod = 0;
    int iMin = -1, kMax = -1;
    forall (i, totlen) {
	int c = Code[s[i%s.size()]];
	assert(Within(c, 1, 3));
	prod = Table[prod][c];
	if (prod == 1) {
	    iMin = i;
	    break;
	}
    }
    prod = 0;
    for (int i=totlen-1; i>=0; i--) {
	int c = Code[s[i%s.size()]];
	assert(Within(c, 1, 3));
	prod = Table[c][prod];
	if (prod == 3) {
	    kMax = i;
	    break;
	}
    }
    assert(iMin < 0 || kMax != iMin);
    if (kMax > iMin) {
	assert(SubProd(s, 0, iMin+1) == 1);
	assert(SubProd(s, kMax, totlen) == 3);
	assert(SubProd(s, iMin+1, kMax) == 2);
    }
    return iMin >= 0 && kMax > iMin;
}
    

int main() {
    FillTable();
    int nTasks;
    cin >> nTasks;
    for (int iTask=1; iTask<=nTasks; iTask++) {
	size_t len;
	ull nRep;
	cin >> len >> nRep;
	assert(Within(len, 1, 10000) && nRep > 0);
	string s;
	cin >> s;
	assert(s.size() == len);
	forall (i, len)
	    assert(Within(Code[s[i]], 1, 3));
	bool b = Test(s, nRep);
	cout << "Case #" << iTask << ": " << (b ? "YES\n" : "NO\n");
    }
}
