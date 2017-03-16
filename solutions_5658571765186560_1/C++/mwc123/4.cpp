#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<stack>
#define MAXN 100000
#define LL long long
#define pb push_back
#define mp make_pair
#define X first
#define Y second
using namespace std;
int n,m;
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("4in.txt", "r", stdin);
        freopen("4out.txt", "w", stdout);
    #endif
    int T,t,x,r,c;
    scanf("%d",&T);
    for(t=1; t<=T; t++)
    {
        scanf("%d%d%d",&x,&r,&c);
        printf("Case #%d: ",t);
        if(x>=7)
        {
            puts("RICHARD");
            continue;
        }
        if(r*c%x==0)
        {
            if(x<=2)
            {
                puts("GABRIEL");
                continue;
            }
            if(r>c)swap(r,c);
            if(c>=x&&r>=(x+1)/2)
            {
                if(x==3){puts("GABRIEL");continue;}
                if(r>(x+1)/2)
                {
                    puts("GABRIEL");
                    continue;
                }
                else
                {
                    if(x==4||x==6){puts("RICHARD");continue;}
                    else if(x==5)
                    {
                        if(c>=10){puts("GABRIEL");continue;}
                        else {puts("RICHARD");continue;}
                    }
                }
            }
            else puts("RICHARD");
        }
        else puts("RICHARD");
    }
    return 0;
}
