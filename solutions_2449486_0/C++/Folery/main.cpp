#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
using namespace std;
int T,t;
int n,m;
int a[110][110];
int flag_r[110][110];
int flag_c[110][110];
int main()
{
    FILE *fin,*fout;
    fin=fopen("B-small-attempt0.in","r");
    fout=fopen("out.txt","w");
    fscanf(fin,"%d",&T);
    int i,j;
    for(t=1;t<=T;t++)
    {
        fscanf(fin,"%d%d",&n,&m);
        memset(flag_c,0,sizeof(flag_c));
        memset(flag_r,0,sizeof(flag_r));
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                fscanf(fin,"%d",&a[i][j]);
            }
        }
        int maxh;
        for(i=0;i<n;i++)
        {
            maxh=a[i][0];
            for(j=0;j<m;j++)
                maxh=max(maxh,a[i][j]);
            for(j=0;j<m;j++)
            {
                if(a[i][j]<maxh)
                    flag_r[i][j]=1;
            }
        }
        for(j=0;j<m;j++)
        {
            maxh=a[0][j];
            for(i=0;i<n;i++)
                maxh=max(maxh,a[i][j]);
            for(i=0;i<n;i++)
            {
                if(a[i][j]<maxh)
                    flag_c[i][j]=1;
            }
        }
        int num=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(flag_c[i][j]==1&&flag_r[i][j]==1)
                    num++;
            }
        }
        fprintf(fout,"Case #%d: ",t);
        if(num>0)
            fprintf(fout,"NO\n");
        else
            fprintf(fout,"YES\n");
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
