#include <iostream>
#include <stdio.h>
using namespace std;
int h[3000],n;
int main() {
  FILE *in = fopen("/Users/Basun/Downloads/B-small-attempt1.in.txt","r");
  FILE *out = fopen("/Users/Basun/Desktop/ansb.txt","w");
  int t,T,i,n_21,temp;
  fscanf(in,"%d",&T);
  for(t=1;t<=T;t++) {
    memset(h, 0, sizeof(h));
    fscanf(in,"%d",&n);
    n_21 = n*(n*2-1);
    for(i=0;i<n_21;i++){
      fscanf(in,"%d",&temp);
      h[temp]++;
    }
    fprintf(out,"Case #%d: ",t);
    for(i=1;i<=2500;i++)
      if(h[i]%2==1)
        fprintf(out,"%d ",i);
    fprintf(out,"\n");
  }
  return 0;
}
