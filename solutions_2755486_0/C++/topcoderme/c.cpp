//di, ni, wi, ei, si, delta_di, delta_pi and delta_si
#include<stdio.h>
using namespace std;

int a[405];
int b[405];
struct S
{
    int di, ni, wi, ei, si, delta_di, delta_pi, delta_si;
}ob[20];

int main()
{
    int t,n,i,dmin,z,pos,c;
    scanf("%d",&t);
    for(int w=1;w<=t;w++)
    {
        for(i=0;i<=400;i++)
            a[i]=b[i]=0;
        c=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d%d%d%d%d%d%d%d",&ob[i].di,&ob[i].ni,&ob[i].wi,&ob[i].ei,&ob[i].si,&ob[i].delta_di,&ob[i].delta_pi,&ob[i].delta_si);
            ob[i].wi+=200;
            ob[i].ei+=200;
        }
       // sort(ob,ob+n,compa);
        while(1)
        {

           // z=0;
            for(i=0;i<n&&ob[i].ni==0;i++);
            if(i==n) break;
            dmin=ob[i].di;
            i++;
            for(;i<n;i++)
                if(ob[i].ni!=0&&ob[i].di<dmin)
            {
                dmin=ob[i].di;
            }
            for(pos=0;pos<n;pos++)
            if(ob[pos].ni!=0&&ob[pos].di==dmin){

            ob[pos].ni=ob[pos].ni-1;z=0;
           // printf("%d ",pos);
            for(i=ob[pos].wi+1;i<=ob[pos].ei;i++)
                if(a[i]<ob[pos].si) { if(b[i]<ob[pos].si) b[i]=ob[pos].si;z=1;}
            ob[pos].ei+=ob[pos].delta_pi;
            ob[pos].wi+=ob[pos].delta_pi;
            ob[pos].di+=ob[pos].delta_di;
            ob[pos].si+=ob[pos].delta_si;
            if(z) {c++;}
           // else printf("fail\n");
            }
            for(i=0;i<=400;i++)
                a[i]=b[i];
        }
        //Case #1: 5
        printf("Case #%d: %d\n",w,c);
    }
}
