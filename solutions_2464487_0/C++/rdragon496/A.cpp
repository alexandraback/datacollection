#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
#define MAXN 128
#define INF 1<<30
///
using namespace std;

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    int cases;
    scanf("%d",&cases);
    for(int c=1;c<=cases;c++)
    {
        int r,t;
        scanf("%d %d",&r,&t);
        int tmp=(int)sqrt(1.0*t/2);
        //printf("%d\n",tmp);
        printf("Case #%d: ",c);
        int i;
        for(i=tmp;i>=0;i--)
        {
            int cur=2*i*i+(2*r-1)*i;
            if(cur<=t)
            {
                printf("%d\n",i);
                break;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
