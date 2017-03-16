#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int v[1500];
int h[1500];
int f[1500];
int n;
vector<int> nxt[1500];
void dfs(int b,int height, int &bheight){
    h[b] = height;
    bheight = max(bheight, height);
    for (int i = 0; i < nxt[b].size(); ++i){
        if (h[nxt[b][i]] != -1) continue;
        dfs(nxt[b][i], height + 1, bheight);
    }
}
int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t, tt;
    scanf("%d", &tt);
    for (int t = 0; t < tt; ++t){
        scanf("%d", &n);
        //cout<<n<<endl;
        for (int i = 0; i < n; ++i)
            nxt[i].clear();
        for (int i = 0; i < n; ++i){
            scanf("%d", &f[i]);
            --f[i];
            nxt[f[i]].push_back(i);
        }
        int kd = 0;
        int cycle = 0;
        memset(v, 0, sizeof(v));
        memset(h, 255, sizeof(h));
        for (int i = 0; i < n; ++i){
            if (h[i] == -1){
                int b = i;
                while (!v[b]){
                    v[b] = 1;
                    b = f[b];
                }
                int e = b;
                int c = 0;
                do{
                    ++c;
                    h[e] = 0;
                    e = f[e];
                }while (e != b);
                e = b;
                int height = 0;
                do {
                    int ht = 0;
                    dfs(e, 0, ht);
                    height += ht;
                    e = f[e];
                }while (e != b);
                //if (c == 1) cout<<"xxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
                //cout<<i<<' '<<height<<' '<<c<<endl;
                if (c <= 2) kd += c + height;
                else cycle = max(cycle, c);
            }
        }
        printf("Case #%d: %d\n", t + 1, max(kd, cycle));
    }
}
