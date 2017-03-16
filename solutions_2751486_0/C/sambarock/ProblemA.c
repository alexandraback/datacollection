#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    FILE *ip=fopen("input","r");
    int T,i, l, j,k,x,y, n, index1, index2, count, match;
    char a[200];
    FILE *op=fopen("output.txt","w");
    
    fscanf(ip,"%d",&T);
    
    for(i=1;i<=T;i++)
    {
           fscanf(ip,"%s",a);
           //printf("\n");
           //puts(a);
           fscanf(ip,"%d", &n);
           l=strlen(a);
           
           index1=l;
           index2=0;
           int index3=0;
           count=0;
           match=0;
           
           for(j=0;j<l;j++)
           {
                                
                                if( (a[j]!='a') && (a[j]!='e') && (a[j]!='i') && (a[j]!='o') && (a[j]!='u') )
                                {
                                                                                        match+=1;
                                                                                        if(match==n)
                                                                                        {
                                                                                                    index1=j-n+1;
                                                                                                    index2=j;
                                                                                                    count+=(index1+1-index3)*(l-index2);
                                                                                                    //printf("\n%d %d %d %d",index1, index2, index3, count);
                                                                                                    index3=index1+1;
                                                                                                    match=match-1;
                                                                                                    
                                                                                        }
                                }
                                
                                else
                                {
                                    match=0;
                                }
           }         
           
           fprintf(op,"Case #%d: %d\n", i, count);
    }
    
    //getch();
    
}
