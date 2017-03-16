#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int test, caseNum;
double a[1005], b[1005];
int n;
bool chk_a[1005], chk_b[1005];
int b_min, b_max;

int main()
{
	FILE *in = fopen("D-large.in", "r");
	//FILE *in = fopen("input.txt", "r");
	FILE *out = fopen("output.txt", "w");

	int d_res, r_res;
	caseNum = 1;
	fscanf(in, "%d", &test);
	while(caseNum <= test)
	{
		fscanf(in, "%d", &n);
		for (int i = 0; i < n; i++) fscanf(in, "%lf", &a[i]);
		for (int i = 0; i < n; i++) fscanf(in, "%lf", &b[i]);
		for (int i = 0; i < n; i++) chk_a[i] = chk_b[i] = false;
		d_res = 0, r_res = 0;

		sort(a, a+n);
		sort(b, b+n);

		// Deceitful War
		b_min = 0;
		b_max = n-1;
		for (int i = 0; i < n; i++) {
			if (a[i] > b[b_min]) {
				d_res++;
				b_min++;
			}
			else {
				b_max--;
			}
		}
		
		// War
		bool flag;
		for (int i = 0; i < n; i++) {
			flag = false;
			b_min = -1;
			for (int j = 0; j < n; j++) {
				if (b_min == -1 && !chk_b[j])
					b_min = j;
				if (!chk_b[j] && b[j] > a[i]) {
					chk_b[j] = true;
					flag = true;
					break;
				}
			}
			if (!flag) {
				r_res++;
				chk_b[b_min] = true;
			}
		}

		fprintf(out, "Case #%d: %d %d\n", caseNum++, d_res, r_res);
	}

	fcloseall();

	return 0;
}
