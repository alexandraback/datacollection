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

int st[2001];
int A[2001], B[2001];

int main() {
	int T;
	scanf("%d",&T);
	FR(i,T) {
		cout << "Case #" << i+1 << ": ";
		int N;
		scanf("%d",&N);
		FR(i,N) {
			scanf("%d %d",&A[i],&B[i]);
		}
		
		int nstars=0;
		memset(st,0,sizeof(st));
		
		int nmoves=0;
		for(;;) {
			nmoves++;
			int nxt=-1;
			FR(i,N) {
				if(st[i]<2&&nstars>=B[i]) {
					nxt=i;
					break;
				}
			}
			
			if(nxt!=-1) {
				nstars+=2-st[nxt];
				st[nxt]=2;
				continue;
			}
			
			int curreq=-1;
			FR(i,N) {
				if(st[i]<1&&nstars>=A[i]) {
					if(B[i]>curreq) {
						curreq=B[i];
						nxt=i;
					}					
				}
			}
			
			if(nxt!=-1) {
				nstars+=1;
				st[nxt]=1;
				continue;
			}
			if(nstars==2*N) {
				cout << nmoves-1<<endl;
			} else {
				cout << "Too Bad" << endl;
			}
			break;
		}
		
	}
}