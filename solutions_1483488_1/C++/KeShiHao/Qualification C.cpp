#include<stdio.h>
#include<iostream>
using namespace std;
int main(){
        int T,A,B,i,y,n,m,L,l,a[7]={0},j,e=0;
        FILE *fo,*fi;
        fi=freopen("D:\\C++\\code jam\\C-large.in", "r", stdin);
        fo=freopen("D:\\C++\\code jam\\C-large.out", "w+", stdout);
        scanf("%d",&T);
        for(i=0;i<T;i++)
        {
           y=0;
           scanf("%d%d",&A,&B);
           for(L=1;A/L!=0;L*=10);
           L=L/10;
           for(n=A;n<B;n++)
           {    
                for(j=0;j<7;j++) a[j]=0;         
                for(l=L;l!=1;l/=10)
                {                 
                    m=n/l+(n%l)*((L*10)/l);
                    if(n<m&m<=B)  
                    {
                       e=0;
                       for(j=0;a[j]!=0;j++)
                       {
                         if(a[j]==m) 
                         {
                            e=1;
                            break;
                         }
                       }
                       //printf("%d %d \n",n,m);                      
                       if(e==0) 
                       { 
                          y++;
                          a[j]=m;
                       }
                    }
                }
           }
           printf("Case #%d: %d",i+1,y);
           printf("\n");
        }       
		//fclose(fo);
		//fclose(fi);
		return 0;
}
