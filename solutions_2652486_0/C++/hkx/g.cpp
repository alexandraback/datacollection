#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <ctime>
#include <stdio.h>
#include <memory.h>
#include <windows.h>
using namespace std;
int R,N,M,K;
int product[20];
int A[10];
bool check(int i,int j,int k)
{
    int t;
    for(t=1;t<=K;t++)
    {
        int X=product[t];
        if(X%i==0) X/=i;
        if(X%j==0) X/=j;
        if(X%k==0) X/=k;
        if(X!=1) return false;
    }
    return true;
}
int main()
{
    freopen("C.in","r",stdin);freopen("out.txt","w",stdout);
    int T,cas=0;
    cin>>T;
    while(T--)
    {
        cas++;
        printf("Case #%d:\n",cas);
        cin>>R>>N>>M>>K;
        int i,j,k;
        int s1,s2,s3;
        while(R--)
        {
            for(i=1;i<=K;i++) {cin>>product[i];}

            for(i=2;i<=M;i++)
            {
                for(j=2;j<=M;j++)
                {
                    for(k=2;k<=M;k++)
                    {
                        if(check(i,j,k)){s1=i,s2=j;s3=k;i=M+1;j=M+1;break;}
                    }
                }
            }
            cout<<s1<<s2<<s3<<endl;
        }
    }
    return 0;
}
