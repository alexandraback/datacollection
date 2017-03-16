#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair <int, int> PII;
const int MAXN = 2e5 + 7, Mo = 1e9 + 7;

int a[MAXN], c[MAXN];
int n;

void dec(PII &t){
	int i = t.second;
	c[i]++;
	t.first = a[i]/c[i] + (a[i]%c[i]!=0);
}

int main(){							
	int t; scanf("%d", &t);
	for (int cas = 1; cas <=t; cas++){
		printf("Case #%d: ", cas);
		scanf("%d", &n);
		priority_queue <PII> Q;
		for (int i=0; i<n; i++){
			scanf("%d", a+i);
			Q.push(PII(a[i], i));
			c[i] = 1;
		}
		int mx = Q.top().first;
		int rst = mx;
		for (int i=1; i<mx; i++){		
			PII tmp = Q.top(); Q.pop();
			dec(tmp); Q.push(tmp);
			rst = min(rst, i + Q.top().first);
		}		
		printf("%d\n", rst);
	}
	return 0;
}
