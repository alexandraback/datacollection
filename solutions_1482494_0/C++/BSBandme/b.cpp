/*
 * b.cpp
 *
 *  Created on: 2012-4-28
 *      Author: Administrator
 */
#include <iostream>
#include <fstream>
#include <cstdio>
#include <string.h>
#include <algorithm>
#include <queue>

using namespace std;

int f[10000];
int orig[10000][2];
struct level{
	int ji, min, no;
	bool operator < (const level &a) const{
		if(min == a.min){
			if(ji == a.ji && ji == 1) return orig[no][1] < orig[a.no][1];
			if(ji == a.ji && ji == 2) return orig[no][0] < orig[a.no][0];
			return ji < a.ji;
		}
		else return min > a.min;
	}
	level(int a1 = 0, int a2 = 0, int a3 = 0){
		ji = a1; min = a2; no = a3;
	}
};
priority_queue <level> pq1, pq2;


int main(){
	int ncase, n;

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &ncase);
	for(int i1 = 0; i1 < ncase; i1++){
		int nh = 0;
		memset(f, 0, sizeof(f));
		while(pq1.size()) pq1.pop();
		while(pq2.size()) pq2.pop();
		scanf("%d", &n);
		for(int i = 0; i < n; i++){
			int a1, a2;
			scanf("%d%d", &a1, &a2);
			orig[i][0] = a1; orig[i][1] = a2;
			level l1(1, a1, i), l2(2, a2, i);
			pq1.push(l1); pq2.push(l2);
		}
		int ans = 0; int star = 0;
		while((pq1.size() && pq1.top().min <= star) || (pq2.size() && pq2.top().min <= star)){
			level l2 = pq2.top(), l1 = pq1.top();
			while(l2.min <= star){
				pq2.pop();
				nh++;
				star += 2 - f[l2.no];
				f[l2.no] = 2;
				ans++;
				if(pq2.size()) l2 = pq2.top();
				else break;
			}
			while(pq1.size() && f[pq1.top().no] == 2) pq1.pop();
			if(pq1.size() && pq1.top().min <= star){
				f[pq1.top().no] = 1;
				star++;
				ans++;
				pq1.pop();
			}
		//	if(f[l.no] == 2) continue;

		}
		if(nh == n) printf("Case #%d: %d\n", i1 + 1, ans);
		else printf("Case #%d: Too Bad\n", i1 + 1);
	}
	return 0;
}



