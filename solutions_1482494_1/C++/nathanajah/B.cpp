#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
using namespace std;

int t,aaaa;
int n,i,j;
int a[2000],b[2000];
int cmplt[2000];
int maxi,nummax;
int level;

int main()
{
    scanf("%d",&t);
    for (aaaa=0;aaaa<t;++aaaa)
    {
        level=0;
        scanf("%d",&n);
        for (i=0;i<n;++i)
            scanf("%d %d",&a[i],&b[i]);
        memset(cmplt,0,sizeof(cmplt));
        i=0;
        while (i<2*n)
        {
            maxi=-1;
            for (j=0;j<n;++j)
            {
                if (cmplt[j]==1 && b[j]<=i)
                {
                    maxi=2000000000;
                    nummax=j;
                }
                if (cmplt[j]==0 && b[j]<=i)
                {
                    maxi=2000000000;
                    nummax=j;
                }
                if (cmplt[j]==0 && a[j]<=i && b[j]>maxi)
                {
                    maxi=b[j];
                    nummax=j;
                }
            }
            if (maxi==-1)
                break;
            if (cmplt[nummax]==1 && b[nummax]<=i)
            {
                ++level;
                cmplt[nummax]=2;
                ++i;
            }
            else if (cmplt[nummax]==0 && b[nummax]<=i)
            {
                ++level;
                cmplt[nummax]=2;
                i+=2;
            }
            else if (cmplt[nummax]==0 && a[nummax]<=i)
            {
                ++level;
                cmplt[nummax]=1;
                ++i;
            }
        }
        printf("Case #%d: ",aaaa+1);
        if (i==2*n)
            printf("%d\n",level);
        else
            printf("Too Bad\n");
    }
}
