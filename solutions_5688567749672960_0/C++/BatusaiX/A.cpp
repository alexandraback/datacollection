#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <deque>
#include <numeric>
#include <iterator>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <climits>
#include <sys/time.h>

using namespace std;

#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }

typedef long long llong;

const int MAXN = 1000002;
int dis[MAXN];

llong reverse(llong n)
{
    llong res = 0;
    llong x = n;
    while(x > 0)
    {
        llong d = x % 10;
        x /= 10LL;
        res = res * 10LL + d;
    }
    return res;
}

int bfs(llong n)
{
    queue<llong> Q;
    Q.push(1LL);
    dis[1] = 1;
    while(!Q.empty())
    {
        llong x = Q.front();
        Q.pop();
        if(x == n)
        {
            return dis[(int)x];
        }
        
        llong nxt1 = reverse(x);
        llong nxt2 = x + 1;
        
        if(nxt1 <= MAXN && dis[(int)nxt1] == -1) 
        {
            Q.push(nxt1);
            dis[(int)nxt1] = dis[(int)x] + 1;
        }
        if(nxt2 <= MAXN && dis[(int)nxt2] == -1) 
        {
            Q.push(nxt2);
            dis[(int)nxt2] = dis[(int)x] + 1;
        }
    }
    return -1;
}



int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   
   int TC, n;
   cin >> TC;
   for(int tc = 1; tc <= TC; ++tc)
   {
       memset(dis, -1, sizeof(dis));
       cin >> n;
       cout << "Case #" << tc << ": " << bfs(n) << endl;
   }
   
   return 0;
}
