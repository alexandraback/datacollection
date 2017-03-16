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

//Google Code Jam 2012 Round 1B, Problem C code.google.com/codejam
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
	const long long nmin=1, nmax=1000000;
	long long test, cases, n, m, mt, res, i, j, k, t, rt, ax, a, t0, t1;
	//long long d0, d1, r;
	//char ch, ch0, ch1;
	//string sres[2]={"YES", "NO"};
	//string s, st, sr, s0, s1;
	//long double dt;

	//if(INPUT_FROM) from.open("test.txt");
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	//static long long v[nmax+1];
	vector<long long> v;
	//static long long vr[qmax];
	//deque<long long> dq;
	map<long long, long long> mi;
	//map<long long, vector<long long> > mi;
	//map<long long, vector<long long> >::iterator it;
	//typedef map<string, long long>::const_iterator CI;
	//time_t ltime0, ltime1;

	//time(&ltime0);


	//scanf("%lld\n", &cases);
	fromc>>cases;
	for(test=1;test<=cases;test++){
		//scanf("%lld %lld %lld %lld %lld\n", &a, &b, &c, &d, &k);
		fromc>>n;

		v.resize(n);
		for(i=0;i<n;i++) fromc>>v[i];

		ax=0;
		for(t=0;(t<(1<<n))&&(ax==0);t++){
			a=0;
			rt=t;
			for(i=0;i<n;i++){
				if(rt%2==1) a+=v[i];
				rt=(rt>>1);
			}
			if(mi.find(a)!=mi.end()){
				ax=1;
				t0=mi[a];
				t1=t;
			}else mi[a]=t;
		}


		//printf("%lld\n", res);
		cout<<"Case #"<<test<<":";
		if(ax==0) cout<<" Impossible"<<endl;
		else{
			cout<<endl;
			rt=t0;
			ax=1;
			for(i=0;i<n;i++){
				if(rt%2==1){
					if(ax==1){
						cout<<v[i];
						ax=0;
					}else cout<<' '<<v[i];
				}
				rt=(rt>>1);
			}
			cout<<endl;
			rt=t1;
			ax=1;
			for(i=0;i<n;i++){
				if(rt%2==1){
					if(ax==1){
						cout<<v[i];
						ax=0;
					}else cout<<' '<<v[i];
				}
				rt=(rt>>1);
			}
			cout<<endl;
		}

		v.clear();
		mi.clear();

	}

	//time(&ltime1);

	//printf("Runtime in seconds:\t%ld\n", ltime1 - ltime0);

	return 0;
}
