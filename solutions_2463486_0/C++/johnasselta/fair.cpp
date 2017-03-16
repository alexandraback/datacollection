#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
#include <cmath>
#define MAXN
#define INF
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

int tab[100],suma[200];
int dlug[50000],liczba[50000][200];
int ile,dlugosc,test,result;
char a[200];

bool dodaj(int dl, int poz, int war) {
	bool mozna = true;
	tab[poz] = tab[dl-poz-1] = war;
	int t;
	if (poz != dl-poz-1) {
		FOR(i,0,poz) {
			if (i != poz) t = 2; else t = 1;
			//printf("t %d\n",t);
			suma[i+poz] += tab[i]*tab[poz]*t;
			if (suma[i+poz] > 9) mozna = false;
			
			suma[i+dl-poz-1] += tab[i]*tab[poz]*t;
			if (suma[i+dl-poz-1] > 9) mozna = false;
		}
		t = 1;
		FOR(i,dl-poz-1,dl-1) {
			if (i != dl-poz-1) t = 2; else t = 1;
			suma[i+poz] += tab[i]*tab[poz]*t;
			if (suma[i+poz] > 9) mozna = false;
			
			suma[i+dl-poz-1] += tab[i]*tab[poz]*t;
			if (suma[i+dl-poz-1] > 9) mozna = false;
		}
	}
	else {
		REP(i,dl) {
			if (i != poz) t = 2; else t = 1;
			suma[i+poz] += tab[i]*tab[poz]*t;
			if (suma[i+poz] > 9) mozna = false;
		}
	}
	return mozna;
}

inline void wypisz(int dl) {
	dlug[ile] = 2*dl-1;
	REP(i,2*dl) liczba[ile][i] = suma[i]; 
	++ile;
} 

void odejmij(int dl, int poz) {
	int t;
	if (poz != dl-poz-1) {
		t = 1;
		FOR(i,0,poz) {
			if (i != poz) t = 2; else t = 1;
			suma[i+poz] -= tab[i]*tab[poz]*t;
			suma[i+dl-poz-1] -= tab[i]*tab[poz]*t;
		}
		t = 1;
		FOR(i,dl-poz-1,dl-1) {
			if (i != dl-poz-1) t = 2; else t = 1;
			suma[i+poz] -= tab[i]*tab[poz]*t;
			suma[i+dl-poz-1] -= tab[i]*tab[poz]*t;
		}
	}
	else {
		REP(i,dl) {
			if (i != poz) t = 2; else t = 1;
			suma[i+poz] -= tab[i]*tab[poz]*t;
		}
	}
	tab[poz] = tab[dl-poz-1] = 0;
	return;
}

void rob(int dl, int poz, int war) {
	//printf("mamy %d %d\n",poz,war);
	if (war) if (!dodaj(dl,poz,war)) return;
	//REP(i,dl) printf("%d",tab[i]); puts("");
	//REP(i,dl*2) printf("%d ",suma[i]); puts("");
	if ((poz+1)*2 >= dl) {wypisz(dl); return;}
	rob(dl,poz+1,0);
	rob(dl,poz+1,1);
	odejmij(dl,poz+1);
	rob(dl,poz+1,2);
	odejmij(dl,poz+1);
	return;
}

bool wieksze(int p) {
	if (dlug[p] > dlugosc) return true;
	if (dlug[p] < dlugosc) return false;
	REP(i,dlug[p]) {
		if (liczba[p][i] > int(a[i]-'0')) return true;
		if (liczba[p][i] < int(a[i]-'0')) return false;
	}
	return false;
}

bool rowne(int p) {
	if (dlug[p] != dlugosc) return false;
	REP(i,dlug[p]) if (liczba[p][i] != int(a[i]-'0')) return false;
	return true;
}

int licz(int razem) {
	int l = 0;
	int p = ile-1;
	while (l != p) {
		int s = (l+p+1)/2;
		if (wieksze(s)) p = s-1; else l = s;
	}
	//printf("%d\n",l+1);
	if (!razem && rowne(l)) return l;
	return l+1;
}

int main() {
	suma[0] = 1; wypisz(1);
	suma[0] = 4; wypisz(1);
	suma[0] = 9; wypisz(1);
	FOR(i,2,50) {
		REP(p,2*i) suma[p] = 0;
		REP(p,i) tab[p] = 0;
		rob(i,0,1);
		odejmij(i,0);
		rob(i,0,2);
	}
	scanf("%d",&test);
	FOR(g,1,test) {
		printf("Case #%d: ",g);
		scanf(" %s",a); dlugosc = strlen(a); result = -licz(0);
		scanf(" %s",a); dlugosc = strlen(a); result += licz(1);
		printf("%d\n",result);
	}
	return 0;
}
