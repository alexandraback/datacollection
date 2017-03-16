
#include<stdlib.h>
#include<stdio.h>
using namespace std;
int solve(int x, int y)
{
    if(x>=0 && y>=0)
    {
           while(x--)
           printf("WE");
           while(y--)
           printf("SN");
    }
    else if(x>=0 && y<0)
    {
         y*=-1;
           while(x--)
           printf("WE");
           while(y--)
           printf("NS");
         
    }
    else if( x<0 && y <0)
    {
           x*=-1;
           y*=-1;
           while(x--)
           printf("EW");
           while(y--)
           printf("NS");
    
    }
    else 
    {
         x*=-1;
         while(x--)
         printf("EW");
         while(y--)
         printf("SN");
    }
    
    return 0;
}
    
int main()
{
    
    freopen("input.in","r",stdin);
    freopen("output.txt","w",stdout);
    int t=0,x,y,cnt=1;
    scanf("%d",&t);
    
    while(t--){
        
        scanf("%d%d",&x,&y);
        
        printf("Case #%d: ",cnt++);
        solve(x,y);
        
        printf("\n");
    }
    return 0;
}
