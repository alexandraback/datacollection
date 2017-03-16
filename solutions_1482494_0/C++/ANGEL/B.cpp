#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>

int T,id;
int i,j,k;
int n,a[1010][3],b[1010][3],flag[1010];
int ans,top,now,ok;

int cmp(const void *a,const void *b)
{
	if (*(int *)a != *(int *)b)
	return *(int *)a- *(int *)b;
	return *((int *)b+1)- *((int *)a+1);
}

int cmp1(const void *a,const void *b)
{
	if (*(int *)a != *(int *)b)
	return *(int *)a- *(int *)b;
	return *((int *)a+1)- *((int *)b+1);
}

int main()
{
	freopen("B-small-attempt2.in","r",stdin);
	freopen("B-small-attempt2.out","w",stdout);
	scanf("%d",&T);
	for (id=1;id<=T;id++)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(flag,0,sizeof(flag));
		scanf("%d",&n);
		for (i=0;i<n;i++)
		{
			scanf("%d%d",&a[i][1],&a[i][0]);
			b[i][0]=a[i][1];b[i][1]=a[i][0];
			a[i][2]=b[i][2]=i;
		}
		qsort(a,n,sizeof(a[0]),cmp1);
		qsort(b,n,sizeof(b[0]),cmp);
		ans=0;
		top=0;
		now=0;
		ok=1;
		for (i=0;i<n;i++)
		{
			if (a[i][0]<=now)
			{
				ans++;
				now+=2-flag[a[i][2]];
				flag[a[i][2]]=2;
			}
			else
			{
				for(top=n-1 ;top>=0;top--)
				{
					if (flag[a[top][2]]>0) continue;
					else if (a[top][1]<=now)
					{
						flag[a[top][2]]=1;
						ans++;
						now++;
						top++;
						i--;
						break;
					}
				}
				if (top<0)ok=0;
				if (ok==0)break;
			}
		}
		printf("Case #%d: ",id);
		if (ok==0)printf("Too Bad\n");
		else printf("%d\n",ans);
	}
	return 0;
}