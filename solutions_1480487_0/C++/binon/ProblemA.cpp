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

//Google Code Jam 2012 Round 1B, Problem A code.google.com/codejam
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
	long long test, cases, n, m, nt, mt, res, rt, i, j, k, t, ax, a, at, b;
	//char ch;
	//string sres[2]={"YES", "NO"};
	//string s, st, sr;
	long double dt, dr, d0, d1, dp;

	//if(INPUT_FROM) from.open("test.txt");
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	vector<long long> v;
	vector<long double> vr;
	//deque<long long> dq;
	//map<char, char> mc;
	//map<long long, long long>::iterator it;
	//typedef map<string, long long>::const_iterator CI;

	//scanf("%ld\n", &cases);
	fromc>>cases;
	for(test=1;test<=cases;test++){
		fromc>>n;

		v.resize(n);
		vr.resize(n);
		a=0;
		for(i=0;i<n;i++){
			fromc>>v[i];
			a+=v[i];
			vr[i]=200.0;
		}

		ax=1;
		at=a;
		nt=n;
		while(ax==1){
			ax=0;
			for(i=0;i<n;i++){
				if(vr[i]==0.0) continue;
				b=at+a-nt*v[i];
				if(b<=0){
					ax=1;
					vr[i]=0.0;
					at-=v[i];
					nt--;
				}else vr[i]=100.0*b/(nt*a);
			}
		}
		//scanf("%ld\n", &n);

		cout.setf(ios::fixed);
		cout.precision(6);
		cout<<"Case #"<<test<<":";
		for(i=0;i<n;i++) cout<<' '<<vr[i];
		cout<<endl;
		v.clear();
		vr.clear();
	}

	return 0;
}

