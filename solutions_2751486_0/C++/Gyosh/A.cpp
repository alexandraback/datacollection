#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <map>

#define REP(a,b) for (int a=0; a<b; a++)
#define FOR(a,b,c) for (int a=b; a<=c; a++)
#define FORD(a,b,c) for (int a=b; a>=c; a--)
#define RESET(a,b) memset(a, b, sizeof a)

#define INF 1023123123
#define LL long long
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define PII pair<int,int> 
#define PDD pair<double,double>

#define __ puts("")
using namespace std;

int nkasus;
LL ans;
char sc[1000002];
int tbm[1000002];
int cur,a,b,n;

int isC(char x){
	if ((x == 'a') || (x == 'i') || (x == 'u') || (x == 'e') || (x == 'o')) return 0;
	return 1;
}	

int main(){
	scanf("%d", &nkasus);
	REP(jt,nkasus){
		scanf("%s%d", sc, &n);
		int l = strlen(sc);
		RESET(tbm,-1);
		
		cur = 0;
		ans = 0;
		REP(i,l){
			cur += isC(sc[i]);
			if (i-n >= 0){
				cur -= isC(sc[i-n]);
			}
			
			if (cur == n){
				tbm[i] = i-n+1;
			}
		}
		
		REP(i,l){
			if ((i > 0) && (tbm[i] == -1)) tbm[i] = tbm[i-1];
			
			ans += (LL)tbm[i]+1;
		}
	
		printf("Case #%d: %lld\n", jt+1, ans);
	}
	
	return 0;
}
