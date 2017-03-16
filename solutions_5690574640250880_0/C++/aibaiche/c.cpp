#include <cstdio>
#include <fstream>
#include <iostream>
#define debug
#define _max 55
using namespace std;
FILE *fin,*fout = NULL;

int t,r,c,m,a,b,aa,bb;

                                         
void print(){
    if(r*c==m+1){
      for(int p=1;p<=r;p++){
          for(int q=1;q<=c;q++){
            if(p==1&&q==1) fprintf(fout,"%c",'c');
            else fprintf(fout,"%c",'*');
          }
          fprintf(fout,"\n");
        }
        
      return;
    }
    if(r==1){
      for(int i=1;i<=c;i++)
        if(i==1) fprintf(fout,"%c",'c');
        else if(i <= c - m)  fprintf(fout,"%c",'.');
        else fprintf(fout,"%c",'*');
        fprintf(fout,"\n");
    }else if(c==1){
        for(int i=1;i<=r;i++)
        if(i==1) fprintf(fout,"%c\n",'c');
        else if(i <= r - m)  fprintf(fout,"%c\n",'.');
        else fprintf(fout,"%c\n",'*');

    }else{
      // both biger than two

      int nonB = r*c - m;
      for(a=2;a<=r;a++)
        for(b=2;b<=c;b++)
          for(aa=0;aa+a<=r;aa++)
            for(bb=0;bb+b<=c;bb++){
              if(a*b + a * bb + b*aa == nonB){
                //print
                  for(int p=1;p<=r;p++){
                    for(int q=1;q<=c;q++){
                      if(p==1&&q==1) fprintf(fout,"%c",'c');
                      else if(p<=a && q<=b+bb) fprintf(fout,"%c",'.');
                      else if(p<=a+aa && q<=b) fprintf(fout,"%c",'.');
                      else fprintf(fout,"%c",'*');
                    }
                    fprintf(fout,"\n");
                  }
                  
                return;
              }else if(aa>0 && bb>0 && (a*b + a * bb + b*aa <nonB)&& (a*b + a * bb + b*aa + (bb-1)*(aa-1)>=nonB ) ){
                      int tem = nonB - a*b - a * bb - b*aa;
                      //fprintf(fout,"   %d %d %d %d\n",a,b,aa ,bb);
                       //print
                      for(int p=1;p<=r;p++){
                        for(int q=1;q<=c;q++){
                          if(p==1&&q==1) fprintf(fout,"%c",'c') ;
                          else if(p<=a && q<=b+bb) fprintf(fout,"%c",'.');
                          else if(p<=a+aa && q<=b) fprintf(fout,"%c",'.');
                          else if(p>a&&p<aa+a&&q>b&&q<b+bb){
                                if(tem>0){ fprintf(fout,"%c",'.'); tem--;}
                                else fprintf(fout,"%c",'*');
                          }
                          else fprintf(fout,"%c",'*');
                        }
                        fprintf(fout,"\n");
                      }
                      
                    return;
              }
            }
      fprintf(fout,"Impossible\n");
    }
}  
          
int main(){

    
    fout= fopen("out.txt","w");
    fin = fopen("C-small.in","r");
    
    fscanf(fin,"%d",&t);

    for(int k=1;k<=t;k++){
       fscanf(fin,"%d%d%d",&r,&c,&m); 
      //scanf("%d%d%d",&r,&c,&m);
       fprintf(fout,"Case #%d:\n",k);
       if(r*c==m) cout<<"@";
      // fprintf(fout,"Case #%d: %d %d %d\n",k,r,c,m);
   
      print();
       
    }
    fclose(fin);
    fclose(fout);
    system("pause");
    return 0;
}
