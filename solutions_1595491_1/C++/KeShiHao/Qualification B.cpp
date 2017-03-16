#include<stdio.h>
#include<iostream>
using namespace std;
int main(){
       int T,N,S,p,i,k,a[100],y,s,psum;
       FILE *fo,*fi;
       fi=freopen("D:\\C++\\code jam\\B-large.in", "r", stdin);
       fo=freopen("D:\\C++\\code jam\\B-large.out", "w+", stdout);
       scanf("%d",&T);
       
       for(i=0;i<T;i++)
       {	
            y=0,s=0;
            scanf("%d%d%d",&N,&S,&p);
            for(k=0;k<N;k++)
                scanf("%d",&a[k]);            
            //printf("%d %d %d ",N,S,p); 
            if(p==0)
            {
                y=N; 
            }
            else
            for(k=0;k<N;k++)
            {
               if(p>=2)
               {
                  psum=3*p;
                  if(a[k]>=psum-4)
                  {
                     if(a[k]>=psum-4&&a[k]<=psum-2||a[k]>=psum+2&&a[k]<=psum+4)
                     {  
                           if(a[k]==psum-2||(a[k]>=psum+2&&a[k]<=psum+4)) y++;
                           else
                           {
                             s++; 
                             if(s<=S) y++;
                           }
                     }
                     else y++;
                  }
               }
               else 
               {
                    
                    if(p==1)
                    {
                          psum=3*p;
                          if(a[k]>=psum-2)
                          {
                             if(a[k]>=psum+2&&a[k]<=psum+4)
                             {
                                  if((a[k]>=psum+2&&a[k]<=psum+4)) y++;
                                  else 
                                  {
                                     s++; 
                                     if(s<=S) y++;
                                   }
                             }
                             else y++;
                          }   
                    }
               }
                 
               //printf("%d ",a[k]);
            }
            //printf("\n");
            printf("Case #%d: %d",i+1,y);
            printf("\n");
       }
		fclose(fo);
		fclose(fi);
		system("pause");
		return 0;
}
