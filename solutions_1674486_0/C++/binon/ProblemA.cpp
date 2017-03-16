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

//Google Code Jam 2012 Round 1C, Problem A code.google.com/codejam
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
	long long test, cases, n, m, nt, mt, res, rt, i, j, k, t, ax;
	long long i0, i1;
	//char ch;
	string sres[2]={"No", "Yes"};
	//string s, st, sr;
	//long double dt, dr, d0, d1, dp;

	//if(INPUT_FROM) from.open("test.txt");
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	//vector<long long> v;
	//vector<long double> vr;
	//deque<long long> dq;
	//map<char, char> mc;
	//map<long long, long long>::iterator it;
	//typedef map<string, long long>::const_iterator CI;
	vector<long long> colour, vt;
	vector<vector<long long> > adj, adjt;

	//scanf("%ld\n", &cases);
	fromc>>cases;
	for(test=1;test<=cases;test++){
		fromc>>n;

		adj.resize(n);
		colour.resize(n);

		for(i=0;i<n;i++){
			fromc>>m;
			i0=i;
			for(j=0;j<m;j++){
				fromc>>i1;
				i1--;
				adj[i0].push_back(i1);
			}
			//fromc>>rt;
		}

		ax=0;
		for(i=0;(i<n)&&(ax==0);i++){
			for(j=0;j<n;j++) colour[j]=0;
			adjt=adj;
			k=i;
			vt.push_back(k);
			colour[k]=1;//grey
			mt=1;
			while((mt>0)&&(ax==0)){
				i0=vt.back();
				vt.pop_back();
				mt--;
				m=adjt[i0].size();
				ax=0;
				for(j=0;(j<m)&&(ax==0);j++){
					i1=adjt[i0].back();
					if(colour[i1]==0){//white
						vt.push_back(i1);
						mt++;
						colour[i1]=1;//grey
					}else{//found a diamond inheritance
						ax=1;
					}
					adjt[i0].pop_back();
				}
			}
			vt.clear();
			adjt.clear();
		}


		//scanf("%ld\n", &n);

		//cout.setf(ios::fixed);
		//cout.precision(6);
		cout<<"Case #"<<test<<": "<<sres[ax]<<endl;
		//cout<<"Case #"<<test<<":";
		//for(i=0;i<n;i++) cout<<' '<<vr[i];
		//cout<<endl;
		adj.clear();
		colour.clear();
	}

	return 0;
}

