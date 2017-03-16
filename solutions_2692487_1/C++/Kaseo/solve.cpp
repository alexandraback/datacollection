#include <cstdio>
#include <algorithm>

using namespace std;

int s[102];

int main(){//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int T;
	scanf("%d", &T);

	for(int r=1; r<=T; r++){
		int a, n, c;
		scanf("%d %d", &a, &n);
		for(int i=0; i<n; i++)
			scanf("%d", s+i);

		sort(s, s+n);
		
		c = a;
		int ans = n;

		for(int k=0; k<=n; k++){
			int p=0;
			c = a;
			for(int i=0; i<k; i++){
				if(s[i] < c){
					c += s[i];
					if(p>100){
						p = -1; 
						break;
					}
				}
				else{
					while( s[i] >= c ){
						c = 2*c - 1;
						p ++;
						if( p>100 ){
							p = -1;
							break;
						}
					}
					c += s[i];
					if( p == -1 )
						break;
				}
				
			}

			if( p!= -1){
				ans = min( ans, p+n-k );
			}
			
		}
		printf("Case #%d: %d\n", r, ans);
	}
	
}