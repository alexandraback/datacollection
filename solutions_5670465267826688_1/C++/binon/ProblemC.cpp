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

//Google Code Jam 2015 Qualification Round, Problem C code.google.com/codejam
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
	const int nmin=1, nmax=5;
	int test, cases, n, m, mt, res, i, j, k, t, rt, ax, bx;
	int i0, i1, j0, j1, t0, t1, r, c;
	int a, b, a0, a1, r0, r1;
	long long xx, jj1;
	char ch, ch0, ch1;
	//string sres[2]={"YES", "NO"};
	//string s, st, sr, s0, s1, s2;
	//long double dt;

	//if(INPUT_FROM) from.open("test.txt");
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	//static long long v[nmax+1], v10[pmax], vt[pmax];
	vector<int> v, vr;
	vector<vector<int> > vv(5);
	//static long long vr[qmax];
	//deque<int> dq, dq0, dq1, dq2;
	map<char, int> mc;
	//map<long long, vector<long long> > mi;
	//map<long long, vector<long long> >::iterator it;
	//typedef map<string, long long>::const_iterator CI;
	//time_t ltime0, ltime1;

	//time(&ltime0);

	// 1 - 1, 2 - i, 3 - j, 4 - k
	for(int i=0;i<5;++i) vv[i].resize(5);
	vv[1][1] = 1; vv[1][2] =  2; vv[1][3] =  3; vv[1][4] =  4;
	vv[2][1] = 2; vv[2][2] = -1; vv[2][3] =  4; vv[2][4] = -3;
	vv[3][1] = 3; vv[3][2] = -4; vv[3][3] = -1; vv[3][4] =  2;
	vv[4][1] = 4; vv[4][2] =  3; vv[4][3] = -2; vv[4][4] = -1;

	mc['1'] = 1; mc['i'] = 2; mc['j'] = 3; mc['k'] = 4;

	//scanf("%lld\n", &cases);
	fromc>>cases;
	for(int test=1;test<=cases;++test){
		//scanf("%lld %lld %lld %lld %lld\n", &a, &b, &c, &d, &k);
		cin >> n >> xx;


		v.resize(n);
		r0 = 1; i0 = i1 = -1;
		for(int i=0;i<n;++i){
			cin >> ch;
			v[i] = r1 = mc[ch];
			if(r0 < 0) r0 = -vv[-r0][r1];
			else r0 = vv[r0][r1];
			if((i0 == -1)&&(r0 == 2)) i0 = i, j0 = 0;
		}

		// total result
		r = r0;
		a = (xx - 1)%4;
		if(r0 < 0){
			for(int i=0;i<a;++i){
				if(r < 0) r =  vv[-r0][-r];
				else      r = -vv[-r0][ r];
			}
		}else{
			for(int i=0;i<a;++i){
				if(r < 0) r = -vv[r0][-r];
				else      r =  vv[r0][ r];
			}
		}

		//cout << r << ' ' << i0 << endl;

		if(r == -1){
			if(i0 == -1){
				for(int j=1;(j<4)&&(j < xx)&&(i0 == -1);++j){
					for(int i=0;(i<n)&&(i0 == -1);++i){
						r1 = v[i];
						if(r0 < 0) r0 = -vv[-r0][r1];
						else r0 = vv[r0][r1];
						if(r0 == 2) i0 = i, j0 = j;
					}
				}
			}

			if(i0 >= 0){
				i1 = j1 = -1;
				r0 = 1;
				for(int j=0;(j<4)&&(j < xx)&&(i1 == -1);++j){
					for(int i = n - 1;(i >= 0)&&(i1 == -1);--i){
						r1 = v[i];
						if(r0 < 0) r0 = -vv[r1][-r0];
						else r0 = vv[r1][r0];
						if(r0 == 4) i1 = i, jj1 = xx - 1 - j;
					}
				}
			}
		}

		ax = 0;
		// must be ijk = -1 = r
		if((i0 >= 0)&&(i1 >= 0)&&(r == -1)){
			if(1LL*n*j0 + i0 < n*jj1 + i1) ax = 1;
		}


		if(ax==0) cout << "Case #" << test << ": " << "NO"  << endl;
		else      cout << "Case #" << test << ": " << "YES" << endl;

		//printf("%lld\n", res);
		//cout<<"Case #"<<test<<": "<<res<<endl;
		v.clear();
	}

	//time(&ltime1);

	//printf("Runtime in seconds:\t%ld\n", ltime1 - ltime0);

	return 0;
}

