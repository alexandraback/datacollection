//ultrablue/rjpt
#include<queue>
#include<stdlib.h>
#include<iostream>
#include<fstream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<map>
#include<set>
#include<cstring>
using namespace std;
#define tr(ds,it) for(typeof(ds.end()) it=ds.begin();it!=ds.end();it++)
int t;
int main(int argc,char* argv[]){
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  scanf("%d",&t);
  for(int i=1;i<=t;i++){
    int a,b;
    scanf("%d %d",&a,&b);
    float ptill[100001]={1};
    for(int j=1;j<=a;j++)
    {
      float t1;
      scanf("%f",&t1);
      ptill[j]=ptill[j-1]*t1;
    }
    float mins=999999999;
    //backspace a to 0
    for(int j=a;j>=0;j--)
    {
      float keys=b-j+1;
      keys+=a-j;
      float keys2=keys+b+1;
      keys*=ptill[j];
      keys2*=(1-ptill[j]);
      keys+=keys2;
      mins=min(mins,keys);
    }
    //enter
    mins=min(mins,2+(float)b);
    printf("Case #%d: %.6f\n",i,mins);
  }
  //system("pause");
  return 0;
}
