//
// Created by e5430 on 2016/5/1.
//


#include <vector>
#include <iostream>
#include <string>
#include <c++/cstring>
#include <math.h>
#include <stdlib.h>
#include <c++/map>

using namespace std;
typedef map<string, int> C;
typedef multimap<string, string> V;

map<int, int> c;
int f(int x)
{
    if(c.find(x) != c.end())
        return c[x];
    int t =0;
    for(int i =1; i < x; ++i)
    {
        t += f(i);
    }
    c[x] = t;
    return t;
}
void g(std::vector< std::vector<int> >& b, int s, int e, int& n)
{
    b[s][e] = 1;
    n= n-1;
    if(n ==0)
    {
        return;
    }
    for(int i =s  + 1; n >0 && i < e; ++i)
    {
        b[s][i] =1;
        g(b, i, e, n);
    }
}
void solve() {
    int x, n;
    cin >> x >> n;
    int total = f(x -1);
    if(total < n)
    {
        cout << "IMPOSSIBLE\n";
        return;
    }
    cout << "POSSIBLE\n";
    std::vector< std::vector<int> > b;
    b.resize(x);
    for(int i =0; i < x;++i)
    {
        b[i].resize(x);
    }
    g(b, 0 , x -1, n);
    for(int i =0; i < x;++i)
    {
        for(int j =0; j < x ;++j)
        {
            cout << b[i][j];
        }
        cout << "\n";
    }
}
int main() {
    int r;
    cin >> r;
    c.insert(make_pair(1, 1));
    for(int i =0; i < r;++i)
    {
        std::cout << "Case #" << i +1 << ": ";
        solve();
    }
    return 0;
}