#include <map>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define MP make_pair
#define PII pair<int, int>
using namespace std;
char buf[1001];
map<pair<int, int> , bool> M;
int ans, a, b;
int main()
{
freopen("C.in", "r", stdin); freopen("C.out", "w", stdout);
int T; scanf("%d", &T);
for (int Ti = 1; Ti <= T; Ti++){
	M.clear();
	scanf("%d%d", &a, &b); ans = 0;
	int l = 0, m = 1; while(m <= a) m *= 10, ++l;
	for (int i = a; i <= b; i++){
		sprintf(buf, "%d", i);
		sprintf(buf + l, "%d", i);
		for (int j = 1; j < l; j++){
			char rec = buf[j + l]; buf[j + l] = 0;
			int t = atoi(buf + j);
			if (t > i && t >= a && t <= b && !M.count(make_pair(i, t))){
				++ans;
				M[make_pair(i, t)] = true;
			}
			buf[j + l] = rec;
		}
	}
	printf("Case #%d: %d\n", Ti, ans);
}	
}
