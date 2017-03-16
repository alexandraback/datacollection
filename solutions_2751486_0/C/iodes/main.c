#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{int t,k,n,i,l,j,m,z;
 char s[100];
 FILE *fin,*fout;
    
  fin=fopen ("a.in", "r");
  fout=fopen ("a.out", "w");
  fscanf(fin, "%d\n", &t);
 
 
 for(k=1;k<=t;k++){
  fscanf(fin,"%s %d\n",&s,&n);
  z=0;
  i=0;
  while (s[i] != '\0'){
        switch (s[i]){
               case 'a':s[i]='a';break;
               case 'e':s[i]='a';break;
               case 'i':s[i]='a';break;
               case 'o':s[i]='a';break;
               case 'u':s[i]='a';break;
               default:s[i]='b';break;
        }i++;
        }
  l=i;
  
  for (i=0;i<=(l-n);i++)
  { m=0;j=i-1;
    while((m<n)&&(j<l))
    {j++;if (s[j]=='b') {m++;} 
     else{m=0;}}
      z=z+l-j;
      }      
  
  
  
  
  
  
  
  
  
fprintf(fout,"Case #%d: %d ",k,z);fprintf(fout,"\n");}
 
 
 
 
 
  fclose(fin);
  fclose(fout);
  system("PAUSE");	
  return 0;
}
