#include <cstdio>
#include <set>
#include <string>
//#include <algorithm>
#include <vector>

using namespace std;
//--common
#define forr(i,f,t) for (int i = (f); i <= (t); i++)
#define fori(i,t) for (int i = 0; i < (t); i++)
#define forc(i,c) for (int i = 0; i < (c).size(); i++)
#define forit(it,c) for (auto it = (c).begin(), end = (c).end(); it != end; ++it)

template <typename C> void rerase(C& s, const typename C::const_reverse_iterator &it ) { s.erase(s.find(*it)); }
template <typename T> vector<T>& operator<<(vector<T>& v, const T& t) { v.push_back(t); return v; }
template <typename T> set<T>& operator<<(set<T>& v, const T& t) { v.insert(t); return v; }
//--end common

#include "QList"
#include "QPair"

typedef long long int ll;

ll decrot(ll i) {
     ll res = 0;
     while (i) {
          res = res * 10 + i % 10;
          i /= 10;
     }
     return res;
}

int main(int argc, char *argv[])
{
     int T;
     scanf("%i", &T);
     forr (tt, 1, T) {
          ll n;
          scanf("%lli\n", &n);

          ll count[n+1] = {0};
          QList<QPair<ll, int> > toVisit;

          count[1] = 1;
          toVisit << QPair<ll, int> (1,1);

          while (!toVisit.isEmpty()) {
               auto x = toVisit.takeFirst();
               ll c = x.first;
               ll d = c+1;
               if (d <= n && !count[d]) { count[d] = x.second + 1; toVisit << QPair<ll, int> (d, count[d]); }
               d = decrot(c);
               if (d <= n && !count[d]) { count[d] = x.second + 1; toVisit << QPair<ll, int> (d, count[d]); }
          }

          int res = count[n];


          printf("Case #%i: %i\n", tt, res);
          //printf("%i %i\n", deceiveScore, warScore);
     }
}
