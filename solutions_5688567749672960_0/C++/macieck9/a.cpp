#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

bool vst[1000005];
int dist[1000005];
int n;

int reverse(int x)
{
    int y = 0;
    while(x)
    { 
        y += x%10;
        y *= 10;
        x /= 10;
    }
    return y/10;
}

int bfs(int s)
{
    queue<int> Q;
    Q.push(s);
    vst[s] = true;
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        if (u == n) return dist[u];
        if (!vst[u+1])
        {
            vst[u+1] = true;
            dist[u+1] = dist[u]+1;
            Q.push(u+1);
        }
        int w = reverse(u);
        if (!vst[w])
        {
            vst[w] = true;
            dist[w] = dist[u]+1;
            Q.push(w);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++)
    {
        cin >> n;
        cout << "Case #" << t << ": " << bfs(1)+1 << "\n";
        memset(vst,0,sizeof(vst));
        memset(dist,0,sizeof(dist));
    }
    
    
    return 0;
}
