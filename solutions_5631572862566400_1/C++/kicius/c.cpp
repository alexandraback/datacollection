#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <numeric>
#include <array>
#include <map>
#include <set>
#include <stack>
#include <unordered_map>
#include <functional>
#include <iostream>
#include <thread>
#include <sstream>
#include <atomic>

using namespace std;

struct Node {
	int mark;
	int next;
	int dist2l;
	int deg;
};

vector<Node> F;


int main () {
	int T;
	scanf("%d", &T);
	for (int t=1; t<=T; t++) {
		int N;
		scanf("%d", &N);
		F.resize(N);
		for (auto &f:F) {
			scanf("%d", &f.next);
			f.next--;
			f.dist2l=0;
			f.deg=0;
			f.mark=0;
		}
		for (auto &f:F) {
			F[f.next].deg++;
		}
		
		stack<int> S;
		for (int i=0; i<F.size(); i++) {
			if (!F[i].deg) S.push(i);
		}
		
		while (!S.empty()) {
			int v=S.top();
			S.pop();
			F[v].mark=1;
			int w=F[v].next;
			F[w].dist2l=max(F[w].dist2l, F[v].dist2l+1);
			if ((--F[w].deg)==0) S.push(w);
		}
		
		int RES2=0;
		int RES3=0;
		for (int i=0; i<F.size(); i++) {
			if (F[i].mark) continue;
			int v=i;
			int d=0;
			do {
				d++;
				F[v].mark=1;
				v=F[v].next;
			} while (v!=i);
			
			if (d==2) {
				RES2+=F[i].dist2l+F[F[i].next].dist2l+2;
			} else {
				RES3=max(RES3, d);
			}
		}
		printf("Case #%d: %d\n", t, max(RES2, RES3));
		F.clear();
	}
	return 0;
}
