#include <vector>
#include <list>
#include <tr1/unordered_map>
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
using namespace tr1;

typedef pair<int, int> per;
typedef vector<int>::iterator it;
typedef set<int>::iterator is;


ifstream f("input.txt");
ofstream g("output.txt");

int t,mx,mi=10,fin[4005];
unordered_map<string,int> mp;
vector<string> v[55];

void gen() {
  ofstream g("input.txt");
  srand(time(NULL));
  g<<"20\n";
  for(int j=0; j<20; ++j) {
    for(int i=0; i<50; ++i) g<<char(rand()%26+'a');
    g<<'\n';
  }

  g.close();
}

int cst(string s) {
  int greseli=(1<<30),lg=s.size();
  if(mp.find(s)==mp.end()) {
    for(int j=0; j<v[lg].size(); ++j) {
        string c=v[lg][j];
        int lst=-100,gc=0,ok=1;
        for(int k=0; k<c.size(); ++k) if(s[k]!=c[k]) {
          if(k-lst<5) {
                  ok=0;
                  break;
          }else {
                  lst=k;
                  ++gc;
          }
          if(gc>=greseli) break;
        }
        if(ok) greseli=min(greseli,gc);
    }
    if(v[lg].size()>100) mp[s]=greseli;
  }
  else greseli=mp[s];
  return greseli;
}

int main()
{
  f>>t;
  ifstream l("dict.txt");
  //gen();
  for(;!l.eof();) {
    string s;
    getline(l,s);
    mx=max(mx,(int)s.size());

    v[s.size()].push_back(s);
    if(s.size()>0)mi=min(mi,(int)s.size());
  }
  //for(int i=mi; i<=mx; ++i) cerr<<v[i].size()<<' ';
    for(int T=1;T<=t;++T) {
      g<<"Case #"<<T<<": ";
      cerr<<T<<'\n';
      string s;
      f>>s;
      for(int i=0; i<s.size(); ++i) {
        fin[i]=(1<<30);
      }

      for(int i=0; i<s.size(); ++i) {
        //cerr<<i<<' '<<mp.size()<<'\n';
        for(int lg=mi; lg<=mx && i+lg-1<s.size(); ++lg) {
          //cerr<<i<<' '<<lg<<'\n';
          string sc;
          for(int j=i; j<i+lg; ++j) sc+=s[j];

          int greseli=cst(sc);
          if(i) greseli+=fin[i-1];
          //cerr<<i<<' '<<lg<<' '<<bst[i][lg]<<'\n';
          fin[i+lg-1]=min(fin[i+lg-1],greseli);
        }
      }

      g<<fin[s.size()-1]<<"\n";
    }
    return 0;
}

