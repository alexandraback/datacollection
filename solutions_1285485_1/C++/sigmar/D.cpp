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
#include <cassert>
//#include <NTL/ZZ.h>
using namespace std;
//using namespace NTL;
static const double EPS = 1e-8;
typedef long long ll;
typedef unsigned long long ull;
typedef complex <double> pt;
typedef complex <ll> pti;

int solve(int H, int W, int D, vector <string> hall) {
	int res=0;
	vector <string> hl[2][2];
	hl[0][0]=hall;
	for(int i=H-1; i>=0; i--) hl[1][0].push_back(hall[i]);
	for(int i=0; i<H; i++) {
		hl[0][1].push_back("");
		for(int j=W-1; j>=0; j--) hl[0][1][i].push_back(hall[i][j]);
	}
	for(int i=H-1; i>=0; i--) hl[1][1].push_back(hl[0][1][i]);

	for(int rot=0; rot<4; rot++) {
		int rmir=rot/2, cmir=rot%2;
		int xr=0, xc=0;
		for(int i=0; i<H; i++) {
			for(int j=0; j<W; j++) {
				if(hl[rmir][cmir][i][j]=='X') {
					xr=i; xc=j;
				}
			}
		}
		
		if(rmir==0) {
			for(int i=xc+1; i<W; i++) {
				if(hl[rmir][cmir][xr][i]=='#') {
					if((i-xc-1)*2+1<=D) res++;
					break;
				}
			}
		}
		if(cmir==0) {
			for(int i=xr+1; i<H; i++) {
				if(hl[rmir][cmir][i][xc]=='#') {
					if((i-xr-1)*2+1<=D) res++;
					break;
				}
			}
		}

		for(int r=1; r<=D; r++) {
			for(int c=1; c<=D; c++) {
				if(r*r+c*c>D*D) continue;
				int base=r*c*4;
				int cr=xr*base+base/2, cc=xc*base+base/2;
				int tgor=0, tgoc=0;
				rmir=rot/2, cmir=rot%2;
				bool ok=true;
				while(1) {
					int remr=base-cr%base, remc=base-cc%base;
					int nr=cr+remc*r/c, nc=cc+remr*c/r;
					assert(remc*r%c==0); assert(remr*c%r==0);
					bool rover=(cr/base!=nr/base), cover=(cc/base!=nc/base);
					int nrp=nr/base, ncp=nc/base;
					if(rover && cover && hl[rmir][cmir][nrp][ncp]=='#' && hl[rmir][cmir][nrp-1][ncp]=='#' && hl[rmir][cmir][nrp][ncp-1]=='#') {
						tgor=tgor+remr;
						tgoc=tgoc+remc;
						cr=nr;
						cc=nc;
						rmir=1-rmir;
						cmir=1-cmir;
						cr=H*base-cr;
						cc=W*base-cc;
					} else if(rover && cover && hl[rmir][cmir][nrp][ncp]!='#') {
						tgor=tgor+remr;
						tgoc=tgoc+remc;
						cr=nr;
						cc=nc;
					} else if(rover && cover && hl[rmir][cmir][nrp][ncp]=='#' && hl[rmir][cmir][nrp-1][ncp]!='#' && hl[rmir][cmir][nrp][ncp-1]!='#') {
						ok=false;
						break;
					} else if(rover && !cover || rover && cover && hl[rmir][cmir][nrp][ncp]=='#' && hl[rmir][cmir][nrp-1][ncp]!='#' && hl[rmir][cmir][nrp][ncp-1]=='#') {
						tgor=tgor+remr;
						tgoc=tgoc+(nc-cc);
						cr=cr+remr;
						cc=nc;
						if(hl[rmir][cmir][cr/base][cc/base]=='#') {
							rmir=1-rmir;
							cr=H*base-cr;
						}
					} else if(!rover && cover || rover && cover && hl[rmir][cmir][nrp][ncp]=='#' && hl[rmir][cmir][nrp-1][ncp]=='#' && hl[rmir][cmir][nrp][ncp-1]!='#') {
						tgor=tgor+(nr-cr);
						tgoc=tgoc+remc;
						cr=nr;
						cc=cc+remc;
						if(hl[rmir][cmir][cr/base][cc/base]=='#') {
							cmir=1-cmir;
							cc=W*base-cc;
						}
					} else {
						cerr << "something wrong." << endl;
						exit(1);
					}
					int crp=cr/base, ccp=cc/base;
					if(hl[rmir][cmir][crp][ccp]=='X') {
						int cxr=(crp*2+1)*base/2, cxc=(ccp*2+1)*base/2;
						if((cxr-cr)*c==(cxc-cc)*r) {
							if(tgor+(cxr-cr)==r*base && tgoc+(cxc-cc)==c*base) break;
							ok=false;
							break;
						}
					}
				}
				if(ok) res++;
			}
		}
	}
	
	return res;
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
		int H, W, D;
		ifs >> H >> W >> D;
		vector <string> hall(H);
		for(int i=0; i<H; i++) ifs >> hall[i];
		int res=solve(H, W, D, hall);
		ofs << "Case #" << testnum << ": ";
		ofs << res << endl;
	}
}

//Powered by NTL-5.5.2 (http://www.shoup.net/ntl/)