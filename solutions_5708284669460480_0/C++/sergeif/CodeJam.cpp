#include <cstdio>
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

typedef long long LL;
typedef long double LD;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int,int> PII;
#define FOR(k,a,b) for(typeof(a) k=(a); k <= (b); ++k)
#define REP(k,a) for(int k=0; k < (a); ++k)
#define REPD(k,a) for(int k=(a)-1; k >= 0; --k)
#define PB push_back 
#define MP make_pair

double prob[26];
int ress[26];
int ctrs[26];
int iinp[26];

int main()
{
	int t, T;
	cin >> T;
	

	for (int t = 1; t <= T; ++t) {
		int K,L,S;
		string sinp, coutp;
		memset(prob, 0, sizeof(double) * 26);
		memset(ctrs, 0, sizeof(int) * 26);
		cin >> K >> L >> S;
		std::map<int, int> cvs;
		cin >> sinp >> coutp;
		for (int i=0; i<K; i++) {
			int idx = sinp[i] - 'A';
			ctrs[idx] += 1;
		}
		int pos = 0;
		for (int i=0; i<K; i++) {
			int idx = sinp[i] - 'A';
			if (cvs.find(idx) == cvs.end()) {
				cvs[idx] = pos;
				prob[pos] = (double)ctrs[idx] / (double)K;
				pos++;
			}
		}
		int nDiffLetter = pos;
		bool bCan = true;
		for (int i=0; i<L; i++) {
			int idx = coutp[i] - 'A';
			if (cvs.find(idx) == cvs.end()){
				bCan = false;
				break;
			}else
				iinp[i] = cvs[idx];
		}
		if (! bCan) {
			cout << "Case #" << t << ": 0.0" << endl;
			continue;
		}
		double mat = 0;
		LL lim = pos;
		for (int i=1; i<S; i++) {
			lim *= pos;
		}
		auto nmax=  0;
		for (auto i=0LL; i < lim; i++) {
			int str[7] = { 0, 0, 0, 0, 0, 0, 0 };
			auto res = i;
			auto yy = 0;
			while (res > 0) {
				str[yy++] = res % pos;
				res = res / pos;
			}
			auto n = 0;
			for (auto p0=0; p0<S-L+1; p0++){
				bool bOk = true;
				for (auto p1=0; p1<L && p0 + p1 < S; p1++) {
					if (str[p0+p1] != iinp[p1]) {
						bOk = false;
						break;
					}
				}
				if (bOk) {
					n++;
					if (n > nmax) nmax = n;
				}
			}
			double probab = 1.0;
			for (auto p0=0; p0<S; p0++) {
				probab *= prob[str[p0]];
			}
			mat += probab * n;
		}
		std::cout.precision(7);
		cout << "Case #" << t << ": " << (nmax - mat) << endl;
	}

	return 0;
}
