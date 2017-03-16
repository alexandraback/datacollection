#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
using namespace std;
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)

typedef long long ll;
#define INF (1<<29)

int main(){
	int t, n, s, p, a[110], tc, i, j;
	cin >> t;
	REP(tc,t){
		cin >> n >> s >> p;
		REP(i,n)cin >> a[i];
		int x, y, cnt=0, ret=0;
		if(p==0)x=0;
		else x=p*3-2;
		if(p<=1)y=1;
		else y=p*3-4;
		REP(i,n){
			if(x<=a[i])ret++;
			else if(y<=a[i])cnt++;
		}
		printf("Case #%d: %d",tc+1,ret+min(s,cnt));
		puts("");
	}

	return 0;
}

