#include <stdio.h>
#include <string.h>

using namespace std;

char m[15][105];

int v[15];
int pos;
int used[15];
int mk[35];

bool check(int n)
{
	for(int i=0; i<35; i++)
		mk[i] = 0;
	char last = '0';
	for(int i=0; i<n; i++)
	{
		int ln = strlen(m[v[i]]);
		for(int j=0; j<ln; j++)
		{
			char c = m[v[i]][j];
			if(last == '0')
			{
				last = c;
				mk[c-'a'] = 1;
				continue;
			}
			
			if(c != last && mk[c-'a'])
				return false;
			
			last = c;
			mk[c-'a'] = 1;
		}
	}
	return true;
}

int solve(int n, int k)
{
	int ans=0;
	
	if(k==n)
	{
		if(check(n))
			return 1;
		else
			return 0;
	}
	
	for(int i=0; i<n; i++)
	{
		if(!used[i])
		{
			v[pos++] = i;
			used[i] = 1;
			ans += solve(n, k+1);
			pos--;
			used[i]=0;
		}
	}
	
	return ans;
}

bool f(int n)
{
	for(int i=0; i<n; i++)
	{
		int ln = strlen(m[i]);
		char a = m[i][0];
		char b = m[i][ln-1];
		int x=0, y=ln-1;
		while(x < ln && m[i][x] == a) x++;
		while(y >= 0 && m[i][y] == b) y--;
		if(x > y)
			continue;
		for(int j=x; j <= y; j++)
		{
			for(int l=0; l<n; l++)
			{
				if(l == i)
					continue;
				int ln2 = strlen(m[i]);
				for(int o=0; o<ln2; o++)
				{
					if(m[l][o] == m[i][j])
						return false;
				}
			}
		}
	}
	
	for(int i=0; i<n; i++)
	{
		int ln = strlen(m[i]);
		char a = m[i][0];
		char b = m[i][ln-1];
		m[i][1] = b;
		m[i][2] = '\0';
	}
	return true;
}

int main()
{
	freopen("B-small-attempt1.in", "r", stdin);
	freopen("B-small-attempt1.out", "w", stdout);
	
	int nt, t=1;
	scanf(" %d", &nt);
	
	while(nt--)
	{
		pos=0;
		for(int i=0; i<15; i++)
			used[i] = 0;
		
		int n;
		scanf(" %d", &n);
		
		for(int i=0; i<n; i++)
			scanf(" %s", m[i]);
		
		bool ts = f(n);
		if(!ts)
		{
			printf("Case #%d: 0\n", t++);
			continue;
		}
		int ans = solve(n, 0);
		printf("Case #%d: %d\n", t++, ans);
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
