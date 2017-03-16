#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<set>
using namespace std;
#define INF (1<<29)
#define min(x,y) (((x)<(y))?(x):(y))
#define max(x,y) (((x)>(y))?(x):(y))
#define FOR(i,x,y) for(int i=(x);i<(y);++i)
#define FOE(i,x,y) for(int i=(x);i<=(y);++i)
#define CLR(i) memset(i,0,sizeof(i))
#define ll long long

char s[100];

struct node{
    ll x;
    int pos;

    node(){}
    node(ll x,int pos):x(x),pos(pos){}
};

queue<node> q;
bool visited[1000005];

int main(){
    int T; scanf("%d",&T);
    FOE(t,1,T){
        CLR(visited);
        while (!q.empty()) q.pop();

        ll N; scanf("%lld",&N);
        q.push(node(0,0));

        int ans = 0;
        while (!q.empty()){
            node tmp = q.front(); q.pop();
            visited[tmp.x] = 1;
            if (tmp.x == N){
                ans = tmp.pos;
                break;
            }

            if (tmp.x+1 <= 1000000){
                if (!visited[tmp.x+1]){
                    if (tmp.x+1 == N){
                        ans = tmp.pos+1;
                        break;
                    }
                    visited[tmp.x+1] = 1;
                    q.push(node(tmp.x+1ll,tmp.pos+1));
                }
            }

            ll tar = 0ll, tt = tmp.x;
            while (tt > 0){
                tar = tar*10ll + tt%10ll;
                tt /= 10ll;
            }
            if (tar > 1000000) continue;
            if (!visited[tar]){
                if (tar == N){
                    ans = tmp.pos+1;
                    break;
                }
                visited[tar] = 1;
                q.push(node(tar,tmp.pos+1));
            }
        }
        printf("Case #%d: %d\n",t,ans);
    }
    return 0;
}
