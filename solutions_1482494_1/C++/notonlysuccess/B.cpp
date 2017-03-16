#include <cstdio>
#include <cstdlib>
#include <string>
#include <climits>
#include <iostream>   
#include <vector>
#include <set>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <sstream>
#include <map>
#include <cstring>
#include <queue>
using namespace std;

struct Node {
	int star;
	int level;
	int need;
	Node() {}
	Node(int a,int b,int c) {
		star = a;
		level = b;
		need = c;
	}
	bool operator < (const Node &cmp) const {
		if (star == cmp.star) return need < cmp.need;
		return star < cmp.star;
	}
};
struct Node2 {
	int star;
	int need;
	int level;
	Node2() {}
	Node2(int a,int b,int c) {
		star = a;
		level = b;
		need = c;
	}
	bool operator < (const Node2 &cmp) const {
		return need > cmp.need;
	}
};
priority_queue<Node> que;
priority_queue<Node2> que2;
const int maxn = 1111;
int cnt[maxn];
int B[maxn];
int main() {
	freopen("B-large.in","r",stdin);
	freopen("B.out","w",stdout);
	int T;
	scanf("%d",&T);
	for (int cas = 1 ; cas <= T ; cas ++) {
		int n;
		scanf("%d",&n);
		while (!que.empty()) que.pop();
		while (!que2.empty()) que2.pop();
		for (int i = 0 ; i < n ; i ++) {
			int a , b;
			scanf("%d%d",&a,&b);
			B[i] = b;
			que2.push(Node2(1 , i , a));
			que2.push(Node2(2 , i , b));
		}
		int now = 0;
		memset(cnt , 0 , sizeof(cnt));
		int ans = 0;
		while (!que2.empty() || !que.empty()) {
			while (!que2.empty() && que2.top().need <= now) {
				Node2 top = que2.top();
				que2.pop();
				que.push(Node(top.star , top.level , B[top.level]));
			}
			if (que.empty()) {
				ans = 0;
				break;
			} else {
				Node top = que.top();
				que.pop();
				if (top.star == 1) {
					if (cnt[top.level] == 0) {
						now ++;
						cnt[top.level] = 1;
						ans ++;
					}
				} else {
					if (cnt[top.level] == 1) {
						now ++;
						cnt[top.level] = 1;
						ans ++;
					} else if (cnt[top.level] == 0){
						now += 2;
						cnt[top.level] = 2;
						ans ++;
					}
				}
			}
		}
		printf("Case #%d: ",cas);
		if (ans) printf("%d\n",ans);
		else puts("Too Bad");
	}
	return 0;
}