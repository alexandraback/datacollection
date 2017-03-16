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

//Google Code Jam 2012 Qualification Round, Problem A code.google.com/codejam
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
	const int nmin=1, nmax=100000;
	int test, cases, n, m, mt, res, rt, i, j, k, t, ax, a;
	char ch;
	//string sres[2]={"YES", "NO"};
	string s, st, sr;
	//long double dt;
	string s0="ynficwlbkuomxsevzpdrjgthaq ";
	string s1="abcdefghijklmnopqrstuvwxyz ";
	int np=27;

	//if(INPUT_FROM) from.open("test.txt");
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	//vector<long long> v;
	//deque<long long> dq;
	map<char, char> mc;
	//map<long long, long long>::iterator it;
	//typedef map<string, long long>::const_iterator CI;

	//y,n,f,i,c,w,l,b,k,u,o,m,x,s,e,v,z,p,d,r,j,g,t,h,a,q
	//a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w.x,y,z


	for(i=0;i<np;i++) mc[s0[i]]=s1[i];

	//scanf("%ld\n", &cases);
	fromc>>cases;
	fromc.get(ch);
	for(test=1;test<=cases;test++){
		s="";
		while((fromc.get(ch))&&(ch!='\n')&&(ch!='\r')) s+=mc[ch];
		//scanf("%ld\n", &n);

		cout<<"Case #"<<test<<": "<<s<<endl;
	}

	return 0;
}

