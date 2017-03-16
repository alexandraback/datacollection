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

ll basecache[20] = {0};

ll base (int l){
     if (basecache[l]) return basecache[l];
     if (l == 2) return 10;
     ll r = base(l - 1);

     QString s( (l ) / 2 + 1, QChar('9'));
     s[0] = '1';
     if (l % 2 == 0) s[1] = '0';
     r += s.toLongLong();

     basecache[l] = r;
     return r;
}

bool all0 (QString s){
     for (int i=0;i<s.length();i++)
          if (s[i] != '0') return false;
     return true;
}

ll large(ll xxx){
     if (xxx < 10) return xxx;
     QString s = QString::number(xxx);
     int middle = s.length() / 2;
     QString rightside = s.right( ( s.length() + 1) / 2);
     if (all0(rightside)) return large(xxx - 1) + 1;
     //01234
     QString t = s.left(middle);
     for (int i=0;i<t.length()/2;i++) {
          QChar a = t[i];
          t[i] = t[t.length()-i-1] ;
          t[t.length()-i-1] = a;
     }
     ll count = rightside.toLongLong()
              + t.toLongLong()
              + base(s.length());
     if (t.toLongLong() == 1) count --;
     return count;
}

int main(int argc, char *argv[])
{
     int T;
     scanf("%i", &T);
     forr (tt, 1, T) {
          ll n;
          scanf("%lli\n", &n);
/*
          ll * count = new ll[n+1];
          memset(count, 0, sizeof(ll) * (n+1));
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

          int last = -1;
          for (int i = 1; i<=n; i++) {
               //if (count[i] != last + 1) {
               if (count[i] != large(i)) {
                    printf("%lli: %lli %lli\n", i, count[i], large(i));
               }
               last = count[i];
          }

          int res = count[n];
*/

          printf("Case #%i: %i\n", tt, large(n));
          //printf("%i %i\n", deceiveScore, warScore);
     }
    // for (int i=3;basecache[i];i++)
    //      printf("%lli\n", basecache[i]);
}
