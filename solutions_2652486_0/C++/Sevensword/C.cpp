#include<stdio.h>

int main()
{
    int i,j,k,n,t,r,m,kk,value,v;
    scanf("%d",&t);
    //scanf("%c",&fre);
    scanf("%d %d %d %d",&r,&n,&m,&k);
    int count[m+1];
    for(i=0;i<=m;i++) count[i]=0;
    printf("Case #1:\n");
    for(kk=1;kk<=r;kk++)
    {
        for(i=0;i<=m;i++) count[i]=0;
        for(i=1;i<=7;i++)
        {
            scanf("%d",&value);
            v=value; j=0;
            while(v%2==0) { v=v/2; j++; } if(j>count[2]) count[2]=j;

            v=value; j=0;
            while(v%3==0) { v=v/3; j++; } if(j>count[3]) count[3]=j;

            v=value; j=0;
            while(v%5==0) { v=v/5; j++; } if(j>count[5]) count[5]=j;
        }
        while(count[2]+count[3]+count[4]+count[5]>n)
        {
            count[2]-=2;
            count[4]+=1;
        }
        j=0;
        for(i=1;i<=count[2];i++) { printf("2"); j++; }
        for(i=1;i<=count[3];i++) {printf("3"); j++;}
        for(i=1;i<=count[4];i++) {printf("4"); j++;}
        for(i=1;i<=count[5];i++) {printf("5"); j++;}
        for(i=j+1;i<=n;i++) { printf("2");}
        printf("\n");

    }

    return 0;
}
