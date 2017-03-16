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

int dpow(int n){
	int ret=1;
	for(int i=1;i<n;i++)ret*=10;
	return ret;
}

int main(){
	int t, tc, i, j, a, b;
	cin >> t;
	REP(tc,t){
		ll ret=0;
		cin >> a >> b;
		int cnt=0, tmp=a;
		for(i=a;i<=b;i++){
			int tmp=i, cnt=0, x=i;
			while(tmp!=0){
				tmp/=10;
				cnt++;
			}
			int z=dpow(cnt);
			REP(j,cnt-1){
				x=x/10+(x%10)*z;
				if(x==i)break;
				if(x>i&&x<=b)ret++;
			}
		}
		printf("Case #%d: %lld",tc+1,ret);
		puts("");
	}
	return 0;
}

