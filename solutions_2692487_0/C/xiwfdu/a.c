#include <stdio.h>

int main(){

  int t,ti;
  int d[100],n,a,i,j,k,s,smin;
  
  scanf("%d",&t);
  for(ti=0;ti<t;ti++){
    scanf("%d %d",&a,&n);
    for(i=0;i<n;i++)
        scanf("%d",&d[i]);
    
    for(i=0;i<n;i++)
      for(j=i+1;j<n;j++)
	if(d[i]>d[j]){
	  k=d[i];d[i]=d[j];d[j]=k;
	}

    smin=1000000000;
    for(j=0;j<=n;j++){
      s=0;k=a;
      for(i=0;i<j;){
	if(k<=d[i]){
	  if(k==1){
	    i++; s++;
	  }else{
	    k+=k-1; s++;
	  }
	}else{
	  k+=d[i];i++;
	}
      }
      if(s+n-j<smin)
	smin=s+n-j;
      //printf("%d ",smin);
    }
    
    printf("Case #%d: %d\n",ti+1,smin);
	
	  

  }
      
    

}

    

  
