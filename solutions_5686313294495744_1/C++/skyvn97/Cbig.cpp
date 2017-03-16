#include<bits/stdc++.h>
#define MAX   1111
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
class DinicFlow {
private:
    static const int INF=(int)1e9+7;
    vector<int> dist,head,q,work;
    vector<int> point,capa,flow,next;
    int n,m;
public:
    DinicFlow() {
        n=0;m=0;
    }
    DinicFlow(int n) {
        this->n=n;m=0;
        dist.assign(n+7,0);
        head.assign(n+7,-1);
        q.assign(n+7,0);
        work.assign(n+7,0);
    }
    void addEdge(int u,int v,int c1,int c2) {
        //printf("Add %d %d %d %d\n",u,v,c1,c2);
        point.push_back(v);capa.push_back(c1);flow.push_back(0);next.push_back(head[u]);head[u]=m++;
        point.push_back(u);capa.push_back(c2);flow.push_back(0);next.push_back(head[v]);head[v]=m++;
    }
    bool bfs(int s,int t) {
        FOR(i,1,n) dist[i]=-1;
        int sz=0;
        q[sz++]=s;dist[s]=0;
        for (int x=0;x<sz;x=x+1) {
            int u=q[x];
            for (int i=head[u];i>=0;i=next[i])
                if (dist[point[i]]<0 && flow[i]<capa[i]) {
                    dist[point[i]]=dist[u]+1;
                    q[sz++]=point[i];
                }
        }
        return (dist[t]>=0);
    }
    int dfs(int s,int t,int f) {
        if (s==t) return (f);
        for (int &i=work[s];i>=0;i=next[i])
            if (dist[point[i]]==dist[s]+1 && flow[i]<capa[i]) {
                int d=dfs(point[i],t,min(f,capa[i]-flow[i]));
                if (d>0) {
                    flow[i]+=d;
                    flow[i^1]-=d;
                    return (d);
                }
            }
        return (0);
    }
    int maxFlow(int s,int t) {
        int totflow=0;
        while (bfs(s,t)) {
            FOR(i,1,n) work[i]=head[i];
            while (true) {
                int d=dfs(s,t,INF);
                if (d<=0) break;
                totflow+=d;
            }
        }
        return (totflow);
    }
};
map<string,int> strID[2];
string word[MAX][2];
int wordID[MAX][2];
int n;
void init(void) {
    REP(i,2) strID[i].clear();
    cin>>n;
    FOR(i,1,n) REP(j,2) {
        cin>>word[i][j];
        if (strID[j].find(word[i][j])==strID[j].end()) {
            int tmp=strID[j].size();
            strID[j][word[i][j]]=tmp+1;
        }
        wordID[i][j]=strID[j][word[i][j]];
    }
}
int process(void) {
    int a=strID[0].size();
    int b=strID[1].size();
    DinicFlow df(a+b+2);
    int src=a+b+1;
    int snk=a+b+2;
    FOR(i,1,a) df.addEdge(src,i,1,0);
    FOR(i,1,b) df.addEdge(a+i,snk,1,0);
    FOR(i,1,n) df.addEdge(wordID[i][0],a+wordID[i][1],1,0);
    return (n-a-b+df.maxFlow(src,snk));
}
int main(void) {
    int t; cin>>t;
    FOR(i,1,t) {
        init();
        printf("Case #%d: %d\n",i,process());
    }
    return 0;
}
