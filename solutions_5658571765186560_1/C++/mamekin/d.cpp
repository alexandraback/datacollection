#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <limits>
#include <climits>
#include <cfloat>
#include <functional>
using namespace std;

class UnionFindTree
{
private:
    int n;
    vector<int> parent; // 親ノード
    vector<int> rank;   // 木の高さの上限
    vector<int> num;    // グループの要素数
    int find(int i){
        if(parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }
public:
    UnionFindTree(int n0){ // コンストラクタ
        n = n0;
        parent.resize(n);
        for(int i=0; i<n; ++i)
            parent[i] = i;
        rank.assign(n, 0);
        num.assign(n, 1);
    }
    void unite(int a, int b){ // aとbのグループを併合
        if((a = find(a)) != (b = find(b))){
            if(rank[a] < rank[b]){
                parent[a] = b;
                num[b] += num[a];
            }else{
                parent[b] = a;
                if(rank[a] == rank[b])
                    ++ rank[a];
                num[a] += num[b];
            }
            -- n;
        }
    }
    bool same(int a, int b){ // aとbのグループが同じかを調べる
        return find(a) == find(b);
    }
    int getNum(){ // グループの数を返す
        return n;
    }
    int getNum(int a){ // aのグループの要素数を返す
        return num[find(a)];
    }
};

void makePolyomino(int n, vector<vector<vector<pair<int, int> > > >& p, bool isFlip = true)
{
    const int dy[] = {0, 1, 0, -1};
    const int dx[] = {1, 0, -1, 0};

    class Func
    {
    public:
        static void normalize(vector<pair<int, int> >& v)
        {
            int n = v.size();
            int y = INT_MAX;
            int x = INT_MAX;
            for(int i=0; i<n; ++i){
                y = min(y, v[i].first);
                x = min(x, v[i].second);
            }
            for(int i=0; i<n; ++i){
                v[i].first  -= y;
                v[i].second -= x;
            }
            sort(v.begin(), v.end());
        }
        static void rotate(vector<pair<int, int> >& v)
        {
            int n = v.size();
            for(int i=0; i<n; ++i){
                swap(v[i].first, v[i].second);
                v[i].first *= -1;
            }
        }
        static void flip(vector<pair<int, int> >& v)
        {
            int n = v.size();
            for(int i=0; i<n; ++i)
                v[i].first  *= -1;
        }
    };

    set<vector<pair<int, int> > > s;
    s.insert({make_pair(0, 0)});
    for(int i=1; i<n; ++i){
        set<vector<pair<int, int> > > t;
        for(const auto& v : s){
            for(int j=0; j<i; ++j){
                for(int k=0; k<4; ++k){
                    auto p = make_pair(v[j].first + dy[k], v[j].second + dx[k]);
                    if(find(v.begin(), v.end(), p) != v.end())
                        continue;

                    auto v2 = v;
                    v2.push_back(p);
                    Func::normalize(v2);
                    t.insert(v2);
                }
            }
        }

        s.clear();
        for(const auto& v : t){
            auto v2 = v;
            auto minV = v2;
            for(int a=0; a<(isFlip?2:1); ++a){
                for(int b=0; b<4; ++b){
                    Func::rotate(v2);
                    Func::normalize(v2);
                    minV = min(minV, v2);
                }
                Func::flip(v2);
            }
            s.insert(minV);
        }
    }

    p.clear();
    for(const auto& v : s){
        set<vector<pair<int, int> > > t;
        auto v2 = v;
        for(int a=0; a<(isFlip?2:1); ++a){
            for(int b=0; b<4; ++b){
                Func::rotate(v2);
                Func::normalize(v2);
                t.insert(v2);
            }
            Func::flip(v2);
        }
        p.push_back(vector<vector<pair<int, int> > >(t.begin(), t.end()));
    }
}

bool isAbleFill(int r, int c, const vector<pair<int, int> >& p)
{
    int n = p.size();
    for(int y1=0; y1<r; ++y1){
        for(int x1=0; x1<c; ++x1){
            bool ng = false;
            vector<vector<bool> > grid(r, vector<bool>(c, false));
            for(int i=0; i<n; ++i){
                int y2 = y1 + p[i].first;
                int x2 = x1 + p[i].second;
                if(y2 >= r || x2 >= c){
                    ng = true;
                    break;
                }
                grid[y2][x2] = true;
            }
            if(ng)
                continue;
            
            UnionFindTree uft(r*c);
            for(int y=0; y<r; ++y){
                for(int x=0; x<c; ++x){
                    if(y + 1 < r && !grid[y][x] && !grid[y+1][x])
                        uft.unite(y * c + x, (y + 1) * c + x);
                    if(x + 1 < c && !grid[y][x] && !grid[y][x+1])
                        uft.unite(y * c + x, y * c + (x + 1));
                }
            }

            bool ok = true;
            for(int y=0; y<r; ++y){
                for(int x=0; x<c; ++x){
                    if(!grid[y][x] && uft.getNum(y*c+x) % n != 0)
                        ok = false;
                }
            }
            if(ok)
                return true;
        }
    }
    return false;
}

bool solve(int x, int r, int c)
{
    if(x >= 7)
        return false;

    vector<vector<vector<pair<int, int> > > > p;
    makePolyomino(x, p);

    for(const auto& v : p){
        bool ng = true;
        for(unsigned i=0; i<v.size(); ++i){
            if(isAbleFill(r, c, v[i]))
                ng = false;
        }
        if(ng)
            return false;
    }

    return true;
}

int main()
{
    int T;
    cin >> T;

    for(int t=1; t<=T; ++t){
        int x, r, c;
        cin >> x >> r >> c;

        if(solve(x, r, c))
            cout << "Case #" << t << ": GABRIEL" << endl;
        else
            cout << "Case #" << t << ": RICHARD" << endl;
    }
}