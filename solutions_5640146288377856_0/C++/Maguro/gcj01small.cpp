#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define X first
#define Y second
using namespace std;

int main()
{
    //freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T,t,i,j,k;
    int r,c,w;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%d %d %d",&r,&c,&w);
        int sum=0;
        sum+=c/w;
        if(c%w==0)
            sum+=w-1;
        else
            sum+=w;
        printf("Case #%d: %d\n",t,sum);
    }

}

