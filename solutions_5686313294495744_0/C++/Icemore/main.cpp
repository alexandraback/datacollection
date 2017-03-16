#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <memory.h>
#include <queue>
using namespace std;

#define forn(i, n) for(int i = 0; i < (n); ++i)
#define forv(i, a) forn(i, (int)(a).size())

typedef long long lng;

const int maxn = 2020;
const int inf = 1000 * 1000 * 1000;

struct edge
{
    int to, f, c;
    int back;
};

int n;
int start, finish;

vector<edge> graph[maxn];

int get(map<string, int>& m, string& val)
{
    if (m.count(val) == 0)
    {
        size_t size = m.size();
        m[val] = size;
    }

    return m[val];
}

void add_edge(int left, int right, int c)
{
    edge first = {right, 0, c, (int)graph[right].size()};
    edge second = {left, 0, 0, (int)graph[left].size()};

    graph[left].push_back(first);
    graph[right].push_back(second);

    //std::cerr << "edge " << left << " " << right << " allow " << c << std::endl;
}


bool was[maxn];
int pred[maxn];
int edge_id[maxn];
bool increase_flow()
{
    memset(was, 0, sizeof(was));
    memset(pred, -1, sizeof(pred));

    was[start] = true;
    queue<int> q;
    q.push(start);

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();

        //cerr << "\ncur " << cur << endl;

        forv(i, graph[cur])
        {
            edge& e = graph[cur][i];

            //cerr << "edge " << i << ": to " << e.to << " flow " << e.f << " allow " << e.c << endl;

            if (!was[e.to] && (e.c - e.f > 0))
            {
                //cerr << "go " << e.to << endl;
                was[e.to] = true;
                pred[e.to] = cur;
                edge_id[e.to] = i;

                q.push(e.to);
            }
        }

        if(was[finish])
            break;
    }

    //cerr << "bfs finish" << endl;

    if(!was[finish])
        return false;

    //cerr << "path ";

    int cur = finish;
    while(pred[cur] != -1)
    {
        //cerr << cur << " ";

        int p = pred[cur];

        edge& forward = graph[p][edge_id[cur]];
        edge& backward = graph[cur][forward.back];

        forward.f++;
        backward.f--;

        cur = p;
    }

    //cerr << cur << endl;

    return true;
}

int solve_flow()
{
    int res = 0;

    while(increase_flow())
    {
        ++res;
    }

    return res;
}

void read()
{
    map<string, int> one;
    map<string, int> two;

    cin >> n;
    forn(i, n)
    {
        string first, second;
        cin >> first >> second;

        int left = get(one, first);
        int right = get(two, second);

        right += n;

        add_edge(left, right, 1);
    }

    start = 2 * n;
    finish = start + 1;

    forn(i, (int)one.size())
    {
        add_edge(start, i, graph[i].size() - 1);
    }

    forn(i, (int)two.size())
    {
        add_edge(i + n, finish, graph[i + n].size() - 1);
    }
}

int solve()
{
    read();
    int flow = solve_flow();

    return flow;
}


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0); 

    int T;
    cin >> T;
    forn(tc, T) {
        auto res = solve();

        std::cout << "Case #" << tc + 1 << ": " << res << endl;
    }
    
    return 0;
}
