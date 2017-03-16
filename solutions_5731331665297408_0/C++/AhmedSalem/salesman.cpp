#include<bits/stdc++.h>
using namespace std ;

const int MAXN = 8;

#define min(a,b) (((a) < (b)) ? (a) : (b))

struct Number{
    string num;
    Number(){}
    Number(string num):
        num(num){}
    Number operator + (const Number& that) const{
        return Number(this->num + that.num);
    }
    bool operator < (const Number& that) const{
        if (num.find('|') != -1)return 0;
        if (that.num.find('|') != -1)return 1;
        if (num.size() != that.num.size())return num.size() < that.num.size();
        return num < that.num;
    }
}oops("|");


bool flag[MAXN+5][1<<MAXN|5][2];
Number best[MAXN+5][1<<MAXN|5][2];

Number zip[MAXN+5];
vector<vector<int> > G;
int n,m;


Number solve(int u, int mask, bool first){
    if (mask == 0){
        if (first) return zip[u];
        return Number("");
    }
    Number& ret = best[u][mask][first];
    if (flag[u][mask][first])return ret;
    flag[u][mask][first] = true;
    ret = oops;
    for (int c=0;c<G[u].size();c++){
        int v = G[u][c];
        if (!(mask & (1<<v)))continue;
        ret = min(ret, solve(v,mask - (1 << v),true));
    }
    for (int newmask = mask; newmask ; newmask = (newmask - 1) & mask){
        for (int c=0;c<G[u].size();c++){
            int v = G[u][c];
            if (!(newmask & (1<<v)))continue;
            ret = min(ret, solve(v, newmask - (1 << v), true) + solve(u, mask ^ newmask, false));
        }
    }
    
    if (first)
        ret = zip[u] + ret;
    return ret;
}


int main(){
    freopen("salesman.in","r",stdin);
    freopen("salesman.out","w",stdout);
    int c,c2;
    int tests;
    scanf("%d",&tests);
    for (int test=1;test<=tests;test++){
        printf("Case #%d: ",test);
        scanf("%d%d",&n,&m);
        for (c=0;c<n;c++){
            char temp[10];
            scanf("%s",temp);
            zip[c] = Number(temp);
        }
        G.clear();
        G.resize(n);
        for (c=0;c<m;c++){
            int u,v;
            scanf("%d%d",&u,&v);
            u--;v--;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        memset(flag,0,sizeof(flag));
        Number ret = oops;
        for (c=0;c<n;c++)
            ret = min(ret, solve(c, ((1<<n)-1) - (1 << c), true ));
        printf("%s\n",ret.num.c_str());
    }
    
    return 0;
}
