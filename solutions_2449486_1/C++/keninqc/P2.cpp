#include <cstdio>

void Open()
{
	freopen ("P2.in", "r", stdin);
	freopen("P2.out", "w", stdout);
}

void Close()
{
	fclose(stdin);
	fclose(stdout);
}

int grass[200][200];

inline int min(int &a, int &b)
{
	return a < b ? a : b;
}

bool Judge(int N, int M)
{
	int fori[200], forj[200];
	for (int i = 0; i < N; i++)
		fori[i] = grass[i][0];
	for (int j = 0; j < M; j++)
		forj[j]=  grass[0][j];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			if (grass[i][j] > fori[i])
				fori[i] = grass[i][j];
			if (grass[i][j] > forj[j])
				forj[j] = grass[i][j];
		}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			int val = min(fori[i], forj[j]);
			if (val != grass[i][j]) return false;
		}
	return true;
}

void Run()
{
	int T, N, M;
	scanf ("%d", &T);
	for (int k = 0; k < T; k++)
	{
		scanf ("%d %d", &N, &M);
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				scanf ("%d", &grass[i][j]);
		if (Judge(N, M))
			printf ("Case \#%d: YES\n", k+1);
		else
			printf ("Case \#%d: NO\n", k+1);
	}
}

int main()
{
	Open();
	Run();
	Close();
	return 0;
}