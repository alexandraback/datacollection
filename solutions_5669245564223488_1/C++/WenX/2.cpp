#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int nexts[255];
int firsts[255];
int lasts[255];
int middles[255];
int fulls[255];
int visited[255];
int bad;

int n;
char ss[111][111];
char min_ss[111][111];

long long ans;
long long pairs;

void frac(int n){
	if (n <= 1)
		return;
	while (n > 1){
		ans *= n--;
		ans %= 1000000007;
	}
}

void doit(int i){
	if (i == 0)return;
	visited[i] = 1;
	frac(fulls[i]);
	doit(nexts[i]);
}

int main(){
	int cc, tt;
	scanf("%d", &tt);
	for (int cc = 1; cc <= tt; cc++){
		ans = 1;
		pairs = 0;
		memset(nexts, 0, sizeof(nexts));
		memset(firsts, 0, sizeof(firsts));
		memset(lasts, 0, sizeof(lasts));
		memset(middles, 0, sizeof(middles));
		memset(fulls, 0, sizeof(fulls));
		memset(visited, 0, sizeof(visited));
		bad = 0;

		scanf("%d", &n);
		for (int i = 0; i < n; i++){
			scanf("%s", ss[i]);
			int minsslen = 0;
			for (int j = 0; j < strlen(ss[i]); j++){
				if (j == 0 || ss[i][j] != ss[i][j - 1])
					min_ss[i][minsslen++] = ss[i][j];
			}
			min_ss[i][minsslen] = 0;
			if (minsslen == 1){
				fulls[min_ss[i][0]]++;
			}
			else{
				firsts[min_ss[i][0]]++;
				lasts[min_ss[i][minsslen - 1]]++;
				nexts[min_ss[i][0]] = min_ss[i][minsslen - 1];
				for (int k = 1; k < minsslen - 1; k++)
					middles[min_ss[i][k]]++;
			}
		}

		for (int i = 'a'; i <= 'z'; i++){
			if (middles[i] && (firsts[i] || fulls[i] || lasts[i]))
				bad = 1;
			if (firsts[i]>1)
				bad = 1;
			if (middles[i] > 1)
				bad = 1;
			if (lasts[i] > 1)
				bad = 1;
		}

		for (int i = 'a'; i <='z'; i++){
			if (lasts[i] || visited[i])
				continue;
			if (firsts[i] || fulls[i]){
				pairs++;
				doit(i);
			}
		}

		for (int i = 'a'; i <= 'z'; i++)
		if (!visited[i] && (fulls[i] || lasts[i] || firsts[i]))
			bad = 1;

		if (bad){
			cout << "Case #" << cc << ": " << 0 << endl;
		}
		else{
			frac(pairs);
			cout << "Case #" << cc << ": " << ans << endl;
		}

	}
	return 0;
}