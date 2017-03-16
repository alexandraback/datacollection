#include<stdio.h>
#include<math.h>
int main()
{
    int i,j,k,n,t,r,v;
    scanf("%d",&t);
    //scanf("%c",&fre);
    for(k=1;k<=t;k++)
    {
        scanf("%d %d",&r,&v);
        //n=0;
        /*
        j=(2*r+1);
        for(int n=0;v>0;n++)
        {
            if(v<(j)) break;
            else
        }*/
        float nn,ans1,ans2;
        nn=sqrt((2*r-1)*(2*r-1)+4*2*v);
        ans1=(1-2*r+nn)/4;
        ans2=(1-2*r-nn)/4;
        //printf("%f %f\n",ans1,ans2);
        if(ans1>0)
            printf("Case #%d: %.0f\n",k,floor(ans1));
        else printf("Case #%d: %.0f\n",k,floor(ans2));
    }

    return 0;
}
