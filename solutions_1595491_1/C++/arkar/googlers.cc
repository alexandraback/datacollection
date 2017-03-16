#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <vector>
#include <cstdio>
#include <complex>
#include <stack>
#include <cctype>
#include "assert.h"
#include <cstdlib>
#include <iostream>

#define PB push_back
#define MP make_pair
#define FR(i,n) for( long long i = 0; i < n; i ++ )
#define FOR(i,a,n) for(long long i = a; i < n; i ++)
#define FREACH(it,v) for( typeof(v.end()) it = v.begin(); it != v.end(); it ++ )
#define EPS 1e-9
using namespace std;
typedef long long ll;


int scores[100];

int main() {
	int T;
	scanf("%d",&T);
	FR(i,T) {
		cout << "Case #" << i+1 << ": ";
		int N,S,p;
		scanf("%d %d %d\n", &N, &S, &p);
		FR(i,N) {
			scanf("%d",&scores[i]);
		}
		int cnt=0;
		FR(i,N) {
			int a=scores[i];
			int lw = (p==0?0:p+2*(p-1));
			if(lw<=a) {
				cnt++;
				continue;
			}

			if(S>0) {
				if(p==0) lw = 0;
				else if (p==1) lw = 1;
				else lw = p+2*(p-2);

				if(lw<=a) {
					cnt++;
					S--;
				}				
			}
		}
		cout << cnt << endl;
	}
}