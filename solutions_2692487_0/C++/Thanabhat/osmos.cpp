/*
LANG: C++
*/

#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<functional>
#include<vector>
#include<list>
#include<set>
#include<queue>
#include<map>
#include<cctype>
#include<cstring>
#include<string>
#include<sstream>
#include<iostream>
#include<ctime>

#define INF 10000

using namespace std;

int solve(int cc){

    long long a,b[105];
    int n;

    scanf("%lld %d",&a,&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&b[i]);
    }
    sort(b+1,b+1+n);
    int c[105];
    for(int i=0;i<=n;i++)
        c[i]=INF;
    c[0]=0;

    long long tmpa=a;
    for(int i=1;i<=n;i++)
    {
        if(c[i-1]==INF)
            c[i]=INF;

        int cnt=0;
        while(a<=b[i])
        {
            a=a+a-1;
            cnt++;
            if(cnt>n)
                break;
        }
        if(cnt>n)
            c[i]=INF;
        else
            c[i]=c[i-1]+cnt;
        a+=b[i];
    }

//    for(int i=0;i<=n;i++)
//        printf("%lld ",b[i]);
//    printf("\n");
//    for(int i=0;i<=n;i++)
//        printf("%lld ",c[i]);
//    printf("\n");

    int sol=INF;

    for(int i=1;i<=n+1;i++)
        sol=min(sol,c[i-1]+(n+1-i));

    printf("Case #%d: %d\n",cc,sol);

    return 1;
}

int main(){

//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
        solve(i+1);

	return 0;
}
