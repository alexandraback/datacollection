//GCJ Round1C 2014-05-11 B
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define MOD 1000000007
FILE* fw;

struct str {
	char s[110];
	int flag_all;
}p[110];

int all[27], head[27], tail[27], mid[27], vis[110], seg, n;

void DFS(int x) {
	vis[x] = 1;
	for(int i = 0; i < n; ++i) {
		if(p[x].s[strlen(p[i].s) - 1] == p[i].s[0] && !vis[i]) {
			DFS(i);
		}
	}
}

int main() {
//	freopen("C-large.in", "r", stdin);
	freopen("B-small-attempt2.in", "r", stdin);
	fw = fopen("B-s2.txt", "w");
	int cse, i, g = 1, j, cnt;
	long long res, tp;
	bool ok;
	scanf("%d", &cse);
	while (cse--) {
		scanf("%d", &n);
		memset(all, 0, sizeof(all));
		memset(head, 0, sizeof(head));
		memset(tail, 0, sizeof(tail));
		memset(mid, 0, sizeof(mid));
		ok = true;
		for(i = 0; i < n; ++i) {
			memset(p[i].s, 0x00, sizeof(p[i].s));
			scanf("%s", p[i].s);
			p[i].flag_all = 0;
			cnt = 0;
			for(j = 1; p[i].s[j]; ++j) {
				if(p[i].s[j] != p[i].s[j - 1]) {
					cnt++;
				}
			}
			if(!cnt) {
				all[p[i].s[0] - 'a']++;
				p[i].flag_all = 1;
			}
			else {
				head[p[i].s[0] - 'a']++;
				tail[p[i].s[strlen(p[i].s) - 1] - 'a']++;
				for(j = 0; p[i].s[j]; ++j) {
					if(p[i].s[j] != p[i].s[0]) break;
				}
				for(++j; p[i].s[j]; ++j) {
					if(p[i].s[j] != p[i].s[j - 1]) {
						mid[p[i].s[j- 1] - 'a']++;
					}
				}
				mid[p[i].s[strlen(p[i].s) - 1] - 'a']--;
			}
		}
		for(i = 0; i < 26; ++i) {
			if(mid[i] > 1) {
//				printf("case%d %c\n", g, i + 'a');
				ok = false;
				break;
			}
			if(mid[i] == 1 && (head[i] > 0 || tail[i] > 0)) {
//				printf("case%d %c\n", g, i + 'a');
				ok = false;
				break;
			}
			if(head[i] > 1 || tail[i] > 1) {
//				printf("case%d %c\n", g, i + 'a');
				ok = false;
				break;
			}
		}
		if(ok) {
			seg = 0;
			memset(vis, 0, sizeof(vis));
			for(i = 0; i < n; ++i) {
				if(!vis[i] && head[i] == 1 && tail[i] == 0) {
					DFS(i);
					seg++;
				}
			}
			for(i = 0; i < n; ++i) {
				if(!vis[i]) {
					DFS(i);
					seg++;
				}
			}
//			printf("seg=%d\n", seg);
			res = 1;
			for(i = 0; i < 26; ++i) {
				if(all[i] > 0) {
					tp = 1;
					for(j = 1; j <= all[i]; ++j) {
						tp = (tp * j) % MOD;
					}
					res = (res * tp) % MOD;
					if(!head[i] && !tail[i])seg++;
				}
			}
			for(i = 1; i <= seg; ++i) {
				res = (res * i) % MOD;
			}
			fprintf(fw, "Case #%d: %lld\n", g++, res);
		}
		else {
			fprintf(fw, "Case #%d: 0\n", g++);
		}
	}
	fclose(fw);
	return 0;
}

