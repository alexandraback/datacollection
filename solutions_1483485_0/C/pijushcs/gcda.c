#include<stdio.h>

int main(){
    int i,k,t,n,j;
    char ch[]="yhesocvxduiglbkrztnwjpfmaq",ch1='a',st[102];
    FILE *fp,*fp1;
    fp=fopen("A-small-attempt1.in","r");
    fp1=fopen("a2.out","w");
    
    fscanf(fp,"%d%*c",&n);
    
    for(i=0;i<n;i++){
      fgets(st,102,fp);
      t=strlen(st);
      if(st[t-1]=='\n')
        t=t-1;
      for(j=0;j<t;j++){
        if(st[j]!=' '){
         k=st[j]-ch1;
         st[j]=ch[k];
        }
      }
      st[j]='\0';
      fprintf(fp1,"Case #%d: %s\n",i+1,st);
    }
    
    fclose(fp);
    fclose(fp1);
}
      
