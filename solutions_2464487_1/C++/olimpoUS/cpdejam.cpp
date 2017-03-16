#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <bitset>
#include <cmath>
#include <complex>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <stdlib.h>
#include <utility>
#include <ctime>
#include <limits.h>
using namespace std;
double r;
bool Ink(long long i, long long l){
    l-= i*(2*r+1);
  return l >= 2*i*(i-1);
}
void Solve(){
    double l;
    cin >> r >> l;
    long long a = 1;
    long long b = 2000000000;
    while(a+1<b){
       long long m =(a+b)/2;
       if(Ink(m,l)) a = m;
       else b = m;
    }
  cout << a << endl;
}
int main(){
  freopen("inp.txt","r",stdin);
  freopen("outp.txt","w",stdout);
  int te;
  scanf("%d",&te);
  for(int t = 1 ; t <= te ; ++t){
     printf("Case #%d: ",t);
     Solve();
  }
  return 0;
}
