#include<stdio.h>
#include<algorithm>
#include<vector>
#include<math.h>
#include<string.h>
#include<vector>
#include<map>
#include<set>
#include<iostream>

using namespace std;

typedef long long ll;

int x,r,c;

int main()
{
    freopen("D-small-attempt2.in","r",stdin);
    freopen("D-small-attempt2.out","w",stdout);
    int T,I=1,i,j;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d %d",&x,&r,&c);
        printf("Case #%d: ",I++);
        if(r*c%x||x>max(r,c)||x>=7||(x+1)/2>min(r,c)||x>=min(r,c)+2) printf("RICHARD\n");
        else printf("GABRIEL\n");
    }
    return 0;
}
