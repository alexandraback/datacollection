#include<cstdio>
#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<numeric>
#include<cmath>
using namespace std;

#define ALL(t) t.begin(),t.end()
#define FOR(i,n) for (int i=0;i<(int)(n);i++)
#define FOREACH(i,t) for (typeof(t.begin())i=t.begin();i!=t.end();i++)
typedef vector<int> vi;
typedef long long int64;

int main(){
  int c;
  scanf("%d",&c);
  for(int cc=1;cc<=c;cc++){
    int A,B,K;
    scanf("%d %d %d",&A,&B,&K);
    long long res=0;
    for(int i=0;i<A;i++)for(int j=0;j<B;j++)res+=(i&j)<K;
    printf("Case #%d: %lld\n",cc,res);
  }
}
