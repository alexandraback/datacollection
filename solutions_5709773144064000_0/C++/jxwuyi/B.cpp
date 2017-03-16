#include<iostream>
#include<fstream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<ctime>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<utility>
#include<random>
#include<numeric>
#include<deque>
using namespace std;
#define LL long long

const int MaxFact = 100000002;

long double C,F,X; 
#include<ctime>
int main() {
  freopen("B.in","r",stdin);
  freopen("B.out","w",stdout);
  
  int test;scanf("%d", &test);
  //int test = 100;
  
  
  cout.setf(ios::fixed);
  cout.precision(9);
  for(int no=1;no<=test;++no){
    cin >> C >> F >> X;
    //C = 10000 - rand() % 10, F = 100, X = 100000;
    
    
    long double ans = X / 2;
    long double rat = 0;
    for(int k = 0; k < MaxFact; ++ k) {
      rat += ((long double)1.0) / (2 + k * F);
      if(C * rat > ans) break;
      ans = min(ans, rat * C + X / (2 + (k + 1) * F));
    }
    cout << "Case #"<<no<<": "<< ans << endl;
  }
  
  cerr << clock() << endl;
}
