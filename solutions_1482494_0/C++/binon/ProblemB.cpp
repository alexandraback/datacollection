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
#include <cstdlib>
#include <algorithm>
using namespace std;

//Google Code Jam 2012 Round 1A, Problem B code.google.com/codejam
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
	const long long nmin=1, nmax=100;
	long long test, cases, n, m, mt, res, rt, i, j, k, t, ax, i1, i2;
	//char ch;
	//string sres[2]={"YES", "NO"};
	//string s, st, sr;
	//long double dt;


	//if(INPUT_FROM) from.open("test.txt");
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	vector<long long> v1, v2;
	//deque<long long> dq;
	//map<long long, long long> mi;
	//map<long long, long long>::iterator it;
	//typedef map<string, long long>::const_iterator CI;

	//scanf("%lld\n", &cases);
	fromc>>cases;
	for(test=1;test<=cases;test++){
		//scanf("%lld\n", &n);
		fromc>>n;
		v1.resize(n);
		v2.resize(n);

		for(i=0;i<n;i++) fromc>>v1[i]>>v2[i];
		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());

		i1=i2=0;
		res=rt=0;
		ax=1;
		while((i2<n)&&(ax==1)){
			while((i2<n)&&(ax==1)&&(rt>=v2[i2])){
				i2++;
				rt+=2;
				res++;
			}
			if(i2<n){
				while((i1<n)&&(ax==1)&&(rt>=v1[i1])&&(rt<v2[i2])){
					i1++;
					rt+=1;
					res++;
				}
			}
			if((i2<n)&&(rt<v2[i2])) ax=0;
		}

		if(ax==1) cout<<"Case #"<<test<<": "<<res<<endl;
		else cout<<"Case #"<<test<<": "<<"Too Bad"<<endl;

		//cout<<"Case #"<<test<<": "<<res<<endl;
		v1.clear();
		v2.clear();
	}

	return 0;
}
