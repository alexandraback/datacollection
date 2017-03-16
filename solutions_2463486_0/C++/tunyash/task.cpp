#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <assert.h>
using namespace std;
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
const int INF = 1000000000;
const int prime = 9241;
const ld pi = acos(-1.);

string rev(string a)
{
   string b = a;
   reverse(b.begin(), b.end());
   return b;
}

string itos(ll a)
{ 
   string b = "";
   if (a == 0) return "0";
   while (a)
   {
      b.pb(char(a%10ll+'0'));
      a /= 10ll;
   }
   reverse(b.begin(), b.end());
   return b;
}

ll stoi(string s)
{
   ll ans = 0ll;
   for (int i = 0; i < (int)s.size(); i++)
      ans = ans * 10ll + (ll)(s[i] - '0');
   return ans; 
}

bool ispal(ll a)
{
    return rev(itos(a)) == itos(a);
}

ll sq1(ll a)
{
    ll c = (ll)sqrt((ld)a);
    if (c*c != a) return -1;
    return c;
}

bool isfair(ll a)
{
   if (sq1(a) == -1) return 0;
   return ispal(a) && ispal(sq1(a));
}

void solve2(int test)
{
   int a, b;
   cin >> a >> b;
   int ans = 0;
   
   for (ll i = 1; i <= b; i++)
   {
       string s = itos(i);
       for (int j = 0; j < 10; j++)
       {
           string p = s + char(j+'0') + rev(s);
         //  cerr << p << endl;
           ll u = stoi(p);
         //  cerr << u << endl;
           if (ispal(u) && ispal(u*u))
           {
              ans++;
              cout << u*u << "LL, ";
           }
       }
       ll u = stoi(s + rev(s));
         //  cerr << u << endl;
        if (ispal(u) && ispal(u*u))
        {
           ans++;
           cout << u*u << "LL, ";
        }
        if (ispal(i) && ispal(i*i))
        {
           cout << i*i << "LL, ";
           ans++;
        }
   }
   cout << endl;
   cout << "ans=" << ans << endl;
}

ll val[86] = {1LL, 4LL, 9LL, 121LL, 484LL, 10201LL, 12321LL, 14641LL, 40804LL, 44944LL, 1002001LL, 1234321LL, 4008004LL, 100020001LL, 102030201LL, 104060401LL, 121242121LL, 123454321LL, 125686521LL, 400080004LL, 404090404LL, 10000200001LL, 10221412201LL, 12102420121LL, 12345654321LL, 40000800004LL, 1000002000001LL, 1002003002001LL, 1004006004001LL, 1020304030201LL, 1022325232201LL, 1024348434201LL, 1210024200121LL, 1212225222121LL, 1214428244121LL, 1232346432321LL, 1234567654321LL, 4000008000004LL, 4004009004004LL, 100000020000001LL, 100220141022001LL, 102012040210201LL, 102234363432201LL, 121000242000121LL, 121242363242121LL, 123212464212321LL, 123456787654321LL, 400000080000004LL, 10000000200000001LL, 10002000300020001LL, 10004000600040001LL, 10020210401202001LL, 10022212521222001LL, 10024214841242001LL, 10201020402010201LL, 10203040504030201LL, 10205060806050201LL, 10221432623412201LL, 10223454745432201LL, 12100002420000121LL, 12102202520220121LL, 12104402820440121LL, 12122232623222121LL, 12124434743442121LL, 12321024642012321LL, 12323244744232321LL, 12343456865434321LL, 12345678987654321LL, 40000000800000004LL, 40004000900040004LL, 1000000002000000001LL, 1000220014100220001LL, 1002003004003002001LL, 1002223236323222001LL, 1020100204020010201LL, 1020322416142230201LL, 1022123226223212201LL, 1022345658565432201LL, 1210000024200000121LL, 1210242036302420121LL, 1212203226223022121LL, 1212445458545442121LL, 1232100246420012321LL, 1232344458544432321LL, 1234323468643234321LL, 4000000008000000004LL}; 


void solve(int test)
{
   ll a, b;
   cin >> a >> b;
   int ans = 0;
   for (int i = 0; i < 86; i++)
     if (val[i] >= a && val[i] <= b) ans++;
   cout << "Case #" << test << ": " << ans << endl;
}

int main()
{
    int t;
    cin >> t;
   /* sort(val, val + 104);
    int cnt = unique(val, val + 104) - val;
    cout << "cnt = " << cnt << endl;
    for (int i = 0; i < cnt; i++) cout << val[i] << "LL, ";
    cout << endl;   */
    for (int i = 0; i < t; i++) solve(i+1);
    return 0;
}