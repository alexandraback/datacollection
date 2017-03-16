#include <stdio.h>
#include <string.h>
#include <algorithm>

int n;
char ar[3005];
bool check[3005];
int ans[3005];
int p;

int find(char k)
{
	int cnt = 0;
	for(int i=1;i<=strlen(ar+1);i++)
	{
		if(ar[i]==k&&check[i]==false)cnt++;
	}
	return cnt;
}

void erase(char k)
{
	for(int i=1;i<=strlen(ar+1);i++)
	{
		if(ar[i]==k&&check[i]==false)
		{
			check[i]=true;
			return;
		}
	}
}

void solve()
{
	p=0;
	int zero = find('Z');
	for(int i=1;i<=zero;i++)
	{
		ans[p++]=0;
		erase('Z');
		erase('E');
		erase('R');
		erase('O');
	}
	int two = find('W');
	for(int i=1;i<=two;i++)
	{
		ans[p++]=2;
		erase('T');
		erase('W');
		erase('O');
	}
	int eight = find('G');
	for(int i=1;i<=eight;i++)
	{
		ans[p++]=8;
		erase('E');
		erase('I');
		erase('G');
		erase('H');
		erase('T');
	}
	int four = find('U');
	for(int i=1;i<=four;i++)
	{
		ans[p++]=4;
		erase('F');
		erase('O');
		erase('U');
		erase('R');
	}
	int six = find('X');
	for(int i=1;i<=six;i++)
	{
		ans[p++]=6;
		erase('S');
		erase('I');
		erase('X');
	}
	int five = find('F');
	for(int i=1;i<=five;i++)
	{
		ans[p++]=5;
		erase('F');
		erase('I');
		erase('V');
		erase('E');
	}
	int seven = find('V');
	for(int i=1;i<=seven;i++)
	{
		ans[p++]=7;
		erase('S');
		erase('E');
		erase('V');
		erase('E');
		erase('N');
	}
	int one = find('O');
	for(int i=1;i<=one;i++)
	{
		ans[p++]=1;
		erase('O');
		erase('N');
		erase('E');
	}
	int three = find('T');
	for(int i=1;i<=three;i++)
	{
		ans[p++]=3;
		erase('T');
		erase('H');
		erase('R');
		erase('E');
		erase('E');
	}
	int nine = find('I');
	for(int i=1;i<=nine;i++)
	{
		ans[p++]=9;
		erase('N');
		erase('I');
		erase('N');
		erase('E');
	}
	for(int i=1;i<=strlen(ar+1);i++)
	{
		check[i]=false;
	}
	std::sort(ans, ans+p);
	for(int i=0;i<p;i++)printf("%d", ans[i]);
	return;
}

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("A_result.txt", "w", stdout);
	scanf("%d", &n);
	for(int i=1;i<=n;i++)
	{
		scanf("\n%s", ar+1);
		printf("Case #%d: ", i);
		solve();
		puts("");
	}
	
	return 0;
}
