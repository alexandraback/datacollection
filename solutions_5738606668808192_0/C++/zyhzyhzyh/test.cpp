#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<cmath>
#include<iostream>
#define fi first
#define se second
#define MP make_pair
#define PB push_back
#define PII pair<int,int>
typedef long long LL;
using namespace std;
int T,tot,n,m;
LL a[10001],one=1;
template<class T>
void read(T&x)
{
	char ch=getchar();int mk=1;x=0;for(;ch!='-'&&(ch<'0'||ch>'9');ch=getchar());
	if (ch=='-') mk=-1,ch=getchar();for(;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-48;x*=mk;
}
int get(LL x,int j){return (x>>j)&1;}
inline void print(LL x,LL y)
{
	//100011 5 13 147 31 43 1121 73 77 629
	for(int i=0;i<n;i++)
		if (i&1)
		{
			printf("%d",get(x,n/2-i/2-1));
		}
		else
		{
			printf("%d",get(y,i/2));
		}
	printf(" 3 2 3 3 7 3 3 2 3\n");
}
void dfs(int step,long long st,int num)
{
	if (num>3) return ;
	if (step==n/2)
	{
		if (num==3) a[++tot]=st;
		return;
	}
	dfs(step+1,st,num);
	dfs(step+1,st|(one<<step),num+1);
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	read(T);
	for(int _=1;_<=T;_++)
	{
		printf("Case #%d:\n",_);
		read(n);read(m);
		dfs(1,1,1);
		for(int i=1;i<=tot;i++)
			for(int j=1;j<=tot;j++)
			{
				if (m==0) return 0;
				m--;
				print(a[i],a[j]);
			}
	}
}

