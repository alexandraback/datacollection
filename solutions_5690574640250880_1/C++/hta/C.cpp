#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
inline int get()
{
    int f=0,v=0;char ch;
    while(!isdigit(ch=getchar()))if(ch=='-')break;
    if(ch=='-')f=1;else v=ch-48;
    while(isdigit(ch=getchar()))v=v*10+ch-48;
    if(f==1)return -v;else return v;
}
const int maxn=100;
char a[maxn][maxn];
int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	int T=get();
	for(int t=1;t<=T;t++)
	{
		printf("Case #%d:\n",t);
		bool change=0;
		int n=get(),m=get(),tot=get();
		if(n*m==tot+1)
		{
			for(int i=1;i<=n;i++,puts(""))
				for(int j=1;j<=m;j++)
				{
					if(i==n&&j==m)putchar('c');else putchar('*');
				}
			continue;
		}
		if(n==1)
		{
			for(int i=1;i<=m;i++)
			{
				if(i<=tot)putchar('*');
				else if(i>tot&&i<m)putchar('.');
				else putchar('c');
			}
			puts("");
			continue;
		}
		if(m==1)
		{
			for(int i=1;i<=n;i++)
			{
				if(i<=tot)putchar('*');
				else if(i>tot&&i<n)putchar('.');
				else putchar('c');
				puts("");
			}
			continue;
		}
		if(m<n)swap(n,m),change=1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)a[i][j]='*';
		bool have=0;
		for(int i=2;!have&&i<=n;i++)
			for(int j=2;j<=m;j++)
			{
				//int lim=min(i-2,j-2),cnt=n*m-i*j;
				//if(cnt>tot)continue;
				/*for(int k=0;k<=lim;k++)
				{
					cnt+=k;
					if(cnt<tot)continue;
					if(cnt>tot)break;
					have=1;
					for(int x=n-i+1;x<=n;x++)
						for(int y=m-j+1;y<=m;y++)a[x][y]='.';
					for(int x=n-i+1,p=k;x<=n-i+k;x++,p--)
						for(int y=m-j+1;y<=m-j+p;y++)a[x][y]='*';
					a[n][m]='c';
					if(change)
					{
						for(int y=1;y<=m;y++,puts(""))
							for(int x=1;x<=n;x++)putchar(a[x][y]);
					}else
					{
						for(int x=1;x<=n;x++,puts(""))
							for(int y=1;y<=m;y++)putchar(a[x][y]);
					}
					break;
				}*/
				int cnt=n*m-i*j;
				if(cnt>tot)continue;
				if(cnt+(i-2)*(j-2)<tot)continue;
				for(int x=n-i+1;x<=n;x++)
					for(int y=m-j+1;y<=m;y++)a[x][y]='.';
				int left=tot-cnt;
				for(int x=n-i+1;x<=n-2;x++)
				{
					int k=min(j-2,left);left-=k;
					for(int y=m-j+1;y<=m-j+k;y++)a[x][y]='*';
				}
				a[n][m]='c';
				if(change)
				{
					for(int y=1;y<=m;y++,puts(""))
						for(int x=1;x<=n;x++)putchar(a[x][y]);
				}else
				{
					for(int x=1;x<=n;x++,puts(""))
						for(int y=1;y<=m;y++)putchar(a[x][y]);
				}
				int cc=0;
				for(int x=1;x<=n;x++)
					for(int y=1;y<=m;y++)cc+=(a[x][y]=='*');
				if(cc!=tot){cerr<<"fuck"<<endl;while(1);}
				have=1;
				break;
			}
		if(!have)puts("Impossible"),cerr<<n<<" "<<m<<" "<<tot<<endl;
	}
	return 0;
}
