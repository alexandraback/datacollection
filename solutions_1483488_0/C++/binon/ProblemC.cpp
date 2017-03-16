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
#include <time.h>
using namespace std;

//Google Code Jam 2012 Qualification Round, Problem C code.google.com/codejam
//Disable warning messages C4996.
#pragma warning(disable:4996)

#define INPUT_FROM 0
#if INPUT_FROM
#define fromc from
#else
#define fromc cin
#endif

//long long fr(vector<long long>&, long long);
string lltostr(long long);

int main(int argc, char **argv)
{
	//ifstream from;
	const long long nmin=1, nmax=2000000;
	long long test, cases, n, m, mt, res, i, j, k, t, rt, ax, a, b, c, d;
	long long d0, d1, r;
	char ch, ch0, ch1;
	//string sres[2]={"YES", "NO"};
	string s, st, sr, s0, s1;
	//long double dt;

	//if(INPUT_FROM) from.open("test.txt");
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	//static long long v[nmax+1];
	//vector<long long> v;
	//static long long vr[qmax];
	//deque<long long> dq;
	map<string, long long> ms;
	//map<long long, vector<long long> > mi;
	//map<long long, vector<long long> >::iterator it;
	//typedef map<string, long long>::const_iterator CI;
	//time_t ltime0, ltime1;

	//time(&ltime0);


	//scanf("%lld\n", &cases);
	fromc>>cases;
	for(test=1;test<=cases;test++){
		//scanf("%lld %lld %lld %lld %lld\n", &a, &b, &c, &d, &k);
		fromc>>a>>b;

		s0=lltostr(a);
		m=s0.size();
		ch0=s0[0];

		res=0;
		for(t=a+1;t<=b;t++){
			s=st=lltostr(t);
			ch1=s[0];
			for(i=1;i<m;i++){
				ch=st[m-1];
				for(j=m-1;j>=1;j--) st[j]=st[j-1];
				st[0]=ch;
				if((ch0<=ch)&&(ch<=ch1)&&(s0<=st)&&(st<s)){
					if(ms.find(st)==ms.end()){
						ms[st]=1;
						res++;
					}
				}
			}
			ms.clear();
		}

		//printf("%lld\n", res);
		cout<<"Case #"<<test<<": "<<res<<endl;
	}

	//time(&ltime1);

	//printf("Runtime in seconds:\t%ld\n", ltime1 - ltime0);

	return 0;
}

string lltostr(long long x){
	long long n, rt, i;
	char ch;
	string s, st;

	s=st="";
	n=0;
	if(x<0){
		s+='-';
		x=-x;
	}
	if(x==0) s="0";
	else{
		rt=x;
		while(rt>0){
			ch='0'+rt%10;
			st+=ch;
			rt/=10;
			n++;
		}
	}
	for(i=n-1;i>=0;i--) s+=st[i];

	return s;
}


