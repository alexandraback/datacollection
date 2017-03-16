/*
 * c-small.cpp
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
	freopen("c-small.in", "rt", stdin);
	freopen("c-small.txt", "wt", stdout);
#endif
	int T;
	int arr[20];
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		map <int , vector <int> > mp ;
		printf("Case #%d:\n", t);
		int N;
		scanf("%d", &N);
		for (int i = 0; i < N; ++i)
			scanf("%d", &arr[i]);

		for (int msk = 0; msk < (1 << 20); ++msk) {
			int sum = 0 ;
			for (int i = 0; i < N; ++i)
				if (msk & (1 << i))
					sum += arr[i];

			if (mp.find(sum) != mp.end()){
				vector <int> vi = mp[sum] ;

				for (int i = 0; i < SZ(vi); ++i) {
					if ((msk & vi[i]) == 0){

						string s = "" ;
						for (int j=0 ; j<N ; j++){
							if (vi[i] & (1 << j)){
								cout << s << arr[j] ;
								s = " " ;
							}
						}
						cout << endl ;

						s = "" ;
						for (int j=0 ; j<N ; j++){
							if (msk & (1 << j)){
								cout << s << arr[j] ;
								s = " " ;
							}
						}
						cout << endl ;

						goto end ;
					}
				}
			}
			mp[sum].push_back(msk);
		}
		end: ;
	}
	return 0;
}
