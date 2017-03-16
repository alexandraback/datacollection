#include <cstdio>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int match[2010], rev[2010], vis[2010];
int tstm, ans;
string a, b;
int s, e, n;
vector<int> edge[2020];
vector<pair<int, int> > elist;
int cnt1, cnt2;

bool dfs(int node){
    for(int i = 0; i < edge[node].size(); i++){
        if(!vis[edge[node][i]]){
            vis[edge[node][i]] = 1;
            if(rev[edge[node][i]] == -1 || (rev[edge[node][i]] != -1 && dfs(rev[edge[node][i]]))){
                match[node] = edge[node][i];
                rev[edge[node][i]] = node;
                return true;
            }
        }
    }
    return false;
}

void bip_match(){
    for(int i = 1; i <= cnt1; i++){
        for(int j = 1; j <= 2005; j++) vis[j] = 0;
        if(dfs(i)) ans++;
    }
}

int tc;

int main(){
    freopen("Cs.in", "r", stdin);
    freopen("Cs.out", "w", stdout);
    scanf("%d", &tc);
    for(tstm = 1; tstm <= tc; tstm++){
        scanf("%d", &n);
        map<string, int> mps, mpe;
        cnt1 = cnt2 = 0;
        for(int i = 0; i < n; i++){
            cin >> a >> b;
            if(mps[a]) s = mps[a]; else s = mps[a] = ++cnt1;
            if(mpe[b]) e = mpe[b]; else e = mpe[b] = ++cnt2;
            edge[s].push_back(e + n);
            edge[e + n].push_back(s);
            elist.push_back(make_pair(s, e + n));
            //printf("%d %d\n", s, e + n);
        }
        ans = 0;
        for(int i = 0; i <= 2005; i++) match[i] = rev[i] = -1;
        bip_match();
        /*
        for(int i = 0; i < elist.size(); i++){
            if(match[elist[i].first] != -1 && rev[elist[i].second] != -1) ans++;
        }*/
        printf("Case #%d: %d\n", tstm, n - (cnt1 + cnt2 - ans));
        for(int i = 0; i <= 2005; i++) vector<int>().swap(edge[i]);
        vector<pair<int, int> >().swap(elist);
    }
}
