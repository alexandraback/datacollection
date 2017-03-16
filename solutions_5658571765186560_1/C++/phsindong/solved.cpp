#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

int main()
{
  FILE *ifp,*ofp;
  char ga[]="GABRIEL";
  char ri[]="RICHARD";
  char *ret;
  int t,x,r,c;
  ofp=fopen("D-large-result.in","w");
  if((ifp=fopen("D-large.in","r"))!=NULL){
    fscanf(ifp,"%d",&t);
    for(int i=0;i<t;i++){
      ret=ga;
      fscanf(ifp,"%d",&x);
      fscanf(ifp,"%d",&r);
      fscanf(ifp,"%d",&c);
      if(!((r*c)%x==0)){
        ret=ri;
      }
      else{
        if((r*c)/x==2&&x>3) ret=ri;
        if(x>4&&min(r,c)==2) ret=ri;
        if(min(r,c)>2&&x>6) ret=ri;
        for(int j=1;j<21;j++){
          if(max(r,c)==j&&x>j) ret=ri;
        } 
        for(int j=1;j<21;j++){
          if(min(r,c)==j&&x>=(2*(j+1)-1)) ret=ri;
        }
      }
      fprintf(ofp,"Case #%d: %s\n",i+1,ret);
      printf("Case #%d: %s\n",i+1,ret);
    
    }
  }
  fclose(ifp);
  fclose(ofp);
}
