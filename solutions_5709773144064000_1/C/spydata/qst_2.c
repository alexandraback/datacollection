#include <stdio.h>
void eval(FILE *f1,double c,double f,double x,int ca)
{
     double r=2;
     double time=0;
     double t1,t2;
     while(1)
     {
            //  printf("%lf\n",time);
                               
                if((x/r)<=(c/r))
               {
                                time=time+x/r;
                            //    printf("%lf\n",time);
                                break;
                                }
                else
                {
                    t1=x/r;
                    t2=c/r;
                    if(((t1-t2)*(r+f))>=x)
                    {
                                        time=time+c/r;
                                        r=r+f;
                                        }
                                        else
                                        {
                                            time=time+x/r;
                                            break;
                                            }
                                            }
                                            }
        fprintf(f1,"Case #%d: %0.7lf\n",ca,time); 
        }
        int main()
        {
           double c,f,x;
           int t,i;
           FILE *f1,*f2;
           f1=fopen("B-large.in","r");
           f2=fopen("output2.txt","w");
           fscanf(f1,"%d",&t);
           fgetc(f1);
           for(i=1;i<=t;++i)
           {
                            fscanf(f1,"%lf %lf %lf",&c,&f,&x);
                            fgetc(f1);
                            eval(f2,c,f,x,i);
                            }
                            fclose(f1);
                            fclose(f2);
           //getchar();
           return 0;
           }                                    
