#include <cstdio>

#define MAXN  3
#define MAXM  100

#define min(a,b) ((a<b)?a:b)
#define max(a,b) ((a>b)?a:b)

typedef unsigned long long ull;

ull quantBox[MAXN];
int typeBox[MAXN];
ull quantToy[MAXM];
int typeToy[MAXM];
int n;
int m;

ull solve(int i, int z)
{
	ull ans = 0ULL;
	for (;i < n;i++)
	{
		if (z == m)
			break;
		if (typeToy[i] == typeBox[z])
		{
			ans += min(quantToy[i], quantBox[z]);
			if (quantToy[i] > quantBox[z])
			{
				quantToy[i] -= quantBox[z];
				i--;
				z++;
			} else if (quantToy[i] == quantBox[z])
				z++;
			else
				quantBox[z] -= quantToy[i];
			continue;
		}
		int dist1, dist2, j1, j2; dist1 = dist2 = 0;
		for (j1 = 0;j1 < m-z;dist1+=quantBox[(j1++)+z])
			if (typeBox[j1+z] == typeToy[i])
				break;
		for (j2 = 0;j2 < n-i;dist2+=quantToy[(j2++)+i])
			if (typeToy[j2+i] == typeBox[z])
				break;
		if (dist1 < dist2 || i+j2 >= n)
		{
			z += j1;
			i--; // do this one again
			continue;
		}
		if (dist2 < dist1 || z+j1 >= m)
		{
			i += j2;
			i--; // do this one again
			continue;
		}
		ans += max(solve(i, z+j1), solve(i+j2, z));
	}
	return ans;
}

int main()
{
	FILE* in = fopen("input3.txt", "r");
#ifndef DEBUG
	freopen("output3.txt", "w", stdout);
#endif
	int t;
	fscanf(in, "%d", &t);
	for (int _ = 1;_ <= t;_++)
	{
		fscanf(in, "%d %d", &n, &m);
		for (int i = 0;i < n;i++)
			fscanf(in, "%llu %d", quantBox+i, typeBox+i);
		for (int i = 0;i < m;i++)
			fscanf(in, "%llu %d", quantToy+i, typeToy+i);
		printf("Case #%d: %llu\n", _, solve(0, 0));
	}
	fclose(in);
	return 0;
}

