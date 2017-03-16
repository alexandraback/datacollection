#include <stdio.h>

int n, m;
int low[128][128], high[128][128];
int h;

struct entr {
	int r, c;
};

entr que[128*128];
int qstart, qend, qmax=128*128, qlen;

int can[128][128][4];
int mr[4]={-1, 1, 0, 0};
int mc[4]={0, 0, -1, 1};
int best[128][128];
int pos[128][128];

int main() {
	FILE *fi = fopen("b.in", "r");
	FILE *fo = fopen("b.out", "w");

	int tests;
	fscanf(fi, "%d", &tests);
	for (int t=0; t<tests; t++) {
		fscanf(fi, "%d%d%d", &h, &n, &m);
		for (int i=0; i<n; i++)
			for (int j=0; j<m; j++)
				fscanf(fi, "%d", high[i]+j);
		for (int i=0; i<n; i++)
			for (int j=0; j<m; j++)
				fscanf(fi, "%d", low[i]+j);
		for (int r=0; r<n; r++)
			for (int c=0; c<m; c++)
				for (int k=0; k<4; k++) {
					int nr = r+mr[k];
					int nc = c+mc[k];
					if (nr>=0 && nr<n && nc>=0 && nc<m && high[nr][nc]-low[r][c]>=50 && high[r][c]-low[nr][nc]>=50 && high[nr][nc]-low[nr][nc]>=50)
						can[r][c][k]=1;
					else
						can[r][c][k]=0;
				}

		for (int r=0; r<n; r++)
			for (int c=0; c<m; c++)
				best[r][c]=-1;

		qstart=0;
		qend=0;
		que[0].r = 0;
		que[0].c = 0;
		best[0][0]=0;
		while (qstart<=qend) {
			int r = que[qstart].r;
			int c = que[qstart].c;
			qstart++;
			for (int k=0; k<4; k++) {
				int nr = r + mr[k];
				int nc = c + mc[k];
				if (can[r][c][k] && high[nr][nc]-h>=50 && best[nr][nc] == -1) {
					qend++;
					que[qend].r = nr;
					que[qend].c = nc;
					best[nr][nc] = 0;
				}
			}
		}

		if (best[n-1][m-1] != 0) {

			qstart=0;
			qend=-1;
			qlen=0;
			for (int r=0; r<n; r++)
				for (int c=0; c<m; c++)
					if (best[r][c]==0) {
						qlen++;
						qend++;
						que[qend].r = r;
						que[qend].c = c;
						pos[r][c]=qend;
					} else
						pos[r][c]=-1;

			while (qlen>0) {
				int r = que[qstart].r;
				int c = que[qstart].c;
				pos[r][c]=-1;
				qstart = (qstart+1)%qmax;
				qlen--;
				for (int k=0; k<4; k++) {
					int nr = r + mr[k];
					int nc = c + mc[k];
					if (can[r][c][k] && best[nr][nc]!=0) {
						int t = 50 - (high[nr][nc]-(h-best[r][c]));
						if (t<0) t = 0;
						int newb = best[r][c] + t;
						int h2 = h-newb;
						if (h2-low[r][c]>=20)
							newb += 10;
						else
							newb += 100;
						if (best[nr][nc]==-1 || best[nr][nc] > newb) {
							best[nr][nc] = newb;
							if (pos[nr][nc]==-1) {
								qend = (qend+1)%qmax;
								qlen++;
								pos[nr][nc] = qend;
								que[qend].r = nr;
								que[qend].c = nc;
							}
						}
					}
				}
			}
		}

		fprintf(fo, "Case #%d: %.1lf\n", t+1, best[n-1][m-1]*0.1);

	}

	fclose(fi);
	fclose(fo);
	return 0;
}
