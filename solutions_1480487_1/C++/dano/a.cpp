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

int s[222];
ld ts;

int main(){
  int _cases; scanf("%d",&_cases);
  for(int _case=1;_case<=_cases;_case++){
    printf("Case #%d:",_case);
    ts = 0;
    int n;
    scanf("%d",&n);
    REP(i,n)scanf("%d",&s[i]);
    REP(i,n)ts+=s[i];
    REP(i,n){
      ld low=0,high=1;
      REP(xx,100){
        ld mid = (low+high)/2.0;
        ld pi = (ld)s[i] + mid * ts;
        ld tot=0;
        tot=mid;
        REP(j,n)
          if(i!=j){
            ld y = (pi - (ld)s[j])/ts;
            if(y>0)tot+=y;
          }
        if(tot>1)high = mid;
        else low=mid;
      }
      printf(" %.12Lf",low*(ld)100);
    }
    printf("\n");
  }
  return 0;
}
