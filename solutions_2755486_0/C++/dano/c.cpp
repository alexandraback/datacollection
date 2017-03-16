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

int wall[2000];
int get(int ind) {return wall[ind+1000];}
void sset(int ind, int val){wall[ind+1000] = max(wall[ind+1000],val);}

struct att {
  int day, from, to, str;
};

bool cmp(const att& a, const att& b){
  return a.day < b.day;
}

int main(){
  int _cases; scanf("%d",&_cases);
  for(int _case=1;_case<=_cases;_case++){
    REP(i,2000)wall[i]=0;
    printf("Case #%d:",_case);
    int n;scanf("%d",&n);
    vector<att> a;
    REP(i,n){
      int d0,days,w,e,s,deltad,deltap,deltas;
      scanf("%d%d%d%d%d%d%d%d",&d0,&days,&w,&e,&s,&deltad,&deltap,&deltas);
      REP(i,days) {
        att na;
        na.day = d0 + deltad * i;
        na.from = 2*(w + deltap * i);
        na.to = 2*(e + deltap * i);
        na.str = s + deltas * i;
        a.push_back(na);
      }
      sort(a.begin(),a.end(),cmp);
    }
    int res = 0;
    int ind = 0;
    while (ind < (int)a.size()) {
      int from = ind;
      int cd = a[ind].day;

      while (ind < (int)a.size() && a[ind].day == cd) {
        for (int i = a[ind].from; i <= a[ind].to; i++)
          if (get(i) < a[ind].str) {res++; break;}
        ind++;
      }
      ind = from;
      while (ind < (int)a.size() && a[ind].day == cd) {
        for (int i = a[ind].from; i <= a[ind].to; i++)
          sset(i,a[ind].str);
        ind++;
      }

    }
    printf(" %d\n",res);

  }
  return 0;
}
