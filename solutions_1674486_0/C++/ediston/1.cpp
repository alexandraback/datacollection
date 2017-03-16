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
#define inf  99999999999999.9999
using namespace std;


int main()
{
    int cases ; int kase = 1;
    cin >>cases;
    while(kase<=cases)
    {
       cout << "Case #" << kase << ": " ;
       int n; int m; int node;
       vector < set<int> > adj(1000000);
       cin >> n;
       fp(i,0,n)
       {
         cin >> m;
         fp(j,0,m)
         {
            cin >> node;
            adj[i].insert(node-1);
         }
       }
       int t[1000]; queue<int> Q; bool loopfound = false;
       fp(i,0,n)
       {
         fp(j,0,n) t[j] =0;
         t[i] = 1;
         Q.push(i);
         while(!Q.empty()&&!loopfound)
         {
            int c = Q.front();
             Q.pop();
            set <int> :: iterator it;
            for(it = adj[c].begin(); it != adj[c].end(); it++)
            {
                  node = *it;
                  if(!t[node])
                  {
                     t[node] = 1;
                     Q.push(node);
                   }
                  else
                  {
                     loopfound = true;
                     break;
                  }
            }
         }
         if (loopfound) break;
       }
       if(loopfound)
                    cout << "Yes" << endl;
       else
           cout << "No" << endl;
       kase++;
       adj.clear();
    }
   return 0;
}
