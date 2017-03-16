#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<iostream>
#include<queue>
#include<stack>
using namespace std;

const int N=60;
int r,c,m,sp;
int col[N];

bool check(int row,int pre,int now)
{
    if(sp==1)
    {
        col[0] = 1;
        return true;
    }
    if(row>=r)
    {
        return now==sp;
    }
    if(now>sp) return false;
    if(now==sp) return true;
    if(row==1)
    {
        col[row] = pre;
        return check(row+1,pre,now+pre);
    }
    for(int i=pre; i>=2; i--)
    {
        col[row] = i;
        if(check(row+1,i,now+i))
            return true;
        col[row] = 0;
    }
    return false;
}

int main()
{
	freopen("C-small-attempt4.in","r",stdin);
	freopen("C-small-attempt4.out","w",stdout);
	
	int t;
	scanf("%d",&t);
	for(int cnt=1;cnt<=t;cnt++)
	{
	    
	    scanf("%d%d%d",&r,&c,&m);
	    printf("Case #%d:\n",cnt);
	    if(m==r*c)
        {
            printf("Impossible\n");
            continue;
        }
        if(r==1 || c==1)
        {
            int ls = r*c-m;
            for(int i=0; i<r; i++)
            {
                for(int j=0; j<c; j++)
                {
                    if(ls>0)
                    {
                        if(i==0 && j==0) printf("c");
                        else printf(".");
                        ls--;
                    }
                    else printf("*");
                }
                printf("\n");
            }
            continue;
        }
        sp = r*c-m;
        memset(col,0,sizeof(col));
        if(check(0,min(sp/2,c),0))
        {
            for(int i=0; i<r; i++)
            {
                for(int j=0; j<c; j++)
                {
                    if(i==0 && j==0) printf("c");
                    else if(j<col[i]) printf(".");
                    else printf("*");
                }
                printf("\n");
            }
        }
        else
            printf("Impossible\n");
	} 
} 
