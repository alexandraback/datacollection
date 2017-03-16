
    #include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
  int a,n,T[100][100],i,j,test,k,t,l,m;
     FILE* in = NULL;
     FILE* out = NULL;
 in = fopen("B-large-0.in", "r");
    out = fopen("B-large-0.out", "w");
    
   fscanf(in, "%d", &t);
   fgetc(in);
   for(a=0;a<t;a++){
    fscanf(in, "%d", &n);
                      fscanf(in, "%d", &m);
                      fgetc(in);
                      test=0;
                     // if(n==1 || m==1) goto end;
                     for(i=0;i<n;i++){
                                      for(j=0;j<m;j++){
                                      fscanf(in,"%d",&T[i][j]);
                                                       }
                                                      ;
                                      fgetc(in);
                                      }   
                                                    
                     for(i=0;i<n;i++){ 
                                      for(j=0;j<m;j++){test=0;
                                                       for(k=0;k<n;k++){if (T[i][j]<T[k][j]) test=1;
                                                                        }
                                                                        if(test==1){
                                                                                    for(l=0;l<m;l++){if (T[i][j]<T[i][l]) {test=2; 
                                                                                                    goto end;}
                                                                                                    }
                                                                                    }
                                                                        
                                                       }
                                      }            
       end: fprintf(out,"Case #%d: ",a+1);
       if(test==2){fprintf(out,"NO");}
       else{fprintf(out,"YES");}
       if(a!=t) fprintf(out,"\n");   }       
            
    fclose(in);
    fclose(out);
}
