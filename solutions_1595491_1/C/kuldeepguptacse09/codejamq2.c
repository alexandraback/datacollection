#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#define f(i,n) for(i=0;i<n;i++)
#define fa(i,a,n) for(i=a;i<n;i++)
#define in(n) scanf("%d",&n)
#define MOD  1000000009ll
int main()
{
//freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);
    int t,i,j,n,k,m,s,p,a[105],l;
    in(t);
    j=1;
    while(j<=t){
    int count=0,k=0;
    in(n);in(s);in(p);
    f(i,n){in(a[i]);if(a[i]>=2&&a[i]<=28)k++;} 
    
    //printf("** %d %d %d\n",n,s,p);
    int f[105][2]={0},v[105]={0};
    f(i,n){
           int st=(int)(a[i]/3)-2;
           //intf("%d\n",st);
           st=st>=0?st:0;
          
           int max,b1,c1,fs=0,fp=0;
           for(k=st;k<=st+5&&k<=10;k++)
           {for(l=k;l<=st+5&&l<=10;l++)if((l-k<=2)){
                                 c1=a[i]-k-l;
                                 if(c1>=0&&c1<=10&&abs(c1-k)<=2&&abs(c1-l)<=2)
                                 {
                                       max=c1>l?c1:l;
                                       
                                       if(max>=p){
                                               // printf("%d %d %d %d\n",a[i],k,l,c1);
                                                  if(abs(c1-k)<=1&&abs(c1-l)<=1&&abs(l-k)<=1){f[i][0]=1;}
                                       if((abs(c1-k)==2||abs(c1-l)==2||abs(l-k)==1)&&s){f[i][1]=1;} }                               
                                                                      }
                                 }}
                                
          
           
           }
           f(i,n){if(s&&f[i][0]==0&&f[i][1]==1&&v[i]==0){s--;count++;v[i]=1;}}
                    if(s)f(i,n){if(s&&f[i][0]==1&&f[i][1]==1&&v[i]==0){s--;count++;v[i]=1;}}
                     f(i,n){if(f[i][0]==1&&v[i]==0){count++;v[i]=1;}}
                     
          end:  printf("Case #%d: %d\n",j,count);
           
    j++;}
    return 0;}
