#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

#define NMAX 1001

typedef struct node_ {
	int pre;
	int post;
	std::vector<int> c;
} node;

node T[NMAX+1];

int t;
int bad;
void dfs(int i)
{
	if (T[i].pre != -1) {
		bad = 1;
		return;
	}
	T[i].pre = t++;

	int jmax = T[i].c.size();
	for (int j=0; j<jmax; ++j) {
		dfs(T[i].c[j]);
	}

	T[i].post = t++;
}

int main(void)
{
	int T_;
	scanf("%d ", &T_);
	for (int i_ = 1; i_ <= T_; ++i_) {
		printf("Case #%d: ", i_);
		//
		int N;
		scanf("%d", &N);
		for (int i=0; i<=N; ++i) {
			T[i].pre = -1;
			T[i].c.clear();
		}
		for (int i=1; i<=N; ++i) {
			int Mi;
			scanf("%d", &Mi);
			for (int j=0; j<Mi; ++j) {
				int p;
				scanf("%d", &p);
				T[p].c.push_back(i);
			}
			if (Mi == 0) {
				T[0].c.push_back(i);
			}
		}
		t = 0;
		int imax = T[0].c.size();
		for (int i=0; i<imax; ++i) {
			bad = 0;
			for (int j=0; j<=N; ++j) {
				T[j].pre = -1;
			}
			dfs(T[0].c[i]);
			if (bad == 1)
				break;
		}
		printf("%s\n", bad ? "Yes" : "No");
	}
	return 0;
}
