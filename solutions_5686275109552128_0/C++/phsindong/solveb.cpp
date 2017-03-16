#include<iostream>
#include<cstdio>
#include<string>
#include<vector>

using namespace std;

int main()
{
  FILE *ifp,*ofp;
  int t,d,p;
  vector<int> data;
  int dmax,ret,retmin;
  ofp=fopen("B-small-result.in","w");
  if((ifp=fopen("B-small-attempt0.in","r"))!=NULL){
    fscanf(ifp,"%d",&t);
    for(int i=0;i<t;i++){
      dmax=ret=0;
      retmin=1000000000;
      data.clear();
      fscanf(ifp,"%d",&d);
      for(int j=0;j<d;j++){
        fscanf(ifp,"%d",&p);
        data.push_back(p);
        if(dmax<p) dmax=p;
      }
      for(int j=1;j<=dmax;j++){
        ret=j;
        for(int k=0;k<data.size();k++){
          if(data[k]>j){
            if(data[k]%j==0){
             ret+=data[k]/j-1;
            }else{ 
              ret+=data[k]/j;
            }
          }
        }
        retmin=min(retmin,ret);
      }
      fprintf(ofp,"Case #%d: %d\n",i+1,retmin);
      printf("Case #%d: %d\n",i+1,retmin);
    
    }
  }
  fclose(ifp);
  fclose(ofp);
}
