#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

const int mn = 12, mlen=200;
char s[mn][mlen];
int id[mn];


bool check(int n, int *id) {
	int pos[26];
	memset(pos, -1, sizeof(pos));

//	for (int i=0;i<n;++i) {
//		printf("%s ", s[id[i]]);
//	}
//	putchar('\n');

	int curp = 0;
	for(int i=0;i<n;++i) {

		for(const char *p = s[id[i]]; *p; ++p) {
			int c = *p - 'a';
			if (pos[c] != -1) {
				if (curp != pos[c]+1) return 0;
			}
			pos[c] = curp;
			curp++;
		}
	}
	return 1;
}


int main() {
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);
	int Tn;
	scanf("%d", &Tn);
	for (int Tc = 1; Tc <= Tn; ++Tc) {
		int n;
		scanf("%d", &n);
		for(int i=0;i<n;++i) {
			scanf("%s", s[i]);
			id[i]=i;
		}

		int ans = 0;
		do{
			if (check(n, id)) ++ans;
		}while(next_permutation(id, id+n));


		printf("Case #%d: %d\n", Tc, ans);
	}
	return 0;
}
