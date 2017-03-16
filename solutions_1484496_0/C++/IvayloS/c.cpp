#define _CRT_SECURE_NO_DEPRECATE
#include <iostream> 
#include <string>
#include <vector>
#include <sstream>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <math.h>
#include <stack>
#include <deque>
#include <numeric>
#define all(x) x.begin(),x.end()
#define mpair make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
const ld epsylon = 1e-9;
int A[21 * 100000];
template<class T >
string to_s(const vector<T>& a,char delim = ' ')
{
  ostringstream out;
  for(int i=0;i<(int)a.size();i++)
  {
    out<<a[i];
    if(i!= (int)a.size()-1)
      out<<delim;
  }
  return out.str();
}
int main()
{
  freopen("google.in","r",stdin);
  freopen("google.out","w",stdout);
  int nt;
  cin>>nt;
  for(int it=1;it<=nt;it++)
  {
    memset(A, -1,sizeof(A));
    int n;
    cin >> n;
    vector<int> a(n);
    for (int  i =0;i<n;++i){
      cin >> a[i];
    }
    vector<int> x,y;
    for (int j=0;j<(1<<n);++j) {
      int s = 0;
      for (int k=0;k<n;++k){
        if (j &(1<<k)){
          s += a[k];
        }
      }
      if (A[s] != -1) {
        for (int k=0;k<n;++k){
          if (A[s] & (1<<k)) {
            x.push_back(a[k]);
          }
          if (j & (1 << k)) {
            y.push_back(a[k]);
          }
        }
        break;
      } else {
        A[s]= j;
      }
    }
    cout<<"Case #"<<it<<":"<<endl;
    if (x.size()) {
      cout << to_s(x) << endl;
      cout << to_s(y) << endl;
    } else {
      cout << "Impossible\n";
    }
  }
  return 0;
}
