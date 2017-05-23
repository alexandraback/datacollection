#include <cstdio>
using namespace std;

const int Maxn = 52;

int t;
int r, c, m;
bool found;
char B[Maxn][Maxn];

void Fill(char ch)
{
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
			printf("%c", i == 0 && j == 0? 'c': ch);
		printf("\n");
	}
}

void printOnlyRow()
{
	for (int i = 0; i < c; i++)
		if (m) { printf("*"); m--; }
		else printf("%c", i == c - 1? 'c': '.');
	printf("\n");
}

void printOnlyCol()
{
	for (int i = 0; i < r; i++)
		if (m) { printf("*\n"); m--; }
		else printf("%c\n", i == r - 1? 'c': '.');
}

void Solve(int a, int b, int add, int flag)
{
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			B[i][j] = i == 0 && j == 0? 'c': i < a && j < b? '.': '*';
	if (flag == 1) {
		for (int i = 0; i < add; i++)
			B[i][b] = '.';
		if (add == 1) { B[a - 1][b - 1] = '*'; B[1][b] = '.'; }
	}
	else {
		for (int j = 0; j < add; j++)
			B[a][j] = '.';
		if (add == 1) { B[a - 1][b - 1] = '*'; B[a][1] = '.'; }
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
			printf("%c", B[i][j]);
		printf("\n");
	}
}

int main()
{
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		scanf("%d %d %d", &r, &c, &m);
		printf("Case #%d:\n", tc);
		if (m == 0) Fill('.');
		else if (m == r * c - 1) Fill('*');
		else if (r == 1) printOnlyRow();
		else if (c == 1) printOnlyCol();
		else {
			int need = r * c - m;
			found = false;
			for (int a = 2; a <= r && !found; a++)
				for (int b = 2; b <= c && !found; b++) if (a * b <= need) {
					int add = need - a * b;
					if ((add != 1 || a >= 3 && b >= 3) && add <= a && (add == 0 || b < c)) {
						Solve(a, b, add, 1);
						found = true; continue;
					}
					if ((add != 1 || a >= 3 && b >= 3) && add <= b && (add == 0 || a < r)) {
						Solve(a, b, add, 2);
						found = true; continue;
					}
				}
			if (!found) printf("Impossible\n");
		}
	}
	return 0;
}