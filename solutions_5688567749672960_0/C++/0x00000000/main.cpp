#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define type unsigned long long int

int lTen(type x) {
	int res = 1;
	while (x / 10 != 0) {
		res++;
		x /= 10;
	}
	return res;
}

type p10(int x) {
	type res = 1;
	for (int i = 0; i < x; i++) res *= 10;
	return res;
}

type invert(type x) {
	int len = lTen(x);
	type res = 0;
	for (int i = 0; i < len; i++) {
		res += (x % 10) * p10(len - i - 1);
		x /= 10;
	}
	return res;
}

type nines(int x) {
	type res = 0;
	type tn = 9;
	for (int i = 0; i < x - 1; i++) {
		res += tn;
		tn *= 10;
	}
	return res;
}

int main(void) {
	type N, T, cnt, t1, t2, temp, tmp, tt;
	int len;
	FILE *in = fopen("input.in", "rt");
	FILE *out = fopen("output.out", "wt");
	fscanf(in, "%llu", &N);
	for (type i = 0; i < N; i++) {
		fscanf(in, "%llu", &T);
		len = lTen(T);
		if (len == 1) {
			cnt = T;
		}
		else if (len == 2) {
			t1 = T / 10;
			t2 = T % 10;
			if (t1 == 1) {
				cnt = T;
			}
			else if (t2 == 0) {
				cnt = 10 + t1 + 9;
			}
			else {
				cnt = 10 + t2 + t1;
			}
		}
		else {
			cnt = 29;
			tt = 100;
			for (int j = 2; j < len - 1; j++) {
				tt *= 10;
				if (j % 2 == 0) {
					cnt += (1 + nines(lTen(tt) / 2) + nines(lTen(tt) / 2 + 1));
				}
				else {
					cnt += (1 + nines(lTen(tt) / 2 + 1) * 2);
				}
			}
			if (len % 2 == 0) {
				temp = p10(len / 2);
				t1 = T % temp;
				tmp = T / temp;
				t2 = invert(tmp);
				if (t2 != 1) cnt += (t1 + t2);
				else cnt += t1;
			}
			else {
				temp = p10(len / 2 + 1);
				t1 = T % temp;
				tmp = T / temp;
				t2 = invert(tmp);
				if (t2 != 1) cnt += (t1 + t2);
				else cnt += (t1);
			}
		}
		fprintf(out, "Case #%llu: %llu", i+1, cnt);
		if (i != N - 1) fprintf(out, "\n");
	}
	fclose(in);
	fclose(out);
	return 0;
}