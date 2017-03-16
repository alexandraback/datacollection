#include <cstdio>
#include <fstream>
#include <iostream>

#include <set>
#include <map>
#include <queue>
#include <deque>
#include <cmath>
#include <vector>
#include <bitset>
#include <string>
#include <cstring>
#include <algorithm>

#include <ctime>
#include <cstdlib>
#include <cassert>

#define pb push_back
#define mp make_pair
#define sz(A) (int) (A).size()

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define eputs(A) fputs((A), stderr)

#define sqr(A) ((A) * (A))
#define x first
#define y second
  
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair <int, int> pii;
typedef pair <int, int> point;

const int N = (int) 501;

int t;
map <point, int> dp[N];
map <point, point> last[N];
queue <pair <point, int> > q;
point res;
string s;

char get (point a, point b)
{
    if (a.x == b.x) {
        if (a.y < b.y)
            return 'N';
        else
            return 'S';
    }
    else if (a.x < b.x)
        return 'E';
    else
        return 'W';
}

void makeAns (point v, int num)
{
    if (!num)
        return;

    point l = last[num][v];
    makeAns(l, num - 1);
    s += get(l, v);
}

void add (int num, point v, int val, point l)
{
    dp[num][v] = val;
    last[num][v] = l;
    q.push(mp(v, num));
} 

int main () 
{
    #ifdef DEBUG
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
    #endif
    
    scanf("%d", &t);

    for (int T = 0; T < t; T++) {
        s = "";
        for (int i = 0; i < N; i++)
            dp[i].clear(), last[i].clear();
        while (sz(q))
            q.pop();

        scanf("%d%d", &res.x, &res.y);

        add(0, point(0, 0), 0, point(0, 0));
        int ans = 0;        
        while (true) {
            point pos = q.front().first;
            int num = q.front().second;
            q.pop();

            if (pos == res) {
                cerr << num << endl;
                ans = num;
                break;
            }

            int delta = num + 1;

            for (int dx = -1; dx < 2; dx++)
                for (int dy = -1; dy < 2; dy++) 
                    if (abs(dx) + abs(dy) == 1) {
                        point next = point(pos.x + delta * dx, pos.y + dy * delta);                    
                        
                        if (!dp[delta].count(next))
                            add(delta, next, delta, pos); 
                    }
        }

        makeAns(res, ans);
        
        printf("Case #%d: %s\n", T + 1, s.c_str()); 
    }
        

    return 0; 
}

