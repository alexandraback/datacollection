#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <map>
#include <utility>
#include <set>
#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;

#define CLEAR(X) memset(X,0,sizeof(X))
#define REP(i,n) for(int i=0;i<(n);i++) 
template <class T> vector<T>parse(string s,const char d=' '){
  vector<T> v; string p; s+=d; int i=0; 
  while(i<(int)s.size())
    if (s[i] == d){stringstream u; u<<p; T t; u>>t; v.push_back(t); p=""; while(i<(int)s.size() && s[i]==d)i++;} else p+=s[i++];   
  return v;
} 

typedef long long ll;
typedef long double ld;

int n, a[22];

void pr(int m){
  bool f=true;
  REP(j,n)
    if(m&(1<<j)){
      if(!f)printf(" ");
      f=false;
      printf("%d",a[j]);
    }
  printf("\n");
}

int main(){
  int _cases; scanf("%d",&_cases);
  for(int _case=1;_case<=_cases;_case++){
    printf("Case #%d:\n",_case);
    map<int, int> m;
    scanf("%d",&n);
    REP(i,n)scanf("%d",&a[i]);
    bool found=false;
    for(int i=1;i<(1<<n);i++){
      int sum=0;
      REP(j,n)
        if(i&(1<<j))sum+=a[j];
      if(m.count(sum)){
        int com = m[sum] & i;
        int one = i ^ com;
        int two = m[sum] ^ com;
        pr(one);pr(two);
        found=true;
        break;
      }
      m[sum]=i;
    }
    if(!found)printf("Impossible\n");
  }
  return 0;
}
