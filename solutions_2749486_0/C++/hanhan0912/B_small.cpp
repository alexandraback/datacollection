/* hanhanw v1.2 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
// for Online Judge or Contests
#define MSET(x,y) memset(x,y,sizeof(x))
#define REP(x,y,z) for(int x=(y); x<=(z); x++)
#define FORD(x,y,z) for(int x=(y); x>=(z); x--)
#define FLST(x,y,z) for(int x=(y); x; x=z[x])
#define FOR(x,y) for(__typeof(y.begin())x=y.begin();x!=y.end();x++)
#define SZ(x) ((int)x.size())
#define PB push_back

using namespace std;
//
typedef long long LL;
typedef unsigned long long uLL;
typedef long double LD;
// start here OAO~

char a,b;
void solve(int T){
	printf("Case #%d: ", T);
	int x,y;
	scanf("%d %d", &x, &y);
	if (x<0){
		x=-x;
		a='E';
		b='W';
	} else {
		a='W';
		b='E';
	}
	for (int i=1; i<=x; i++){
		putchar(a);
		putchar(b);
	}
	if (y<0){
		y=-y;
		a='N';
		b='S';
	} else {
		a='S';
		b='N';
	}
	for (int i=1; i<=y; i++){
		putchar(a);
		putchar(b);
	}
	puts("");
}

int main(){
	int nT; scanf("%d", &nT);
	for (int i=1; i<=nT; i++)
		solve(i);
	return 0;
}
