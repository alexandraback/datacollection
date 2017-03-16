#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

int ttt;

int x,y;





int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0_out.txt","w",stdout);
    
    int i,j;
    
    scanf("%d",&ttt);
    for(int tt=1;tt<=ttt;tt++)
    {
        printf("Case #%d: ",tt);
        scanf("%d %d",&x,&y);
        if(x>0)
        {
            for(i=0;i<x;i++)
            {
                printf("WE");
            }
        }
        else
        {
            for(i=0;i<-x;i++)
            {
                printf("EW");
            }
        }
        if(y>0)
        {
            for(i=0;i<y;i++)
            {
                printf("SN");
            }
        }
        else
        {
            for(i=0;i<-y;i++)
            {
                printf("NS");
            }
        }
        puts("");
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
    }
    
    
    
    //system("pause");
    return 0;
}
