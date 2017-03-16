#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<string>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<string>

using namespace std;


int main()
{
    FILE *fin,*fout;
    fin=fopen("B-small-attempt0.in","r");
    fout=fopen("output.txt","w");
    int i,j,n,t,x,a,b,k,count;
    fscanf(fin,"%d",&t);
    for(x=1;x<=t;x++)
    {
        fscanf(fin,"%d %d %d",&a,&b,&k);
        count=0;
        for(i=0;i<a;i++)
        {
            for(j=0;j<b;j++)
            {
                if((i & j) <k)
                count++;
            }
        }
        fprintf(fout,"Case #%d: %d\n",x,count);
    }
    return(0);
}

