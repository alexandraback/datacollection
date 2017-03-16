#include<bits/stdc++.h>
using namespace std;
map<char,int> Map;
char a[100],b[100];
void debug()
{
	
}
typedef long long LL;
LL ans,ansx,ansy;
char ans1[20],ans2[20];
inline LL abs(LL x,LL y)
{
	if (y > x) return y - x;
	else return x-y;
}
int calc(LL x)
{
	int ret = 0;
	do
	{
		ret++;
		x/=10;
	}
	while (x > 0);
	return ret;
}
void dfs(int p,int n,int state,LL x,LL y)//state -1:x<y 0 x=y 1:x>y
{
	if (p == n)
	{
		if (abs(x,y) < ans || abs(x,y) == ans && x < ansx || abs(x,y) == ans && x == ansx && y < ansy)
		{
			ansx = x;
			ansy = y;
			ans = abs(x,y);
		}
		return;
	}
	LL tx = x,ty = y;
	if (state == 1)//x > y
	{
		for (int i=p;i<n;i++)
		{
			x = x * 10;
			if (a[i] != '?') x += a[i] - '0'; 
		}
		for (int i=p;i<n;i++)
		{
			y = y * 10;
			if (b[i] != '?') y += b[i] - '0'; 
			else y+=9;
		}
		if (abs(x,y) < ans || abs(x,y) == ans && x < ansx || abs(x,y) == ans && x == ansx && y < ansy)
		{
			ansx = x;
			ansy = y;
			ans = abs(x,y);
		}
		return;
	}
	if (state == -1)//x < y
	{
		for (int i=p;i<n;i++)
		{
			x = x * 10;
			if (a[i] != '?') x += a[i] - '0'; 
			else x+=9;
		}
		for (int i=p;i<n;i++)
		{
			y = y * 10;
			if (b[i] != '?') y += b[i] - '0'; 
		}
		if (abs(x,y) < ans || abs(x,y) == ans && x < ansx || abs(x,y) == ans && x == ansx && y < ansy)
		{
			ansx = x;
			ansy = y;
			ans = abs(x,y);
		}
		return;
	}
	if (state == 0)
	{
		if (a[p]=='?' && b[p]=='?')
		{
			x = tx * 10;
			y = ty * 10; dfs(p+1,n,0,x,y);
			y++; dfs(p+1,n,-1,x,y);
			x++; y--; dfs(p+1,n,1,x,y);
		}
		else if (a[p]!='?' && b[p]=='?')
		{
			x = tx * 10 + a[p] - '0';
			if (a[p]-'0'>0)
			{
				y = ty * 10 + a[p] - '0' - 1;
				dfs(p+1,n,1,x,y);
			}
			if (a[p]-'0'<9)
			{
				y = ty * 10 + a[p] - '0' + 1;
				dfs(p+1,n,-1,x,y);
			}
			y = ty * 10 + a[p] - '0';
			dfs(p+1,n,0,x,y);
		}
		else if (a[p]=='?' && b[p]!='?')
		{
			y = ty * 10 + b[p] - '0';
			if (b[p]-'0'>0)
			{
				x = tx * 10 + b[p] - '0' - 1;
				dfs(p+1,n,-1,x,y);
			}
			if (b[p]-'0'<9)
			{
				x = tx * 10 + b[p] - '0' + 1;
				dfs(p+1,n,1,x,y);
			}
			x = tx * 10 + b[p] - '0';
			dfs(p+1,n,0,x,y);
		}
		else
		{
			x = tx * 10 + a[p] - '0';
			y = ty * 10 + b[p] - '0'; 
			if (x == y) dfs(p+1,n,0,x,y);
			else if (x<y) dfs(p+1,n,-1,x,y);
			else dfs(p+1,n,1,x,y);
		}
	}
	
}

int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	int T,test = 0;
	scanf("%d\n",&T);
	while (T--)
	{
		scanf("%s %s\n",a,b);
		ansx = 1e18 + 1;
		ansy = 1e18+1;
		ans = 1e18 + 1;
		dfs(0,strlen(a),0,0,0);
		printf("Case #%d: ",++test);
		for (int i=0;i<strlen(a) - calc(ansx);i++) printf("0"); printf("%lld ",ansx);
		for (int i=0;i<strlen(a) - calc(ansy);i++) printf("0"); printf("%lld\n",ansy);
	}
}
