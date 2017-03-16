#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    FILE *ip=fopen("input","r");
    FILE *ip2=fopen("input","r");
    
    long long int T,i, l, j,k,x,y, n, index1, index2, count, match;
    char a[200], ch;
    FILE *op=fopen("output.txt","w");
    
    fscanf(ip2,"%lld",&T);
    
    while(fscanf(ip,"%c", &ch)!=EOF)
           {
                                  
                                  if(ch=='\n')
                                  {
                                           break;
                                  }
           }
    
    for(i=1;i<=T;i++)
    {
           fscanf(ip2,"%c", &ch);
           l=0;
           while(fscanf(ip2,"%c", &ch)!=EOF)
           {
                                  
                                  if(ch==' ')
                                  {
                                           break;
                                  }
                                  l++;
           }
           
           fscanf(ip2,"%lld", &n);
           
                     
           //fscanf(ip,"%s",a);
           //printf("\n%d\n", l);
           //puts(a);
           //fscanf(ip,"%d", &n);
           //l=strlen(a);
           
           index1=l;
           index2=0;
           long long int index3=0;
           count=0;
           match=0;
           
           for(j=0;j<l;j++)
           {
                                fscanf(ip,"%c", &ch);
                                
                                if( (ch!='a') && (ch!='e') && (ch!='i') && (ch!='o') && (ch!='u') )
                                {
                                                                                        match+=1;
                                                                                        if(match==n)
                                                                                        {
                                                                                                    index1=j-n+1;
                                                                                                    index2=j;
                                                                                                    count+=(index1+1-index3)*(l-index2);
                                                                                                    //printf("\n%lld %lld %lld %lld",index1, index2, index3, count);
                                                                                                    index3=index1+1;
                                                                                                    match=match-1;
                                                                                                    
                                                                                        }
                                }
                                
                                else
                                {
                                    match=0;
                                }
           }         
           
           fprintf(op,"Case #%lld: %lld\n", i, count);
           
           while(fscanf(ip,"%c", &ch)!=EOF)
           {
                                  
                                  if(ch=='\n')
                                  {
                                           break;
                                  }
           }
           
    }
    
    //getch();
    
}
