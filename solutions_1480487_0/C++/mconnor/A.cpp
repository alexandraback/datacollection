#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <functional>

#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef map<string,int> msi;

bool rev(int i, int j) { return (j<i);}

int main (void) {
    int T = 0;
    cin >> T;

    for (int c = 1; c<=T; ++c) {
		int N, X = 0, t;
		cin >> N;
		vi ss, sorted;
		ss.reserve(N);
		sorted.reserve(N);
		for (int i = 0; i<N; ++i) {
			cin >> t;
			ss.push_back(t);
			sorted.push_back(t);
			X += t;
		}
		sort(all(sorted), rev);

		int tN = N, tX = X;
		for (int i = 0; i<N && sorted[i]>(X+tX)/tN; i++) {
			tX -= sorted[i];
			tN--;
		}
		//cout<<"sorted[0] = "<<sorted[0]<<endl;
		//cout<<"tN = "<<tN<<", tX = "<<tX<<endl;

		printf("Case #%d:",c);
		for (int i = 0; i<N; ++i) {
			double a = double(X+tX - tN*ss[i])/(X*tN);
			if (a < 0) a = 0.0;
			printf(" %0.6f",a*100.0);
		}
		printf("\n");
    }

    return 0;
}
