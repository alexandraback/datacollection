#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>
using namespace std;

pair<long long, int> ap[110];
pair<long long, int> bp[110];
int n,m;
long long dyna[110][110];
bool memo[110][110];
long long solution(int i, int j) {
	if (memo[i][j]) return dyna[i][j];
	memo[i][j] = true;
	if (i>=n || j>=m) return dyna[i][j] = 0;
	long long ret = max(solution(i+1, j), solution(i, j+1));
	long long apI = 0, bpI = 0;
	for (int k=i;k<n;k++) {
		if (ap[k].second == ap[i].second) apI += ap[k].first;
		if (ap[k].second == bp[j].second) bpI += ap[k].first;
		long long  apJ = 0 , bpJ = 0;
		for (int l=j;l<m;l++) {
			if (bp[l].second == ap[i].second) apJ += bp[l].first;
			if (bp[l].second == bp[j].second) bpJ += bp[l].first;
			long long t_result = max(min(bpI, bpJ) + solution(k+1, l+1), min(apI, apJ) + solution(k+1, l+1));
			ret = max(ret, t_result);
		}
	}
	return dyna[i][j] = ret;
}

int main() {
	freopen("C-small-attempt1.in", "r", stdin);
    freopen("output.txt", "w+", stdout);
	int t;
	cin>>t;
	int cn = 1;
	while(t--) {
		memset(memo, 0, sizeof(memo));
		scanf("%d%d",&n,&m);
		for (int i=0;i<n;i++) {
			scanf("%lld%d", &ap[i].first, &ap[i].second);
		}
		for (int i=0;i<m;i++) {
			scanf("%lld%d", &bp[i].first, &bp[i].second);
		}
		long long t_result = solution(0, 0);
		printf("Case #%d: %lld\n", cn++, t_result);
	}
	return 0;
}