#include <cstdio>
#include <math.h>

using namespace std;

struct pont
{
    double x;
    double t;
};

int t,n,A;
double d,g;
pont* a;

int main()
 {
    FILE* be = fopen("small.in","r");
    FILE* ki=fopen("ki.out","w");
    fscanf(be,"%d",&t);
    for(int c=0; c<t; c++)
    {
        float tmp;
        fscanf(be,"%f %d %d",&tmp,&n,&A);
        d=(double)tmp;
        fprintf(ki,"Case #%d:",c+1);
       // printf("%f %d %d\n",d,n,A);
        a=new pont[n];
        for(int i=0; i<n; i++)
        {
            float tmp1,tmp2;
            fscanf(be,"%f %f",&tmp1,&tmp2);
            a[i].t =(double)tmp1;
            a[i].x =(double)tmp2;
           // printf("%f %f\n",a[i].t,a[i].x);
        }
        for(int ca=0; ca<A; ca++)
        {
            fscanf(be,"%f",&tmp);
            g=(double)tmp;
         //   printf("%f\n",g);

            double v=0;
            double s=0;
            double T=0;
            bool f=true;
            int i=1;
          while(f)
            {
                if(c==15)
                {
                    f=false;
                    if(d-s>0) T+=(-v+sqrt(v*v+2*(d-s)*g))/(g);
                    fprintf(ki,"\n%f",T);
                }
                if(!(n==1))
                {
                    if(a[i].x>d)
                    {
                        //printf("itt%f %f\n ",a[i].x,d);
                        double v2=(a[i].x-a[i-1].x)/(a[i].t-a[i-1].t);
                        a[i].x=d;
                        a[i].t=a[i-1].t+(a[i].x-a[i-1].x)/v2;
                    }
                    if(v*(a[i].t-a[i-1].t)+0.5*g*(a[i].t-a[i-1].t)*(a[i].t-a[i-1].t)+s>a[i].x)
                    {
                      //  printf("ÖH: %f %f\n",(a[i].t),a[i].x);
                        s=a[i].x;
                        v=(a[i].x-a[i-1].x)/(a[i].t-a[i-1].t);
                        T+=(a[i].t-a[i-1].t);
                       // printf("1:%f %f %f\n",s,v,T);

                    }
/*                    else if(v*(a[i].t-a[i-1].t)+0.5*g*(a[i].t-a[i-1].t)*(a[i].t-a[i-1].t)+s>d)
                    {
                            f=false;
                            if(d-s>0) T+=(-v+sqrt(v*v+2*(d-s)*g))/(g);
                        //    printf("%f\n",T);
                    }*/
                    else
                    {
                      //  printf("ÖH: %f %f\n",(a[i].t),a[i].x);

                        s=v*(a[i].t-a[i-1].t)+0.5*g*(a[i].t-a[i-1].t)*(a[i].t-a[i-1].t)+s;
                        v=v+g*(a[i].t-a[i-1].t);
                        T+=(a[i].t-a[i-1].t);
                    //    printf("%f %f %f\n",s,v,T);
                    }
                }
                else a[i].x=d;
                if(a[i].x==d&&f)
                {
                    f=false;
                    if(d-s>0) T+=(-v+sqrt(v*v+2*(d-s)*g))/(g);
                    fprintf(ki,"\n%f",T);
                }

                i++;
            }
        }

        fprintf(ki,"\n");
    }
 }
