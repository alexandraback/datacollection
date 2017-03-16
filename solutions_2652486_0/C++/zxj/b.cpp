#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<queue>
#include<list>
#include<stack>
#include<set>
#include<map>
#include<string>
#include<algorithm>
using namespace std;


#define PB push_back
#define MP make_pair


int r,n,m,k;
int a[10];
int vis[5*5*5+10];

int main()
{
	freopen("C-small-1-attempt3.in","r",stdin);
	freopen("output.txt","w",stdout);
    int i,j,t;
    scanf("%d",&t);
   int cas=0;
    while(t--)
    {

        scanf("%d%d%d%d",&r,&n,&m,&k);
        printf("Case #%d:\n",++cas);
        while(r--)
        {
            memset(vis,0,sizeof(vis));
            for(i=1;i<=k;i++)
              scanf("%d",&a[i]);
            int ans=0;
            if(n==1)
            {
                for(i=2;i<=m&&ans==0;i++)
                {
                    int aa=i;
                    vis[aa]=1;
                    vis[1]=1;
                    int flag=0;
                    for(int tt=1;tt<=k;tt++)
                    {
                        if(vis[a[tt]])flag++;
                    }
                    if(flag==k)
                    {
                        ans=1;
                        cout<<i<<endl;
                    }
                    vis[aa]=0;
                    vis[1]=0;
                }
            }
            else if(n==2)
            {
                for(i=2;i<=m&&ans==0;i++)
                {
                    for(j=2;j<=m&&ans==0;j++)
                    {

                            int aa=i,bb=j;
                            int ab =i*j;
                            vis[aa]=1;vis[bb]=1;;
                            vis[ab]=1;
                            vis[1]=1;

                            int flag=0;
                            for(int tt=1;tt<=k;tt++)
                            {
                                if(vis[a[tt]])flag++;
                            }
                            if(flag==k)
                            {
                                ans=1;
                                cout<<i<<j<<endl;
                            }
                            vis[aa]=0;vis[bb]=0;
                            vis[ab]=0;
                            vis[1]=0;
                        }
                }
            }
            else
            {
                for(i=2;i<=m&&ans==0;i++)
                {
                    for(j=i;j<=m&&ans==0;j++)
                    {
                        for(int g=j;g<=m&&ans==0;g++)
                        {

                            int aa=i,bb=j,cc=g;
                            int ab =i*j,ac=i*g,bc=j*g;
                            int abc=i*j*g;
                            //if(i==3&&j==4&&g==3)cout<<
                            //ab<<" "<<ac<<" "<<bc<<" "<<abc<<endl;
                            vis[aa]=1;vis[bb]=1;vis[cc]=1;
                            vis[ab]=1;vis[ac]=1;vis[bc]=1;
                            vis[1]=1;
                            vis[abc]=1;
                            int flag=0;
                            for(int tt=1;tt<=k;tt++)
                            {
                                if(vis[a[tt]])flag++;
                            }
                            if(flag==k)
                            {
                                ans=1;
                                cout<<i<<j<<g<<endl;
                            }
                            vis[aa]=0;vis[bb]=0;vis[cc]=0;
                            vis[ab]=0;vis[ac]=0;vis[bc]=0;
                            vis[1]=0;
                            vis[abc]=0;
                        }
                    }
                }
            }

        }
    }
}
