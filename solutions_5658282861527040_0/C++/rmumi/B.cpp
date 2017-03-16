#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define mp make_pair
#define xx first
#define yy second
#define pb push_back
using namespace std;
int t,n,a,b,c,k;
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
	scanf("%d",&t);
	for(int CASE=1;CASE<=t;CASE++)
    {
        scanf("%d %d %d",&a,&b,&k);
        c=0;
        for(int i=0;i<a;i++)
        {
            for(int j=0;j<b;j++)
            {
                if((i&j)<k)c++;
            }
        }
        printf("Case #%d: %d\n",CASE,c);
    }
    return 0;
}
