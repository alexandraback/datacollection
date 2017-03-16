#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

int main()
{
  FILE *ifp,*ofp;
  char s[1010];
  string str;
  int t,smax;
  ofp=fopen("A-small-result.in","w");
  if((ifp=fopen("A-small-attempt1.in","r"))!=NULL){
    fscanf(ifp,"%d",&t);
    for(int i=0;i<t;i++){
      fscanf(ifp,"%d",&smax);
      fscanf(ifp,"%s",s);
      int tmp=0;
      int sum=0;
      int cnt=0;
      str=string(s);
      for(int j=0;j<str.size();j++){
        tmp=0;
        if(j>sum){
          cnt+=(j-sum);
          tmp=j-sum;
        }
        sum+=(int)(str[j]-'0')+tmp;
      }
      fprintf(ofp,"Case #%d: %d\n",i+1,cnt);
      printf("Case #%d: %d\n",i+1,cnt);
    
    }
  }
  fclose(ifp);
  fclose(ofp);
}
