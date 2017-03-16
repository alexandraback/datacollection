#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<set>
#include<iostream>
#include<string>
#include<sstream>
using namespace std;

vector<long long> arr;

void trytry(char tem[]){
  stringstream os;
  os << string(tem);
  long long now;
  int i;
  os >> now;
  char fff[200];
  sprintf(fff,"%lld",now*now);
  int len = strlen(fff);
  for(i=0;i<len;i++)if(fff[i]!=fff[len-i-1])break;
  if(i==len){
    arr.push_back(now*now);
  }
}

int main()
{
  char str[200];
  char tem[200];
  int i,j;
  int len;
  char t;
  int tn,z;
  long long a,b;

  for(i=1;i<=10000;i++){
    sprintf(str,"%d",i);
    len = strlen(str);
    for(j=0;j+j<len;j++){
      t = str[j];
      str[j] = str[len-j-1];
      str[len-j-1] = t;
    }
    sprintf(tem, "%d%s",i,str);
    trytry(tem);
    sprintf(tem, "%d%s",i,str+1);
    trytry(tem);
  }
  sort(arr.begin(),arr.end());
  arr.resize(unique(arr.begin(), arr.end())-arr.begin());
  scanf("%d",&tn);
  for(z=1;z<=tn;z++){
    scanf("%lld%lld",&a,&b);
    printf("Case #%d: %d\n",z,int(lower_bound(arr.begin(),arr.end(), b+1LL) - lower_bound(arr.begin(),arr.end(),a)));
  }
  return 0;
}
