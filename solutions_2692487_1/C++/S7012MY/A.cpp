#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define x first
#define y second
#define LL long long
#define MOD 1000000007
using namespace std;

typedef pair<int, int> per;
typedef vector<int>::iterator it;
typedef set<int>::iterator is;


ifstream f("input.txt");
ofstream g("output.txt");

int t,a,n,v[105];

int main()
{
  f>>t;
    for(int T=1;T<=t;++T) {
      g<<"Case #"<<T<<": ";
      f>>a>>n;
      for(int i=0; i<n; ++i) f>>v[i];
      sort(v,v+n);
      int rez=(1<<30);
      for(int j=0; j<=n; ++j) {
        int sc=a,rc=0,nop=j;
        for(int i=0; i<n; ++i)
          if(v[i]<sc) sc+=v[i];
          else if(v[i]>=sc) {
            for(;v[i]>=sc && nop;--nop,++rc,sc+=(sc-1));
            if(v[i]>=sc) ++rc;
            else sc+=v[i];
          }
        rez=min(rez,rc);

      }

      g<<rez<<"\n";
    }
    return 0;
}
