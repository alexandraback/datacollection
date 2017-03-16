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
using namespace std;

//Google Code Jam 2012 Qualification Round, Problem B code.google.com/codejam
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
	long long test, cases, n, m, mt, res, rt, i, j, k, t, ax, a, p;
	//char ch;
	//string sres[2]={"YES", "NO"};
	//string s, st, sr;
	//long double dt;


	//if(INPUT_FROM) from.open("test.txt");
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	//vector<long long> v;
	//deque<long long> dq;
	//map<long long, long long> mi;
	//map<long long, long long>::iterator it;
	//typedef map<string, long long>::const_iterator CI;

	//scanf("%lld\n", &cases);
	fromc>>cases;
	for(test=1;test<=cases;test++){
		//scanf("%lld\n", &n);
		fromc>>n>>m>>p;

		res=0;
		for(i=0;i<n;i++){
			fromc>>t;
			a=t/3;
			if(a>=p) res++;
			else if((a+1>=p)&&(3*a<t)) res++;
			else if(m>0){
				if(3*a+2==t){
					if(a+2==p){
						res++;
						m--;
					}
				}else if(a>=1){
					if(a+1==p){
						res++;
						m--;
					}
				}
			}
		}

		cout<<"Case #"<<test<<": "<<res<<endl;
	}

	return 0;
}
