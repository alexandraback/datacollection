#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int r,c,w;

bool isEnd(int x) {
	int z = 0;
	for(int i=0;i+w<=c;++i) {
		if( ( (x >> i) & ( (1<<w)-1 ) ) == 0 )
			++z;
		if(z > 1)
			return false;
	}
	return z == 1;
}

int f[1<<21];
int main() {
	int T,ics = 0;
	scanf("%d",&T);
	while(T--) {
		cin >> r >> c >> w;
		
		for(int i=(1<<c)-1;i>=0;--i) {
			if( isEnd(i) )
				f[i] = w;
			else
				f[i] = c;
			
			for(int k=0;k<c;++k) if( ((i>>k)&1) == 0 ) {
				f[i] = min(f[i],f[i|(1<<k)]+1);
			}
		}
		
		printf("Case #%d: %d\n",++ics,r * f[0]);
	}
	return 0;
}