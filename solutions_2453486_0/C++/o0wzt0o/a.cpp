#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<stack>
using namespace std;
int n,m,len;
char a[5][5];
int s[128]={0};
int main()
{
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
        int i,j,k,tot,ttl;
        scanf("%d",&tot);
        for(ttl=1;ttl<=tot;ttl++)
        {
            for(i=0;i<4;i++)
                scanf("%s",&a[i]);
            int state=0;
            //1:x 2:o 0:not complete
            for(i=0;i<4;i++)
            {
                s['X']=s['O']=s['T']=0;
                for(j=0;j<4;j++)
                    s[a[i][j]]++;
                if(s['X']+s['T']==4)
                    {state=1;break;}
                else if(s['O']+s['T']==4)
                    {state=2;break;}
            }
            for(i=0;i<4;i++)
            {
                s['X']=s['O']=s['T']=0;
                for(j=0;j<4;j++)
                    s[a[j][i]]++;
                if(s['X']+s['T']==4)
                    {state=1;break;}
                else if(s['O']+s['T']==4)
                    {state=2;break;}
            }
            
            s['X']=s['O']=s['T']=0;
            for(j=0;j<4;j++)
                s[a[j][j]]++;
            if(s['X']+s['T']==4)
                state=1;
            else if(s['O']+s['T']==4)
                state=2;
            
            
            s['X']=s['O']=s['T']=0;
            for(j=0;j<4;j++)
                s[a[j][3-j]]++;
            if(s['X']+s['T']==4)
                state=1;
            else if(s['O']+s['T']==4)
                state=2;
            
            s['X']=s['O']=s['T']=0;
            for(i=0;i<4;i++)
                for(j=0;j<4;j++)
                    s[a[i][j]]++;
            if(state==0&& s['X']+s['O']+s['T']==16)state=3;
            if(state==1)printf("Case #%d: X won\n",ttl);
            else if(state==2)printf("Case #%d: O won\n",ttl);
            else if(state==3)printf("Case #%d: Draw\n",ttl);
            else printf("Case #%d: Game has not completed\n",ttl);
        }
        
        return 0;
}
