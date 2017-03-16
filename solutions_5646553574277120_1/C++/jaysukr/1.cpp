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
        ll ans;




        fprintf(out,"Case #%d: %lld\n",cs,ans);
    }
    fclose(in);
    fclose(out);

    return 0;
}

