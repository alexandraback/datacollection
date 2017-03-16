#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <set>
#include <assert.h>

#define file_name ""

typedef long long ll;

const int N = 1e5+5;

using namespace std;

char ans[1555];
int d,h,k;
int main()
{
    // freopen(file_name".in","r",stdin);
    // freopen(file_name".out","w",stdout);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int Test;
    scanf("%d",&Test);
    int X,Y,x,y;

    for(int test=1;test<=Test;++test)
    {
        scanf("%d%d",&X,&Y);
        x=y=0;
        d=0;
        h=1;
        k=1;
        //if (test>3) return 0;
        while (x!=X)
        {
            x+=k*h;
            h++;
            if (k>0) ans[d++]='E';
            else ans[d++] = 'W';
            k*=-1;
       //     if (test==3) {printf("%d \n",d);};
        }
    //    printf("%d\n",d);
        k=1;
        if (Y<0)
        {
            k=-1;
            if (y+k*h<Y) k=1;
        }
        else
        {
            if (y+k*h>Y) k=-1;
        }
        while (y!=Y)
        {
            y+=k*h;
            h++;
            if (k>0) ans[d++]='N';
            else ans[d++] = 'S';
            k*=-1;
        }

      //  if (test==3) {printf("%d ",d); return 0;};
        ans[d]=0;
        printf("Case #%d: %s\n",test,ans);
    }
    return 0;
}
