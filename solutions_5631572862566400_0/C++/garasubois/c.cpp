#include <bits/stdc++.h>

#define INF (1 << 29)
#define rep2(i,m,n) for(int i=(int)(m);i<(int)(n);i++)
#define rep(i,n) rep2(i,0,n)
#define EPS 1e-10

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int dfs(int x, int d, vector<int> &edge, vector<int> &memo){
    if(memo[x]>=0) return d-memo[x];
    memo[x] = d;
    return dfs(edge[x],d+1,edge,memo);
}

void dfs2(int x,int d,vector<int> &edge,vector<int> &memo, vector<bool> &used, vector<bool> &visited){
    if(used[x]) {
        memo[x] = max(memo[x],d);
        return;
    }
    if(visited[x]) return;
    visited[x] = true;
    dfs2(edge[x],d+1,edge,memo,used,visited);
}

int solve(vector<int> &edge){
    int sz = edge.size();
    vector<int> memo(sz);
    int res = 0;
    rep(i,sz){
        fill(memo.begin(),memo.end(),-1);
        res = max(res,dfs(i,0,edge,memo));
    }

    int tmp=0;
    vector<bool> used(sz,false);
    rep(i,sz) if(!used[i]){
        if(i==edge[edge[i]]){
            used[i] = true;
            used[edge[i]] = true;
            tmp += 2;
        }
    }

    fill(memo.begin(),memo.end(),0);
    rep(i,sz) if(!used[i]){
        vector<bool> visited(sz,false);
        dfs2(i,0,edge,memo,used,visited);
    }
    rep(i,sz) tmp += memo[i];
    res = max(tmp,res);

    return res;
}

int main()
{
    int T;
    cin >> T;
    rep(case_num,T){
        int N;
        cin >> N;
        vector<int> edge(N);
        rep(i,N){
            cin >> edge[i];
            edge[i]--;
        }
        cout << "Case #" << case_num+1 << ": " << solve(edge) << endl;
    }
    return 0;
}

