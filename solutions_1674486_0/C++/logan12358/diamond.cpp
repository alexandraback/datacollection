#include <cstdio>
#include <vector>
using namespace std;

bool seen[1005];
vector<int> children[1005];
vector<int> parents;
int n;

bool diamond2(int i) {
	if(seen[i]==1) {
		return 1;
	}
	seen[i]=1;
	bool ret=0;
	for(int j=0; j<children[i].size(); j++) {
		ret = ret | diamond2(children[i][j]);
	}
	return ret;
}

bool diamond() {
	bool ret=0;
	for(int i=0; i<parents.size(); i++) {
		for(int j=0; j<n; j++) seen[j]=0;
		ret = ret | diamond2(parents[i]);
	}
	return ret;
}

int main() {
	freopen("diamond.in", "r", stdin);
	freopen("diamond.out", "w", stdout);
	int t; scanf("%d", &t);
	for(int _=0; _<t; _++) {
		scanf("%d", &n);
		parents.clear();
		for(int i=0; i<n; i++) {
			children[i].clear();
		}
		for(int i=0; i<n; i++) {
			seen[i]=0;
			int m; scanf("%d", &m);
			if(m==0) parents.push_back(i);
			for(int j=0; j<m; j++) {
				int x; scanf("%d", &x);
				children[x-1].push_back(i);
			}
		}
		printf("Case #%d: %s\n", _+1, diamond()?"Yes":"No");
	}
}
