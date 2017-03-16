#include<cstdio>
#include<iostream>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<list>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<iomanip>
#include<fstream>
#include<ctime>
using namespace std;
typedef vector<int> VI;
typedef pair <int,int> ii;
typedef long long LL;
#define pb push_back
const int INF = 2147483647;

int r,c,w,i,j,tab1[25], tab2[25], z, q, r1, r2, r3, r4;

int main() {
scanf("%d",&z);
for (q=1;q<=z;q++) {
	scanf("%d %d %d",&r, &c, &w);
	for (i=0;i<=c;i++) tab1[i] = i / w;
	for (i=0;i<w;i++) tab2[i] = 0;
	tab2[w] = w;
	for (i = w+1; i<=c;i++) {
		tab2[i] = INF;
		for (j = 1;j <= i;j++) {
			r1 = (j == 1 || j == i) ? w : w + 1;
			if (i - j >= w) r2 = 1 + tab1[j - 1] + tab2[i - j]; else r2 = -1;
			if (j - 1 >= w) r3 = 1 + tab1[i - j] + tab2[j - 1]; else r3 = -1;
			r4 = max(r1, max(r2, r3));
			//printf("%d %d %d %d\n", r1, r2, r3, r4);
			tab2[i] = min(tab2[i], r4);
		}
		//printf("%d %d\n", i, tab2[i]);
	}
	printf("Case #%d: %d\n", q, (r-1) * tab1[c] + tab2[c]);
}
return 0;
}

