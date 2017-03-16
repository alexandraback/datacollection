#include <cstdlib>
#include <cstdio>
#include <algorithm>

using namespace std;

const int L = 10000 + 10;

int m[8][8] =
{
	{ 0, 1, 2, 3, 4, 5, 6, 7},
	{ 1, 4, 3, 6, 5, 0, 7, 2},
	{ 2, 7, 4, 1, 6, 3, 0, 5},
	{ 3, 2, 5, 4, 7, 6, 1, 0},
	{ 4, 5, 6, 7, 0, 1, 2, 3},
	{ 5, 0, 7, 2, 1, 4, 3, 6},
	{ 6, 3, 0, 5, 2, 7, 4, 1},
	{ 7, 6, 1, 0, 3, 2, 5, 4}
};
int tran[200], a[L];
char s[L];
bool used[8][L];
//0->1, 1->i, 2->j, 3->k, 4->-1, 5->-i, 6->-j, 7->-k

int main() {
	tran['1'] = 0;
	tran['i'] = 1;
	tran['j'] = 2;
	tran['k'] = 3;

	int t;
	scanf("%d", &t);
	for(int kase = 1; kase <= t; kase++) {
		int l;
		long long x;
		scanf("%d%lld", &l, &x);
		scanf("%s", s);

		for(int i = 0; i < l; i++)	a[i] = tran[s[i]];

		int num = 0, tmp = 0;
		for(int i = 0; i < l; i++)	num = m[num][a[i]];
		for(int i = 0; i < x%4; i++)	tmp = m[tmp][num];
		if(tmp != 4) {
			printf("Case #%d: NO\n", kase);
			continue;
		}

		fill(used[0], used[8], false);
		num = 0;
		bool flag = false, hasi = false, hask = false;
		int cnt1 = 0, cnt2 = 0;
		long long pos_i, pos_k;
		while(1) {
			for(int i = 0; i < l && !flag; i++) {
				num = m[num][a[i]];
				if(num == tran['i']) {
					hasi = true;
					pos_i = cnt1*l+i;
				}

				if(used[num][i] || hasi)	flag = true;
				used[num][i] = true;
			}
			if(flag)	break;
			cnt1++;
		}
		if(!hasi) {
			printf("Case #%d: NO\n", kase);
			continue;
		}

		fill(used[0], used[8], false);
		num = 0;
		flag = false;
		while(1) {
			for(int i = l-1; i >= 0 && !flag; i--) {
				num = m[a[i]][num];
				if(num == tran['k']) {
					hask = true;
					pos_k = l*x-l*cnt2-l+i;
				}
				if(used[num][i] || hask)	flag = true;
				used[num][i] = true;
			}
			if(flag)	break;
			cnt2++;
		}
		if(!hask) {
			printf("Case #%d: NO\n", kase);
			continue;
		}
		if(pos_i >= pos_k) {
			printf("Case #%d: NO\n", kase);
			continue;
		}

		printf("Case #%d: Yes\n", kase);
	}

	return 0;
}
