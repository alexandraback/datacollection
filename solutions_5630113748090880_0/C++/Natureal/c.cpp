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

int T,N;
int num[2510];

int main(){
	freopen("B-small-attempt0.in","r",stdin);
	freopen("Bsmall.txt","w",stdout);
	scanf("%d",&T);
	for(int tt = 1; tt <= T; ++tt){
		scanf("%d",&N);
		memset(num,0,sizeof(num));
		for(int i = 1; i < N * 2; ++i){
			for(int j = 1; j <= N; ++j){
				int a;
				scanf("%d",&a);
				num[a]++;
			}
		}
		printf("Case #%d: ",tt);
		int cnt = 0;
		for(int i = 1; i <= 2500; ++i) if(num[i]){
			if(num[i] & 1){
				printf("%d",i);
				cnt++;
				if(cnt < N) printf(" ");
				else puts("");
			}
		}
	}
	return 0;
}