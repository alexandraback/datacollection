#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair <int, int> PII;
const int MAXN = 2e5 + 7, Mo = 1e9 + 7;
const int e[5][5] = {{}, 	{0, 1, 2, 3, 4},
							{0, 2, -1, 4, -3},
							{0, 3, -4, -1, 2},
							{0, 4, 3, -2, -1}};					   
LL L, X;
char ss[MAXN];
int a[MAXN];

inline int idx(char c){
	if (c == '1') return 1;
	return c - 'i' + 2;
}
inline int sgn(int x){
	return x >= 0 ? 1 : -1;
}
inline int opt(int a, int b){
	return e[abs(a)][abs(b)] * sgn(a*b);
}

int main(){
	int t; scanf("%d", &t);
	for (int cas = 1; cas <=t; cas++){
		printf("Case #%d: ", cas);
		scanf("%lld%lld%s", &L, &X, ss);		
		for (int i=0; i<L; i++) a[i] = idx(ss[i]);
		
		LL pt = 0, rst = 1;
		for (int i=2; i<=3; i++){			
			int now = 1;			
			for(int j=0; j<(L<<4); j++){
				now = opt(now, a[(pt++) % L]);
				if (now == i) break;				
			}
			if (now != i || pt > L*X){
				rst = 0; break;
			}
		}
	
		int now = 1;
		for (; pt%L; pt++){
			now = opt(now, a[pt%L]);
		}
		LL left = X - pt/L;	
		int one = 1;
		for (int i=0; i<L; i++) one = opt(one, a[i]);		
		
		if (one == -1 && left%2 == 0) one = 1;
		if (abs(one) != 1){
			if (left%4 == 2) one = -1;
			if (left%4 == 3) one = -one;
			if (left%4 == 0) one = 1;
		}		
		now = opt(now, one);			
		
		if (now != 4) rst = 0;		
		if (rst) puts("YES"); else puts("NO");
	}
	return 0;
}
