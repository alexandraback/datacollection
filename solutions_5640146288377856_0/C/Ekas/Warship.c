#include<stdio.h>
#include<string.h>
int solve(int x, int y)
{
    if(x==y)return x;
    else
    return x+1;
}
int main()
{
    int R,C,W,T;
    int i,t,corners,sides,total,ans;
    char fileName[]="A-small-attempt0.in",answer[]="WarshipAns.in";
    FILE *fp, *fp2;
    fp = fopen(fileName,"r");
    fp2 = fopen(answer,"w");
    fscanf(fp,"%d", &T);
    for(t=0;t<T;t++)
    {
        fscanf(fp,"%d %d %d",&R,&C,&W);
        ans=R*(C/W) + solve(W,W+C%W) - 1; 
        fprintf(fp2,"Case #%d: %d\n",t+1,ans);
    }
    fclose(fp);
    fclose(fp2);
    
    return 0;
}
