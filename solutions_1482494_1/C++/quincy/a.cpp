#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

void swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

int main()
{
	int T, N;
	int a[1000], b[1000];
	bool sa[1000], sb[1000];
	int star, round, ans;
	int i, j, k;

	freopen("D:\\VC2005\\GoogleCodeJam\\2012\\R1A_2\\B-large.in","r",stdin);
	freopen("D:\\VC2005\\GoogleCodeJam\\2012\\R1A_2\\out1.txt","w",stdout);

	scanf("%d\n", &T);
	for (i = 1; i <= T; ++i) {
		ans = 0;
		scanf("%d\n", &N);
		for (j = 0; j < N; ++j) {
			scanf("%d %d\n", &a[j], &b[j]);
			sa[j] = sb[j] = false;
			//printf("%d %d\n", a[j], b[j]);
		}
		
		for (j = 0; j < N; ++j) {
			for (k = j+1; k < N; ++k) {
				if (b[k] < b[j]) {
					swap(a[k], a[j]);
					swap(b[k], b[j]);
				}
				else if (b[k] == b[j] && a[k] < a[j]) {
					swap(a[k], a[j]);
					swap(b[k], b[j]);

				}
			}
		}
		//for (j = 0; j < N; ++j) printf("%d %d\n", a[j], b[j]);
		bool change = true;
		ans = star = round = 0;
		for (j = 0; j < N; ++j) sa[j] = sb[j] = false;
		while (change) {
			change = false;
			for (j = 0; j < N; ++j) {
				if (!sb[j] && star >= b[j]) {
					if (sa[j]) star++;
					else star += 2;
					sb[j] = true;
					ans++;
					change = true;
				}
			
			}
			if (star == N*2) break;

			int idx = -1, max = -1;
			for (j = 0; j < N; ++j) {
				if (!sa[j] && star >= a[j]) {
					if (max < b[j]) {
						idx = j;
						max = b[j];
					}
				}
			}

			if (idx != -1) {
					star++;
					sa[idx] = true;
					ans++;
					change = true;
			}
		}

		if (star == N*2) printf("Case #%d: %d\n", i, ans);
		else printf("Case #%d: Too Bad\n", i);
	}

	fclose(stdin);
	fclose(stdout);
}

