#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

int ttt;

int n,val;

char s[1000010];


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

int ok[1000010][2];

int num=0;


int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large_out.txt","w",stdout);
    
    int i,j;
    
    scanf("%d",&ttt);
    for(int tt=1;tt<=ttt;tt++)
    {
        printf("Case #%d: ",tt);
        scanf("%s",s);
        int len=strlen(s);
        scanf("%d",&n);
        memset(ok,0,sizeof(ok));
        int begin=-1;
        int cnt=0;
        long long ans=0;
        for(i=0;i<len;i++)
        {
            
            if(sol(s[i])==0)
            {
                cnt++;
                if(cnt==n)
                {
                    begin=i-cnt+1;
                }
                if(cnt>n)
                {
                    begin++;
                }
            }
            else
            {
                cnt=0;
            }
            ans+=(begin+1);
            
            
            
            
        }
        
        
        
        
        
        
        
        printf("%lld\n",ans);
        
    }
    
    
    
    //system("pause");
    return 0;
}
