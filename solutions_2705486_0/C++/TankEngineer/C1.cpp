#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int INF = 100000000, D = 521196;
int l, f[4005][5], t[D + 5], d[D + 5], cnt[D + 5];
char word[D + 5][11], ls[D + 5], s[4005];

int main() {
	FILE *dict;
	dict = fopen("dict.txt", "r");
	//dict = fopen("dict1.txt", "r");
	for (int i = 0; i < D; ++i) {
	  fscanf(dict, "%s", word[i]);
	  ls[i] = strlen(word[i]);
	  //cout << word[i] << endl;
	}
	int T;
	scanf("%d", &T);
	for (int V = 1; V <= T; ++V) {
	  scanf("%s", s);
	  l = strlen(s);
	  memset(f, 0, sizeof(f));
	  for (int i = 1; i <= l; ++i) {
			for (int j = 0; j < 5; ++j) {
				f[i][j] = INF;
			}
		}
	  f[0][0] = 0;
	  for (int i = 0; i < l; ++i) {
	  	for (int k = 0; k < D; ++k) {
	  	  if (i + ls[k] > l) {
					t[k] = -1;
					continue;
				}
				t[k] = -2;
				cnt[k] = 0;
				int bef = -5;
				for (int j = 0; j < ls[k]; ++j) {
				  if (s[i + j] == word[k][j]) continue;
				  if (bef < 0) {
				    bef = t[k] = j;
				    cnt[k] = 1;
					} else if (j - bef < 5) {
					  t[k] = -1;
					  break;
					} else {
						bef = j;
						++cnt[k];
					}
				}
				d[k] = ls[k] - bef;
				if (d[k] >= 5) d[k] = 0;
			}
	  	for (int j = 0; j < 5; ++j) {
				if (f[i][j] == INF) continue;
				for (int k = 0; k < D; ++k) {
		  	  if (t[k] >= 0 && (j == 0 || t[k] + j >= 5)) {
		  	    f[i + ls[k]][d[k]] = min(f[i + ls[k]][d[k]], f[i][j] + cnt[k]);
					} else if (t[k] == -2) {
					  int nd = j + ls[k];
					  if (nd >= 5 || j == 0) nd = 0;
						f[i + ls[k]][nd] = min(f[i + ls[k]][nd], f[i][j]);
					}
				}
			}
		}
		//cout << word[g[2]] << endl;
		int ans = INF;
		for (int i = 0; i < 5; ++i) {
		  ans = min(ans, f[l][i]);
		}
		printf("Case #%d: %d\n", V, ans);
	}
	return 0;
}

