#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>

using namespace std;

vector< vector<int> > v;
int row[200], col[200];

int main() {
	int T;
	scanf("%d", &T);
	for(int cas=1; cas<=T; ++cas) {
		int N, M;
		scanf("%d%d", &N, &M);
		v.clear();
		for(int i=0; i<N; ++i) {
			for(int j=0; j<M; ++j) {
				int tmp;
				scanf("%d", &tmp);
				v.push_back(vector<int>(3));
				v.back()[0] = tmp;
				v.back()[1] = i;
				v.back()[2] = j;
			}
		}
		memset(row, 0, sizeof(row));
		memset(col, 0, sizeof(col));
		sort(v.begin(), v.end());
		bool flag=true;
		for(int h=0, l=0, r=0; r<v.size(); ++h) {
			while(r<v.size()&&v[r][0]<=h) {
				++row[v[r][1]];
				++col[v[r][2]];
				++r;
			}
			while(l<r) {
				if(row[v[l][1]]!=M&&col[v[l][2]]!=N)
					flag = false;
				++l;
			}
		}
		printf("Case #%d: %s\n", cas, flag?"YES":"NO");
	}
	return 0;
}
