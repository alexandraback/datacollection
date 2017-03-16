#include <memory.h>
#include <algorithm>
#include <stdio.h>
using namespace std;

#define INF 1e32;

int n;
int s[60], p[60];

int nt;
double t[10010];

int binary_search(double *x, int n, double value)
{
	int low = 0, high = n-1;
	int mid;
	int result = -1;

	while (low <= high) {
		mid = (low+high) / 2;
		if (x[mid] == value) return mid;
		if (x[mid] < value) low = mid+1;
		else high = mid-1;
	}

	return result;
}

bool edge[1010][60][60];
inline void makeedge(int k, int i, int j) { edge[k][i][j] = edge[k][j][i] = true; }

int color[1010];

inline int change(int x) { return x==-2 ? -3 : -2; }

int pointer[60];
int root(int x) { return x==pointer[x] ? x : (pointer[x]=root(pointer[x])); }
inline void merge(int x, int y) { pointer[root(x)] = root(y); }

int main()
{
	int i, j, k;

	int ttt, tt=0;
	scanf("%d", &ttt);
	while (ttt--) {
		scanf("%d", &n);
		char temp[4];
		for (i=0; i<n; i++) {
			scanf("%s %d %d", temp, &s[i], &p[i]);
			color[i] = temp[0]=='R';
		}

		nt = 0;
		t[nt++] = 0;
		t[nt++] = INF;
		
		for (i=0; i<n; i++) for (j=0; j<n; j++) if (i!=j) {
			if (s[i] > s[j] && p[i] < p[j]+5) {
				t[nt++] = p[j]-5 - p[i] > 0 ? (double)(p[j]-5 - p[i]) / (s[i] - s[j]) : 0;
				t[nt++] = (double)(p[j]+5 - p[i]) / (s[i] - s[j]);
			}
		}

		sort(t, t+nt);
		nt = unique(t, t+nt) - t;

		memset(edge, 0, sizeof(edge));
		for (i=0; i<n; i++) for (j=0; j<n; j++) if (i!=j) {
			if (s[i] > s[j] && p[i] < p[j]+5) {
				double t1 = p[j]-5 - p[i] > 0 ? (double)(p[j]-5 - p[i]) / (s[i] - s[j]) : 0;
				double t2 = (double)(p[j]+5 - p[i]) / (s[i] - s[j]);

				double start = binary_search(t, nt, t1);
				double end = binary_search(t, nt, t2);

				for (k=start; k<end; k++)
					makeedge(k, i, j);
			}

			else if (s[i] == s[j] && p[j]-5 < p[i] && p[i] <= p[j]) {
				for (k=0; k<nt-1; k++)
					makeedge(k, i, j);
			}
		}

		for (i=0; i<n; i++) pointer[i] = i;
		for (i=0; i<n; i++) for (j=0; j<n; j++) if (edge[0][i][j]) merge(i, j);

		double answer = -2;
		for (k=0; k<nt-1; k++) {
			for (i=0; i<n; i++) pointer[i] = root(i);

			for (i=0; i<n; i++) {
				for (j=0; j<n; j++) if (edge[k][i][j]) break;
				if (j==n) {
					int x;
					for (j=0; j<n; j++) if (i!=j && root(j)==i) {x = j; break; }
					for (j=0; j<n; j++) if (i!=j && root(j)==i) {pointer[j] = x;}
					color[i] = -1, pointer[i] = i;
				}
			}
			
			bool cflag, flag = true;
			do {
				cflag = false;
				for (i=0; i<n && flag; i++) for (j=0; j<n && flag; j++) if (edge[k][i][j]) {
					if (color[i]==-1 && color[j]==-1) color[i] = 0, color[j] = 1, merge(i, j), cflag = true;
					else if (color[i]!=-1 && color[j]!=-1 && root(i) == root(j) && color[i]==color[j]) flag = false;
					else if (color[i]!=-1 && color[j]!=-1 && root(i) != root(j) && color[i]==color[j]) {
						for (int l=0; l<n; l++) if (root(l) == root(i)) color[l] ^= 1;
						pointer[root(i)] = root(j);
						cflag = true;
					}
					else if (color[i]!=-1 && color[j]!=-1 && root(i) != root(j)) {
						pointer[root(i)] = root(j);
						cflag = true;
					}
					else if (color[i]>=0 && color[j]==-1) color[j] = !color[i], merge(i, j), cflag = true;
					else if (color[i]==-1 && color[j]>=0) color[i] = !color[j], merge(i, j), cflag = true;
				}
			} while (cflag && flag);

			if (!flag) {
				answer = t[k];
				break;
			}
		}

		printf("Case #%d: ", ++tt);
		if (answer==-2) printf("Possible\n");
		else printf("%.6lf\n", answer);
	}

	return 0;
}
