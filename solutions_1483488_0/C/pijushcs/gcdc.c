#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    long a,b,k,c=0,ts[20];
    char in[20],tmp[20],in1[20];
    int i,t,j,tm,g,x,n,flg=0,h,q=0;
    
    
    
    FILE *fp,*fp1;
    fp=fopen("C-small-attempt1.in","r");
    fp1=fopen("a5.out","w");
    
    fscanf(fp,"%d",&t);
    
    for(i=0;i<t;i++){
      
      
        
      fscanf(fp,"%ld %ld",&a,&b);
      sprintf(in1,"%ld",b);
      c=0;
      
      for(k=a;k<=b;k++){
        sprintf(in,"%ld",k);
        n=strlen(in);
      
      q=0;
      for(h=0;h<20;h++)
        ts[h]=0;
      //fprintf(fp1,"%s %d\n",in,n);
        for(j=1;j<n;j++){
            
          if(in[j]>=in[0]&&in[j]!='0'&&in[j]<=in1[0]){
            tm=j;
            for(x=j,g=0;x<n;x++,g++)
              tmp[g]=in[x];
            for(x=0;x<tm;x++,g++)
              tmp[g]=in[x];
            tmp[g]='\0';
           // fprintf(fp1,"a:%ld\n",atol(tmp));
            if(atol(tmp)<=b&&atol(tmp)>k){
              for(h=0;h<q;h++){
               //  printf("a:%ld\n",ts[h]);
                 if(ts[h]==(atol(tmp))){
                   flg=1;
               //    printf("%ld",atol(tmp));
                   break;
                 }
                }
              if(!flg){
                c++;
                ts[q]=atol(tmp);
                q++;
             }
              flg=0;
            }
           // fprintf(fp1,"%ld->%ld c:%ld\n\n",k,atol(tmp),c);  
          }
        }
      }
      fprintf(fp1,"Case #%d: %ld\n",i+1,c);
    }
    fclose(fp);
    fclose(fp1);
}      
          
    
