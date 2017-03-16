#include<stdio.h>
int main()
{
    int t,r,c,w,co=1,ans;
    FILE *fp,*fo;
    fp=fopen("A-small-attempt0.in","r");
    fo=fopen("output.txt","w");
    fscanf(fp,"%d",&t);
    while(t--)
    {

        fscanf(fp,"%d%d%d",&r,&c,&w);
        if(c%w==0)
        ans=(c/w)*r+w-1;
        else
        ans=(c/w)*r+w;
        fprintf(fo,"Case #%d: %d\n",co++,ans);
    }
    return 0;

}
