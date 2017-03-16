
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
#include <cstring>

using namespace std;

#define FOR(i,a,b) for(int i = (a) ; i < (b) ; i ++)
#define REP(i,n) FOR(i, 0, n)
#define ALL(a) (a).begin(),(a).end()
#define SZ(a) ((int)(a).size())
#define pb push_back

int main()
{
  string eng ("our language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give up");
  string goo ("ejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jv");
  string gmap("yhesocvxduiglbkrztnwjpfmaq");
  int len = eng.size();
/*
  REP(i, len)
  {
    if (gmap[i] != ' ')
      gmap[goo[i]-'a'] = eng[i];
  }
  REP(i, 26)
    cout<<gmap[i];
  cout<<endl;
*/
  string str;
  int T;
  cin>>T;
  getline(cin, str);
  REP(k, T)
  {
    //cin>>str;
    getline(cin, str);
    len = str.size();
    //cout<<str<<" "<<len<<endl;
    REP(i, len)
    {
      if (str[i] != ' ')
      {
        //cout<<str[i];
        str[i] = gmap[str[i]-'a'];
      }
    }
    cout<<"Case #"<<k+1<<": "<<str<<endl;
  }

  return 0;
}
