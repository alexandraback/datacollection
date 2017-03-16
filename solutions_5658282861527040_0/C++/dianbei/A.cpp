//============================================================================
// Name        : A.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <string.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
typedef long long ll;

const int inf = 1 << 29;
#define mod 1000000007
#define N 100010


int main() {
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	int T, n, m,k,ri=1;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &n,&m,&k);
		int ans=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++){
				if((i&j)<k) ans++;
			}

		printf("Case #%d: ",ri++);
		 printf("%d\n",ans);
	}
	return 0;
}
