#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<map>
#include<math.h>
#include<climits>
using namespace std;

double ans, temp, ans1;
int n, x, y, arr1[1100], arr2[1100];

int bs(int st, int en)
{
    if(st==en)
        return st;
    if((en-st)==1)
    {
        if(arr2[en]>n)
            return st;
        else
            return en;
    }
    int mid=st+en;
    mid/=2;
    if(arr2[mid]>n)
        return bs(st, mid);
    else
        return bs(mid, en);
}

int main()
{
    int t;
    scanf("%d",&t);
    arr1[0]=1;
    arr2[0]=1;
    for(int i=1; i<1100; i++)
    {
        arr1[i]=arr1[i-1]+4;
        arr2[i]=arr2[i-1]+arr1[i];
    }
    for(int cas=1; cas<=t; cas++ )
    {
        scanf("%d%d%d",&n, &x ,&y);
        if(x<0)
            x*=-1;
        int num=bs(0, 1099);
        //printf("fdklfdsfd %d\n", num);
        if(n==arr2[num])
        {
            if((x+y)<=(2*num))
                ans=1;
            else
                ans=0;
        }
        else
        {
            n-=arr2[num];
            if((x+y)==(2*num+2))
            {
                ans=0.5;
                ans1=0.5;
                if(y==2*(num+1))
                    ans=0;
                else if((y+1)>n)
                    ans=0;
                else
                {
                    for(int i=1; i<n; i++)
                    {
                        ans1*=0.5;
                        ans+=(0.5)*ans;
                    }
                    for(int i=0; i<y; i++)
                    {
                        ans-=ans1;
                        ans/=2;
                        ans1/=2;
                    }
                }
            }
            else if((x+y)<=(2*num))
                ans=1;
            else
                ans=0;
        }
        printf("Case #%d: %.8lf\n", cas, ans);
    }
    return 0;
}
