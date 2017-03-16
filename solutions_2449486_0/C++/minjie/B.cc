#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int a[200][200], m, n;
int row[200], col[200];

int x, y;
int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int it = 1;it <= T; ++it){
		scanf("%d%d",&n,&m);
		bool flag = true;
		memset(col, 0, sizeof(col));
		for(int i = 0;i < n; ++i){
			bool f = true;
			for(int j = 0;j < m; ++j){
				scanf("%d",&a[i][j]);
				if(a[i][j] <1 || a[i][j] > 100) flag = false;
				col[j] = max(col[j], a[i][j]);
			}
			row[i] = *max_element(a[i], a[i] + m);
		}
		for(int i= 0;i < n; ++i){
			for(int j = 0;j < m; ++j){
				if(row[i] > a[i][j] &&col[j] >a[i][j]) flag = false;
			}
		}
		printf("Case #%d: ",it);
		if(flag) puts("YES");
		else puts("NO");
	}
}
