#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <math.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <list>
#include <set>
#include <cstdlib>
#include <algorithm>
using namespace std;

//Google Code Jam 2015 Qualification Round, Problem B code.google.com/codejam
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
	const int nmin=1, nmax=1000, amax=100000;
	int test, cases, n, m, mt, res, rt, i, j, k, t, ax;
	int i0, i1, j0, j1;
	int k0, k1, k2;
	int a, a0, a1, r, r0, r1;
	long long aa, ff, cc, xx, yy;
	//char ch;
	//string sres[2]={"YES", "NO"};
	//string s, st, sr;
	//long double dt, dt0, dt1;
	//long double dc, df, dx, dy;


	//if(INPUT_FROM) from.open("test.txt");
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	vector<int> v;
	//vector<int>::iterator it, it0, it1;
	//deque<int> dq;
	//set<pair<int,int> > ss;
	//set<pair<int,int> >::iterator it, it0, it1;
	//pair<int,int> pr;
	//map<int, int> mi;
	//typedef map<string, long long>::const_iterator CI;

	//scanf("%lld\n", &cases);
	fromc>>cases;
	for(int test=1;test<=cases;test++){
		//scanf("%lld\n", &n);
		cin >> n;

		v.resize(n);
		a1 = 0; j1 = -1;
		for(int i=0;i<n;++i){
			cin >> rt;
			v[i] = rt;
			if(rt > a1) a1 = rt, j1 = i;
		}
		r = a1;

		for(int a = 1; a < a1;++a){
			r0 = a;
			for(int i = 0; i < n;++i) r0 += (v[i] + a - 1)/a - 1;
			
			if(r0 < r) r = r0;
		}

		v.clear();

		cout<<"Case #"<< test << ": " << r <<endl;
		//printf("Case #%d: %.7Lf\n", test, dt);

		//cout<<"Case #"<<test<<": "<<sres[1-ax]<<endl;
	}

	return 0;
}
