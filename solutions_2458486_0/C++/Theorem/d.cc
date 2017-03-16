
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <map>
#include <list>
#include <set>
#include <queue>
using namespace std;

struct chest {
    int type;
    std::list<int> keys;
};

struct board {
  int k, n;
  chest chests[20];
  std::list<int> keys;
};

std::list<int> next (const board& b, int s)
{
    int keys[200];
    std::list<int> states;

    memset(keys, 0, sizeof keys);
    for (int x : b.keys) keys[x]++;

    for (int i = 0; i < b.n; ++i)
        if ((s & (1 << i)) != 0) {
            keys[b.chests[i].type]--;
            for (int x : b.chests[i].keys) keys[x]++;
        }

    for (int i = 0; i < b.n; ++i)
        if ((s & (1 << i)) == 0) {
            if (keys[b.chests[i].type] > 0) states.push_back(s | (1<<i));
        }

    return states;
}

int unpow2 (unsigned int v)
{
    static const unsigned int b[] = {0xAAAAAAAA, 0xCCCCCCCC, 0xF0F0F0F0,
                                     0xFF00FF00, 0xFFFF0000};
                                     register unsigned int r = (v & b[0]) != 0;
                                     for (unsigned int i = 4; i > 0; i--) // unroll for speed...
                                     {
                                           r |= ((v & b[i]) != 0) << i;
                                     }
    return r;
}

void solve (int CASE)
{
    board b;
    cin >> b.k >> b.n;

    for (int i = 0; i < b.k; ++i) {
        int t;
        cin >> t;
        b.keys.push_back(t);
    }

    for (int i = 0; i < b.n; ++i) {
        int k;
        cin >> b.chests[i].type;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            int t;
            cin >> t;
            b.chests[i].keys.push_back(t);
        }
    }

    std::queue<int> q;
    std::set<int> visited;
    std::map<int, int> previous;
    q.push(0);
    int final = (1<<b.n)-1;

    while (!q.empty()) {
        int s = q.front(); q.pop();

        if (s == final) {
            std::list<int> steps;
            while (s != 0) {
                int p = previous[s];
                steps.push_front(unpow2(p^s));
                s=p;
            }

            printf("Case #%d:", CASE);
            for (int x : steps) printf(" %d", x+1);
            puts("");
            return;
        }

        for (int n : next(b, s)) {
            if (visited.find(n) == visited.end()) {
                visited.insert(n);
                previous[n] = s;
                q.push(n);
            }
        }
    }



    printf("Case #%d: IMPOSSIBLE\n", CASE);
}

int main ()
{
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) solve(i);
  return 0;
}

