#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <vector>
#include <cmath>
#include <list>
#include <sstream>
#include <algorithm>
using namespace std;

typedef pair<int,int> PII;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<pair<int,int> > VPII;
typedef vector<LL> VLL;
typedef vector<pair<LL,LL> > VPLL;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;

#define PI 3.14159265358979323
#define EE 2.71828182845
#define EPS 10e-11
#define INF 10000000

inline LL MAX(LL a, LL b){ return a < b ? b : a;}
inline LL MIN(LL a, LL b){ return a < b ? a : b;}

#define FOR(i,n)      for(int i=0;i<(n);i++)
#define FORD(i,n)     for(int i=(n)-1;i>=0;i--)
#define FORR(i, a, b) for (int i = (int) (a); i <= (int) (b); ++i)
#define FORE(it, c) for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define SIZE(x) ((int) ((x).size()))

#define PB push_back
#define MP make_pair

string rot1(string s)
{
  if(s[0]=='0') cerr << "Leading zero error." << endl;  
  do
  {
    s = s.substr(1)+s[0];
  }while(s[0]=='0');
  return s;
}

string getSmallest(string s)
{
  string mins = s;
  FOR(i, s.size())
  {
    s = rot1(s);    
    if(s<mins) mins = s;
  }
  return mins;
}

int main(){
  int t;
  cin >> t;
  FOR(i,t)
  {
    unordered_map<string,int> m;
    int a,b;
    cin >> a >> b;
    FORR(j,a,b)
    {
      stringstream ss;
      ss << j;
      m[getSmallest(ss.str())]++;      
    }
    LL sum = 0;
    FORE(it,m)
      sum+=(it->second*(it->second-1))/2;
    cout << "Case #" << i+1 << ": " << sum << endl;
  } 
  return 0;
}

