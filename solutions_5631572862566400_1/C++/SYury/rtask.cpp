#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<string>
#include<cstring>
#include<cassert>
#include<ctime>
#include<vector>
#include<list>
#include<stack>
#include<deque>
#include<queue>
#include<map>
#include<utility>
#include<set>
#include<algorithm>

using namespace std;
typedef long long lint;
typedef long double ldb;

#define X first
#define Y second
#define F(i, l, r) for(auto i = l; i != r; i++)
#define Df(i, l, r) for(auto i = l; i != r; i--)
#define pb push_back
#define rs resize
#define mk make_pair
#define asg assign
#define all(x) x.begin(),x.end()
#define ret return
#define cont continue
#define brk break
#define ins insert
#define era erase

int t, n;
vector<int> b;
vector<char> was;
vector<char> intc2;
vector<list<int> > inve;
int c2s = 0;
int sz = 0;

int dfs(int v){
    was[v] = true;
    sz++;
    if(was[b[v]])
        ret b[v];
    else
        ret dfs(b[v]);
}

int dfs1(int v){
    was[v] = true;
    int curr = 1;
    F(it, inve[v].begin(), inve[v].end()){
        int u = *it;
        if(intc2[u] || was[u])
            cont;
        curr = max(curr, 1 + dfs1(u));
    }
    ret curr;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    F(g, 0, t){
        scanf("%d", &n);
        b.rs(n); was.rs(n); intc2.rs(n); inve.rs(n);
        F(i, 0, n){inve[i].clear();}
        intc2.asg(n, false);
        int ans = 0; c2s = 0;
        F(i, 0, n){
            scanf("%d", &b[i]);
            b[i]--;
            inve[b[i]].push_back(i);
        }
        F(i, 0, n){
            if(b[b[i]] == i){intc2[i] = true; c2s++;}
            was.asg(n, false);
            sz = 0;
            int cb = dfs(i);
            if(cb != i)
                cont;
            ans = max(ans, sz);
        }
        c2s = 0;
        F(i, 0, n){
            if(!intc2[i])
                cont;
            was.asg(n, false);
            int chain = dfs1(i);
            //printf("For %d chain is %d\n", i, chain);
            c2s += chain;
        }
        ans = max(ans, c2s);
        printf("Case #%d: %d\n", g + 1, ans);
    }
    ret 0;
}
