#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int N=10012;

int		L,X,n,tmp,tmp2;
char	s[N];
int		a[N],suf[N];
bool	flag;

const int f[4][4]={{1,2,3,4},{2,-1,4,-3},{3,-4,-1,2},{4,3,-2,-1}};

int calc(int x,int y)
{
	int t=1;
	if (x<0)
		t*=-1,x*=-1;
	if (y<0)
		t*=-1,y*=-1;
	return t*f[x-1][y-1];
}


int main()
{
	freopen("C-small-attempt0.in","r",stdin);
	freopen("C.out","w",stdout);
	
	int test,tid=0;

	for (scanf("%d",&test);test--;)
	{
		scanf("%d%d",&L,&X);
		scanf("%s",s);
		for (int i=L;i<L*X;i++)
			s[i]=s[i-L];

		n=X*L;
		for (int i=0;i<n;i++)
			a[i]=s[i]-'i'+2;
		suf[n-1]=a[n-1];
		for (int i=n-2;i>=0;i--)
			suf[i]=calc(a[i],suf[i+1]);
		flag=0;
		tmp=1;
		for (int i=0;i<n && !flag;i++)
		{
			tmp=calc(tmp,a[i]);
			if (tmp==2)
			{
				tmp2=1;
				for (int j=i+1;j+1<n && !flag;j++)
				{
					tmp2=calc(tmp2,a[j]);
					if (tmp2==3 && suf[j+1]==4)
						flag=1;
				}
			}
		}

		printf("Case #%d: ",++tid);
		if (!flag)
			puts("NO");
		else
			puts("YES");

	}
}