#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cassert>
using namespace std;

typedef long long LL;

struct Integer {
	int l;
	int a[100];
	void clear() {
		memset(a, 0, sizeof(a));
		l = 1;
	}
	bool is_zero() const {
		return l == 0 || l == 1 && a[0] == 0;
	}
};

void Add(Integer &a, const Integer &b)
{
	for (int i = 0; i < b.l; ++i) {
		if (i < a.l) {
			a.a[i] += b.a[i];
		} else {
			a.a[i] = b.a[i];
		}
	}
	if (a.l < b.l) a.l = b.l;
	for (int i = 0; i < a.l; ++i) {
		if (a.a[i] >= 10) {
			a.a[i+1] += a.a[i] / 10;
			a.a[i] %= 10;
		}
	}
	while (a.a[a.l] >= 10) {
		a.a[a.l+1] += a.a[a.l] / 10;
		a.a[a.l] %= 10;
		a.l++;
	}
	if (a.a[a.l] > 0) a.l++;
}

void Muln(const Integer &a, int n, Integer &b)
{
	if (&a == &b) puts("error");
	b.clear();
	if (b.is_zero()) {
		return;
	}
	for (int i = 0; i < a.l; ++i) b.a[i] = a.a[i] * n;
	for (int i = 0; i < a.l; ++i) {
		if (b.a[i] >= 10) {
			b.a[i+1] += b.a[i] / 10;
			b.a[i] %= 10;
		}
	}
	b.l = a.l;
	while (b.a[b.l] >= 10) {
		b.a[b.l+1] = b.a[b.l] / 10;
		b.a[b.l] %= 10;
		b.l++;
	}
	if (b.a[b.l] > 0) ++b.l;
}

void Mul(const Integer &a, const Integer &b, Integer &c)
{
	if (&a == &c || &b == &c) puts("error");
	c.clear();
	if (a.is_zero() || b.is_zero()) {
		return;
	}
	for (int i = 0; i < a.l; i++) {
		for (int j = 0; j < b.l; j++) {
			c.a[i+j] += a.a[i] * b.a[j];
			if (c.a[i+j] >= 10) {
				c.a[i+j+1] += c.a[i+j] / 10;
				c.a[i+j] %= 10;
			}
		}
	}
	int l = a.l + b.l - 1;
	if (c.a[l+1] > 0) l++;
	while (c.a[l] >= 10) {
		c.a[l+1] += c.a[l] / 10;
		c.a[l] %= 10;
		l++;
	}
	c.l = l;
}

void Print(const Integer &a) {
	for (int i = a.l - 1; i >= 0; --i) printf("%d", a.a[i]);
}

void IntStr(const Integer &a, int len, char *str) {
	if (len < a.l) len = a.l;
	for (int i = 0; i < len; ++i) {
		if (i >= a.l) {
			str[len - 1 - i] = '0';
		} else {
			str[len - 1 - i] = a.a[i] + '0';
		}
	}
	str[len] = 0;
}

const LL fa[70] = {1,4,9,121,484,10201,12321,14641,40804,44944,1002001,1234321,4008004,100020001,102030201,104060401,121242121,123454321,125686521,400080004,404090404,10000200001,10221412201,12102420121,12345654321,40000800004,1000002000001,1002003002001,1004006004001,1020304030201,1022325232201,1024348434201,1210024200121,1212225222121,1214428244121,1232346432321,1234567654321,4000008000004,4004009004004,100000020000001,100220141022001,102012040210201,102234363432201,121000242000121,121242363242121,123212464212321,123456787654321,400000080000004,10000000200000001,10002000300020001,10004000600040001,10020210401202001,10022212521222001,10024214841242001,10201020402010201,10203040504030201,10205060806050201,10221432623412201,10223454745432201,12100002420000121,12102202520220121,12104402820440121,12122232623222121,12124434743442121,12321024642012321,12323244744232321,12343456865434321,12345678987654321,40000000800000004,40004000900040004};

