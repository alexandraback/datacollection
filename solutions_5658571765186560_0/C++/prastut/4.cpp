#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,T,x,r,c;
    bool ans;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        scanf("%d %d %d",&x,&r,&c);
        ans=true;

        if(x>=7)
            ans=false;
        else
        if(x>r && x>c)
            ans=false;
        else
        if((r*c)%x!=0)
            ans=false;
        else
        if( ((x+1)/2)>min(r,c) )
            ans=false;
        else
        if(x==1 || x==2 || x==3)
            ans=true;
        else
        if(x==4)
            ans=(min(r,c)>2);
        else
        if(x==5)
            ans=!(min(r,c)==3 && max(r,c)==5);
        else
        if(x==6)
            ans=(min(r,c)>3);

        printf("Case #%d: ",i);
        if(ans)
            printf("GABRIEL\n");
        else
            printf("RICHARD\n");
    }


    return 0;
}
