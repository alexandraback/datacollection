#include<bits/stdc++.h>
using namespace std;
int main()
{
    FILE *in,*out;
    in=fopen("C:\\Users\\VED\\Desktop\\in.txt","r");
    out=fopen("C:\\Users\\VED\\Desktop\\out.txt","w");
    int t;
    fscanf(in,"%d",&t);
    for(int j=1;j<=t;j++)
    {
        int n;
        int h[2505]={};
     fscanf(in,"%d",&n);
       for(int i=1;i<=2*n-1;i++)
       {
           for(int k=1;k<=n;k++)
           {
               int x;
               fscanf(in,"%d",&x);
               h[x]++;
           }
       }
       fprintf(out,"Case #%d: ",j);
       for(int i=1;i<=2500;i++)
       {
           if(h[i]%2)
            fprintf(out,"%d ",i);
       }
       fprintf(out,"\n");
    }
    fclose(out);
    fclose(in);
}
