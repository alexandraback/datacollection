#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
#define MAXN 60
#define PB push_back
#define MP make_pair
#define ST first
#define ND second

#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(a,b,c) for(int a=b;a<=(c);a++)
#define FORD(a,b,c) for (int a=b;a>=(c);a--)
#define VAR(v,n) __typeof(n) v=(n)
#define ALL(c) c.begin(),c.end()
#define FOREACH(i,c) for(VAR(i,(c).begin());i!=(c).end();i++)

using namespace std;

typedef long long LL;  


int test,r,c,m,ile_wolnych;
int t[MAXN][MAXN];

void wypisz() {
	FOR(i,1,r) {
		char znak;
		FOR(j,1,c) {
			if (t[i][j] == 0) znak = '.';
			if (t[i][j] == -1) znak = '*';
			if (i == 1 && j == 1) znak = 'c';
			printf("%c",znak); 
		}
		puts("");
	}
}

void uzupelnij() {
	FOR(i,1,2) FOR(j,1,2) t[i][j] = 0;
	ile_wolnych -= 4;
	FOR(i,1,2) if (ile_wolnych && 3 <= c) {
		t[i][3] = 0;
		--ile_wolnych;
	}
	
	FOR(i,1,2) if (ile_wolnych && 3 <= r) {
		t[3][i] = 0;
		--ile_wolnych;
	}
	
	FOR(i,4,r) if (ile_wolnych >= 2) {
		t[i][1] = t[i][2] = 0;
		ile_wolnych -= 2;
	}
	
	
	FOR(j,4,c) if (ile_wolnych >= 2) {
		t[1][j] = t[2][j] = 0;
		ile_wolnych -= 2;
	}
	
	FOR(i,3,r) FOR(j,3,c) if (ile_wolnych) {
		--ile_wolnych;
		t[i][j] = 0;
	}
	
	wypisz();
}

int main(){
	scanf("%d",&test);
	FOR(g,1,test) {
		printf("Case #%d:\n",g);
		scanf("%d%d%d",&r,&c,&m);
		
		FOR(i,1,r) FOR(j,1,c) t[i][j] = -1;
		
		ile_wolnych = r*c - m;
		if (ile_wolnych == 1) {
			t[1][1] = 0;
			wypisz();
			continue;
		}
		
		if (r == 1) {
			FOR(i,1,ile_wolnych) t[1][i] = 0;
			wypisz();
			continue;
		}
		
		if (c == 1) {
			FOR(i,1,ile_wolnych) t[i][1] = 0;
			wypisz();
			continue;
		}
		
		if (ile_wolnych <= 3) {
			puts("Impossible");
			continue;
		}
		
		if (r == 2 || c == 2) {
			if (ile_wolnych&1) puts("Impossible");
			else uzupelnij();
			continue;
		}
		
		if (ile_wolnych == 5 || ile_wolnych == 7) {
			puts("Impossible");
			continue;
		}
		
		uzupelnij();
	}
	return 0;
}
