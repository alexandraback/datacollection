#include <stdio.h>
#include <cstdlib>
#include <string.h>
#include <math.h>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include "windows.h"
//#include "../../gmp_int.h"
//#include "../../common.h"
#define MAX(a, b)		((a)>(b)?(a):(b))
#define MAX3(a, b, c)	(MAX((a),MAX((b),(c))))
#define FOR(a,b,c)		for (s32(a)=(b);(a)<(s32)(c);(a)++)
#define BL				{char bl[10];cin.getline(bl, 10);}
#define GL(c)			cin.getline(c, sizeof(c))
typedef char					s8;
typedef unsigned char			u8;
typedef short					s16;
typedef unsigned short			u16;
typedef int						s32;
typedef unsigned int			u32;
typedef long long int			s64;
typedef unsigned long long int	u64;
using namespace std;

ifstream test_input;
#define cin test_input
#define M 100
#define INF 100000000
s32 a[M], b[M];
s32 N;
s32 dm;
struct P {
	s32 n, s, l;
};
bool operator < (const P &p1, const P &p2) {
	if (p1.n!=p2.n) return p1.n<p2.n;
	if (p1.s!=p2.s) return p1.s<p2.s;
	if (p1.l!=p2.l) return p1.l<p2.l;
	return false;
}
set<pair<s32,vector<P>>> dic;

void Smart()
{
}

void Next(s32 d, s32 s, vector<P> v)
{
	if (dm<=d) return;
	bool ok=true;	//ƒNƒŠƒAH
	s32 ad=0;
	FOR (i,0,v.size()) {
		if (v[i].l==2) {
			if (v[i].s<=s) {
				ad ++;
			} else {
				ok=false;
				break;
			}
		}
	}
	if (ok) {
		dm = min(dm,d+ad);
		return;
	}
	FOR (i,0,v.size()) {	// l2—Dæ
		if (v[i].s>s) continue;
		if (v[i].l==2) {
			bool ok=false;
			if (i!=0) {
				if (v[i-1].n==v[i].n) ok=true;
			}
			if (i!=v.size()-1) {
				if (v[i+1].n==v[i].n) ok=true;
			}
			if (ok) {
				vector<P> v_new;
				FOR (j,0,v.size()) if (i!=j) v_new.push_back(v[j]);
				Next(d+1, s+3, v_new);
				return;
			}
		}
	}

	FOR (i,0,v.size()) {
		if (s<v[i].s) continue;
		s32 s_new = s + v[i].l;
		vector<P> v_new;
		FOR (j,0,v.size()) {
			if (i!=j) v_new.push_back(v[j]);
		}
		if (v[i].l==2) {
			bool more=true;
			FOR (j,0,v.size()) {
				if (v[j].n==v[i].n && v[j].l==1) {
					more=false;
					break;
				}
			}
			if (more) s_new ++;
		}
		Next(d+1, s_new, v_new);
	}
}

s32 Naive()
{
	dm = INF;
	vector<P> v;
	dic.clear();
	FOR (i,0,N) {
		P p = { i,a[i],1 };
		v.push_back(p);
		P q = { i,b[i],2 };
		v.push_back(q);
	}
	Next(0,0,v);
	return dm;
}

int main(int argc, char* argv[])
{
	cout.precision(15);
	if (argc!=2) {
		cout << "Need input file name." << endl;
		return 0;
	}
	test_input.open(argv[1]);
	if (test_input.fail()) {
		cout << "Cannot open input file " << argv[1] << "." << endl;
		return 0;
	}

	s32 num_of_trial;
	cin >> num_of_trial;
	FOR (tt,0,num_of_trial) {
		cout << "Case #" << tt+1 << ": ";
		cin >> N;
		FOR (i,0,N) cin >> a[i] >> b[i];
		s32 r0 = Naive();
		if (r0==INF) cout << "Too Bad" << endl;
		else cout << r0 << endl;
	}

	return 0;
}
