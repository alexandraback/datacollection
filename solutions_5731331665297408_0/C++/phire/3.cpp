#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <map>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>

#define foreach(i,v) for(typeof(v.end())i=v.begin();i!=v.end();++i) 

typedef std::vector< std::string > VS;
typedef std::vector<int> VI;
typedef long long ll;

using namespace std;

struct ZIP
{
    string s;
    int oldi;

    ZIP(const string& s, int oldi) :
        s(s), oldi(oldi)
    {

    }
};

bool operator < (const ZIP& left, const ZIP& right)
{
    return left.s < right.s;
}

int N;
vector<ZIP> zips;
vector< VI > edges;
int vis[16];
int stack[16];

unsigned int bcur;
unsigned int bans;

void setb(unsigned int *p, int i, unsigned int v)
{
    (*p) &= ~(7U << (29 - i * 3));
    (*p) |= (v << (29 - i * 3));
}

unsigned
int getb(unsigned int x, int i)
{
    return (x >> (29 - i*3)) & 7;
}
 
bool dfs(int c, int i, int depth)
{
    bool ret;
    assert(depth < 16);
    assert(i <= N);
    if (depth == 0) {
        assert(c == -1);
        if (i != N)
            return false;
        if (bcur < bans)
            bans = bcur;
        return true;
    }
    vis[c]++;
    {
        char _stack[sizeof(stack)];
        unsigned int _bcur = bcur;
        memcpy(_stack, stack, sizeof(stack));
        ret = dfs(stack[depth - 1], i, depth - 1);
        memcpy(stack, _stack, sizeof(stack));
        bcur = _bcur;
    }
    foreach(it, edges[c]) {
        if (!vis[*it]) {
            setb(&bcur, i, *it);
            //cur[i] = *it;
            stack[depth] = c;
            if (dfs(*it, i+1, depth + 1))
                ret = true;
        }
    }
    vis[c]--;
    return ret;
}

bool dfs()
{
    bans = (unsigned int)-1;
    bcur = 0;
    for (int i = 0; i < N; i++) {
        setb(&bcur, 0, i);
        //cur[0] = i;
        stack[0] = -1;
        if (dfs(i, 1, 1))
            return true;
    }
    return false;
}

int remap(int x)
{
    for (int i = 0; i < zips.size(); i++)
        if (zips[i].oldi == x)
            return i;
    assert(0);
}

string unmap(int x)
{
    return zips[x].s;
}

int main(int argc, const char* argv[])
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int M;
        cin >> N >> M;
        zips.clear();
        edges.clear();
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < N; i++) {
            string s;
            cin >> s;
            zips.push_back(ZIP(s, i+1));
            edges.push_back(VI());
        }

        sort(zips.begin(), zips.end());
        for (int j = 0; j < M; j++) {
            int x, y;
            cin >> x >> y;
            x = remap(x); y = remap(y);
            edges[x].push_back(y);
            edges[y].push_back(x);
        }
        assert(dfs());

        cout << "Case #" << t << ": ";

        for (int i = 0; i < N; i++) {
            cout << unmap(getb(bans, i));
        }
        cout << endl;
    }
    return 0;
}
