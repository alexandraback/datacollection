//#define DEBUG
#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<list>
#include<map>
using namespace  std;
int n,x,y;
double ways,goodways;
 int place[101][101]={0};
        int top[101]={0};
void dfs(int dno,int cposx,int cposy)
{
     #ifdef DEBUG
    printf("dno %d at %d %d",dno,cposx,cposy);
      #endif
    int f1=0,f2=0;
     #ifdef DEBUG
    scanf(" %d",&f1);
    f1=0;
      #endif
    if(dno==n)
    {
        ways++;
        if(place[x+50][y]==1)
        {
            goodways++;
        }
        #ifdef DEBUG
        cout<<"ways "<<ways<<"goodways"<<goodways<<endl;
        #endif
        return;
    }
    if(top[cposx-1]>=cposy || cposy==0)
    {
        f1=1;
     //   dfs(dno+1,500,top[500]+1);
    }
    else
    {
        dfs(dno,cposx-1,cposy-1);
    }
    if(top[cposx+1]>=cposy || cposy==0)
    {
        f2=1;
     //   dfs(dno+1,500,top[500]+1);
    }
    else
    {
        dfs(dno,cposx+1,cposy-1);
    }
    if(f1==1 && f2==1)
    {
         #ifdef DEBUG
        cout<<"f1 and f2 ==1 REST newd";
          #endif
        top[cposx]+=2;
        place[cposx][cposy]=1;
        dfs(dno+1,50,top[50]+1);
        place[cposx][cposy]=0;
            top[cposx]-=2;
    }

}
int main()
{
    int T,t;
    scanf(" %d",&T);
    t=1;
    int i,j;
    while(t<=T)
    {
        scanf(" %d %d %d",&n,&x,&y);
        double ans=0;
        if(x>50 || x<-50 || y>100)
        {
            ans=0;
            goto end;
        }
        for(i=0;i<101;i++)
        {
            for(j=0;j<101;j++)
            {
                place[i][j]=0;
            }
            top[i]=-1;
        }
        ways=0;
        goodways=0;
        dfs(0,50,0);
        ans=goodways/ways;
        end:
        printf("Case #%d: %.7lf\n",t,ans);
        t++;
    }
	return 0;
}
