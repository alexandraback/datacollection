#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#define MAXN 1011
#define MAX_TIME 1000000

using namespace std;

int n;
int minv;
struct DataStruct
{
    int a;
    int b;
	int v;
} dat[MAXN];


int cmp(const void *x,const void *y)
{
	DataStruct *a =(DataStruct *)x;
	DataStruct *b =(DataStruct *)y;
    if(a->a!=b->a) return a->a>b->a;
    else return a->b<b->b;
}

void solve()
{
    minv = 0;

    qsort(dat+1,n,sizeof(DataStruct),cmp);
    for(int i=1; i<=n; i++)
    {
		dat[i].v=0;
        //printf("%d %d\n",dat[i].a,dat[i].b);
    }
	
	int stars = 0;
	for(int i=0;i<=n*4;i++)
	{
		int flag=0;
		if(stars>=2*n) break;
		for(int j=1;j<=n;j++)
		{
			if(stars >= dat[j].b && dat[j].v == 0)
			{
				//printf("get %d one\n",j);
				dat[j].v = 2;
				stars+=2;
				minv+=1;
				flag = 1;
			}
		}
		if(flag==1) continue;
		for(int j=1;j<=n;j++)
		{
			if(stars >= dat[j].b && dat[j].v == 1)
			{
				//printf("get %d 2/2\n",j);
				dat[j].v = 2;
				stars+=1;
				minv+=1;
				break;
			}
			else if(stars >= dat[j].a && dat[j].v == 0)
			{
				//printf("get %d 1/2\n",j);
				dat[j].v = 1;
				stars+=1;
				minv+=1;
				break;
			}
		}
	}

    if(stars>=2*n)
        printf("%d\n",minv);
    else
        printf("Too Bad\n");
}

int main()
{
    int casen;

    scanf("%d",&casen);
    for(int i=1; i<=casen; i++)
    {
        scanf("%d",&n);
        for(int j=1; j<=n; j++)
        {
            scanf("%d%d",&dat[j].a,&dat[j].b);
        }
        printf("Case #%d: ",i);
        solve();
    }

    return 0;
}
