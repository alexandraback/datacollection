#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<queue>
#include<set>
using namespace std;
typedef long long Int;
const Int MAXN = 1000;
int mote[MAXN];
struct QS
{
    Int index;
    Int len;
    Int A;
    Int cnt;
    QS(){}
    QS(Int in, Int l, Int a)
    {
        index = in;
        A = a;
        len = l;
        cnt = 0;
    }
    bool operator < (const QS& b) const
    {
        if(A != b.A) return A < b.A;
        if(len != b.len) return len < b.len;
        if(index != b.index) return index < b.index;
        return cnt < b.cnt;
    }
};
Int A, n;
Int bfs()
{
    queue<QS>Q;
    set<QS>vis;
    QS st(0, n - 1, A);
    Q.push(st);
    vis.insert(st);
    while(!Q.empty())
    {
        QS u = Q.front();
        Q.pop();
        //puts("here");
        //cout << "index = " << u.index << endl;
        //cout << "len = " << u.len << endl;
        //cout << "u.A = " << u.A << endl;
        //cout << mote[u.index] << endl;
        while(u.index <= u.len && u.A > mote[u.index]) {u.A += mote[u.index];u.index++;}

        if(u.index > u.len) return u.cnt;
        QS v;
        v.A = u.A;
        v.len = u.len;
        v.cnt = u.cnt + 1;
        v.index = u.index;
        v.len--;
        //cout << "len = " << v.len << endl;
        if(vis.find(v) == vis.end())
        {Q.push(v); vis.insert(v);}
        v.len++;
        v.A += v.A - 1;
        if(vis.find(v) == vis.end())
        {Q.push(v); vis.insert(v);}
        //puts("her00e");
    }
    return -1;
}
int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    int T, k = 0;
    cin >> T;
    while(T--)
    {
        cin >> A >> n;
        for(Int i = 0; i < n; ++i) cin >> mote[i];
        sort(mote, mote + n);
        cout << "Case #" << ++k << ": " << bfs() << endl;
    }
    return 0;
}
