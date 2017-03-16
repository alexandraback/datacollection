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

//Google Code Jam 2015 Qualification Round, Problem A code.google.com/codejam
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
	const int nmin=1, nmax=4;
	int test, cases, n, m, mt, res, rt, i, j, k, t, ax, a;
	int i0, i1, i2;
	int r, r0, r1;
	char ch;
	//string sres[2]={"YES", "NO"};
	//string sres[2]={"Bad magician!", "Volunteer cheated!"};
	//string s, st, sr;
	//long double dt;

	//if(INPUT_FROM) from.open("test.txt");
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	static int vv0[nmax][nmax], vv1[nmax][nmax];
	vector<int> vr;
	//deque<long long> dq;
	//map<char, char> mc;
	//map<long long, long long>::iterator it;
	//typedef map<string, long long>::const_iterator CI;


	scanf("%d\n", &cases);
	//cin >> cases;
	for(int test=1;test<=cases;test++){
		scanf("%d ", &n);

		r = r1 = 0;
		for(int i=0;i<=n;++i){
			scanf("%c", &ch);
			if(r1 < i) r += i - r1, r1 = i;
			r1 += (ch - '0');
			//cout << ch << endl;
		}

		cout<<"Case #"<<test<<": "<<r<<endl;
		//else if(t==0) cout<<"Case #"<<test<<": "<<sres[1]<<endl;
		//else cout<<"Case #"<<test<<": "<<sres[0]<<endl;

		//cout<<"Case #"<<test<<": "<<sres[ax]<<endl;
	}

	return 0;
}

