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

using namespace std;

int solve(int cc)
{
    int n,m;
    char tb[128][128];

    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&tb[i][j]);

    bool sol=true;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            bool ch1=true;
            for(int k=0;k<m;k++)
                if(tb[i][k]>tb[i][j])
                    ch1=false;
            bool ch2=true;
            for(int k=0;k<n;k++)
                if(tb[k][j]>tb[i][j])
                    ch2=false;
            sol=sol&&(ch1||ch2);
        }
    }

    if(sol)
        printf("Case #%d: YES\n",cc);
    else
        printf("Case #%d: NO\n",cc);

    return 1;
}

int main(){

//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
        solve(i);

	return 0;
}
