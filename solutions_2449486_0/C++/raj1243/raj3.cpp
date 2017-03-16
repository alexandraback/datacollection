#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;

int main()
{
    int a[10][10],i,j,k,t,l,m,n,r[10],c[10],flag;
    scanf("%d",&t);
   int p=1;
    while(t--)
       {
			flag=0;
        
        scanf("%d %d",&m,&n);
        for(i=0;i<m;i++)
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
              
        for(i=0;i<m;i++)
        {
		  r[i]=0;
		  for(j=0;j<n;j++)
		  if(a[i][j]>r[i])
		  r[i]=a[i][j];
		  
		}
		for(i=0;i<n;i++)
        {
		  c[i]=0;
		  for(j=0;j<m;j++)
		  if(a[j][i]>c[i])
		  c[i]=a[j][i];
		  
		}

           for(i=0;i<m;i++)
         {
				  for(j=0;j<n;j++)
        {
          if(a[i][j]<r[i]&&a[i][j]<c[j])
          {cout<<"Case #"<<p<<": NO\n";
		  flag=1;break;
		  }
        
		}
    if(flag==1)break;
	  	}
		if(flag==0)
		cout<<"Case #"<<p<<": YES\n";
		p++;
   }
   return 0;
}
