#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define NL '\n'
#define xx first
#define yy second
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(i=j;i<=k;i++)
#define REV(i,j,k) for(i=j;i>=k;i--)
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)
#define pi 2.0*acos(0.0)
#define MOD 1000000007
#define MAX 1005

struct node{
    string x,y;
    int u, v, m;
};
node p[MAX];

class Compare{
public:
    bool operator()(node a, node b){
        if(a.m != b.m) return (a.m > b.m);
        if(max(a.u, a.v) != max(b.u, b.v)) return (a.u+a.v) > (b.u+b.v);
        return max(a.u, a.v) > max(b.u, b.v);
    }
};

priority_queue<node, vector<node>, Compare> q;
map <string, int> myMap;
int n;

int solve()
{
    int k;
    int cnt = 0;
    set <string> am, bm;
    am.clear(); bm.clear();

    //cerr << "--------";

    while(!q.empty())
    {
        node t = q.top();
        q.pop();

        if(am.find(t.x) != am.end() && bm.find(t.y) != bm.end())
            cnt++;

        //cerr << t.x << " " << t.y << NL;

        am.insert(t.x);
        bm.insert(t.y);
    }

    return cnt;
}

int main()
{
    READ("C-small-attempt2.in");
    WRITE("C-small-attempt2.out");
    std::ios_base::sync_with_stdio(0);
    int cases, caseno=0, i, j, k, cnt, sum;
    string s, t;
    map <string, int> am, bm;

    cin >> cases;

    while(cases--)
    {
        cin >> n;

        am.clear();
        bm.clear();

        while(!q.empty()) q.pop();

        for(i = 0; i < n; i++)
        {
            cin >> s >> t;
            p[i].x = s;
            p[i].y = t;
            //if(caseno == 0) cerr << s << " " << t << NL;

            if(am.find(s) == am.end())
                am[s] = 0;
            else
                am[s]++;

            if(bm.find(t) == bm.end())
                bm[t] = 0;
            else
                bm[t]++;
        }

        for(i = 0; i < n; i++)
        {
            p[i].u = am[p[i].x];
            p[i].v = bm[p[i].y];
            p[i].m = min( p[i].u, p[i].v );
            q.push(p[i]);
        }

        cnt = solve();

        cout << "Case #" << ++caseno << ": " << cnt << NL;
    }

    return 0;
}




