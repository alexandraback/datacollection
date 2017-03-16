


#include <iostream>
#include <iomanip>
#include <fstream>

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#include <sstream>
#include <string>

#include <bitset>
#include <deque>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>

#include <algorithm>

#include <utility>

using namespace std;



const int inf = 2000000000;
const long long linf = 9000000000000000000LL;
const double finf = 1.0e18;
const double eps = 1.0e-8;


struct node {
	int a, b;
}A[1005];

int T, N, s1[1005], s2[1005], r1, r2, star, ans, b[1005];

struct pqn{
	int i;
	bool operator < (const pqn &t) const {
		return A[i].b < A[t.i].b;
	}
}temp;
priority_queue<pqn> pq;

bool f1(int i, int j) {
	return A[i].a < A[j].a;
}

bool f2(int i, int j) {
	return A[i].b < A[j].b;
}

bool good() {
	for (int i=0; i<N; i++) 
		if (b[i]!=2) 
			return false;
	return true;
}

int main() {

	scanf("%d",&T);
	for (int tt=1; tt<=T; tt++) {
		scanf("%d",&N);
		for (int i=0; i<N; i++) {
			scanf("%d%d", &A[i].a, &A[i].b);
			s1[i] = i;
			s2[i] = i;
		}
		memset(b, 0, sizeof(b));
		sort(s1, s1+N, f1);
		sort(s2, s2+N, f2);
		r1 = r2 = 0;
		star = 0;    // ??
		ans = 0;
/*for (int i=0; i<N; i++) {
	printf("%d ", A[s1[i]].a);
}
printf("\n");
for (int i=0; i<N; i++) {
	printf("%d ", A[s2[i]].b);
}
printf("\n");*/
		while (1) {
			bool flag = true;
			while ((r2<N)&&(A[s2[r2]].b<=star)) {
				if (b[s2[r2]]<2) {
					star += 2-b[s2[r2]];
					b[s2[r2]] = 2;
					ans++;
					flag = false;
				}
				r2++;
			}
			while ((r1<N)&&(A[s1[r1]].a<=star)) {
				if (b[s1[r1]]<1) {
					temp.i = s1[r1];
					pq.push(temp);
				}
				r1++;
			}
			while (!pq.empty()) {
				temp = pq.top();
				pq.pop();
				if (b[temp.i]<1) {
					star += 1-b[temp.i];
					b[temp.i] = 1;
					ans++;
					flag = false;
					break;
				}
			}
			if (flag) break;
		}
		printf("Case #%d: ", tt);
		if (good()) {
			printf("%d\n", ans);
		}
		else {
			printf("Too Bad\n");
		}
	}
	return 0;
}


