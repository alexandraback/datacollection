#include <stdio.h>
#include <string.h>


int tab[30][30];
int tt[30][30];
int vis[30];
int fact[1010];
int idx[30];
int MOD = 1000000007;
char ss[110][110];
int ff ;

int find(int x){
	if (idx[x] == x) return x;
	return idx[x] = find(idx[x]);
}


void merge(int a, int b){
	a = find(a), b = find(b);
	if (a != b) idx[a] = b;
	else ff = 0;
}


int gao()
{
	int i, j, cc ;
	int ans;
	memset (vis, 0, sizeof(vis));
	for (i = 0; i < 26; i++)
		for (j = 0; j < 26; j++)
		{
			tt[i][j] = tab[i][j];
			if (tt[i][j]) vis[i] = 1, vis[j] = 1;
		}

	for (i = 0; i < 26; i++) 
	{
		cc = 0;
		for (j = 0; j < 26; j++)
			if (i != j)cc+=tt[i][j];
		if (cc > 1) return 0;
	}
	for (j = 0; j < 26; j++)
	{
		cc = 0;
		for (i = 0; i < 26; i++)
			if (i != j) cc+= tt[i][j];	
		if (cc > 1) return 0;
	}
	
	for (i = 0; i < 26; i++)idx[i] = i;
	ff = 1;
	for (i = 0; i < 26; i++)for (j = 0; j < 26; j++)
		if (i != j && tt[i][j]) merge(i, j);
	if (ff == 0) return 0;
	cc = 0;
	for (i = 0; i < 26; i++) if (vis[i])
	{
		if (idx[i] == i) cc++;
	}
	ans = fact[cc];
	for (i = 0; i < 26; i++)
		ans = (1LL * ans * fact[tt[i][i]]) % MOD;
	return ans;
}


int cnt[30];

int invalid(char ss[110][110], int n)
{
	int i, j, k, l;
	memset (vis, 0, sizeof(vis));
	
	for (i = 0; i < n; i++)
	{
		memset (cnt, 0, sizeof(cnt));
		for (j = 0; ss[i][j]; j++)
			if (j == 0 || ss[i][j] != ss[i][j-1])
				cnt[ss[i][j]-'a']++;
		for (j = 0; j < 26; j++) if (cnt[j] > 1) return 0;
	}
	
	memset (cnt, 0, sizeof(cnt));
	for (i = 0; i < n; i++)
	{
		for (j = 1; j < strlen (ss[i]); j++)
			if (ss[i][j] != ss[i][j-1]) break ;
		for (k = strlen(ss[i])-2; k >= 0; k--)
			if (ss[i][k] != ss[i][k+1]) break ;
		if (j > k) continue;
		for (l = j ; l <= k; l++)
			vis[ss[i][l]-'a'] = 1;
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; ss[i][j]; j++)
		{
			if (j == 0 || ss[i][j] != ss[i][j-1])
				cnt[ss[i][j]-'a']++;
		}
	}
	for (i = 0; i < 26; i++) if (vis[i] && cnt[i] > 1) return 0;
	return 1;
}

char str[110];

int main ()
{
	int T, cas ;
	int a, b, i, n;
	int ans;
	freopen ("B-large.in", "r", stdin);
	freopen ("blargetest.txt", "w", stdout);
	scanf ("%d", &T);
	fact[0] = 1;
	for (i = 1; i <= 1000; i++)
		fact[i] = (1LL * fact[i-1] * i) % MOD;
		
	for (cas = 1; cas <= T; cas++)
	{
		scanf ("%d", &n);
		memset (tab, 0, sizeof (tab));
		ans = 1;
		for (i = 0; i < n; i++)
		{
			scanf ("%s", str);
			strcpy (ss[i], str);
			//if (!invalid(str)) ans = 0;
			a = str[0]-'a', b = str[strlen(str)-1]-'a';
			tab[a][b] ++;
		}
		if (!invalid(ss, n)) ans = 0;
		printf ("Case #%d: ", cas);
		if (ans != 0) ans = gao();
		printf ("%d\n", ans);
		
	}
	return 0;
}
