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

		int N ;

		scanf ("%d" , &N);

		vector <vector <int> > adj (N , vector<int> ());

		for (int i = 0; i < N; ++i) {
			int M ;
			scanf ("%d" , &M) ;
			for (int j = 0; j < M; ++j) {
				int a ;
				scanf ("%d" , &a) ;
				adj[i].push_back(a-1);
			}
		}


		for (int i = 0; i < N; ++i) {
			queue <int> q ;
			q.push(i) ;

			set <int> vis ;
			while (q.size()){

				int cur = q.front() ;
				q.pop() ;

				if (!vis.insert(cur).second){
					printf ("Yes\n") ;
					goto Done ;
				}

				for (int j = 0; j < SZ(adj[cur]); ++j)
					q.push(adj[cur][j]) ;
			}
		}
		printf ("No\n") ;
		Done:;
	}
	return 0;
}
