// program a
#include <bits/stdc++.h>
using namespace std;

#define MA 1005
#define ll long long
ll n;
ll ans;
struct Node{
    int dist;
    int value;
};
bool vis[1000005];
ll bfs(ll tar){
    memset(vis, 0, sizeof(vis));
    queue<Node> que;
    Node node;
    node.value = 1;
    node.dist = 1;
    que.push(node);
    vis[1] = 1;
    while (!que.empty()){
        Node no = que.front();
        que.pop();
        //vis[no.value] = 1;
        if (no.value == tar)
            return no.dist;
        Node n1;
        n1.dist = no.dist + 1;
        n1.value = no.value + 1;
        if (!vis[n1.value]){
            que.push(n1);
            vis[n1.value] = 1;
        }

        Node n2;
        n2.dist = no.dist + 1;
        int re = 0;
        int t = no.value;
        while (t){
            int x = t % 10;
            t /= 10;
            re = re * 10 + x;
        }
        n2.value = re;
        if (n2.value > tar)
            continue;
        if (!vis[n2.value]){
            //n2.value = re;
            que.push(n2);
            vis[n2.value] = 1;
        }

    }
    return -1;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    //std::cout << "Hello, Worsadld!\n";
    freopen("A-large.in", "r", stdin);
    freopen("data.out", "w", stdout);
    //ifstream fin = ifstream("/Users/momo/Desktop/userProfile/user_profile1.txt");
    //cout << bfs(124001) << endl;
    int cas;
    cin >> cas;
    int cc = 0;
    while (cc++ < cas){
        ans = 0;
        cin >> n;
        int count = 0;
        if (n < 1000){
            int ans = bfs(n);

        }
        ll t = n;
        while (t){
            count ++;
            t /= 10;
        }
        ll jz = 1;
        for (int i = 0; i < count - 2; ++i)
            jz *= 10;
        ll ans = 0;

        while (n){
            if (n < 1000){
                ans += bfs(n);
                break;
            }
            ll t = n / jz * jz;
            ans += n - (t + 1);
            ans ++;
            if (t+1 < 1000){
                ans += bfs(t+1);
                break;
            }
            n = t + 1;

            ll re = 0;
            t = n;
            while (t){
                int x = t % 10;
                t /= 10;
                re = re * 10 + x;
            }
            n = re;
            jz /= 10;
            n -= 100;
            ans += 100;

            //int top2 = n /
        }
        //cout << ans << endl;
        //cout << n << endl;
        /*
        while (n){
            if (n % 10 == 0){
                ans++;
                --n;
            }else{
                ll re = 0;
                ll t = n;
                while (t){
                    int x = t % 10;
                    t /= 10;
                    re = re * 10 + x;
                }
                ans++;
                if (re < n)
                    n = re;
                else
                    --n;
            }
        }*/
        cout << "Case #" << cc <<": ";
        cout << bfs(n) << endl;

    }

    return 0;
}


