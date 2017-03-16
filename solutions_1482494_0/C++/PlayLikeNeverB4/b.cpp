#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXN 1024
int a[MAXN], b[MAXN];
vector<pair<int, int> > levelOne, levelTwo;
int completedOne[MAXN], completedTwo[MAXN];
int i, t, N, T;

bool cmp(const pair<int, int> &x, const pair<int, int> &y) {
	if(x.first < y.first) return true;
	if(x.first > y.first) return false;
	if(b[x.second] > b[y.second]) return true;
	return false;
}

int main() {
	freopen("b.in", "r", stdin);
	freopen("b.out","w", stdout);
	
	scanf("%d", &T);
	
	for(t = 1; t <= T; t++) {
		scanf("%d", &N);
		levelOne.clear(); levelTwo.clear();
		for(i = 0; i < N; i++) {
			scanf("%d %d", &a[i], &b[i]);
			levelOne.push_back(make_pair(a[i], i));
			levelTwo.push_back(make_pair(b[i], i));
		}
		
		sort(levelOne.begin(), levelOne.end(), cmp);
		sort(levelTwo.begin(), levelTwo.end());
		//for(i = 0; i < N; i++) printf("(%d,%d) ", levelTwo[i].first, levelTwo[i].second); printf("\n");
		
		memset(completedOne, 0, sizeof(completedOne));
		memset(completedTwo, 0, sizeof(completedTwo));
		
		int c1 = 0, c2 = 0, stars = 0, levels = 0, ok = 1;
		
		while(c2 < N && ok) {
			ok = 0;
			
			while(c2 < N && stars >= levelTwo[c2].first) {
				completedTwo[levelTwo[c2].second] = 1;
				if(completedOne[levelTwo[c2].second])
					stars++;
				else {
					completedOne[levelTwo[c2].second] = 1;
					stars += 2;
				}
				c2++;
				levels++;
				ok = 1;
			}
			
			while(c1 < N && completedOne[levelOne[c1].second])
				c1++;
			
			if(c2 < N && c1 < N && stars >= levelOne[c1].first) {
				completedOne[levelOne[c1].second] = 1;
				stars++;
				levels++;
				c1++;
				ok = 1;
			}
		}
		
		printf("Case #%d: ", t);
		if(!ok) printf("Too bad\n");
		else printf("%d\n", levels);
	}
	
	return 0;
}
