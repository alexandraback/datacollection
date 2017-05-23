#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
 
using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define sz size()
#define INF (int)1e9
 
typedef long long LL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector< vector <int> > VVI;
typedef pair<int,int> pii;

int a[1000];

bool isPalin(int a) {
  int y=0;
  int x = a;
  while(a) {
     y = y*10 + a%10;
     a = a/10;
  }
  if(x==y) return true;
  return false;
}

int main() {
      freopen("abc.txt","r",stdin);
      freopen("myfile.txt","w",stdout);
      int count=1;
      a[1]=count;
      
      for(int i=2; i*i <= 1000; i++) {
          int sq  = i*i;
          if(isPalin(i) && isPalin(sq)) {
             a[sq] = ++count;
          }
      } 
      
      for(int i=1; i<=1000; i++) {
         if(a[i]==0) a[i] = a[i-1];
      }
      
      int T,A,B;
      cin>>T;
      REP(i,T) {
         cin>>A>>B;
         cout<<"Case #"<<i+1<<": "<<a[B] - a[A-1]<<endl;
      }
}
