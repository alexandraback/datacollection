#include <stdio.h>
#include <assert.h>

void testcase() {
	int r, c, m, fr;
	scanf("%d%d%d", &r, &c, &m);
	fr = r * c - m;

	if(r == 1) {
		putchar('c');
		for(int i = 1; i < fr; ++i)
			putchar('.');
		for(int i = fr; i < c; ++i)
			putchar('*');
		putchar(10);
	}
	else if(c == 1) {
		putchar('c'), putchar(10);
		for(int i = 1; i < fr; ++i)
			putchar('.'), putchar(10);
		for(int i = fr; i < r; ++i)
			putchar('*'), putchar(10);
	}
	else if(fr == 1) {
		for(int i = 0; i < r; ++i) {
			for(int j = 0; j < c; ++j)
				putchar(i == 0 && j == 0 ? 'c' : '*');
			putchar(10);
		}
	}
	else {
		for(int h = 2; h <= r; ++h)
			for(int w = 2; w <= c; ++w)
				if((h + w - 2) * 2 <= fr && fr <= h * w) {
					fr -= (h + w - 2) * 2;
					for(int i = 0; i < r; ++i) {
						for(int j = 0; j < c; ++j) {
							if(i < h && j < w) {
								if(i == 0 && j == 0)
									putchar('c');
								else if(i < 2 || j < 2)
									putchar('.');
								else if(fr > 0)
									putchar('.'), --fr;
								else
									putchar('*');
							}
							else
								putchar('*');
						}
						putchar(10);
					}

					assert(fr == 0);
					return;
				}

		fprintf(stderr, "%dx%d, %d mines\n", r, c, m);
		puts("Impossible");
	}
}

int main() {
	int n;

	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		printf("Case #%d:\n", i);
		testcase();
	}
}
