#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <utility>
#define pi (2*acos(0))
#define ll long long int
#define pii pair<int,int>

using namespace std;

struct ss{
    int x,y;
}aa[1005];

bool mycomp(ss a,ss b)
{
    return (a.y>b.y);
}

int a[1005][2],m[1005][2];

int main()
{
    int i,j,k,t,T,r,l,s,n;

    freopen("B-large(1).in","r",stdin);
    freopen("b1-large.txt","w",stdout);

    scanf("%d",&T);

    for(t=1;t<=T;t++)
    {
        scanf("%d",&n);

        for(i=0;i<n;i++)
        {
            scanf("%d %d",&aa[i].x,&aa[i].y);
        }

        sort(aa,aa+n,mycomp);

        for(i=0;i<n;i++)
        {
            a[i][0]=aa[i].x;
            a[i][1]=aa[i].y;
        }

        for(i=0;i<n;i++) m[i][0]=m[i][1]=1;
        l=s=0;

        while(s<2*n)
        {

            k=0;
            for(i=0;i<n;i++)
            {
                if(m[i][1] && s>=a[i][1])
                {
                    if(m[i][0])
                    {
                        s+=2;
                        l++;
                        m[i][0]=m[i][1]=0;
                    }

                    else
                    {
                        s++;
                        l++;
                        m[i][1]=0;
                    }

                    k=1;
                    break;
                }
            }

            if(k) continue;;


            for(i=0;i<n;i++)
            {
                if(m[i][0] && s>=a[i][0])
                {
                    m[i][0]=0;
                    s++;
                    l++;
                    k=1;
                    break;
                }
            }

            if(!k) break;
        }

        if(s<2*n) printf("Case #%d: Too Bad\n",t);
        else printf("Case #%d: %d\n",t,l);
    }

    return 0;
}



