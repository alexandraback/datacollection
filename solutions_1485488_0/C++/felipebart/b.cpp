#include <cstdio>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <cassert>

using namespace std;

const int MAXN = 100;

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

int h,m,n;
pair<int,int> grid[MAXN][MAXN];

int minimum_time(const pair<int,int>& orig, const pair<int,int>& dst, int t)
{
    //printf("  %d %d\n", orig.first, orig.second); 
    //printf("  %d %d\n", dst.first, dst.second); 
    if(dst.first - dst.second < 50)
    {
        return -1;
    }
    if(dst.first - orig.second < 50)
    {
        return -1;
    }
    if(orig.first - dst.second < 50)
    {
        return -1;
    }
    int clevel = max(0, h - t);
    
    if(dst.first - clevel >= 50) //no need to wait
    {
        if(t == 0)
        {
            return 0;
        }
        else if(clevel - orig.second >= 20)
        {
            return 10;
        }
        else
        {
            return 100;
        }
    }
    
    int wait = 50 - (dst.first - clevel);
    clevel -= wait;
    if(clevel - orig.second >= 20)
    {
        return (wait+10);
    }
    else
    {
        return (wait+100);
    }
    
    return -1;
}

int dijkstra()
{
    map<pair<int,int>,int> dist;
    set<pair<int,pair<int,int>>> queue;
    
    dist[make_pair(0,0)] = 0;
    queue.insert(make_pair(0,make_pair(0,0)));
    
    while(!queue.empty())
    {
        auto it = queue.begin();
        auto sqr = it->second;
        auto t = it->first;
        queue.erase(it);
        
        //printf("%d %d\n", sqr.first, sqr.second); 
        if((sqr.first == m-1) && (sqr.second == n-1))
        {
            return t;
        }
        
        for(int i=0;i<4;++i)
        {
            auto nxt = make_pair(sqr.first+dx[i], sqr.second+dy[i]);
            //printf("%d %d\n", nxt.first, nxt.second); 
            if(nxt.first < 0 || nxt.first >= m)
            {
                continue;
            }
            if(nxt.second < 0 || nxt.second >= n)
            {
                continue;
            }
            int dt = minimum_time(grid[sqr.first][sqr.second], grid[nxt.first][nxt.second], t);
            
            if((dt >= 0) && ((dist.find(nxt) == dist.end()) || (dist[nxt] > t+dt)))
            {
                auto it = queue.find(make_pair(dist[nxt], nxt));
                if(it != queue.end())
                {
                    queue.erase(it);
                }
                dist[nxt] = t+dt;
                queue.insert(make_pair(dist[nxt], nxt));
            }
        }
        
    }
    
    return -1;
}

int main()
{
    int t;
    scanf("%d", &t);
    for(int lp=1;lp<=t;++lp)
    {
        scanf("%d %d %d", &h, &m, &n);
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                scanf("%d", &grid[i][j].first);
            }
        }
        
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                scanf("%d", &grid[i][j].second);
            }
        }
        
        int resp = dijkstra();
        printf("Case #%d: %.1lf\n", lp, resp/10.0); 
    }
    return 0;
}