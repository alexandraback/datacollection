#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define FOR(i, a, b) for (int i(a), _b(b); i <= _b; ++i)
#define REP(i, n) for (int i(0), _n(n); i < _n; ++i)

int main(void){
	int T, r,c,m;

	ifstream fin("C-large.in");
	ofstream fout("out.txt");
	fin >> T;
	REP(t, T){
		fout << "Case #" << t+1 << ":\n";
		fin >> r >> c >> m;
//fout << r << " " << c << " " << m << endl;
		if(r*c - m == 1){
			fout << "c";
			REP(q,c - 1) fout << "*";
			fout << endl;
			REP(w, r-1){
				REP(q,c) fout << "*";
				fout << endl;
			}
			continue;
		}
		if(r==1){
			REP(q, m) fout << "*";
			REP(q,c-m-1)fout << ".";
			fout << "c\n";
			continue;
		}
		if(c==1){
			REP(q, m) fout << "*\n";
			REP(q,r-m-1)fout << ".\n";
			fout << "c\n";
			continue;
		}
		if(r*c - 4 < m){
			fout << "Impossible\n";
			continue;
		}
		if(r==2){
			if(m%2 == 1){
				fout << "Impossible\n";
				continue;
			}
			fout << "c";
			REP(q, c - m/2 - 1) fout << ".";
			REP(q, m/2) fout << "*";
			fout << endl;
			REP(q, c - m/2) fout << ".";
			REP(q,m/2) fout << "*";
			fout << endl;

			continue;
		}
		if(c == 2){
			if(m%2 == 1){
				fout << "Impossible\n";
				continue;
			}
			fout << "c.\n";
			REP(q, r - m/2 - 1)fout << "..\n";
			REP(q,m/2) fout << "**\n";
			continue;
		}
		
		int fr, sqrt_fr, s, rdone;
		s = r*c;
		fr = r*c - m;
		if(fr > 2*c + 1){
			rdone = 0;
			fout << "c";
			REP(q, c-1) fout << ".";
			fout << endl; rdone++;
			fr -= c;
			while(fr > 2*c){
				REP(q, c) fout << ".";
				fout << endl;rdone++;
				fr -= c;
			}
			if((fr % c) == 1){
				REP(q, c-1) fout << ".";
				fout << "*";
				fout << endl;rdone++;
				fout << "..";
				REP(q, c-2) fout << "*";
				fout << endl;rdone++;
			} else {
				REP(q, c) fout << ".";
				fr-=c;
				fout << endl;rdone++;
				REP(q, fr)fout << ".";
				REP(q,c-fr)fout << "*";
				fout << endl;rdone++;
			}
			REP(w, r - rdone){
				REP(q, c)fout << "*";
				fout << endl;
			}
			continue;
		}
		
		if(fr > 2 * r + 1){
			rdone = 0;
			if(fr % r == 1){
				REP(i, fr / r - 1) fout << ".";
				REP(i, c - fr / r + 1) fout << "*";
				fout << endl;
				REP(w, r - 3){
					REP(i, fr / r) fout << ".";
					REP(i, c - fr / r) fout << "*";
					fout << endl;
				}
				REP(i, fr / r + 1) fout << ".";
				REP(i, c - fr / r - 1) fout << "*";
				fout << endl;

				fout << "c";
				REP(i, fr / r) fout << ".";
				REP(i, c - fr / r - 1) fout << "*";
				fout << endl;
			} else {
				REP(w, fr % r){
					REP(i, fr / r + 1) fout << ".";
					REP(i, c - fr / r - 1) fout << "*";
					fout << endl;
				}
				REP(w, r - (fr % r) - 1){
					REP(i, fr / r) fout << ".";
					REP(i, c - fr / r) fout << "*";
					fout << endl;
				}
				fout << "c";
				REP(i, fr / r - 1) fout << ".";
				REP(i, c - fr / r) fout << "*";
				fout << endl;
			}
			continue;
		}
		
		int mn, good, tmp;
		mn = max(r,c);
		good = 0;
		FOR(i,2,min(mn, fr/2)){
			if(fr % i != 1){
				good = i;
				break;
			}
		}
		if(!good){
			fout << "Impossible\n";
			continue;
		}
		if(good>r){
			rdone = 0;
			fout << "c";
			REP(q, good - 1) fout << ".";
			REP(q,c - good) fout << "*";
			fout << endl; rdone++;
			fr -= good;
			while(fr >= good){
				REP(q, good) fout << ".";
				REP(q,c - good) fout << "*";
				fout << endl; rdone++;
				fr -= good;
			}
			REP(q, fr) fout << ".";
			REP(q,c - fr) fout << "*";
			fout << endl; rdone++;
			REP(w, r - rdone){
				REP(q, c) fout << "*";
				fout << endl; 
			}
		} else {
			rdone = 0;	
			if(fr % good != 0){
				good = fr / good + 1;
			} else {
				good = fr / good;
			}

			fout << "c";
			REP(q, good - 1) fout << ".";
			REP(q,c - good) fout << "*";
			fout << endl; rdone++;
			fr -= good;
			while(fr >= good){
				REP(q, good) fout << ".";
				REP(q,c - good) fout << "*";
				fout << endl; rdone++;
				fr -= good;
			}
			REP(q, fr) fout << ".";
			REP(q,c - fr) fout << "*";
			fout << endl; rdone++;
			REP(w, r - rdone){
				REP(q, c) fout << "*";
				fout << endl; 
			}
		}
	}
	return 0;
}
