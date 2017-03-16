#include<bits/stdc++.h>
using namespace std;

#define question '?'

char a[20], b[20];
int test, l;
long long dif, resA, resB;

void imp(long long num, int digi) {
	if (digi == 0) return;
	imp(num / 10, digi - 1);
	printf("%lld", num % 10);
}

long long cambia(char * cad) {
	long long res = 0;
	for (int i = 0; i < l; i++) {
		res = (res * 10) + (int)(*(cad + i)) - '0';
	}
	return res;
}

void checa(int idx, int relacion) {
	if (idx == l) {
		long long prim = cambia(a);
		long long seg = cambia(b);
		long long curDif = abs(prim - seg);
		if (curDif < dif || (curDif == dif && prim < resA) || (curDif == dif && prim == resA && seg < resB)) {
			resA = prim;
			resB = seg;
			dif = curDif;
		}
		return;
	}

	if (relacion) {
		if (a[idx] == question) {
			if (b[idx] == question) {
				a[idx] = (relacion == 1) ? '0' : '9';
				b[idx] = (relacion == 2) ? '0' : '9';
				checa(idx + 1, relacion);
				a[idx] = question;
				b[idx] = question;
			}
			else {
				a[idx] = (relacion == 1) ? '0' : '9';
				checa(idx + 1, relacion);
				a[idx] = question;
			}
		}
		else {
			if (b[idx] == question) {
				b[idx] = (relacion == 2) ? '0' : '9';
				checa(idx + 1, relacion);
				b[idx] = question;
			}
			else {
				checa(idx + 1, relacion);
			}
		}
	}
	else {
		if (a[idx] != question && b[idx] != question) {
			if (a[idx] == b[idx])
				checa(idx + 1, relacion);
			else
				checa(idx + 1, 1 + (int)(b[idx] > a[idx]));
		}
		else {
			if (a[idx] == question) {
				if (b[idx] == question) {
					// los dos
					// Cero
					a[idx] = b[idx] = '0';
					checa(idx + 1, 0);
					a[idx] = b[idx] = question;
					// Primero
					a[idx] = '1';
					b[idx] = '0';
					checa(idx + 1, 1);
					a[idx] = b[idx] = question;
					// Segundo
					a[idx] = '0';
					b[idx] = '1';
					checa(idx + 1, 2);
					a[idx] = b[idx] = question;
				}
				else {
					// a
					// Cero
					a[idx] = b[idx];
					checa(idx + 1, 0);
					a[idx] = question;
					// Primero
					if (b[idx] < '9') {
						a[idx] = b[idx] + 1;
						checa(idx + 1, 1);
						a[idx] = question;
					}
					// Segundo
					if (b[idx] > '0') {
						a[idx] = b[idx] - 1;
						checa(idx + 1, 2);
						a[idx] = question;
					}
				}
			}
			else {
				// B
				// Cero
				b[idx] = a[idx];
				checa(idx + 1, 0);
				b[idx] = question;
				// Primero
				if (a[idx] > '0') {
					b[idx] = a[idx] - 1;
					checa(idx + 1, 1);
					b[idx] = question;
				}
				// Segundo
				if (a[idx] < '9') {
					b[idx] = a[idx] + 1;
					checa(idx + 1, 2);
					b[idx] = question;
				}
			}
		}
	}
}

void solve() {
	scanf("%s %s", a, b);
	l = strlen(a);
	dif = LLONG_MAX;

	checa(0, 0);

	imp(resA, l);
	printf(" ");
	imp(resB, l);
	printf("\n");
}

int main() {

	freopen("BLarge.out", "w", stdout);
	freopen("BLarge.in", "r", stdin);
	scanf("%d", &test);
	for (int testCase = 1; testCase <= test; testCase++) {
		printf("Case #%d: ", testCase);
		solve();
	}
	fclose(stdout);

	/*
	char arrr[500][500];
	for(int i = 0; i < 400; i++) gets(arrr[i]);
	for(int i = 200; i < 400; i++)
	if(strcmp(arrr[i], arrr[i - 200]) != 0){
	printf("-----\n%s %s", arrr[i], arrr[i - 200]);
	return 0;
	}
	*/
}
