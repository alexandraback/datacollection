
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 1000000000
#define F first
#define S second
#define forn(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)

using namespace std;

int b;
ll m;


int main(){
	int testc;
	scanf("%d", &testc);
	rep(tc, testc){
		int mat[1234][1234];
				
		scanf("%d %lld", &b, &m);
		rep(i,b+20){
			rep(j,b+20){
				mat[i][j]=0;
			}
		}
		printf("Case #%d: ", tc+1);
		
		if(m > (1<<(b-2))){
			printf("IMPOSSIBLE\n");
			continue;
		}
		if(m == 1<<(b-2)){
			m--;
			mat[b][1] = 1;
		}
		printf("POSSIBLE\n");
		int p = 0;
		while(m >= 1<<p){
	//		printf("Complete %d %d\n", p+2, 1<<p);
			for(int z = 1; z < p+2; z++)
				mat[p+2][z]=1;
			m-=1<<p;
			p++;
		}
		int z = 0;
		while(1<<z <= m){
			if((1<<z & m) > 0){
	//			printf("Setting %d\n", z+2);
				mat[p+2][z+2] = 1;
			}
			z++;
		}
		for(int y = 1; y <= b; y++){
			for(int x = 1; x <= b; x++){
				if(x == b && y < b && y > 1) printf("1");
				else printf("%d", mat[x][y]);
			}
			printf("\n");
		}
	}
	return 0;
}
