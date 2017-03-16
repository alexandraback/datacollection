#include<iostream>
#include<cmath>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<algorithm>

#define LL long long

using namespace std;

const int INF=0x3f3f3f3f;
const int N=1000005;
double F(int n,int i)
{
    int k=n;
    double tmp=1.0;
    for(int w=i;w>=1;--w,--n)
    {
        tmp=tmp*n/w;
        while(tmp>100.0&&k>0)
        {
            tmp=tmp/2.0;
            k--;
        }
    }
    while(k>0)
    {
        tmp=tmp/2.0;
        k--;
    }
    return tmp;

}
int main()
{
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    int T;
    cin>>T;
    for(int w=1;w<=T;++w)
    {
        printf("Case #%d: ",w);
        int n,x1,y1;
        cin>>n>>x1>>y1;
        if(n==1)
        {
            if(x1==0&&y1==0)
            {printf("1.000000\n");continue;}
            else
            {printf("0.000000\n");continue;}
            continue;
        }
        x1=abs(x1);
        bool flag=false;
        int k=1,x=0;
        for(k=1,x=0;n>=(k*2-1);k=k+2,x=x+2)
        {
            for(int x2=x,y2=0;x2>=0;x2--,y2++)
            if(x2==x1&&y2==y1)
            flag=true;
            n=n-(k*2-1);
        }
        if(flag==true)
        {printf("1.000000\n");continue;}
        if(n==0)
        {printf("0.000000\n");continue;}
        int i=1;
        for(int x2=x,y2=0;i<=n&&x2>0;x2--,y2++,i++)
        if(x2==x1&&y2==y1)
        {flag=true;break;}
        if(flag==false)
        {printf("0.000000\n");continue;}
        /*
        int sum=0;
        int s=0;
        for(int l=0;l<=n&&l<k;++l)
        {
            int r=n-l;
            if(r<k)
            {
                ++sum;
                if(r>=i)
                ++s;
            }
        }*/
        //cout<<n<<" "<<k<<" "<<i<<endl;
        double tmp=0.0;
        for(;i<=min(k-1,n);++i)
        {
            if(n-i>=k) continue;

            if(n-i==k-1&&i==k-1)
            {
                tmp+=1.0;
                continue;
            }
            if(n-i==k-1||i==k-1)
            {
                double h=0.0;
                for(int w=k-2;w<n;++w)
                {
                    h=h+(F(w,w-(k-2)))*0.5;
                }
                tmp+=h;
                continue;
            }
            tmp+=F(n,i);
        }
        printf("%lf\n",tmp);

    }
    return 0;
}
