#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <sstream>
using namespace std;

ifstream fin("in");
ofstream fout("out");

const int MAXN = 201;
int s[MAXN];
bool safe[MAXN];

int main() {
	int T; fin>>T;
	for(int t=1; t<=T; t++) {
		int N; fin>>N;
		int sum = 0;
		int nzeros=0;
		for(int i=0; i<N; i++) {
			fin >> s[i];
			sum += s[i];
		}
		int M=N;
		int subsum = sum;
		for(int i=0; i<N; i++) {
			safe[i] = (N*s[i]>=2*sum);
			if(safe[i]) {
				M--;
				subsum -= s[i];
			}
		}

		fout << "Case #" << t << ": ";
		for(int i=0; i<N; i++) {
			double miny=0.0;
			if(!safe[i])
				miny = 100.0*(sum+subsum-M*s[i]+0.0)/(M*sum+0.0);
			fout << fixed << setprecision(6) << miny << " ";
		}
		fout << endl;
	}

	return 0;
}

