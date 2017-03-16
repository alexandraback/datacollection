
#include <iostream>
#include <string.h>

typedef char DIGIT[32];

void toDIGIT(DIGIT dest, DIGIT src) {
	for (int i = 0; i < 32; i++) {
		dest[i] = src[i];
	}
}

void toDIGIT(DIGIT dest, int src) {
	for (int i = 31; i >= 0; i--) {
		dest[i] = src % 10;
		src /= 10;
	}
}

void addDIGIT(DIGIT dest, DIGIT src) {
	int n;
	for (int i = 31; i >= 0; i--) {
		n = src[i];
		for (int j = i; j >= 0; j--) {
			if (n == 0) break;
			dest[j] += n;
			n = dest[j] / 10;
			dest[j] %= 10;
		}
	}
}

void addDIGIT(DIGIT dest, int src) {
	DIGIT tmp;
	toDIGIT(tmp, src);
	addDIGIT(dest, tmp);
}

void lshiftDIGIT(DIGIT dest, unsigned int left) {
	for (int i = 0; i < 32; i++) {
		if (i + left < 32)dest[i] = dest[i + left];
		else dest[i] = 0;
	}
}

void rshiftDIGIT(DIGIT dest, unsigned int right) {
	for (int i = 31; i >= 0; i--) {
		if (i - (int)right >= 0)dest[i] = dest[i - right];
		else dest[i] = 0;
	}
}

void multDIGIT(DIGIT a, DIGIT b, DIGIT out) {
	DIGIT tmp;
	toDIGIT(tmp, a);
	toDIGIT(out, 0);
	for (int i = 31; i >= 0; i--) {
		for (int j = b[i]; j > 0; j--) {
			addDIGIT(out, tmp);
		}
		lshiftDIGIT(tmp, 1);
	}
}

int compDIGIT(DIGIT a, DIGIT b) {
	for (int i = 0; i < 32; i++) {
		if (a[i] > b[i]) return 1;
		else if (a[i] < b[i]) return -1;
	}
	return 0;
}

void subDIGIT(DIGIT dest, DIGIT src) {
	for (int i = 0; i < 31; i++) dest[i] += 9;
	dest[31] += 10;
	int n;
	n = 0;
	for (int i = 31; i >= 0; i--) {
		dest[i] = dest[i] - src[i] + n;
		n = dest[i] / 10;
		dest[i] %= 10;
	}
}

int isZeroDIGIT(DIGIT in) {
	for (int i = 0; i < 32; i++) {
		if (in[i]) return 0;
	}
	return 1;
}

void modDIGIT(DIGIT in, DIGIT mod, DIGIT out) {
	DIGIT tmp;
	toDIGIT(tmp, mod);
	toDIGIT(out, in);
	while (tmp[0] == 0) lshiftDIGIT(tmp, 1);
	while (compDIGIT(tmp, mod) >= 0) {
		while (compDIGIT(out, tmp) >= 0) subDIGIT(out, tmp);
		rshiftDIGIT(tmp, 1);
	}
}

void getminDiv(DIGIT n, DIGIT out) {
	DIGIT mod;
	DIGIT modret;
	//DIGIT pow;
	DIGIT limit;
	toDIGIT(limit, 10000);
	toDIGIT(mod, 2);
	modDIGIT(n, mod, modret);
	if (isZeroDIGIT(modret)) toDIGIT(out, 2);
	else {
		DIGIT i;
		for (toDIGIT(i, 3);; addDIGIT(i, 2)) {
			/*
			toDIGIT(pow, i);
			multDIGIT(pow, i, pow);
			if (compDIGIT(pow, n) > 0) {
				toDIGIT(out, 0);
				break;
			}
			*/
			if (compDIGIT(i, limit) > 0) {
				toDIGIT(out, 0);
				break;
			}
			modDIGIT(n, i, modret);
			if (isZeroDIGIT(modret)) {
				toDIGIT(out, i);
				break;
			}
		}
	}
}

void BintoDec(DIGIT in, int base, DIGIT out) {
	DIGIT tmp;
	DIGIT dbase;
	toDIGIT(tmp, in);
	toDIGIT(dbase, base);
	toDIGIT(out, 0);
	for (int i = 0; i < 32;i++) {
			multDIGIT(out, dbase, out);
		if (tmp[0]) {
			addDIGIT(out, 1);
		}
		lshiftDIGIT(tmp, 1);
	}
}

void printDIGIT(DIGIT in) {
	int i = 0;
	while (in[i] == 0) {
		i++;
		if (i >= 32) std::cout << 0;
	}
	for (int j = i; j < 32; j++)
		std::cout << (char)('0' + in[j]);
}

void DWORDtoBIN(unsigned int dword, DIGIT out) {
	for (int i = 0; i < 32; i++) {
		out[i] = (0x80000000 & dword) != 0 ? 1 : 0;
		dword <<= 1;
	}
}

int main(void) {
	int T;
	int N;
	int J;

	unsigned int dwBin;
	DIGIT digit;
	DIGIT dec[9];
	DIGIT res[9];
	int invalid;

	std::cin >> T;
	for (int i = 0; i < T; i++) {
		std::cin >> N >> J;
		dwBin = (1 << (N - 1)) + 1;
		std::cout << "Case #" << i + 1 << ":" << std::endl;
		while (J > 0) {
			DWORDtoBIN(dwBin, digit);
			invalid = 0;
			for (int j = 2; j <= 10; j++) {
				BintoDec(digit, j, dec[j-2]);
				getminDiv(dec[j-2], res[j-2]);
				if (isZeroDIGIT(res[j - 2])) {
					invalid = 1;
					break;
				}
			}
			if (!invalid) {
				printDIGIT(digit);
				for (int j = 0; j < 9; j++) {
					std::cout << ' ';
					printDIGIT(res[j]);
				}
				std::cout << std::endl;
				J--;
			}
			dwBin += 2;
		}
	}
	return 0;
}