#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<cmath>
#include<string>
#include<iostream>
#include<queue>
#include<stack>
#include<map>
#include<algorithm>
#include<utility>
#include<sstream>
using namespace std;

#define pi (2*acos(0.0))
#define inf 1<<30
#define maxi(a,b) ((a>b)?a:b)
#define mini(a,b) ((a>b)?b:a)
#define pb(a) push_back(a)
#define sz 1100
int fa_pr[sz];
bool ispal(int num)
{
     int arr[sz];
     int i,last=0;
     while(num!=0)
     {
         arr[last++]=num%10;
         num/=10;
     }
     int loop=last/2;
     for(i=0;i<=loop;i++)
     {
         if(arr[i]!=arr[last-1])
            return false;
        last--;
     }
     return true;
}
void precal()
{
    int i,j;

    for(i=1;i<=35;i++)
    {
        int sq=i*i;
        if(ispal(i) && ispal(sq))
            fa_pr[sq]=1;
    }

    for(i=1;i<=1000;i++)
        fa_pr[i]+=fa_pr[i-1];
}

int main()
{
    int i,j,k,num,t,test,a,b;


    freopen("C-small.in","r",stdin);
    freopen("C-small.out","w",stdout);

    precal();

    scanf("%d",&test);

    for(t=1;t<=test;t++)
    {
        scanf("%d%d",&a,&b);

        printf("Case #%d: %d\n",t,fa_pr[b]-fa_pr[a-1]);

    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}
