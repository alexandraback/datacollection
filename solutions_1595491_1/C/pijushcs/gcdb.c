#include<stdio.h>

int main(){
    int t,s,p,x[101],k,sm,i,j,c,n;
    
    FILE *fp,*fp1;
    fp=fopen("B-large.in","r");
    fp1=fopen("a4.out","w");
    
    fscanf(fp,"%d",&t);
    
    for(i=0;i<t;i++){
      c=0;
      fscanf(fp,"%d %d %d",&n,&s,&p);
      if(p>1){
       k=p+(p-2)*2;
       sm=p+(p-1)*2;
      }
      else k=sm=p;
      for(j=0;j<n;j++){
        fscanf(fp,"%d",&x[j]);  
        if(s&&x[j]>=k&&x[j]<=(k+1)){
          c++;
          s--;
        }
        else if(x[j]>=sm)
          c++;
      }
      fprintf(fp1,"Case #%d: %d\n",i+1,c);
    }
    fclose(fp);
    fclose(fp1);
    
}
          
        
      
      
      
