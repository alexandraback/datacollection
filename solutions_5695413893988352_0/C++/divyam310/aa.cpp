#include<bits/stdc++.h>
using namespace std;

//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
#define bitcount    __builtin_popcountll
#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d %d",&x,&y);
#define slld(x) scanf("%lld",&x)
#define rep(i,x,y) for(i=x;i<y;i++)
#define ss(x) scanf("%s",x)
#define ll long long
#define mp(a,b) make_pair(a,b)
#define F first
#define S second
#define pb(x) push_back(x)
#define MOD 1000000007

string c,j;
int n;
int ten[18];
int diff=100000;
int ansc,ansj;
void calc(int i,int sumx,int sumy)
{

    if(i>=n)
    {
        //cerr<<sumx<<sumy<<endl;
        if(abs(sumx-sumy)==diff)
        {
            //cerr<<sumx<<sumy<<endl;
            if(ansc==sumx&&ansj>sumy)
            {
                ansc=sumx;
                ansj=sumy;
            }
            if(ansc>sumx)
            {
                ansc=sumx;
                ansj=sumy;
            }


        }
        if(abs(sumx-sumy)<diff)
        {
            //cerr<<sumx<<sumy<<endl;
            diff=abs(sumx-sumy);
            ansc=sumx;
            ansj=sumy;
        }
        return ;
    }

    if(c[i]!='?'&&j[i]!='?')
    {
        calc(i+1,sumx+ten[n-i-1]*(c[i]-'0'),sumy+ten[n-i-1]*(j[i]-'0'));
    }
    if(c[i]=='?'&&j[i]!='?')
    {
        for(int x=0;x<=9;x++)
        {
            calc(i+1,sumx+ten[n-i-1]*(x),sumy+ten[n-i-1]*(j[i]-'0'));
        }

    }
    if(c[i]!='?'&&j[i]=='?')
    {
        for(int x=0;x<=9;x++)
        {
            calc(i+1,sumx+ten[n-i-1]*(c[i]-'0'),sumy+ten[n-i-1]*(x));
        }
    }

    if(c[i]=='?'&&j[i]=='?')
    {

        for(int x=0;x<=9;x++)
        {
            for(int y=0;y<=9;y++)
            {
                calc(i+1,sumx+ten[n-i-1]*x,sumy+ten[n-i-1]*(y));
            }
        }
    }
    return ;


}


int main()
{
    freopen("B-small-attempt0.in","r",stdin);freopen("output.txt","w",stdout);
    ten[0]=1;
    for(int i=1;i<=18;i++)
        ten[i]=ten[i-1]*10;
    //cerr<<ten[2];
    int t;
    sd(t);
    for(int q=0;q<t;q++)
    {
        diff=10000000;
        cin>>c;
        cin>>j;
        n=c.size();
        calc(0,0,0);
        printf("Case #%d: ",q+1);

        if(n==1)
        {
            printf("%d %d\n",ansc,ansj);
        }
        else if(n==2)
        {
            if(ansc/10==0)
            {
                printf("0");
            }
            printf("%d ",ansc);
            if(ansj/10==0)
            {
                printf("0");
            }
            printf("%d\n",ansj);
        }
        else
        {
            if(ansc/100==0)
            {
                printf("0");
                if(ansc/10==0)
            {
                printf("0");
            }

            }
            printf("%d ",ansc);
            if(ansj/100==0)
            {
                printf("0");
                if(ansj/10==0)
            {
                printf("0");
            }

            }
            printf("%d\n",ansj);

        }






    }





}



