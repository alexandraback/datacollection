#include<cstdio>
#include<cmath>
#include<stdlib.h>
#include<map>
#include<set>
#include<time.h>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define eps 1e-8
#define SIZE 100005
bool notprime[SIZE];
int prime[SIZE],prinum;
void getprime()
{
    for(int i=2; i<SIZE; i++)
    {
        if(notprime[i])
            continue;
        prime[prinum++]=i;
        for(int j=2*i; j<SIZE; j+=i)
            notprime[i]=1;
    }
}
int N,J;
int main()
{
//    freopen("C-small-attempt3.in","r",stdin);
//    freopen("C-small-attempt3.out","w",stdout);
    freopen("C-large.in","r",stdin);
    freopen("C-large.out","w",stdout);
    int T;
    getprime();
    scanf("%d",&T);
    for(int cas=1; cas<=T; cas++)
    {
        scanf("%d%d",&N,&J);
        printf("Case #%d:\n",cas);
        for(int i=1; i<(1<<16); i++)
        {
//            printf("%d\n",i);
            if((i&(1<<0))==0)
                continue;
            if((i&(1<<15))==0)
                continue;
            vector<int>vec;
            for(int k=2; k<=10; k++)
            {
                long long t=0;
                for(int j=15; j>=0; j--)
                {
                    t=t*k;
                    if(i&(1<<j))
                        t++;
                }
//                printf("%I64d ",t);
                for(int j=0; j<prinum; j++)
                {
                    if(t<=prime[j])
                        break;
                    if(t%prime[j]==0)
                    {
                        vec.push_back(prime[j]);
                        break;
                    }
                }
            }
//            printf("\n");
//            if(J==48)
//                break;
//            for(int j=0; j<16; j++)
//            {
//                if(i&(1<<j))
//                    printf("1");
//                else
//                    printf("0");
//            }
//            printf("\n");
            if(vec.size()==9)
            {
                for(int j=15; j>=0; j--)
                {
                    if(i&(1<<j))
                        printf("1");
                    else
                        printf("0");
                }
                for(int j=15; j>=0; j--)
                {
                    if(i&(1<<j))
                        printf("1");
                    else
                        printf("0");
                }
                for(int i=0; i<9; i++)
                    printf(" %d",vec[i]);
                printf("\n");
                J--;
            }
            if(J==0)
                break;
        }
    }
    return 0;
}
