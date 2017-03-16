#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <math.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <cstdlib>
using namespace std;

//Google Code Jam 2012 Round 1A, Problem A code.google.com/codejam
//Disable warning messages C4996.
#pragma warning(disable:4996)

#define INPUT_FROM 0
#if INPUT_FROM
#define fromc from
#else
#define fromc cin
#endif

//long long fr(vector<long long>&, long long);

int main(int argc, char **argv)
{
	//ifstream from;
	const long long nmin=1, nmax=100000;
	long long test, cases, n, m, mt, res, rt, i, j, k, t, ax, a, b;
	//char ch;
	//string sres[2]={"YES", "NO"};
	//string s, st, sr;
	long double dt, dr, d0, d1, dp;

	//if(INPUT_FROM) from.open("test.txt");
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	//vector<long long> v;
	//deque<long long> dq;
	//map<char, char> mc;
	//map<long long, long long>::iterator it;
	//typedef map<string, long long>::const_iterator CI;

	//scanf("%ld\n", &cases);
	fromc>>cases;
	for(test=1;test<=cases;test++){
		fromc>>a>>b;
		d0=2.0;
		d0+=b;
		//cout<<d0<<endl;//press enter
		d1=1.0+a+b;//remove all letters
		if(d1<d0) d0=d1;
		dt=1.0;
		//cout<<d1<<endl;
		for(i=1;i<=a;i++){
			fromc>>dp;
			dt*=dp;
			d1=1.0-dt;
			d1*=(1.0+b);
			d1+=(1.0+b-i+a-i);
			if(d1<d0) d0=d1;
			//cout<<d1<<endl;
		}
		dr=d0;
		//scanf("%ld\n", &n);

		cout.setf(ios::fixed);
		cout.precision(6);
		cout<<"Case #"<<test<<": "<<dr<<endl;
	}

	return 0;
}

