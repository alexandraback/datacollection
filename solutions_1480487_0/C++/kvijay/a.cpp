#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <bitset>
#include <cmath>
using namespace std;

#define FORZ(i,n) for(typeof(n)i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
#define PB push_back
#define sz size()
#define FF first
#define SS second
typedef vector<int> VI;
typedef pair<int,int> pII;
typedef vector<string> VS;
typedef long long LL;

int main () {
	int T;
	cin >> T;
	
	for (int t = 1 ; t <= T ; t ++) {
		int N;
		cin >> N;
		
		VI J(N);
		int X = 0;
		int minJ = (int) 1e9;
		
		FORZ (i, N) {
			cin >> J[i];
			X += J[i];
			minJ = min (minJ, J[i]);
		}
			
		vector <double> toget (N);
		double toget_tot = 0.0;
		FORZ (i, N) {
			int diff = abs(J[i] - minJ);
			toget[i] = diff * 100.0 / X;
			toget_tot += toget[i];
		}
		
		double val = 100.0;
		
		if (toget_tot >= 100.0) {
			val += (toget_tot / 100.0);
		}
		else {
			val += toget_tot;
		}
		val /= N * 1.0;
		
		
		vector <double> ret(N);
		FORZ (i, N) {
			ret[i] = abs(val - toget[i]);
		}
		
		printf ("Case #%d: ", t);
		FORZ (i, N - 1)
			printf ("%.5lf ", ret[i]);
		printf ("%.5lf\n", ret.back());
		
	}
	
	return 0;
}
