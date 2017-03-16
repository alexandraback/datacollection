#include <cstdio>
#include <vector>
using namespace std;


long long int find(vector<pair<long long int,long long int> > l1, vector<pair<long long int,long long int> > l2) {
	long long int ans = 0;
	if(l1.size() == 0 || l2.size() == 0)
		return 0;

	if(l1[0].second == l2[0].second) {
		long long int m= min(l1[0].first, l2[0].first);
		l1[0].first -= m;
		l2[0].first -= m;
		if(l1[0].first == 0)
			l1.erase(l1.begin());
		if(l2[0].first == 0)
			l2.erase(l2.begin());
		ans += m;
		ans += find(l1, l2);
	} else {
		long long int t1 = l1[0].first;
		long long int t2 = l1[0].second;
		l1.erase(l1.begin());
		long long int m1 = find(l1,l2);
		l1.insert(l1.begin(), make_pair(t1,t2));
		l2.erase(l2.begin());
		long long int m2 = find(l1,l2);
		ans += max(m1,m2);

	}
//	printf(">>now max = %di, %d %d\n", ans, l1.size(), l2.size());
	return ans;
}

int main() {
	int t;
	int tp = 0;
	long long int m,n;
	int i;
	long long int num, type;
	scanf("%d", &t);

	vector<pair<long long int,long long int> > l1, l2;
	while(t--) {
		tp++;
		printf("Case #%d: ", tp);
		l1.clear();
		l2.clear();
		scanf("%Ld%Ld", &n, &m);
		for(i=0; i<n; ++i) {
			scanf("%Ld%Ld", &num, &type);
			l1.push_back(make_pair(num, type));
		}
		for(i=0; i<m; ++i) {
			scanf("%Ld%Ld", &num, &type);
			l2.push_back(make_pair(num, type));
		}

		printf("%Ld\n", find(l1,l2));
	}
	return 0;
}
