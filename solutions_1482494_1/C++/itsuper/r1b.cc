#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <fstream>
#include <algorithm>
using namespace std;

std::ifstream input;

std:: ofstream output;
struct node {
  int idx;
  int v;
} a[2020],b[2020];
int c[2020];

bool cmp( const node& A, const node& B) {
  return A.v < B.v;
}
bool select(int&  cur, int & best, int n,int* use) {
  
 
  int i;
  for (i = n-1; i >=0; --i) {
    if (use[b[i].idx] == 0 && cur >= c[b[i].idx] ) {
      best = best + 1;
      use[ b[i].idx] = 1;
      cur += 1;
      return true;
    }
  }
  return false;
}
void Work(int tcase) {
  int n;
  input>>n;
  int i;
  for (i = 0;i<n;++i) {
    input>>a[i].v>>b[i].v;
    a[i].idx = i;
    b[i].idx = i;
    c[i] = a[i].v;
  }
  sort(a, a + n,cmp);
  sort(b, b + n,cmp);
  bool flag = true;
  int ib =0;
  int cur = 0;
  int best = 0;
  int use[1020];
  memset(use,0,sizeof(use));
  while( true) {
    if ( ib == n)
      break;
    if ( cur < b[ib].v) {
      if (select(cur,best,n,use) ) {
      
      } else {
        flag = false;
        break;
      }
    } else {
      cur += 2 - use[b[ib].idx];
      use[b[ib].idx] = 1;
      ++ib;
      ++best;
    }
  }
  if ( flag == false ) {
    output<<"Case #"<<tcase<<": Too Bad"<<endl;
  } else {
    output<<"Case #"<<tcase<<": "<<best<<endl;
  }
}

int main() {
  int t = 0;
  input.open("input.in");
  output.open("output.out");
  input>>t;
  int tcase = 0;
  while (t --) {
    ++tcase;
    Work(tcase);
  }
}
