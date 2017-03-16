#include<stdio.h>
#include<stdlib.h>

 int a[1001],b[1001];
 int n;

int find(int j){

 int i=0;
 int c;
 c=0;
 for(i=1;i<=n;i++){
     if(b[i]== -1)
          c++;
 }
 if(c==n)
    return -2;

 for(i=1;i<=n;i++){
    if((b[i]!= -1) && (b[i] <= j)){
        if(a[i] != -1){
        b[i]= -1;
         a[i]= -1;
         return 2;
        }
    }
 }
 for(i=1;i<=n;i++){
    if((b[i]!= -1) && (b[i] <= j)){
        if(a[i] == -1){
        b[i]= -1;
         return 1;
        }
    }
 }
 int maxb=0,maxin=0;
 for(i=1;i<=n;i++){
    if((a[i]!= -1) && (a[i] <= j)){
       if(!maxb){
          maxb=b[i];
          maxin=i;
       }
       else if(maxb < b[i]){
          maxb=b[i];
          maxin=i;
       }
    }
 }

 if(maxb){
   a[maxin]=-1;
   return 1;
 }

  return -1;


  
}

int main ()
{

 FILE *fin,*fout;
 float p[3];
 int x;
 int i=0,j=0;
 int T,at=0;

 fin= fopen("in.txt","r");
 fout= fopen("out.txt","w");

 fscanf(fin,"%d",&T);
 int c=1;
 while(c<=T){
   fscanf(fin,"%d",&n);
   i=1;
   while(i<=n){
   fscanf(fin,"%d %d",&a[i],&b[i]);
   i++;
   }
   
   j=0;
   x=0;
   at=0;
   while((x=find(j))!= -2){
      if(x== -1)
          break;
      j+=x;
      at++;
   }
   if(x!=-1)
     fprintf(fout,"Case #%d: %d\n",c,at);
   else
     fprintf(fout,"Case #%d: Too Bad\n",c);

   c++;
 }
fclose(fin);
fclose(fout);
return 0;

}
