#include<bits/stdc++.h>
using namespace std;
#define min(a,b) (a<b?a:b)
#define ms0(x) memset(x,0,sizeof(x))
#define FILEIO(x) freopen(#x ".in","r",stdin);freopen(#x ".out","w",stdout);
#define FILEIOS freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
const double eps = 1e-9;
int main(){
    //FILEIO("B-small-practice");
    freopen("C-small-attempt7.in","r",stdin);
    freopen("C-small-attempt7.out","w",stdout);

    int t,i,j,k,r,c,m,a,b;
    int ms[55][55];
    cin>>t;
    for(i=1;i<=t;i++)
    {
        printf("Case #%d:\n",i);

        cin>>r>>c>>m;
        ms0(ms);
        if((r==1||c==1)&&r*c>m||m==0||r*c==m+1)
        {
            for(j=r-1;j>=0;j--)
            for(k=c-1;k>=0;k--)
            if(m>0)
            {ms[j][k]=2;
            m--;
            }
            else
            {
                j=-1;k=-1;
            }
            for(j=0;j<r;j++)
            {
                for(k=0;k<c;k++)
                if(j==0&&k==0)
                cout<<"c";
                else if(ms[j][k]==0)
                cout<<".";
                else
                cout<<"*";
                cout<<endl;
            }
            continue;
        }
        //int x=m;

        if(r*c-4>=m)
        {

            a=r-1;b=c-1;

            while(m>0&&b>2)
            {
                a=r-1;
                while(a>=0&&m>0)
                {
                        if(m==1&&a==1)
                        {
                          break;
                        }
                        else
                        {
                            ms[a][b]=2;
                            m--;
                        }
                    a--;
                }
                b--;
            }
            a=r-1;
            while(m>0&&a>2)
            {
                b=min(c-1,2);
                while(b>=0&&m>0)
                {
                        if(m==1&&b==1)
                        {
                          break;
                        }
                        else
                        {
                            ms[a][b]=2;
                            m--;
                        }
                    b--;
                }
                a--;
            }
            if(m>0)
            {
            a=min(r-1,2);
            b=min(c-1,2);
            if(a==2&&b==2)
            {
                if(m>=1)
                {
                    ms[a][b]=2;
                     m--;
                }
                if(m>=2)
                {
                    ms[1][2]=2;ms[0][2]=2;
                    m=m-2;
                }
                if(m==2)
                {
                    ms[2][0]=2;ms[2][1]=2;
                    m=m-2;
                }
            }
            else if(b<2&&m==b+1&&a==2)
            {
                for(j=0;j<=b;j++)
                {
                    ms[a][j]=2;
                    m--;
                }
            }
            else if(a<2&&m==a+1&&b==2)
            {
                for(j=0;j<=a;j++)
                {
                    ms[j][b]=2;
                    m--;
                }
            }
        }

            if(m>0)
            {
               // cout<<r<<" "<<c<<" "<<x<<endl;
                cout<<"Impossible"<<endl;
            }
            else
            {
                //cout<<r<<" "<<c<<" "<<x<<endl;
            for(j=0;j<r;j++)
            {
                for(k=0;k<c;k++)
                if(j==0&&k==0)
                cout<<"c";
                else if(ms[j][k]==0)
                cout<<".";
                else
                cout<<"*";
                cout<<endl;
            }
            }
        }
        else
        {
            //cout<<r<<" "<<c<<" "<<m<<endl;
            cout<<"Impossible"<<endl;
        }

    }
    return 0;
}


