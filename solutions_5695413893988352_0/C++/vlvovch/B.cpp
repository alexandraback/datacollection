#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int T;
string C, J;

int solC, solJ;
int dif;

void solve() {
	if (C.size()==1) {
		int tC1 = 0, tC2 = 0;
		rep(i1,10) {
			if (C[0]!='?' && i1!=(int)(C[0]-'0')) continue;

			rep(i2,10) {
				if (J[0]!='?' && i2!=(int)(J[0]-'0')) continue;

				
				int tdif = abs(i1-i2);
				bool fl = false;
				if (dif==-1 || tdif<dif) fl = true;
				if (tdif==dif && i1<solC) fl = true;
				if (tdif==dif && i1==solC && i2<solJ) fl = true;

				if (fl) {
					solC = i1;
					solJ = i2;
					dif = tdif;
				}
			}
		}
	}

	if (C.size()==2) {
		rep(i1,10) {
			if (C[0]!='?' && i1!=(int)(C[0]-'0')) continue;
			rep(i12,10) {
				if (C[1]!='?' && i12!=(int)(C[1]-'0')) continue;
				rep(i2,10) {
					if (J[0]!='?' && i2!=(int)(J[0]-'0')) continue;
					rep(i22,10) {
						if (J[1]!='?' && i22!=(int)(J[1]-'0')) continue;

						int t1 = i1*10 + i12;
						int t2 = i2*10 + i22;
						int tdif = abs(t1-t2);
						bool fl = false;
						if (dif==-1 || tdif<dif) fl = true;
						if (tdif==dif && t1<solC) fl = true;
						if (tdif==dif && t1==solC && t2<solJ) fl = true;

						if (fl) {
							solC = t1;
							solJ = t2;
							dif = tdif;
						}
					}
				}
			}
		}
	}


	if (C.size()==3) {
		rep(i1,10) {
			if (C[0]!='?' && i1!=(int)(C[0]-'0')) continue;
			rep(i12,10) {
				if (C[1]!='?' && i12!=(int)(C[1]-'0')) continue;
				rep(i13,10) {
					if (C[2]!='?' && i13!=(int)(C[2]-'0')) continue;
					rep(i2,10) {
						if (J[0]!='?' && i2!=(int)(J[0]-'0')) continue;
						rep(i22,10) {
							if (J[1]!='?' && i22!=(int)(J[1]-'0')) continue;
							rep(i23,10) {
								if (J[2]!='?' && i23!=(int)(J[2]-'0')) continue;

								int t1 = i1*100 + i12*10 + i13;
								int t2 = i2*100 + i22*10 + i23;
								int tdif = abs(t1-t2);
								bool fl = false;
								if (dif==-1 || tdif<dif) fl = true;
								if (tdif==dif && t1<solC) fl = true;
								if (tdif==dif && t1==solC && t2<solJ) fl = true;

								if (fl) {
									solC = t1;
									solJ = t2;
									dif = tdif;
								}
							}
						}
					}
				}
			}
		}
	}
}

int main()
{
    fstream fin("B-small-attempt0.in",ifstream::in);
    fstream fout("B-small-attempt0.out",ofstream::out);
    fin >> T;
	for(int tc=1;tc<=T;tc++)
    {
		fin >> C >> J;
		solC = 0;
		solJ = 0;
		dif = -1;
		solve();
		string retC, retJ;
		retC.resize(C.size());
		retJ.resize(J.size());

		rep(i,retC.size()) { retC[retC.size()-i-1] = solC%10 + '0'; solC /= 10; }
		rep(i,retJ.size()) { retJ[retJ.size()-i-1] = solJ%10 + '0'; solJ /= 10; }

		fout << "Case #" << tc << ": " << retC << " " << retJ << "\n";
    }
    fin.close();
    fout.close();
    cout << "running time=" << clock()/(double)CLOCKS_PER_SEC << "\n";
    //system("PAUSE");
    return 0;
}
