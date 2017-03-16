#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

int sta[2000009];
int a[22], n;
void print(int sta) {
	for( int i = 0; i < n; ++ i) if((sta >> i) & 1) printf("%d ", a[i]);
	puts("");
}
int  main() {
	freopen("C-small-attempt0.in","r",stdin);
	freopen("out","w",stdout);

	int T;
	scanf("%d", &T);
	for( int cas = 1;cas<=T; ++cas){
		scanf("%d", &n);
		for( int i = 0; i < n; ++ i)scanf("%d", a + i);
		memset( sta, 0, sizeof(sta));
		bool yes= false;
		printf("Case #%d:\n", cas);
		for( int i = 1; i < (1 << n); ++ i) {
			int L, R ;
			L = R = 0;
			for( int j = 0; j < n; ++ j) {
				if( (i >> j) & 1) L +=a[j];
			}
			if(sta[L]) {
				yes = true;
				print(sta[L]);
				print(i);
				break;
			}
			sta[L] = i;
		}
		if(!yes) puts("Impossible");
	}
	return 0;
}
