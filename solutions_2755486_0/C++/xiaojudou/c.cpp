#include<cstdio>
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
int het[200100];
struct AA{
  int e,w,s;
  int d;
}a[10000000];
bool cmp(AA x,AA y)
{
    return x.d<y.d;
}
int main()
{
    //freopen("C-small-attempt1.in", "r", stdin);
   // freopen("c.out", "w", stdout);
    int n,ans,t,_=0,num,f;
    int d,nn,w,e,s,d_d,d_p,d_s;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        ans=0;
        memset(het,0,sizeof(het));
        num=0;
        for(int i=0;i<n;++i)
        {
            scanf("%d%d%d%d%d%d%d%d",&d,&nn,&w,&e,&s,&d_d,&d_p,&d_s);
            for(int j=0;j<nn;++j)
            {
                a[num].d=d+j*d_d;
                a[num].w=w+j*d_p;
                a[num].e=e+j*d_p;
                a[num].s=s+j*d_s;
                num++;
            }
          //  for(int j=0;j<num;j++)
           //  cout<<a[j].w<<" "<<a[j].e<<" "<<a[j].s<<"~~"<<a[j].d<<endl;
        }
        sort(a,a+num,cmp);
    //for(int j=0;j<num;j++)
     //   cout<<a[j].w<<" "<<a[j].e<<" "<<a[j].s<<"~~"<<a[j].d<<endl;
        a[num].d=a[num-1].d+1;
        for(int i=0;i<num;++i)
        {
            f=0;
            for(int j=a[i].w;j<a[i].e;++j)
            {
                if(het[j+100000]<a[i].s&&a[i].d<a[i+1].d)
                {
                    f=1;

                        het[j+100000]=a[i].s;
                }
            }
            if(f)ans++;
        }
        //di, ni, wi, ei, si, delta_di, delta_pi and delta_si
        printf("Case #%d: ",++_);
        printf("%d\n",ans);
    }
    return 0;
}


