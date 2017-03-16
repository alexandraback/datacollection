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
#define UNIQUE(v)		(v).erase(unique((v).begin(), (v).end()), (v).end())
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
#define N 2000000
s64 a[N+1];

void Smart()
{
}

void Naive()
{
	s32 A,B;
	char c[10],s[10],t[10];
	vector<pair<s32,s32>> v;
	cin >> A >> B;
	FOR (n,A,B) {
		itoa(n,c,10);
		FOR (j,1,strlen(c)) {
			strcpy(s,c);
			strcpy(t,&s[j]);
			s[j]='\0';
			strcat(t,s);
			s32 m = atoi(t);
			if (n<m && m<=B) {
				//cout << n << " " << m << endl;
				v.push_back(pair<s32,s32>(n,m));
			}
		}
	}
	UNIQUE(v);
	cout << v.size();
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

	//char c[10];
	//FOR (i,1,10) a[i]=0;
	//FOR (i,10,N+1) {
	//	itoa(i,c,10);
	//	FOR (j,0,strlen(c)) 

	s32 num_of_trial;
	cin >> num_of_trial;
	FOR (tt,0,num_of_trial) {
		cout << "Case #" << tt+1 << ": ";
		Naive();
		cout << endl;
	}

	return 0;
}
