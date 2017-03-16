#include <cstdio>
#include <queue>
using namespace std;

int c[2000];
int n;
int main() {
	int T,ics = 0;
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		
		int mx = 0;
		for(int i=0;i<n;++i) {
			scanf("%d",&c[i]);
			if( c[i] > mx )
				mx = c[i];
		}
		
		int t = mx;
		for(int g=1;g<mx;++g) {
			int z = g;
			for(int i=0;i<n;++i) if( c[i] > g ) {
				int ns = c[i] / g;
				if( c[i] % g == 0 )
					--ns;
				z += ns;
			}
			
			if( z < t )
				t = z;
		}
		
		printf("Case #%d: %d\n",++ics,t);
	}
	return 0;
}
