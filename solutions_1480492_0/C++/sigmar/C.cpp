#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <list>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <numeric>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <iterator>
#include <complex>
#include <stack>
#include <queue>
#include <ctime>
//#include <NTL/ZZ.h>
using namespace std;
//using namespace NTL;
static const double EPS = 1e-8;
typedef long long ll;
typedef unsigned long long ull;
typedef complex <double> pt;
typedef complex <ll> pti;

int dfs(int N, int g[52][52], int col[52], int icol[52], int canchg[52], int d) {
	int res=1;
	for(int i=0; i<N; i++) {
		if(g[d][i]) {
			if(col[d]==col[i]) return 0;
			if(!canchg[i] && col[d]==icol[i]) return 0;
			if(col[i]==-1) {
				col[i]=1-col[d];
				icol[i]=col[i];
				res&=dfs(N, g, col, icol, canchg, i);
			}
		}
	}

	return res;
}

int isbipertite(int N, int g[52][52], int icol[52], int canchg[52]) {
	int col[52];
	memset(col, -1, sizeof(col));
	for(int i=0; i<N; i++) {
		if(col[i]==-1) {
			col[i]=icol[i];
			int res1=dfs(N, g, col, icol, canchg, i);
			int res2=0;
			if(canchg[i]) {
				col[i]=1-col[i];
				res2=dfs(N, g, col, icol, canchg, i);
			}
			if(!res1 && !res2) return 0;
			if(res1) icol[i]=0;
			else icol[i]=1;
		}
	}

	return 1;
}

double solve(int N, string C, vector <int> S, vector <int> P) {
	double res=1e100;
	
	vector <pair <double, pair <int, int> > > candt;
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			if(P[i]<=P[j]) continue;
			if(S[i]>=S[j]) continue;
			double t1=(double)(P[i]-P[j]-5)/(S[j]-S[i]);
			if(t1>0) candt.push_back(make_pair(t1, make_pair(i, j)));
			double t2=(double)(P[i]+5-P[j])/(S[j]-S[i]);
			candt.push_back(make_pair(t2, make_pair(j, i)));
		}
	}

	sort(candt.begin(), candt.end());
	int g[52][52]={0};
	int canchg[52]={0};
	for(int i=0; i<N; i++) {
		canchg[i]=1;
		for(int j=i+1; j<N; j++) {
			if(abs(P[i]-P[j])<=5) g[i][j]=g[j][i]=1;
			if(abs(P[i]-P[j])<5) canchg[i]=0;
		}
	}
	int icol[52]={0};
	for(int i=0; i<N; i++) {
		icol[i]=(C[i]=='R');
	}
	for(int i=0; i<(int)candt.size(); i++) {
		double t=candt[i].first;
		int c1=candt[i].second.first, c2=candt[i].second.second;
		if(P[c1]>P[c2]) g[c1][c2]=g[c2][c1]=1;
		else g[c1][c2]=g[c2][c1]=0;
		if(i+1<(int)candt.size() && abs(t-candt[i+1].first)<=EPS) continue;
		if(!isbipertite(N, g, icol, canchg)) return t;
		for(int j=0; j<N; j++) {
			canchg[j]=1;
			for(int k=0; k<N; k++) {
				if(g[j][k]) canchg[j]=0;
			}
		}
	}

	return 1e100;
}

int main() {
	int practice=0;
	string prb[12];
	const string difficulty[2][2]={{"-small-attempt.in", "-large.in"}, {"-small-practice.in", "-large-practice.in"}};
	const string extension="";
	//const string extension=".txt";

	char key;
	while(1) {
		for(int i=0; i<12; i++) {
			prb[i].assign(1, 'A'+i/2);
			prb[i]+=difficulty[practice][i%2];
			prb[i]+=extension;
			cout << (char)(i%2?('A'+i/2):('a'+i/2)) << ". " << prb[i] << endl;
		}
		cout << "p. " << (practice?"change to practice mode.":"change to match mode.") << endl;

		do {
			cout << "Choose the input file." << endl;
			cin >> key;
		} while(!('a'<=key && key<'a'+6) && !('A'<=key && key<'A'+6) && key!='p');
		if(key!='p') break;
		practice^=1;
		system("cls");
	}

	int index, cap;
	if(key>='a') { index=(key-'a')*2; cap=0; }
	else { index=(key-'A')*2+1; cap=1; }
	string filename=prb[index];

	if(!cap && !practice) {
		do {
			cout << "Choose number of attempt times." << endl;
			cin >> key;
		} while(key<'0' || '9'<key);
		filename.insert(15, 1, key);
	}

	cout << "Filename is " << filename << endl;
	ifstream ifs(filename.c_str());

	ofstream ofs("output.txt");

	int testcase;
	ifs >> testcase; ifs.ignore();
	for(int testnum=1; testnum<=testcase; testnum++) {
		int N;
		ifs >> N;
		string C(N, ' ');
		vector <int> P(N), S(N);
		for(int i=0; i<N; i++) ifs >> C[i] >> S[i] >> P[i];
		double res=solve(N, C, S, P);
		ofs << "Case #" << testnum << ": ";
		if(res>=1e100) ofs << "Possible" << endl;
		else ofs << fixed << setprecision(15) << res << endl;
	}
}

//Powered by NTL-5.5.2 (http://www.shoup.net/ntl/)