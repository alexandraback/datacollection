#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{int t,k,s,i,x,y,xe,ye;
 FILE *fin,*fout;
    
  fin=fopen ("b.in", "r");
  fout=fopen ("b.out", "w");
  fscanf(fin, "%d\n", &t);
 
 
 for(k=1;k<=t;k++){
 
  fscanf(fin,"%d %d\n",&xe,&ye);
  x=0;y=0;s=1;
  fprintf(fout,"Case #%d: ",k);
  
  if (xe>0)
 {for(i=0;i<xe;i++){             
     x=x-s;s++;
     fprintf(fout,"W");   
     x=x+s;s++;
     fprintf(fout,"E");}}
     
else for(i=0;i>xe;i--){
     x=x+s;s++;
     fprintf(fout,"E");  
     x=x-s;s++;
     fprintf(fout,"W");}
     
if (ye>0)
 {for(i=0;i<ye;i++){             
     y=y-s;s++;
     fprintf(fout,"S");;   
     y=y+s;s++;
     fprintf(fout,"N");}}
     
else for(i=0;i>ye;i--){
     y=y+s;s++;
     fprintf(fout,"N");   
     y=y-s;s++;
     fprintf(fout,"S");}
  
fprintf(fout,"\n");}
 
 
 
 
 
  fclose(fin);
  fclose(fout);
  system("PAUSE");	
  return 0;
}
