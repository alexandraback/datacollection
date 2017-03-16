#include <cstdio>
#include <cstring>
const int nmax = 18 + 18;

char ansc[nmax], ansj[nmax];
unsigned long long ansv, anscv, ansjv;
char C[nmax], J[nmax];
bool fst;
int n;

unsigned long long absdec(unsigned long long a, unsigned long long b)
{
	if (a > b)
		return a - b;
	else
		return b - a;
}

void update(unsigned long long curcv, unsigned long long curjv, char *curc, char *curj)
{
	unsigned long long v = absdec(curcv, curjv);
//	printf("%s %s\n", curc + 1, curj + 1);
	if (fst || v < ansv || (v == ansv && curcv < anscv) || (v == ansv && curcv == anscv && curjv < ansjv)) {
		fst = 0;
		ansv = v;
		anscv = curcv;
		ansjv = curjv;
		for (int i = 1; i <= n; ++i)
			ansc[i] = curc[i], ansj[i] = curj[i];
	}
}

void calc(unsigned long long curcv, unsigned long long curjv, char *curc, char *curj, int p, int bigger)
{
//	printf("%s %s %d %d\n", curc + 1, curj + 1, p, bigger);
	for (int i = p; i <= n; ++i) {
		if (bigger == 0) {
			if (C[i] == '?')
				curc[i] = '0';
			if (J[i] == '?')
				curj[i] = '9';
		}
		else {
			if (C[i] == '?')
				curc[i] = '9';
			if (J[i] == '?')
				curj[i] = '0';
		}
		curcv = curcv * 10 + curc[i] - '0';
		curjv = curjv * 10 + curj[i] - '0';
	}
	update(curcv, curjv, curc, curj);
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int cases = 1; cases <= T; ++cases) {
		scanf("%s%s", C + 1, J + 1);
		fst = 1;
		n = strlen(C + 1);
		for (int i = 0; i <= n; ++i) {
			char curc[nmax], curj[nmax];
			unsigned long long curcv = 0, curjv = 0, tmpc, tmpj;
			memcpy(curc, C, sizeof(C));
			memcpy(curj, J, sizeof(J));
			for (int j = 1; j <= i; ++j) {
				if (C[j] == '?')
					if (J[j] == '?')
						curc[j] = curj[j] = '0';
					else
						curc[j] = J[j];
				else 
					if (J[j] == '?')
						curj[j] = C[j];
				curcv = curcv * 10 + curc[j] - '0';
				curjv = curjv * 10 + curj[j] - '0';
			}
			if (i == n) {
				update(curcv, curjv, curc, curj);
				continue;
			}
			if (curcv == curjv) {
				for (int k = 0; k < 9; ++k) {
					if (C[i + 1] == '?')
						curc[i + 1] = k + '0';
					if (J[i + 1] == '?')
						curj[i + 1] = k + 1 + '0';
					
					
					tmpc = curcv * 10 + curc[i + 1] - '0';
					tmpj = curjv * 10 + curj[i + 1] - '0';
					calc(tmpc, tmpj, curc, curj, i + 2, tmpj > tmpc);
					
					if (J[i + 1] == '?')
						curj[i + 1] = k + '0';
					if (C[i + 1] == '?')
						curc[i + 1] = k + 1 + '0';
					tmpc = curcv * 10 + curc[i + 1] - '0';
					tmpj = curjv * 10 + curj[i + 1] - '0';
					calc(tmpc, tmpj, curc, curj, i + 2, tmpj > tmpc);
				}
			}
			else if (curcv > curjv) {
				calc(curcv, curjv, curc, curj, i + 1, 0);
			}
			else {
				calc(curcv, curjv, curc, curj, i + 1, 1);
			}
		}
		ansc[n + 1] = 0;
		ansj[n + 1] = 0;
		printf("Case #%d: ", cases);
		printf("%s %s", ansc + 1, ansj + 1);
		printf("\n");
	}
	return 0;
}

