#include <cstdlib>
#include <cstdio>
#include <cstring>

unsigned char a[100][100];
unsigned char b[100][100];
unsigned char mx[100], my[100];

void print(int m, int n)
{
	for(int y=0; y<n; y++) {
		printf("\n");
		for(int x=0; x<m; x++)
			printf("%d", (int)a[x][y]);
	}
	printf("\n");
	for(int y=0; y<n; y++) {
		printf("\n");
		for(int x=0; x<m; x++)
			printf("%d", (int)b[x][y]);
	}
	printf("\n");
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int nCase; scanf("%d", &nCase);
	for(int index=0; index<nCase; index++) {
		int n, m; scanf("%d%d", &n, &m);
		memset(a, 100, sizeof(a));
		memset(b, 100, sizeof(b));
		for(int y=0; y<n; y++)
			for(int x=0; x<m; x++) {
				int t; scanf("%d", &t);
				a[x][y]=t;
			}
		memset(mx, 0, sizeof(mx));
		memset(my, 0, sizeof(my));
		for(int y=0; y<n; y++) {
			for(int x=0; x<m; x++)
				if (a[x][y]>my[y])
					my[y]=a[x][y];
		}
		for(int x=0; x<m; x++) {
			for(int y=0; y<n; y++)
				if (a[x][y]>mx[x])
					mx[x]=a[x][y];
		}
		for(int y=0; y<n; y++) {
			for(int x=0; x<m; x++)
				if (b[x][y]>my[y])
					b[x][y]=my[y];
		}
		for(int x=0; x<m; x++) {
			for(int y=0; y<n; y++)
				if (b[x][y]>mx[x])
					b[x][y]=mx[x];
		}
		//print(25,25);
		if (memcmp(a, b, sizeof(a))==0)
			printf("Case #%d: YES\n", index+1);
		else
			printf("Case #%d: NO\n", index+1);
	}
	//system("pause");
	return 0;
}