#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#define maxn 100
using namespace std;
int CAS;
int n,m;
struct st
{
    long long num,type;
}a1[maxn+10],a2[maxn+10];
long long b1[maxn+10],b2[maxn+10];
int arr[5];

long long minx(long long a,long long b)
{
    return a < b ? a : b;
}
long long maxx(long long a,long long b)
{
    return a > b ? a : b;
}
long long calc()
{
    long long cnt = 0;
    for(int i = 0;i < n;i++)
        b1[i] = a1[i].num;
    for(int i = 0;i < m;i++)
        b2[i] = a2[i].num;
    int pos1 = 0,pos2 = 0;
    while(pos1 < n && pos2 < m)
    {
        if(arr[pos1] <= pos2 || b1[pos1] == 0)
        {
            pos1++;
            continue;
        }
        if(b2[pos2] == 0)
        {
            pos2++;
            continue;
        }
        if(a1[pos1].type == a2[pos2].type)
        {
            long long tmp = minx(b1[pos1],b2[pos2]);
            b1[pos1] -= tmp;b2[pos2] -= tmp;
            continue;
        }
        else pos2++;
    }
    for(int i = 0;i < n;i++) cnt += a1[i].num - b1[i];
    return cnt;
}
int main()
{
    freopen("C-small-attempt1.in","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d",&CAS);
    for(int cas = 1;cas <= CAS;cas++)
    {
        scanf("%d%d",&n,&m);
        for(int i = 0;i < n;i++)
            scanf("%I64d%I64d",&a1[i].num,&a1[i].type);
        for(int i = 0;i < m;i++)
            scanf("%I64d%I64d",&a2[i].num,&a2[i].type);
        arr[0]  =  5;arr[1] = 0;arr[2] = 5;
        //printf("adadsf\n");
       // cout << "calc:" << calc() << endl;
       // system("pause");
        long long ans = 0;
        for(int i = 0;i <= m;i++)
            for(int j = 0;j <= m;j++)
                for(int k = 0;k <= m;k++)
                {
                    arr[0] = i;arr[1] = j;arr[2] = k;
                    ans = maxx(ans,calc());
                    //system("pause");
                }
        printf("Case #%d: ",cas);
        printf("%I64d\n",ans);
    }
    fclose(stdin);
    fclose(stdout);
}
