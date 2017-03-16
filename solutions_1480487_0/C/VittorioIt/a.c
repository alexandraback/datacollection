#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

FILE *x;
FILE *y;

double votes[200];
double ans[200];

void solve()
{
     int i,j,trovato;
     double sum=0,sum2,media,N,cont;
    fscanf(x,"%lf",&N);
    
    cont=N;
    
    for(i=0;i<N;i++)
    {
                    fscanf(x,"%lf",&votes[i]);
                    sum=sum+votes[i];
    }
    media=2*sum/N;
    
    sum2=sum;
    
    do
    {   
        trovato=0; 
        for(i=0;i<N;i++)
        if(votes[i]>media)
        {
        sum2=sum2-votes[i];
        cont--;
        votes[i]=-1;
        trovato=1;
        }
        
        media=(sum+sum2)/cont;
        }while(trovato);
    
    
    for(i=0;i<N;i++)
    {
                    if(votes[i]==-1)
                    ans[i]=0;
                    else
                    ans[i]=100*(media-votes[i])/sum;       
    }
    
    for(i=0;i<N;i++)
    if(ans[i]<0)
    ans[i]=0;
    
    for(i=0;i<N;i++)
    fprintf(y,"%.6lf ",ans[i]);
    
    fprintf(y,"\n");
    
}

int main()
{
    int i,T;
    x=fopen("input.txt","r");
    //x=fopen("-small-attempt0.in","r");
    //x=fopen("-large.in","r");
    y=fopen("output.txt","w");
    fscanf(x,"%d",&T);
    for(i=1;i<=T;i++)
    {
                     
                     fprintf(y,"Case #%d: ",i);
                     solve();
                     
    }
    fclose(x);
    fclose(y);
    return 0;
}
