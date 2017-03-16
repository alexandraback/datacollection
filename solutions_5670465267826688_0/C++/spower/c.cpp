#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;

const int N = 10004;
const int mul[8][8] = {
	{0,1,2,3,4,5,6,7},
	{1,4,3,6,5,0,7,2},
	{2,7,4,1,6,3,0,5},
	{3,2,5,4,7,6,1,0},
	{4,5,6,7,0,1,2,3},
	{5,0,7,2,1,4,3,6},
	{6,3,0,5,2,7,4,1},
	{7,6,1,0,3,2,5,4}
};

long long x;
int l, whole;
char s[N];
inline int getindx(char x) {
	switch(x) {
		case 'i': return 1;
		case 'j': return 2;
		case 'k': return 3;
	}
}
bool checkK(int xi, int indx) {
    int multall = 0;
	for(int i = indx; i < l; i++)
		multall = mul[multall][s[i]];
    int lefx = (x-xi-1) % 4;
	for(int i = 0; i < lefx; i++)
		multall = mul[multall][whole];
    return multall == 3;
}
bool find(int xi, int indx, int t) {
	//printf("%d,%d,%d l=%d\n", xi, indx, t, l);
	if(xi >= x) return false;
	if(t == 3)
		return checkK(xi, indx);
	int bef = 0, inc = 0;
    if(indx > 0) {
        for(int i = indx; i < l; i++) {
            bef = mul[bef][s[i]];
            if(bef == t && find(xi+(i+1)/l, (i+1)%l, t+1))
                return true;
        }
        inc = 1;
    }
	for(int i = 0; i < 4; i++) {
		if(bef == t && find(xi+i+inc, 0, t+1))
			return true;
		int multall = bef;
		for(int j = 0; j < l-1; j++) {
			multall = mul[multall][s[j]];
			//printf("---- mul[%d][%d]=%d, t = %d\n", bef, multall, mul[bef][multall], t);
			if(multall == t && find(xi+i+inc, j+1, t+1))
				return true;
		}
		bef = mul[bef][whole];
	}
    return false;
}
int main() {
	freopen("C-small-attempt2.in", "r", stdin);
	freopen("C-small-attempt2.out", "w", stdout);
	int t;
	scanf("%d", &t);
	for(int cas = 1; cas <= t; cas++) {
		scanf("%d%lld%s", &l, &x, s);
		whole = 0;
		for(int i = 0; i < l; i++) {
			s[i] = getindx(s[i]);
			whole = mul[whole][s[i]];
		}
//		printf("%d\n", whole);
		if(find(0,0,1))
			printf("Case #%d: YES\n", cas);
		else
			printf("Case #%d: NO\n", cas);
	}
	return 0;
}
