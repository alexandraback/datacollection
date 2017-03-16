#include <cstdio>
#include <fstream>
#include <iostream>
#include <cmath>
#include <algorithm>

#define debug
#define _max 1010
using namespace std;
FILE *fin,*fout = NULL;

int t,N,point_war,point_dwar;
double naomi[_max],ken[_max];
int naomi_used[_max],ken_used[_max];

void re_used(){
   for(int i=0;i<N;i++){
        naomi_used[i] = 0;
        ken_used[i] = 0;
   }
}                                        
void war(){
    re_used();
    int point = 0;
    for(int i=0;i<N;i++)
      for(int j=0;j<N;j++){
        if(ken_used[j]==0 && ken[j]-naomi[i]>0.0000001){
          ken_used[j]=1; point++;
          break;
        }
    }
    point_war = N-point;
}
void de_war(){
  //re_used();
  int point = 0;
  int ken_p = 0,naomi_p=0;
  for(int i=0;i<N;i++){
        if(1.0 - ken[N-1] < 0.0000001 && naomi_p==0){
            naomi_p++;
  
        }else{
            if(naomi[naomi_p] - ken[ken_p] > 0.0000001){
              point++;
              naomi_p++;  ken_p++;
            }else naomi_p++;
        }

  }
  point_dwar = point;
}          
int main(){

    
    fout= fopen("out.txt","w");
    fin = fopen("D-small.in","r");
    
    fscanf(fin,"%d",&t);

    for(int k=1;k<=t;k++){
       fscanf(fin,"%d",&N); 

        for(int i=0;i<N;i++) fscanf(fin,"%lf",&naomi[i]); 
        for(int i=0;i<N;i++) fscanf(fin,"%lf",&ken[i]); 

        sort(naomi,naomi+N);
        sort(ken,ken+N);

        #ifdef debug1
          for(int i=0;i<N;i++) fprintf(fout,"%lf ",naomi[i]); 
          fprintf(fout,"\n");
          for(int i=0;i<N;i++) fprintf(fout,"%lf ",ken[i]); 
          fprintf(fout,"\n");
        #endif
        war();
        de_war();
        //printf("%d\n",point_dwar);
       fprintf(fout,"Case #%d: %d %d\n",k,point_dwar,point_war);
   
 
       
    }
    fclose(fin);
    fclose(fout);
    system("pause");
    return 0;
}
