#include<iostream>
#include<cstring>
#include<cmath>
#include<stdio.h>
using namespace std;

double t[2020];
double p[2020];
int main()
{
int tt;
cin>>tt;
for(int i=1;i<=tt;i++)
{
double d;
int n,a;
cin>>d>>n>>a;
for(int i=1;i<=n;i++)cin>>t[i]>>p[i];
cout<<"Case #"<<i<<":"<<endl;
t[0]=0;
p[0]=0;
    for(int i=1;i<=a;i++)
    {
    double ax;
    cin>>ax;
    double tx=0;
    double px=0;
    double vx=0;
    double an=0;
    bool f=0;
        for(int i=2;i<=n;i++)
        {
            double pp=px+vx*(t[i]-t[i-1])+0.5*ax*(t[i]-t[i-1])*(t[i]-t[i-1]);
            if(pp<=p[i]){
                //cout<<"1====\n";
            if(pp>=d)
                {
                    double aa=0.5*ax;
                    double bb=vx;
                    double cc=px-d;
                an=tx+(sqrt(bb*bb-4.0*aa*cc)-bb)/(2.0*aa);
                f=1;break;
                }
            tx=t[i];
            px=pp;
            vx=vx+ax*(t[i]-t[i-1]);

            }
            else
            {
                //cout<<"2====\n";
                //if(px==p[i-1]&&vx>(p[i]-p[i-1])/(t[i]-t[i-1]))
                if(abs(px-p[i-1])<0.0000001&&vx>(p[i]-p[i-1])/(t[i]-t[i-1]))
                {
                    //cout<<"3====\n";
                    vx=(p[i]-p[i-1])/(t[i]-t[i-1]);
                    if(p[i]>=d)
                    {
                        an=tx+(d-px)/(vx);
                        f=1;break;
                    }
                    px=p[i];
                }
                else{
                if(p[i]>=d)
                {

                double aa=0.5*ax;
                double bb=vx-(p[i]-p[i-1])/(t[i]-t[i-1]);
                double cc=px-p[i-1];
                double tt=(sqrt(bb*bb-4.0*aa*cc)-bb)/(2.0*aa);
                    if(tt*(p[i]-p[i-1])/(t[i]-t[i-1])+p[i-1]>d)
                    {
                        //cout<<"4====\n";
                        aa=0.5*ax;
                        bb=vx;
                        cc=px-d;
                        an=tx+(sqrt(bb*bb-4.0*aa*cc)-bb)/(2.0*aa);
                    }
                    else
                    {
                        //cout<<"5====\n";
                        an=tx+(d-p[i-1])/((p[i]-p[i-1])/(t[i]-t[i-1]));
                    }
                f=1;break;
                }
                tx=t[i];
                px=p[i];
                vx=(p[i]-p[i-1])/(t[i]-t[i-1]);
                }
            }

        }
        if(!f)
        {
            double aa=0.5*ax;
            double bb=vx;
            double cc=px-d;
            an=tx+(sqrt(bb*bb-4.0*aa*cc)-bb)/(2.0*aa);
        }
        printf("%.7lf\n",an);
    }
}
return 0;
}
