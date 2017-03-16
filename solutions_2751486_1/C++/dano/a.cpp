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

bool cons(char c) {
  return !(c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
}

char s[1000100];

int main(){
  int _cases; scanf("%d",&_cases);
  for(int _case=1;_case<=_cases;_case++){
    printf("Case #%d:",_case);
    ll n;
    scanf("%s%lld",s,&n);

    ll from=0,to=0,res=0;
    ll len = strlen(s);
    ll cnt = 0;
    while (s[from]) {
      while(s[to] && cnt < n) {
        if (cons(s[to]))cnt++;
        else cnt=0;
        to++;
      }
      if (cnt == n) {
        res += len - to + 1LL;
        from++;
        cnt = min(cnt,to-from);
      } else break;
    }

    printf(" %lld\n",res);

  }
  return 0;
}
