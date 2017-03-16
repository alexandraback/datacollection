/*
 */
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
#define N (1 << 21)
#define oo 0xfffffffful

unsigned int z[N];
queue<unsigned int> q;

unsigned int rev( int n ) {
	char c[0x400];
	int i,j,k;
	sprintf(c,"%d",n);
	unsigned int u = 0;
	for ( k = strlen(c), i = 0, j = k-1; i < j; ++i, --j )
		swap(c[i],c[j]);
	for ( i = 0; i < k; ++i )
		u *= 10, u += (int)(c[i]-'0');
	return u;
}

void bfs() {
	unsigned int u,v;
	for ( z[1] = 1, q.push(1); !q.empty(); ) {
		u = q.front(), q.pop();
		if ( u+1 < N && z[u+1] > z[u]+1 )
			q.push(u+1), z[u+1] = z[u]+1;
		v = rev(u);
		if ( v < N && z[v] > z[u]+1 )
			q.push(v), z[v] = z[u]+1;
	}
}

int main() {
	int i,j,k,ts,cs = 0,n;
	memset(z,0xff,sizeof z);
	bfs();
	for ( scanf("%d",&ts); ts--; ) {
		printf("Case #%d: ",++cs);
		scanf("%d",&n);
		printf("%u\n",z[n]);
	}
    return 0;
}

