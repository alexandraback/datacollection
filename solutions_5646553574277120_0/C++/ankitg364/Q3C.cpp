#include<stdio.h>
#include<iostream>

using namespace std;

int arr[40];

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t,c,d,v;
    scanf("%d",&t);
    for(int ci=1;ci<=t;ci++)
    {
        scanf("%d%d%d",&c,&d,&v);
        int arr2[100]={0};
        for(int i = 0; i<d;i++)
        {
            scanf("%d",&arr[i]);
            arr2[arr[i]]=1;
        }
        int ans = 0;
        int j=1;
        while(1)
        {
            int temp;
            temp = (j*(j-1))/2;
            if(temp>=v)
                break;
            else if(v == (temp+1) && arr2[v]==1)
                break;
            if(arr2[j] == 0)
            {
                    arr2[j]=1;
                    ans++;
            }
            j++;
        }
        printf("Case #%d: %d\n",ci,ans);
    }
    return 0;
}
