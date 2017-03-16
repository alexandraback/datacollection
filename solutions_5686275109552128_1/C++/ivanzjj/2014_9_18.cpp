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
LL MAX (LL a, LL b){ return (a) > (b) ? (a) : (b); }
LL MIN (LL a, LL b){ return a < b ? a : b; }

int D; 

int solve(int a){
	int ret = 1, now = 1 ;
	for (; now < a; now *=2 ){
		ret++ ;
	}
	return ret; 
}

int a[1010];

int main (){
//	freopen ("F:\\C++\\B-large.in","r",stdin);
//	freopen ("F:\\C++\\B-large.out", "w", stdout);
	int T; scanf ("%d",&T);
	for (int cas=1;cas<=T;cas++){
		scanf ("%d",&D);
		int _max = -1;
		for (int i=0;i<D;i++){
			scanf ("%d", &a[i]);
			_max = max (_max, a[i]);
		}
		int ans = _max; 
		for (int i=1;i<=_max;i++){
			int tmp = i;
			for (int j=0;j<D;j++){
				if (a[j] % i == 0)	tmp += (a[j] / i - 1);
				else		tmp += (a[j] / i);
			}
			ans = min (ans , tmp);
		}
		printf ("Case #%d: %d\n", cas, ans);
	}
	return 0;
}