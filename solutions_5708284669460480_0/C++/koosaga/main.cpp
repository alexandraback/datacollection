#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <queue>
using namespace std;

set<char> st;
queue<int> q;
char s1[105], s2[105];
int k,l,s;

int trie[105][26], fail[105], piv, vis[105], term[105];
int dp1[105][105], dp2[105][105];
double dp3[105][105];
int maxmatch(int pos, int pt){
    if(pos == s) return term[pt];
    if(~dp1[pos][pt]) return dp1[pos][pt];
    int ret = 0;
    for (int i=0; i<k; i++) {
        int new_pt = pt;
        while (new_pt && !trie[new_pt][s1[i] - 'A']) {
            new_pt = fail[new_pt];
        }
        new_pt = trie[new_pt][s1[i] - 'A'];
        ret = max(ret,maxmatch(pos+1,new_pt));
    }
    if(term[pt]) ret++;
    return dp1[pos][pt] = ret;
}

double tradmatch(int pos, int pt){
    if(pos == s) return term[pt];
    if(dp2[pos][pt]) return dp3[pos][pt];
    double ret = 0;
    for (int i=0; i<k; i++) {
        int new_pt = pt;
        while (new_pt && !trie[new_pt][s1[i] - 'A']) {
            new_pt = fail[new_pt];
        }
        new_pt = trie[new_pt][s1[i] - 'A'];
        ret += tradmatch(pos+1,new_pt) * 1.0 / k;
    }
    if(term[pt]) ret+=1;
    dp2[pos][pt] = 1;
    return dp3[pos][pt] = ret;
}

void solve(){
    scanf("%d %d %d %s %s",&k,&l,&s,s1,s2);
    int p = 0;
    memset(trie,0,sizeof(trie));
    memset(fail,0,sizeof(fail));
    memset(vis,0,sizeof(vis));
    memset(term,0,sizeof(term));
    memset(dp1,-1,sizeof(dp1));
    memset(dp2,0,sizeof(dp2));
    piv = 0;
    for (int i=0; i<l; i++) {
        if(!trie[p][s2[i] - 'A']){
            trie[p][s2[i] - 'A'] = ++piv;
        }
        p = trie[p][s2[i] - 'A'];
    }
    term[p] = 1;
    q.push(0);
    vis[0] = 1;
    while (!q.empty()) {
        int qf = q.front();
        q.pop();
        for (int i=0; i<26; i++) {
            if(trie[qf][i] && !vis[trie[qf][i]]){
                vis[trie[qf][i]] = 1;
                q.push(trie[qf][i]);
                if(qf == 0){
                    fail[trie[qf][i]] = 0;
                    continue;
                }
                int pos = fail[qf];
                while (pos && trie[pos][i] == 0) {
                    pos = fail[pos];
                }
                pos = trie[pos][i];
                fail[trie[qf][i]] = pos;
            }
        }
    }
    printf("%lf\n",maxmatch(0,0) - tradmatch(0,0));
}

int main(){
    freopen("B-small-attempt0.in","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for (int i=1; i<=t; i++) {
        printf("Case #%d: ",i);
        solve();
        puts("");
    }
}