int get_cnt(char *num) {
	int ls = strlen(num);
	if (ls <= 17+1) {
		LL n;
		sscanf(num, "%lld", &n);
		return lower_bound(fa, fa + 70, n+1) - fa;
	}
	int ret = 3;
	int j = (ls+1) / 2;
	for (int i = 2; i < j; ++i) {
		int t = 0;
		if (i & 1) {
			ret += (t=3 * (1<<i/2-1) + 2);
		} else {
			ret += (t=(1<<i/2-1) + 1);
		}
	}
	Integer a, b;
	char str[200];
	if (j & 1) {
		int h = j/2, l = 0, r = (1<<h-1) * 3 + 1;
		while (l <= r) {
			//fprintf(stderr, "1: %d - %d\n", l, r);
			int m = (r - l)/2 + l;
			int d = m / (1<<h-1);
			int s = m / 3;
			if (s == (1<<h-1)-1 && d == 2) {
				s = 1<<h-1;
				d = 0;
			}
			if (s == (1<<h-1) && d == 2) {
				d = 1;
			}
			a.clear();
			int len = 0;
			for (int i = h-1; i >= 0; --i) {
				str[len++] = (s &(1<<i)) ? 1 : 0;
			}
			str[0]++;
			str[len] = d;
			for (int i = 0; i < len; ++i) {
				str[len+i+1] = str[len - i];
			}
			for (int i = 0; i < j; ++i) {
				a.a[i] = str[j - i - 1];
			}
			a.l = j;
			Mul(a, a, b);
			IntStr(b, ls, str);
			int cmp = strcmp(str, num);
			if (cmp < 0) {
				l = m + 1;
			} else if (cmp > 0) {
				r = m - 1;
			} else {
				l = r = m;
				break;
			}
		}
		ret += r + 1;
	} else {
		int h = j/2, l = 0, r = 1<<h-1;
		while (l <= r) {
		//	fprintf(stderr, "2: %d - %d\n", l, r);
			int m = (r - l)/2 + l;
			a.clear();
			int len = 0;
			for (int i = h-1; i >= 0; i--) {
				str[len++] = (m & (1<<i)) ? 1 : 0;
			}
			str[0]++;
			for (int i = 0; i < len; ++i) {
				str[len+i] = str[len - 1 - i];
			}
			for (int i = 0; i < j; ++i) {
				a.a[i] = str[j - i - 1];
			}
			a.l = j;
			Mul(a, a, b);

			IntStr(b, ls, str);

	//		Print(a); putchar( ' ' ); Print(b); putchar(' '); puts(num);

			int cmp = strcmp(str, num);
			if (cmp < 0) {
				l = m + 1;
			} else if (cmp > 0) {
				r = m - 1;
			} else {
				l = r = m;
				break;
			}
		}
		ret += r + 1;
	}
	return ret;
}

char sa[200], sb[200], sc[200];

int main() {
	int T;
	scanf("%d", &T);
	for (int run = 1; run <= T; ++run) {
		scanf("%s%s", sa, sb);
		int la = strlen(sa);
		strcpy(sc, sa);
		int lc = la;
		if (!(la == 1 && sa[0] == '0')) {
			for (int i = 0; i < la; ++i) sc[i] -= '0';
			sc[la-1]--;
			lc = la - 1;
			while (lc > 0 && sc[lc] < 0) {
				sc[lc] += 10;
				sc[--lc] -= 1;
			}
			if (lc == 0 && sc[lc] < 0) {
				lc = la - 1;
				for (int i = 0; i < lc; ++i) {
					sc[i] = sc[i+1];
				}
				sc[lc] = 0;
			} else {
				lc = la;
			}
			for (int i = 0; i < lc; ++i) sc[i] += '0';
		}
		/*
		fprintf(stderr, "%s %s\n", sa, sb);
		fprintf(stderr, "%s %s\n", sc, sb);
		*/
		int x = get_cnt(sc), y = get_cnt(sb);
		int ans = y - x;
		printf("Case #%d: %d\n", run, ans);
	}
	return 0;
}
