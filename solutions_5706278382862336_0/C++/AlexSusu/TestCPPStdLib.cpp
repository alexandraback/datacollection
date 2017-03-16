// TestCPPStdLib.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <bitset>
#include <map>
#include <string>
#include <unordered_map>

#include <assert.h>

using namespace std;



// These are portable on both x86 and x64 compilers
typedef short int i16;
typedef short unsigned u16;
typedef int i32;
typedef unsigned int u32;

//!!!!TODO
// From https://stackoverflow.com/questions/152016/detecting-cpu-architecture-compile-time
//#ifdef __i386__

// These are for x86 compilers
typedef long long int i64;
typedef long long unsigned u64;



#define MY_DEBUG


#ifdef MY_DEBUG
    #define dout cout
    // See http://gcc.gnu.org/onlinedocs/cpp/Variadic-Macros.html
    #define dprintf(...) printf(__VA_ARGS__)
#else
    #define dout 0 && cout
    #define dprintf(...) 0 && printf(__VA_ARGS__)
#endif




#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <assert.h>
#include <string.h>


int T;

#define T_MAX 100

//#define MYDEBUG


u64 GCD(u64 a, u64 b) {
	u64 t;
	while (b != 0) {
		t = b;
		b = a % b;
		a = t;
		/*
		if (a < b)
			a -= b;
		else
			b -= a;
		*/
	}
	return a;
}

FILE *fin;
u64 P, Q;


int DoIt(u64 P, u64 Q) {
	int j;
	u64 k, j1;
	dprintf("Q=%llu\n", Q);

	assert(Q != 1);
	if (P >= Q)
		return -1;
	//if (P == Q) return 0;
	if (Q > (1ULL << 40))
		return -1;

	//"Tell her what is the minimum number of generations ago that there could have been a 1/1 Elf in her family."
	u64 gcd = GCD(P, Q);
	if (gcd != 1) {
		P /= gcd;
		Q /= gcd;
	}
	dprintf("GCD=%llu\n", gcd);
	dprintf("After GCD, P=%llu, Q=%llu\n", P, Q);

	u64 Qtmp = Q;
	for (j = 0; ; j++) {
		if ((Qtmp & 1) == 0)
			Qtmp >>= 1;
		else
			break;
	}
	dprintf("Qtmp = %llu, j = %d\n", Qtmp, j);

	// j is the pow(2) factors
	//if (j == 0) {
	if (Qtmp != 1) {
		// Not divisible by 2 (NOTE: not even Q = 1 doesn't work)
		return -1;
	}
	else {
		//if (Qtmp == 1)
		//if (P > Q / 2) // NOTE: case P==Q/2 is covered by GCD reduction above

		k = 2ULL;
		for (j1 = 0; j1 < 40; j1++) {
			if (k >= P)
				break;
			if (P > k)
				j--;
			k <<= 1;
			//k *= 2;
		}

	}

	return j;
}

void ReadData() {
    int i, j;
    int res;

    #define STRLEN_MAX 1000
    char str[STRLEN_MAX + 1];

    fgets(str, STRLEN_MAX, fin);
    sscanf(str, "%d", &T);
    //fscanf(fin, "%d", &T);

    assert(T >= 1 && T <= T_MAX);

    for (i = 0; i < T; i++) {
        fscanf(fin, "%llu/%llu", &P, &Q);
		res = DoIt(P, Q);
		if (res == -1)
			printf("Case #%d: impossible\n", i + 1);
		else
			printf("Case #%d: %d\n", i + 1, res);
	}
}

int main() {
    //freopen("Z:\\1Job_Search\\Google\\Google_CodeJAM_2009\\Online_Round_1\\C\\A.in", "rt", stdin);
    /*
    freopen("Z:\\1Job_Search\\Google\\Google_CodeJAM_2009\\Online_Round_1\\C\\A-large.in", "rt", stdin);
    freopen("Z:\\1Job_Search\\Google\\Google_CodeJAM_2009\\Online_Round_1\\C\\A-large.out", "wt", stdout);
    */
    //freopen("A-large-practice.in", "rt", stdin);
    //freopen("A-large-practice.out", "wt", stdout);
    freopen("C:\\Users\\Alex\\Documents\\Visual Studio 2010\\Projects\\TestCPPStdLib\\TestCPPStdLib\\A-small-attempt0.in", "rt", stdin);
	//freopen("C:\\Users\\Alex\\Documents\\Visual Studio 2010\\Projects\\TestCPPStdLib\\TestCPPStdLib\\A.in", "rt", stdin);

    fin = stdin;
    ReadData();

    fclose(fin);

    return 0;
}


/*
int _tmain(int argc, _TCHAR* argv[]) {
    //LCS();

    printf("Test");

    //mainInfInt();
    return 0;
}
*/
