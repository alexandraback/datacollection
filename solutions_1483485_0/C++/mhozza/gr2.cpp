#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <set>
#include <map>
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

//string s1 = "abcdefghijklmnopqrstuvwxyz";
string m =    "yhesocvxduiglbkr?tnwjpfma?";
string m2 =   "ynficwlbkuomxsev?pdrjgtha?";

int main(){  
    string s,s2;
    getline(cin,s);
    getline(cin,s2);
    FOR(i,s.size())
    {
      if(s[i]>='a' && s[i]<='z')
      {
        int ind = s[i]-'a';
        m[ind]=s2[i];
        ind = s2[i]-'a';
        m2[ind]=s[i];
      }
    }
    cout << m << endl << m2 << endl;  
    return 0;
}

