#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#define eps 1e-8
#define oo 1<<29
#define LL long long

using namespace std;

int T, m, n, q, w, mi, ma, cnt, s, t, fi, cc, e, r, z, x, an, pcnt;
int a[110][110];
bool b[110][110];

int main(){
	scanf("%d", &T);
	for (int rr = 1; rr <= T; rr++){
		cnt = 0;
		pcnt = -1;
		memset(b, 0, sizeof(b));
		printf("Case #%d: ", rr);
		scanf("%d%d", &n, &m);
		for (int i=0; i<n; i++)
			for (int j=0; j<m; j++)
				scanf("%d", &a[i][j]);
		bool ok = false;
		while (!ok){
			mi = 1000;
			for (int i=0; i<n; i++)
				for (int j=0; j<m; j++)
					if (a[i][j] < mi && b[i][j] == false)
						mi = a[i][j];
			for (int i=0; i<n; i++){
				bool correct = true;
				for (int j=0; j<m; j++){
					if (a[i][j] != mi && b[i][j] == false)
						correct = false;
				}
				if (correct)
					for (int j=0; j<m; j++){
						if (b[i][j] == false)
							cnt++;
						b[i][j] = true;
					}
			}
			for (int i=0; i<m; i++){
				bool correct = true;
				for (int j=0; j<n; j++){
					if (a[j][i] != mi && b[j][i] == false)
						correct = false;
				}
				if (correct)
					for (int j=0; j<n; j++){
						if (b[j][i] == false)
							cnt++;
						b[j][i] = true;
					}
			}
			if (pcnt == cnt)
				ok = true;
//			printf("%d %d\n", pcnt, cnt);
			pcnt = cnt;

		}
		if (cnt == n*m)
			printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
