
#include <stdio.h>
#include <time.h>

#include <vector>
#include <list>
#include <set>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <queue>
#include <map>
#include <iomanip>
#include <sstream>
#define _USE_MATH_DEFINES
#include <cmath>
#include <stack>
#include <numeric>
#include <complex>

using namespace std;


typedef long long LL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef vector<LL> VL;
#define FORE(it, c, T) for(T::iterator it = c.begin(); it != c.end(); it++)
#define FORI(i, n) for(int i = 0; i < (n); i++)
#define FORIS(i, s, n) for(int i = (s); i < (n); i++)
#define CLEAR(a, n) memset(a, n, sizeof(a))
#define PB(n) push_back(n)
#define SZ(c) int((c).size())
#define ALL(c) (c).begin(), (c).end()

int T, K, N, N2;
int ks[50];
int ko[50];
int nn[50];
int p[50][50];
string m[1 << 21];
int cur[500];

template <class T> int count_bits(T n) { int res; for(res = 0; n; res++) n &= n-1; return res; }
template<class T> inline string toString(T a) { ostringstream is; is << a; is.flush(); return is.str(); }
typedef map<int, int> MII;

int main(int argc, char* argv[])
{
#define TASK_NAME(file) "D"file
#define FOLDER(file) "c:\\Projects\\coding\\cj\\2013\\QualificationRound\\"TASK_NAME("")"\\"file
//	ifstream in(FOLDER(TASK_NAME("-test.in")));
//	ofstream out(FOLDER(TASK_NAME("-test.out")));
	ifstream in(FOLDER(TASK_NAME("-small-attempt0.in")));
	ofstream out(FOLDER(TASK_NAME("-small-attempt0.out")));
//	ifstream in(FOLDER(TASK_NAME("-large.in")));
//	ofstream out(FOLDER(TASK_NAME("-large.out")));

	in >> T;
	FORI(ncase, T) {
		in >> K >> N;
		N2 = 1<<N;
		FORI(i, K) in >> ks[i];
		FORI(i, N) {
			in >> ko[i] >> nn[i];
			FORI(j, nn[i])
				in >> p[i][j];
		}
		FORI(i, N2) m[i] = "-";
		FORI(j, N) {
			bool gd = 0;
			FORI(k, K)
				if(ks[k] == ko[j]) {
					gd = 1;
					break;
				}
			if(gd)
				m[1 << j] = 'a'+j;
		}
		FORIS(i, 1, N) {
			FORI(j, N2) {
				if(count_bits(j) != i) continue;
				if(m[j] == "-") continue;
				CLEAR(cur, 0);
				FORI(s, K)
					cur[ks[s]]++;

				FORI(s, N) {
					if((1 << s) & j) {
						FORI(l, nn[s])
							cur[p[s][l]]++;
						cur[ko[s]]--;
					}
				}
				FORI(k, 205) {
					if(cur[k] > 0) {
						FORI(s, N) {
							if(ko[s] == k && !((1<<s) & j)) {
								string mm = m[j] + char('a'+s);
								int jj = j | (1<<s);
								if(m[jj] == "-" || m[jj] > mm)
									m[jj] = mm;
							}
						}
					}
				}
			}
		}

		string res_s = m[N2-1];
		
		string res;
		if(res_s == "-")
			res = "IMPOSSIBLE";
		else {
			FORI(i, res_s.length()) {
				res += toString(((int)(res_s[i]-'a'))+1) + " ";
			}
			res = res.substr(0, res.length()-1);
		}

		out << "Case #" << (ncase+1) << ": " << res << endl;
	}
	return 0;
}
