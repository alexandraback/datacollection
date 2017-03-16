#include <stdio.h>
#include <memory.h>
#include <vector>
#include <string>
#include <algorithm>
#define MN 51
using namespace std;
char str[8];
int n, m;
pair<string,int> data[MN];
bool d[MN][MN];
string r; bool path[MN];
int cnt, top[MN], st[MN][MN]; bool fin[MN][MN];
int qu[MN], qs, qe; bool vis[MN];
bool asdf[MN];
bool cut(int id, vector<int> del)
{
	int f, p, q;
	
	memset(asdf,0,sizeof(asdf));
	for (f = 0; f < del.size(); f++)
		asdf[del[f]] = 1;
	for (f = 0; f < n; f++) {
		if (path[f] == false) break;
	}
	memset(vis,0,sizeof(vis));
	qs = qe = 0;
	qu[qe++] = f; vis[f] = 1;
	while (qs < qe) {
		p = qu[qs++];
		for (q = 0; q < n; q++) {
			if (!asdf[q] && !fin[id][q] && d[p][q] && !vis[q]) {
				qu[qe++] = q; vis[q] = 1;
			}
		}
	}
	for (f = 0; f < n; f++) {
		if (path[f] == false && !vis[f])
			return true;
	}
	return false;
}
int main()
{
	FILE *in=fopen("input.txt","r");
	FILE *out=fopen("output.txt","w");
	int t, T, i, j, k, f;
	
	fscanf(in,"%d",&T);
	for (t = 1; t <= T; t++) {
		printf("Case #%d:\n",t);
		fprintf(out,"Case #%d: ",t);
		fscanf(in,"%d%d",&n,&m);
		for (i = 0; i < n; i++) {
			fscanf(in,"%s",str);
			data[i] = make_pair(str,i);
		}
		sort(data,data+n);
		memset(d,0,sizeof(d));
		for (i = 0; i < m; i++) {
			fscanf(in,"%d%d",&j,&k); j--; k--;
			for (f = 0; f < n; f++) {
				if (data[f].second == j) {
					j = f;
					break;
				}
			}
			for (f = 0; f < n; f++) {
				if (data[f].second == k) {
					k = f;
					break;
				}
			}
			d[j][k] = d[k][j] = 1;
		}
		f = 0;
		memset(path,0,sizeof(path));
		memset(fin,0,sizeof(fin));
		path[f] = 1; r = data[0].first;
		memset(top,-1,sizeof(top));
		cnt = 0; st[0][++top[0]] = f;
		for (;;) {
			for (i = 0; i < n; i++) {
				if (path[i]) continue;
				bool pos = false;
				vector<int> del;
				for (j = 0; j <= cnt; j++) {
					del.clear();
					for (k = top[j]; k >= 0; k--) {
						if (d[st[j][k]][i]) {
							pos = true;
							break;
						}
						else {
							del.push_back(st[j][k]);
							if (cut(j,del)) break;
						}
					}
				}
				del.clear();
				for (j = top[0]; j >= 0; j--) {
					if (d[st[0][j]][f] && d[f][i]) {
						pos = true;
						break;
					}
					else {
						del.push_back(st[0][j]);
						if (cut(0,del)) break;
					}
				}
				
				if (pos) break;
			}
			if (i >= n) break;
			path[i] = 1; r += data[i].first;
			// i
			top[cnt+1] = top[0];
			for (j = top[0]; j >= 0; j--)
				st[cnt+1][j] = st[0][j];
			for (j = 0; j < n; j++)
				fin[cnt+1][j] = fin[0][j];
			vector<int> del;
			for (j = 0; j <= cnt; j++) {
				del.clear();
				for (; top[j] >= 0; top[j]--) {
					if (d[st[j][top[j]]][i]) {
						st[j][++top[j]] = i;
						for (k = 0; k < del.size(); k++)
							fin[j][del[k]] = 1;
						break;
					}
					else {
						del.push_back(st[j][top[j]]);
						if (cut(j,del)) {
							top[j] = -1;
							break;
						}
					}
				}
			}
			del.clear();
			for (j = top[cnt+1]; j >= 0; j--) {
				if (d[st[cnt+1][j]][f] && d[f][i]) {
					cnt++;
					top[cnt] = j;
					st[cnt][++top[cnt]] = f;
					st[cnt][++top[cnt]] = i;
					for (k = 0; k < del.size(); k++)
						fin[cnt][del[k]] = 1;
					break;
				}
				else {
					del.push_back(st[cnt+1][j]);
					if (cut(0,del)) break;
				}
			}
		}
		if (r.length() != n*5) {
			printf("error\n");
			//for (;;);
		}
		fprintf(out,"%s\n",r.c_str());
	}
	fclose(in);
	fclose(out);
	return 0;
}