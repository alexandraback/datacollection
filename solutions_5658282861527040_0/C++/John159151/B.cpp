#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<map>
#include<set>
#include<deque>
#include<bitset>
#define ll __int64
#define inf 0x7FFFFFFF
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
int main()
{
    int i,j,k;
    int n,m,t;
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-output.txt","w",stdout);
    scanf("%d",&t);for(int tcase=1;tcase<=t;tcase++)
    //while(scanf("%d",&n)!=EOF)
    {
        int a,b;
        scanf("%d%d%d",&a,&b,&k);
        int num=0;
        for(i=0;i<a;i++)
        for(j=0;j<b;j++)
        {
            if((i&j)<k) num++;
        }
        printf("Case #%d: %d\n",tcase,num);
    }
    fclose(stdin);
    fclose(stdout);
}
