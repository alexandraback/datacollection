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
#include <algorithm>
using namespace std;

//Google Code Jam 2013 Round 1B, Problem A code.google.com/codejam
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
	const long long nmin=1, nmax=1000;
	const long double pi = acos(-1.0);
	long long test, cases, n, m, mt, res, rt, i, j, k, t, ax, r, q;
	long long qt;
	//char ch;
	//string sres[2]={"YES", "NO"};
	//string s, st, sr;
	//long double dt, dr, d0, d1, dp;

	//if(INPUT_FROM) from.open("test.txt");
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	vector<long long> v;
	//deque<long long> dq;
	//map<char, char> mc;
	//map<long long, long long>::iterator it;
	//typedef map<string, long long>::const_iterator CI;

	//scanf("%ld\n", &cases);
	fromc>>cases;
	for(test=1;test<=cases;test++){
		fromc>>q>>n;

		v.resize(n);

		for(i=0;i<n;i++) fromc>>v[i];

		if(q==1) res=n;
		else{
			sort(v.begin(),v.end());

			i=0;
			while((i<n)&&(q>v[i])){q+=v[i]; i++;}

			res=n-i; r=0; qt=q;
			while(i<n){
				while((r<res)&&(qt<=v[i])){
					rt=qt-1;
					r++; qt+=rt;
				}
				//cout<<r<<endl;
				if(r<res){
					while((i<n)&&(qt>v[i])){qt+=v[i]; i++;}
					if(res>r+n-i) res=r+n-i;
				}else i=n;
			}
		}
		
		v.clear();

		//cout.setf(ios::fixed);
		//cout.precision(6);
		cout<<"Case #"<<test<<": "<<res<<endl;
	}

	return 0;
}

