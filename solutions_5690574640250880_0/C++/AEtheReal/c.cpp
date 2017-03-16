#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cstdlib>
#include <cctype>
using namespace std;
#define FOR(i,s,e) for(int i=(s);i<(int)(e);i++)
#define FORS(i,s) for(int i=0;(s)[i];i++)
#define FOE(i,s,e) for(int i=(s);i<=(int)(e);i++)
#define CLR(s) memset(s,0,sizeof(s))
typedef long long LL;
#define PB push_back

bool a[111][111], b[111][111];
int n,m,pm,pn,x;
void rot(){
	FOR(i,0,pn)FOR(j,0,pm) b[j][i] = a[i][j];
	swap(pn,pm);
	swap(n,m);
	FOR(i,0,pn)FOR(j,0,pm) a[i][j] = b[i][j];
}

bool isbad(){
	int r = n*m-x;
	if(r < 0) return true;
	if(r <= 1) return false;
	if(n == 1 || m == 1) return false;
	if(n == 2 || m == 2){
		if(r == 2 || (r % 2 == 1)) return true;
		return false;
	}
	if(r == 4) return false;
	if(x > 0 && (r < 6 || r == 7)) return true;
	return false;
}

int main() {	
int nt; scanf("%d", &nt); FOR(tt,1,nt+1){
	scanf("%d%d%d", &n,&m,&x);
	printf("Case #%d:\n", tt);
	
	bool bad = false;
	
	
	if(isbad()){
		printf("Impossible\n");
		continue;
	}
	FOR(i,0,n)FOR(j,0,m) a[i][j] = false;
	pn = n; pm = m;
	
	while(x > 0){
		bool isrot = (m > n);
		if(isrot) rot();
		for(int i=m-1; i>=2 && x>0; i--){
			a[n-1][i] = true;
			x--;
		}
		if(x >= 1 && m == 1){
			a[n-1][m-1] = true;
			x --;
		}else if(x == 1){
			a[n-2][m-1] = true;
			x --;
		}else if(x >= 2){
			a[n-1][0] = a[n-1][1] = true;
			x -= 2;
		}
		n --;
		
		if(isrot) rot();
	}
	FOR(i,0,pn){
		FOR(j,0,pm) printf("%c", (i==0 && j==0)?'c':( a[i][j]?'*':'.'));
		printf("\n");
	}
}	
return 0;
}


