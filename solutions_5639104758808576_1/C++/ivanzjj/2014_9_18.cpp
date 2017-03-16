#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <memory>
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long LL;
LL MAX (LL a, LL b){ return a > b ? a : b; }
LL MIN (LL a, LL b){ return a < b ? a : b; }

int N;
char ch[1010];

int main (){
//	freopen ("F:\\C++\\A-large.in","r",stdin);
//	freopen ("F:\\C++\\A-large.out", "w", stdout);
	int T;scanf ("%d",&T);
	for (int cas=0;cas<T;cas++){
		scanf ("%d",&N);
		scanf ("%s",ch);
		int ans = 0, now = 0;
		for (int i = 0; i <= N; i++) if (ch[i] != '0'){
			if (now >= i)	now += (ch[i] - '0');
			else{
				ans += (i - now);
				now = i + ch[i] - '0';
			}
		}
		printf ("Case #%d: %d\n", cas+1, ans);
	}
	return 0;
}