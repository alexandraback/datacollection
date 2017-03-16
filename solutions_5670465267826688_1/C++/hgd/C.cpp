#include <cstdio>
#include <cstdlib>
#include <cctype>

char *s = NULL;
int x, l;
int lfirst[8], rfirst[8];

char mul(char a, char b) {
	int sign = 1;
	if (a < 0) {
		sign = -sign;
		a = -a;
	}
	if (b < 0) {
		sign = -sign;
		b = -b;
	}
	if (a == '1') return sign * b;
	if (b == '1') return sign * a;
	if (a == b) return -sign * '1';
	if (a == 'i' && b == 'j') return sign * 'k';
	if (a == 'j' && b == 'k') return sign * 'i';
	if (a == 'k' && b == 'i') return sign * 'j';
	if (a == 'j' && b == 'i') return -sign * 'k';
	if (a == 'k' && b == 'j') return -sign * 'i';
	if (a == 'i' && b == 'k') return -sign * 'j';
	return '\0'; //error
}

char inv(char a) {
	if (a == '1' || a == -'1') return a;
	return -a;
}

int cti(char a) {
	switch (a) {
		case '1': return 0;
		case -'1': return 1;
		case 'i': return 2;
		case -'i': return 3;
		case 'j': return 4;
		case -'j': return 5;
		case 'k': return 6;
		case -'k': return 7;
	}
	return 9999; //error
}

bool work() {
	char cur = '1';
	for (int i = 0; i < 8; ++i) {
		lfirst[i] = l + 1;
		rfirst[i] = l + 1;
	}
	lfirst[cti('1')] = 0;
	rfirst[cti('1')] = 0;
	for (int i = 0; i < l; ++i) {
		cur = mul(cur, s[i]);
		if (lfirst[cti(cur)] > i + 1)
			lfirst[cti(cur)] = i + 1;
	}
	char total = '1';
	for (int j = 0; j < x % 4; ++j)
		total = mul(total, cur);
	if (total != -'1') return false;
	cur = '1';
	for (int i = 1; i <= l; ++i) {
		cur = mul(s[l - i], cur);
		if (rfirst[cti(cur)] > i)
			rfirst[cti(cur)] = i;
	}
	
	int x1 = x + 1, l1 = l + 1;
	total = '1';
	for (int j = 0; j < 4; ++j) {
		char tmp = mul(inv(total), 'i');
		if (lfirst[cti(tmp)] <= l) {
			x1 = j;
			l1 = lfirst[cti(tmp)];
			break;
		}
		total = mul(total, cur);
	}
	if (x1 > x) return false;
	
	int x2 = x + 1, l2 = l + 1;
	total = '1';
	for (int j = 0; j < 4; ++j) {
		char tmp = mul('k', inv(total));
		if (rfirst[cti(tmp)] <= l) {
			x2 = j;
			l2 = rfirst[cti(tmp)];
			break;
		}
		total = mul(cur, total);
	}
	if (x2 > x) return false;
	
	if (x1 + x2 < x - 1) return true;
	if (x1 + x2 == x - 1 && l1 + l2 <= l) return true;
	return false;
}

int main() {
	FILE *fp = fopen("C-large.in", "r");
	FILE *fout = fopen("out.txt", "w");
	int T;	
	fscanf(fp, "%d", &T);
	for (int i = 0; i < T; ++i) {
		fscanf(fp, "%d %d", &l, &x);
		s = (char *)realloc(s, l * sizeof(char) + 1);
		fscanf(fp, "%s", s);
		if (work())
			fprintf(fout, "Case #%d: YES\n", i + 1);
		else
			fprintf(fout, "Case #%d: NO\n", i + 1);
	}
	free(s);
	fclose(fp);
	fclose(fout);
	return 0;
}