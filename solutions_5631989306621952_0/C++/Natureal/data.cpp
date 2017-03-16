#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#define getmid(l,r) ((l) + ((r) - (l)) / 2)
#define MEM(a,b) memset(a,b,sizeof(a))
#define MP(a,b) make_pair(a,b)
#define PB push_back
#define X first
#define Y second

const double eps = 1e-8;
const double pi = acos(-1.0);
const int MAXN = 1500;
const int INF = 0x3f3f3f3f;

int T;
char s[MAXN],ans[MAXN * 2];

int main(){
	freopen("A-small-attempt0.in","r",stdin);
	freopen("Asmall.txt","w",stdout);
	scanf("%d",&T);
	for(int tt = 1; tt <= T; ++tt){
		scanf("%s",s + 1);
		int len = strlen(s + 1);
		int L = 1000,R = 1000;
		ans[1000] = s[1];
		for(int i = 2; i <= len; ++i){
			if(s[i] >= ans[L]){
				ans[--L] = s[i];
			}
			else{
				ans[++R] = s[i];
			}
		}
		printf("Case #%d: ",tt);
		for(int i = L; i <= R; ++i) printf("%c",ans[i]);
		puts("");
	}
    return 0;
}