#include <cstdio>
#include <algorithm>

using namespace std;
const int N = 1005;
int p[N];

int main(){
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for(int R=1; R<=T; R++){
		int n, s = 0;
		scanf("%d", &n);
		for(int i=0; i<n; i++){
			scanf("%d", p+i);
			s += p[i];
		}
		int re = 1000;
		for(int h=1; h<=1000; h++){
			int c = 0;
			for(int i=0; i<n; i++){
				int pp = p[i];
				if( pp > h ){
					pp -= h;
					c += ((pp+h-1)/h);
				}
			}
			re = min( re, h+c );
		}

		printf("Case #%d: ", R);
		printf("%d\n", re);
		
	}
}