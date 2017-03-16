#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <random>
#include <map>
#include <functional>
#include <string.h>
using namespace std;

void use_file(const std::string& s = "")
{
    if (s != "std" && s != "") {
        freopen((s+".in").c_str(), "r", stdin);
        freopen((s+".out").c_str(), "w", stdout);
    }
}

map<string, int> mpa, mpb;
vector<pair<int, int> > vp;


#define maxn 1001//表示x集合和y集合中顶点的最大个数！
 int nx,ny;//x集合和y集合中顶点的个数
 int edge[maxn][maxn];//edge[i][j]为1表示ij可以匹配
 int cx[maxn],cy[maxn];//用来记录x集合中匹配的y元素是哪个！
 int visited[maxn];//用来记录该顶点是否被访问过！
 int path(int u)
 {
     int v;
     for(v=0;v<ny;v++)
     {
         if(edge[u][v]&&!visited[v])
         {
             visited[v]=1;
            if(cy[v]==-1||path(cy[v]))//如果y集合中的v元素没有匹配或者是v已经匹配，但是从cy[v]中能够找到一条增广路
             {
                 cx[u]=v;
                 cy[v]=u;
                 return 1;
             }
         }
     }
     return 0;
 }

 int maxmatch()
 {
     int res=0;
     memset(cx,0xff,sizeof(cx));//初始值为-1表示两个集合中都没有匹配的元素！
     memset(cy,0xff,sizeof(cy));
     for(int i=0;i<=nx;i++)
     {
         if(cx[i]==-1)
         {
             memset(visited,0,sizeof(visited));
             res+=path(i);
         }
     }
     return res;
 }


int solve(int n){
    memset(edge, 0, sizeof(edge));
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < n; i++){
        edge[vp[i].first][vp[i].second] = 1;
    }
    nx = mpa.size();
    ny = mpb.size();
    return n - (nx + ny - maxmatch());
}

int main() {
    use_file("C2");
    int T, N;
    cin >> T;

    std::string a, b;
    for(int ca = 1; ca <= T; ca++){
        cin >> N;
        mpa.clear();
        mpb.clear();
        int ida = 0, idb  = 0;
        vp.clear();
        for (int i = 0; i < N; i++){
            cin >> a >> b;
            if (mpa.count(a) == 0){
                mpa[a] = ida++;
            }
            if (mpb.count(b) == 0){
                mpb[b] = idb++;
            }
            vp.push_back(make_pair(mpa[a], mpb[b]));
        }
        cout << "Case #" << ca << ": "  << solve(N) << std::endl;
    }
	return 0;
}
