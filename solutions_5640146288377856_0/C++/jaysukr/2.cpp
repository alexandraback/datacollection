
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<map>
#include<vector>
#include<algorithm>
#include<utility>

using namespace std;
typedef long long int ll;

main()
{
    FILE *in  = fopen("in.txt","r");
    FILE *out  = fopen("out.txt","w");

    int cases,cs;
    fscanf(in,"%d",&cases);
    for(cs=1;cs<=cases;++cs)
    {
        int r,c,w;
        fscanf(in,"%d%d%d",&r,&c,&w);
        int ans = (r-1)*(c/w) + ceil(double(c)/w)-1 + w;

        fprintf(out,"Case #%d: %d\n",cs,ans);
    }
    fclose(in);
    fclose(out);

    return 0;
}

