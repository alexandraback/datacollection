#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
    FILE* f;
    FILE* fo;
    f=fopen("A.txt","r");
    fo=fopen("AO.txt","w");
    int n;
    int xrc[101][3];
    int rcmax[7]={0,1,1,2,2,3,3};
    fscanf(f,"%d",&n);
    for(int i=0;i<n;i++)
    {
        fscanf(f,"%d%d%d",&xrc[i][0],&xrc[i][1],&xrc[i][2]);
        if(xrc[i][0]>=7||rcmax[xrc[i][0]]>xrc[i][1]||
           rcmax[xrc[i][0]]>xrc[i][2]||xrc[i][1]*xrc[i][2]%xrc[i][0]!=0||
           (xrc[i][0]>xrc[i][1]&&xrc[i][0]>xrc[i][2]))
        {
            fprintf(fo,"Case #%d: RICHARD\n",i+1);
            continue;
        }
        if(xrc[i][0]<=3)
        {
            fprintf(fo,"Case #%d: GABRIEL\n",i+1);
            continue;
        }
        if(xrc[i][0]==4&&xrc[i][1]>=3&&xrc[i][2]>=3)
        {
            fprintf(fo,"Case #%d: GABRIEL\n",i+1);
            continue;
        }
        if(xrc[i][0]==5&&xrc[i][1]+xrc[i][2]>=9)
        {
            fprintf(fo,"Case #%d: GABRIEL\n",i+1);
            continue;
        }
        if(xrc[i][0]==6&&xrc[i][1]>=4&&xrc[i][2]>=4)
        {
            fprintf(fo,"Case #%d: GABRIEL\n",i+1);
            continue;
        }
        fprintf(fo,"Case #%d: RICHARD\n",i+1);

    }

    return 0;
}
