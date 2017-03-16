//Author: Tusshar Singh
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<algorithm>

using namespace std;

#define mod 1000000007
#define inf 2147483647
#define ninf -2147483648
#define FOR(i,a,b) for(i=a;i<b;i++)
#define s(a) scanf("%d",&a)
#define lls(a) scanf("%lld",&a)
#define ss(a) scanf("%s",a)
#define p(a) printf("%d",a)
#define llp(a) printf("%lld",a)
#define sp(a) printf("%s",a)
#define cp(a) printf("%c",a)
#define nline printf("\n")
#define space printf(" ")
#define ll long long

int main() 
{
    int i,j,k,t;
    s(t);
    FOR(k,1,t+1)
    {
        int state=-1;
        string tic[4];
        FOR(i,0,4)
        {
            cin>>tic[i];
        }
        for(i=0;i<4;i++)
        {
            int countt=0,countx=0,counto=0;
            for(j=0;j<4;j++)
            {
                if(tic[i][j]=='X')
                countx++;
                if(tic[i][j]=='O')
                counto++;
                if(tic[i][j]=='T')
                countt++;
            }
            if(countt+counto==4)
            {state=0;break;}
            if(countt+countx==4)
            {state=1;break;}
        }
        for(i=0;i<4;i++)
        {
            int countt=0,countx=0,counto=0;
            for(j=0;j<4;j++)
            {
                if(tic[j][i]=='X')
                countx++;
                if(tic[j][i]=='O')
                counto++;
                if(tic[j][i]=='T')
                countt++;
            }
            if(countt+counto==4)
            {state=0;break;}
            if(countt+countx==4)
            {state=1;break;}
        }
        int countt=0,countx=0,counto=0;
        for(i=0;i<4;i++)
        {
                if(tic[i][i]=='X')
                countx++;
                if(tic[i][i]=='O')
                counto++;
                if(tic[i][i]=='T')
                countt++;
        }
        if(countt+counto==4)
            state=0;
            if(countt+countx==4)
            state=1;
        countt=0,counto=0,countx=0;
        for(i=0;i<4;i++)
        {
                if(tic[i][3-i]=='X')
                countx++;
                if(tic[i][3-i]=='O')
                counto++;
                if(tic[i][3-i]=='T')
                countt++;
        }
        if(countt+counto==4)
            state=0;
            if(countt+countx==4)
            state=1;
        for(i=0;i<4;i++)
            for(j=0;j<4;j++)
                if(tic[i][j]=='.'&&state==-1)
            {state=2;break;}
        if(state==-1)
        printf("Case #%d: Draw\n",k);
        if(state==0)
        printf("Case #%d: O won\n",k);
        if(state==1)
        printf("Case #%d: X won\n",k);
        if(state==2)
        printf("Case #%d: Game has not completed\n",k);
    }
    return 0;
}