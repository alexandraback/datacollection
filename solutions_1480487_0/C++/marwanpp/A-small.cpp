/*
 * A-small.cpp
 *
 *  Created on: May 5, 2012
 *      Author: Marwan
 */
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstring>
#include <sstream>
#include <complex>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <bitset>
#include <climits>
#include <set>
#include <map>

using namespace std;

const int oo = (int) 1e9;
const double PI = 2 * acos(0.0);
const double eps = 1e-9;
#define MP make_pair
#define SZ(x) (int)x.size()

typedef long long ll;
typedef pair<int, int> pii;

#define SMALL

int main() {
#ifdef SMALL
	freopen("A-small.in", "rt", stdin);
    freopen ("A-small.txt" , "wt" , stdout) ;
#endif
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		printf("Case #%d: ", t);
		int N;
		scanf("%d", &N);

		double sum = 0.0;
		vector<double> arr(N);
		for (int i = 0; i < N; ++i)
			scanf("%lf", &arr[i]), sum += arr[i];

		string ss = "";
		for (int i = 0; i < N; ++i) {
			double lo = 0.0 , hi = 1.0 ;
			for (int c =0  ; c < 100 ; c++ ){
//				cout << lo << " lo - hi " << hi << endl ;
				double mid = lo + ((hi - lo) / 2) ;
				double nval = arr[i] + (sum * mid) ;
//				cout << mid << " mid - nval " << nval << endl ;

				double need = 0.0 ;

				for (int j = 0; j < N; ++j)
					if (arr[j] < nval && j != i)
						need += ((nval - arr[j]) / (sum)) ;

//				cout << need << " " << mid << endl << endl ;
				if ( (mid + need) - 1.0 > eps)
					hi = mid ;
				else if ( 1.0 - (mid + need) > eps)
					lo = mid ;
				else
					hi = lo = mid ;
			}

//			for (ans = 0.00000 ; ans < 1.00000 ; ans += 0.00001){
//				double nval = arr[i] + (sum * ans) ;
//				double need = 0.0 ;
//
//				for (int j = 0; j < N; ++j)
//					if (arr[j] < nval && j != i)
//						need += ((nval - arr[j]) / (sum)) ;
//
//				if (ans + need > 1.0)
//					break ;
//			}
			cout << ss ;
			printf("%.5lf", hi*100);
			ss = " ";
		}
		cout << endl;
	}
	return 0;
}
