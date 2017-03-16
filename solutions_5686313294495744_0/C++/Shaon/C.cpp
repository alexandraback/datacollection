#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds;

typedef long long LL;

typedef tree<
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update>
ordered_set;
//find_by_order
//order_of_key

#define FO(i,a,b) for (int i = (a); i < (b); i++)

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );
#define ALL(v) v.begin(),v.end()

#define X first
#define Y second
#define MP make_pair

typedef pair<int,int> pint;
typedef map<int,int> mint;

void show() {cout<<'\n';}
template<typename T,typename... Args>
void show(T a, Args... args) { cout<<a<<" "; show(args...); }
template<typename T>
void show_c(T& a) { for ( auto &x:a ){ cout<<x<<" ";}cout<<endl;  }



#define SIZE 50000

struct hopcroft_karp {

    int n1, n2;
    int matching[SIZE], dist[SIZE], Q[SIZE];
    bool used[SIZE], vis[SIZE];

    vector<int> out[SIZE];

    void ini(int _n1, int _n2) {
        n1 = _n1;
        n2 = _n2;
    }

    void addEdge(int u, int v) {
        out[u].PB( v );
    }

    void bfs() {
        fill(dist, dist + n1, -1);
        int sizeQ = 0;
        for (int u = 0; u < n1; ++u) {
            if (!used[u]) {
                Q[sizeQ++] = u;
                dist[u] = 0;
            }
        }
        for (int i = 0; i < sizeQ; i++) {
            int u1 = Q[i];
            for (int j=0;j<out[u1].size();++j){
                int u2 = matching[ out[u1][j] ];
                if (u2 >= 0 && dist[u2] < 0) {
                    dist[u2] = dist[u1] + 1;
                    Q[sizeQ++] = u2;
                }
            }
        }
    }

    bool dfs(int u1) {
        vis[u1] = true;
        for (int i=0;i<out[u1].size();++i) {
            int v = out[u1][i];
            int u2 = matching[v];
            if (u2 < 0 || !vis[u2] && dist[u2] == dist[u1] + 1 && dfs(u2)) {
                matching[v] = u1;
                used[u1] = true;
                return true;
            }
        }
        return false;
    }

    int maxMatching() {
        fill(used, used + n1, false);
        fill(matching, matching + n2, -1);
        for (int res = 0;;) {
            bfs();
            fill(vis, vis + n1, false);
            int f = 0;
            for (int u = 0; u < n1; ++u)
                if (!used[u] && dfs(u))
                    ++f;
            if (!f)
                return res;
            res += f;
        }
    }
    void clear(){
        for (int i=0;i<n1+n2;++i){
            out[i].clear();
        }
    }

}hk;

pair<string,string> str[SIZE];

int main(){

    freopen("C-small-attempt1.in","r",stdin);
    freopen("outC.out","w",stdout);

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        int n;
        scanf("%d",&n);

        map<string,int> A;
        map<string,int> B;

        FO(i,0,n){
            cin>>str[i].X>>str[i].Y;
            A[ str[i].X ];
            B[ str[i].Y ];
        }

        int a = 0;
        for ( auto &p:A ){
            p.Y = a++;
        }
        int b = 0;
        for ( auto &p:B ){
            p.Y = b++;
        }

        hk.ini(a,b);
        FO(i,0,n){
            hk.addEdge( A[ str[i].X ],B[ str[i].Y ] );
        }

        int re = hk.maxMatching();
        re = max( re , a );
        re = max( re , b );

        printf("Case #%d: %d\n",kk,n-re);

    }

    return 0;
}
