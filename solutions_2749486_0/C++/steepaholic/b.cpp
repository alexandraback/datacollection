#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <utility>
#include <vector>

using namespace std;

struct key
{
    short x, y, leap;
    bool operator<(const key & rhs) const
    {
        if(x != rhs.x) return x < rhs.x;
        if(y != rhs.y) return y < rhs.y;
        return leap < rhs.leap;
    }
};

struct predecessor
{
    predecessor() {} 
    predecessor(char d_, key p_)
        : dir(d_), pred(p_) {}
    
    char dir;
    key pred;
};

struct Node
{
    key n, e, s, w;
    predecessor pred;
};

map<key, Node> plane;

key construct(short x, short y, short leap, predecessor pred)
{
    key k;
    k.x = x;
    k.y = y;
    k.leap = leap;
    if(leap > 25) return k;
    
    std::pair<std::map<key, Node>::iterator, bool> it = plane.insert(make_pair(k, Node()));
    if(!it.second)
    {
        // there's no way this will lead to a shorter path
        return k;
    }
    Node &n = it.first->second;
    
    n.n = construct(x, y + leap, leap+1, predecessor('N', k));
    n.e = construct(x + leap, y, leap+1, predecessor('E', k));
    n.s = construct(x, y - leap, leap+1, predecessor('S', k));
    n.w = construct(x - leap, y, leap+1, predecessor('W', k));
    n.pred = pred;
    return k;
}

void testcase(int tst)
{
    key k;
    cin >> k.x >> k.y;
    k.leap = 0;
    
    std::map<key, Node>::iterator it = plane.lower_bound(k);
    if(it != plane.end() && it->first.x == k.x && it->first.y == k.y)
    {
        std::stringstream path;
        path << it->second.pred.dir;
        std::map<key, Node>::iterator kt = plane.find(it->second.pred.pred);
        while(kt != plane.end() && kt->second.pred.dir != 'O')
        {
            path << kt->second.pred.dir;
            kt = plane.find(kt->second.pred.pred);
        }
        std::string spath(path.str());
        reverse(spath.begin(), spath.end());
        cout << "Case #" << tst << ": " << spath << endl;
    }
}

int main()
{
    key orig;
    orig.x = 0;
    orig.y = 0;
    orig.leap = 0;
    construct(0, 0, 1, predecessor('O', orig));
    
    int T;
    cin >> T;
    for(int t = 1; t <= T; ++t)
    {
        testcase(t);
    }
    return 0;
}
