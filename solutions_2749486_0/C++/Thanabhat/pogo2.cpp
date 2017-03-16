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
    int x,y;
    scanf("%d %d",&x,&y);
    int xx,yy;
    if(x<0) xx=-x;
    else xx=x;
    if(y<0) yy=-y;
    else yy=y;
    printf("Case #%d: ",cc);
    for(int i=1;i<=xx;i++)
    {
        if(x>0)
            printf("WE");
        else
            printf("EW");
    }
    for(int i=1;i<=yy;i++)
    {
        if(y>0)
            printf("SN");
        else
            printf("NS");
    }
    printf("\n");
    return 1;
}

int main(){

//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        solve(i);
    }
	return 0;
}
