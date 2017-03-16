#include <bits/stdc++.h>

#define in freopen("C-small-attempt0.in", "r", stdin);
#define out freopen("output.txt", "w", stdout);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define infinity (1 << 28)
#define LL long long
#define PI acos(-1)
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a)*((b)/gcd(a,b)))
#define all(v) v.begin(), v.end()
#define no_of_ones __builtin_popcount // __builtin_popcountll for LL
#define SZ(v) (int)(v.size())
#define eps 1e-7

//int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
//int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
//int col[4] = {1, 0, -1, 0};
//int row[4] = {0, 1, 0, -1};
//int months[13] = {0, ,31,28,31,30,31,30,31,31,30,31,30,31};

using namespace std;

struct point{int x, y; point () {} point(int a, int b) {x = a, y = b;}};
template <class T> T sqr(T a){return a * a;}
template <class T> T power(T n, T p) { T res = 1; for(int i = 0; i < p; i++) res *= n; return res;}
template <class T> double getdist(T a, T b){return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));}    // distance between a and b
template <class T> T extract(string s, T ret) {stringstream ss(s); ss >> ret; return ret;}
template <class T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}
LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}
struct fast{fast(){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}}cincout;

#define MAX 1010
/*************************Forget the risk, take the fall*If it's what u want, it's worth it all*************************/
int adj[MAX];
int color[MAX];

void dfs(int u)
{
    if(color[u])
        return;
    color[u] = 1;
    dfs(adj[u]);
}

bool ok(int mask, int n)
{
    vector <int> arr;
    int i;
    for(i = 0; i < n; i++)
    {
        if(mask & (1<<i))
            arr.pb(i);
    }
    do{
        for(i = 0; i < SZ(arr); i++)
        {
            int nxt = (i+1)%SZ(arr);
            int pre = (i-1+SZ(arr))%SZ(arr);
            if(adj[arr[i]] == arr[pre] || adj[arr[i]] == arr[nxt])
                continue;
            break;
        }
        if(i == SZ(arr))
            return true;
    }while(next_permutation(all(arr)));
    return false;
}

int main()
{
    #ifdef Evan
        in;
        out;
    #endif
    int test, kase = 1, i, x, n, j;
    cin >> test;
    while(test--)
    {
        cin >> n;
        for(i = 0; i < n; i++)
        {
            cin >> x;
            adj[i] = x-1;
        }
        int res = 0;
        for(i = 0; i < (1<<n); i++)
        {
            clr(color, 0);
            for(j = 0; j < n; j++)
                if(i & (1<<j))
                    dfs(j);
            for(j = 0; j < n; j++)
                if((i & (1<<j) == 0) && color[j])
                    break;
            if(j == n && ok(i, n))
                res = max(res, no_of_ones(i));
        }
        cout << "Case #" << kase++ << ": " << res << "\n";
        cerr << "Case #" << kase-1 << ": " << res << "\n";
    }
    return 0;
}
