#include<bits/stdc++.h>

using namespace std;

int main()
{
    FILE *fp,*fo;
    fp=fopen("input.txt","r");
    fo=fopen("output.txt","w");

    int t,x;
    fscanf(fp,"%d",&t);
    for(x=1;x<=t;x++)
    {
        int a,b,k,i,j,c=0;
        fscanf(fp,"%d %d %d",&a,&b,&k);

        for(i=0;i<a;i++)
            for(j=0;j<b;j++)
                if((i&j)<k)
                    c++;

        fprintf(fo,"Case #%d: %d\n",x,c);
    }


    fclose(fp);
    fclose(fo);
    return 0;
}
