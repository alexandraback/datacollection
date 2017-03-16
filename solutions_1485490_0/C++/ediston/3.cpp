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
#include <string>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
//---------- macros ----------
#define fp(i,a,b) for(int i=a; i<b; i++)
#define fm(i,a,b) for(int i=a; i>b; i--)
#define inf  99999999999999ll
using namespace std;

vector < pair <int , long long> > ba(100);
vector < pair <int , long long> > ta(100);
long long maxc;
long n, m;

void maxcomb(int b, int t, long long tot, string str)
{
     //cout << endl<< str << b << "," << t << "," << tot ;
     //str = str + "--";
     if(t==m || b==n)
     {
         maxc = max(maxc, tot);
         return;
     }
     int btype = ba[b].first;
     int ttype = ta[t].first;
     if(btype == ttype)
     {
        long long nb =  ba[b].second;
        long long nt =  ta[t].second;
        //cout <<" - "<< nb << " " << nt << " ";
        if(nb==nt)
        {
            maxcomb(b+1, t+1, tot+nb, str);
        }
        else if (nb>nt)
        {
            ba[b].second = ba[b].second - nt;
            maxcomb(b, t+1, tot+nt, str);
            ba[b].second = ba[b].second + nt;
        }
        else
        {
            ta[t].second = ta[t].second - nb;
            maxcomb(b+1, t, tot+nb, str);
            ta[t].second = ta[t].second + nb;
        }
     }
     else
     {
     maxcomb(b+1,t,tot, str);
     maxcomb(b,t+1,tot, str);
     }
     //maxcomb(b+1,t+1,tot, str);
}

int main()
{
    int cases ; int kase = 1;
    cin >>cases;
    while(kase<=cases)
    {
       cout << "Case #" << kase << ": " ;
       ba.clear();
       maxc = 0;
       ta.clear();
       cin >> n >> m;
       int type; long long num;
       fp(i,0,n)
       {
         cin >> num >> type;
         ba.push_back( pair<int, long long> (type, num) );
       }
       fp(i,0,m)
       {
         cin >> num >> type;
         ta.push_back(  pair<int, long long> (type, num) );
       }
       maxcomb(0,0,0, "");
       cout << maxc << endl;
       kase++;
    }
   return 0;
}
