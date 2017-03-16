#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <iostream>
#include <cstring>

#define pb push_back
#define fs first
#define sc second
#define mp make_pair

using namespace std;

int T,N,M;
int v[101010],ind;
char sir[101010];
int sum[101010];

int is_v(char c)
{
    if(c=='a')
        return 0;
    if(c=='e')
        return 0;
    if(c=='i')
        return 0;
    if(c=='o')
        return 0;
    if(c=='u')
        return 0;
    return 1;
}

void reset()
{
    for(int i=0;i<=101000;++i)
        sir[i]=0;
    for(int i=0;i<=101000;++i)
        sum[i]=0;
}

long long make()
{
long long ret=0;
    for(int i=1;i<=M;++i)
    {
        if(is_v(sir[i]))
        {
            sum[i]++;
        }
        sum[i]+=sum[i-1];
        //printf("%d\n",sum[i]);
    }
    int st=-1;
    for(int i=0;i+N<=M+1;++i)
    {//printf("%d %d %d\n",i,M);
        if(sum[i+N]-sum[i]==N)
        {
         //   printf("%d %d\n",(i-st),(M+1 - (i+N)));
            ret += 1LL*(i-st) * (M+1 - (i+N));
            st = i;
        }
    }

return ret;
}

int main()
{
freopen("a.in","r",stdin);
freopen("a.out","w",stdout);
    scanf("%d",&T);
    while(T--){
    reset();
    ++ind;
    scanf("%s",sir+1);
    scanf("%d\n",&N);
    M=strlen(sir+1);

    printf("Case #%d: %lld\n",ind,make());
    }

return 0;
}
