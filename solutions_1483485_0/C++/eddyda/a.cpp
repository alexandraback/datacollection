#include <vector>
#include <valarray>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <sstream>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <complex>
using namespace std;

char mapping[26] = { 'y','h','e','s','o',
                     'c','v','x','d','u',
                     'i','g','l','b','k',
                     'r','z','t','n','w',
                     'j','p','f','m','a',
                     'q'};

int main()
{
  freopen("A-small-attempt0.in", "rt", stdin);
  freopen("A-small-attempt0.out", "wt", stdout);

  int T;
  string s;
  cin>>T;
  getline(cin,s);
  for (int t=1; t<=T; t++)
  {
    printf("Case #%d: ", t);
    getline(cin, s);
    for (int i=0; i<s.length(); i++)
    {
      if (s.at(i) == ' ')
        printf(" ");
      else
        printf("%c", mapping[s.at(i) - 'a']);
    }
    printf("\n");
  }
}
