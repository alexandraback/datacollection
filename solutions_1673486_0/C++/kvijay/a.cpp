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
		int A, B;
		cin >> A >> B;
		
		vector <double> p (A);
		FORZ (i, A)
			cin >> p[i];
		
		double allcorrect = 1.0;
		vector <double> correctuntil;
		
		FORZ (i, A) {
			allcorrect *= p[i];
			correctuntil.PB(allcorrect);
		}
		
		double a = (allcorrect * (B - A + 1));
		double b = (1.0 - allcorrect) * (B - A + 1 + B + 1);
		double poss1 = a + b;
		
		double c = (allcorrect * (B + 2));
		double d = (1.0 - allcorrect) * (B + 2);
		double poss2 = c + d;
		
		double ret = min(poss1, poss2);
		
		for (int bs = 1 ; bs <= A ; bs ++) {
			double x = correctuntil[A - bs - 1] * ( (2 * bs) + (B - A) + 1);
			double y = ( 1.0 - correctuntil[A - bs - 1] ) * ( (2 * bs) + (2 * B) + 2 - A );
			ret = min(ret, x + y);
		}
		
		printf ("Case #%d: %.6f\n", t, ret);
	}
	
	return 0;
}
