#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define ERROR 9999999
FILE* fp,*fp2;

int j,p,s,k;
int tmp;
int sum;


int main()  
{

    int i,j,k,m,tmp,t;
    int jj,pp,ss;

    fp=fopen("A-small-practice.in","r");
    fp2=fopen("A-small-practice.out","w");
    fscanf(fp,"%d",&t);
    for(m=0;m<t;m++)
    {   

        fprintf(fp2, "Case #%d: ",m+1);
        fscanf(fp,"%d %d %d %d",&j,&p,&s,&k);
        if (s==1) 
        {
            sum=j*p;
            fprintf(fp2, "%d\n",sum);
            for(jj=1;jj<=j;jj++)
                for(pp=1;pp<=p;pp++)
                {
                    fprintf(fp2, "%d %d %d\n",jj,pp,1 );
                }
            continue;
        }
        if (s==2)
        {
            sum=j*p;
            if (k>=2) sum*=2;
            fprintf(fp2, "%d\n",sum);
            for(jj=1;jj<=j;jj++)
                for(pp=1;pp<=p;pp++)
                {
                    fprintf(fp2, "%d %d %d\n",jj,pp,1 );
                    if(k>=2)     fprintf(fp2, "%d %d %d\n",jj,pp,2 );
                }
            continue;
        }
        if (s==3)
        {
            if(k==1) sum=j*p;
            if (k==2)  sum=j*p*2;
            if (k>=3)  sum=j*p*3;
            fprintf(fp2, "%d\n",sum);
            if (k==1)
                for(jj=1;jj<=j;jj++)
                    for(pp=1;pp<=p;pp++)
                    {
                        fprintf(fp2, "%d %d %d\n",jj,pp,1 );
                    }
            if (k==2)
                for(jj=1;jj<=j;jj++)
                    for(pp=1;pp<=p;pp++)
                    {
                        fprintf(fp2, "%d %d %d\n",jj,pp,1 );
                        fprintf(fp2, "%d %d %d\n",jj,pp,2 );
                    }
            if (k>=3)
                for(jj=1;jj<=j;jj++)
                    for(pp=1;pp<=p;pp++)
                    {
                        fprintf(fp2, "%d %d %d\n",jj,pp,1 );
                        fprintf(fp2, "%d %d %d\n",jj,pp,2 );
                        fprintf(fp2, "%d %d %d\n",jj,pp,3 );
                    }
            continue;
        }



        fprintf(fp2,"\n");

    }   
    fclose(fp);
    fclose(fp2);
    return 0;
}
