#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

int ttt;

int n,val;

char s[110];

char vow[6]={'a','e','i','o','u'};


int sol(char c)
{
    
    if(c=='a')
        return 1;
    if(c=='e')
        return 1;
    if(c=='i')
        return 1;
    if(c=='o')
        return 1;
    if(c=='u')
        return 1;
    return 0;
        
}


int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0_out.txt","w",stdout);
    
    int i,j;
    
    scanf("%d",&ttt);
    for(int tt=1;tt<=ttt;tt++)
    {
        printf("Case #%d: ",tt);
        scanf("%s",s);
        int len=strlen(s);
        scanf("%d",&n);
        int ans=0;
        for(i=0;i<len;i++)
        {
            int cnt=0;
            int flag=0;
            for(j=i;j<len;j++)
            {
                if(sol(s[j])==0)
                {
                    cnt++;
                    
                }
                else
                {
                    cnt=0;
                }
                //printf("%d",cnt);
                if(cnt==n)
                {
                    cnt=len-j;
                    //printf("2");
                    flag=1;
                    break;
                }
            }
            //printf("cnt  %d\n",cnt);
            if(flag==1)
                ans+=cnt;
        }
        printf("%d\n",ans);
        
        
        
        
        
        
        
        
        
        
        
    }
    
    
    
    //system("pause");
    return 0;
}
