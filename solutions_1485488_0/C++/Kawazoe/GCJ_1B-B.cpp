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
#define INF 10000000
#define L 15
s32 N,M,H;
s32 F[L][L], C[L][L];
double d[L][L];
bool ok[L][L];
s32 x,y,X,Y;
bool tide;

void Smart()
{
}

double Del()
{
	double r;
	s32 c=min(C[x][y],C[X][Y]);
	s32 f=max(F[x][y],F[X][Y]);
	if (c-f<50) return INF;
	double h=H-10*d[x][y];
	if (!tide) {
		if (h-c+50<=0) return 0;
	}
	double t=max(0,(h-c+50));
	double w=max(0,h-t-f);
	if (w>=20.0) r=t/10.0+1.0;
	else r=t/10.0+10.0;
	return r;
}

void Naive()
{
	cin >> H >> N >> M;
	FOR (i,0,N) FOR (j,0,M) cin >> C[i+1][j+1];
	FOR (i,0,N) FOR (j,0,M) cin >> F[i+1][j+1];
	FOR (i,0,N+2) C[0][i]=C[N+1][i]=C[i][0]=C[N+1][i]=0;
	FOR (i,0,N+2) F[0][i]=F[N+1][i]=F[i][0]=F[N+1][i]=0;
	FOR (i,0,N+2) FOR (j,0,M+2) d[i][j]=INF;
	FOR (i,0,N+2) FOR (j,0,M+2) ok[i][j]=false;
	tide=false;
	d[1][1]=0;
	
	s32 dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};
	while (true) {
		//find min
		double dm=1.0e+10;
		FOR (i,1,N+1) FOR (j,1,M+1) {
			if (!ok[i][j] && dm > d[i][j]) {
				dm = d[i][j];
				x = i; y=j;
			}
		}
		ok[x][y]=true;
		if (dm>0) tide=true;
		if (x==N && y==M) break;
		FOR (i,0,4) {
			X=x+dx[i], Y=y+dy[i];
			if (ok[X][Y]) continue;
			double d_new = d[x][y] + Del();
			d[X][Y] = min(d[X][Y], d_new);
		}
	}
	cout << d[x][y];
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
		Naive();
		cout << endl;
	}

	return 0;
}
