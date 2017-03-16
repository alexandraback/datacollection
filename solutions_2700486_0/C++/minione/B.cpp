#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int T,n,X,Y;
double ans;
bool g[1000][1000];

void search(int dep,double Pr)
{
    if (dep<=n)
    {
        int k=100;
        while (!g[100][k])
        {
            k-=2;
            if (k==-2) break;
        }
        int x=100,y=k+2;
        int xx=x,yy=y;
        if ((y==0) || ((g[x-1][y-1]) && (g[x+1][y-1])))
        {
               g[x][y]=true;
               if ((x-100==X) && (y==Y))
               {
                  ans+=Pr;
               }
               else search(dep+1,Pr);
               g[x][y]=false;
        }
        else
        {
            x=xx;y=yy;
            if ((!g[x-1][y-1]) && (g[x+1][y-1]))
            {
               while (!g[x][y])
               {
                   x--;
                   y--;
                   if (y==-1) break;
               }
               x++;
               y++;
               g[x][y]=true;
               if ((x-100==X) && (y==Y))
               {
                  ans+=Pr;
               }
               else search(dep+1,Pr);
               g[x][y]=false;
            }

            x=xx;y=yy;
            if ((!g[x+1][y-1]) && (g[x-1][y-1]) )
            {
               while (!g[x][y])
               {
                   x++;
                   y--;
                   if (y==-1) break;
               }
               x--;
               y++;
               g[x][y]=true;
               if ((x-100==X) && (y==Y))
               {
                  ans+=Pr;
               }
               else search(dep+1,Pr);
               g[x][y]=false;
            }

            x=xx;y=yy;
            if ((!g[x-1][y-1]) && (!g[x+1][y-1]))
            {
               while (!g[x][y])
               {
                   x--;
                   y--;
                   if (y==-1) break;
               }
               x++;
               y++;
               g[x][y]=true;
                       //cout<<dep<<" "<<x-100<<" "<<y<<" "<<Pr<<endl;

               if ((x-100==X) && (y==Y))
               {
                  ans+=Pr*0.5;
               }
               else search(dep+1,Pr*0.5);
               g[x][y]=false;

               x=xx;y=yy;
               while (!g[x][y])
               {
                   x++;
                   y--;
                   if (y==-1) break;
               }
               x--;
               y++;
               g[x][y]=true;
               //cout<<dep<<" "<<x-100<<" "<<y<<" "<<Pr<<endl;
               if ((x-100==X) && (y==Y))
               {
                  ans+=Pr*0.5;
               }
               else search(dep+1,Pr*0.5);
               g[x][y]=false;
            }
        }

    }
}

int main()
{
    freopen("B-small-attempt2.in","r",stdin);
    freopen("B-small-attempt2.out","w",stdout);
    //freopen("binput.txt","r",stdin);
    //freopen("boutput.txt","w",stdout);
    cin>>T;
    for (int tt=1; tt<=T; ++tt)
    {
        cin>>n>>X>>Y;
        ans=0;
        for (int i=0; i<200; i++)
            for (int j=0; j<200; j++) g[i][j]=false;
        search(1,1);
        cout<<"Case #"<<tt<<": "<<ans<<endl;
    }
    return 0;
}
