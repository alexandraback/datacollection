#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<string>
using std::vector;
using std::fill;
using std::min;
using std::map;
using std::queue;
using std::string;
typedef long long LL;
const LL oo = 1ll<<60; // > sum of |cap|
const int scal_max = 1<<30; // > |max cap|
struct edge{
    int to, rev;
    int cap, flo;
    edge(){}
    edge(int t, int r, int c):
        to(t), rev(r), cap(c){}
};

struct maxflow{
	int lev[10001], nxt[10001];
	vector<edge> G[10001];
    int N, S, T;
    LL flow;
    maxflow(int N, int S=0, int T=-1):
        N(N), S(S), T(T<0?N+T:T){
        flow = 0;
        for(int i=0; i<=N; i++)
            G[i].clear();
    }
    void addedge(int A, int B, int C, int D){
        G[A].push_back(edge(B, G[B].size(), C));
        G[B].push_back(edge(A, G[A].size()-1, D));
    }
    void flood(){
    	for(LL r=1;r;){
    		BFS(r);
    		fill(nxt,nxt+N,0);
    		LL get=DFS(S,oo);
    		if(!get) r>>=1;
    		else flow+=get;
    	}
    }
    bool BFS(int r){
        fill(lev,lev+N,-1);
        queue<int> q;
        lev[S]=0, q.push(S);
        while(q.size()){
            int i=q.front();
            q.pop();
            for(int j=0; j<G[i].size(); j++)
                if(G[i][j].cap>=r && lev[G[i][j].to]==-1)
                    lev[G[i][j].to]=lev[i]+1, q.push(G[i][j].to);
        }
        return lev[T]!=-1;
    }
    LL DFS(int i, LL rem){
        if(i == T)
            return rem;
        LL all = rem;
        for(int j=nxt[i]; j<G[i].size(); j++, nxt[i]++){
            if(G[i][j].cap==0 || lev[i]>=lev[G[i][j].to])
                continue;
            LL add = DFS(G[i][j].to, min(rem, (LL)G[i][j].cap));
            G[i][j].cap-=add;
            G[G[i][j].to][G[i][j].rev].cap+=add;
            if(!(rem-=add)) break;
        }
        return all-rem;
    }
};
char s[100001];
int main(){
	int T,TN;
	scanf("%d",&TN);
	for(T=1;T<=TN;T++){
		map<string,int> mp1,mp2;
		vector<std::pair<int,int> > v;
		int i,j,k,n;
		scanf("%d",&n);
		for(i=0;i<n;i++){
			char s[100001];
			string a,b;
			scanf("%s",s);
			a=s;
			scanf("%s",s);
			b=s;
			k=mp1.size();
			if(!mp1[a])mp1[a]=k+1;
			k=mp2.size();
			if(!mp2[b])mp2[b]=k+1;
			v.push_back(std::make_pair(mp1[a]-1,mp2[b]-1));
		}
		maxflow mf(mp1.size()+mp2.size()+2);
		for(i=0;i<mp1.size();i++){
			mf.addedge(mf.S, 1+i, 1, 0);
		}
		for(i=0;i<n;i++){
			mf.addedge(1+v[i].first, 1+mp1.size()+v[i].second, 1, 0);
		}
		for(i=0;i<mp2.size();i++){
			mf.addedge(1+mp1.size()+i, mf.T, 1, 0);
		}
		mf.flood();
		printf("Case #%d: %lld\n",T,n-(mp1.size()+mp2.size()-mf.flow));
	}
}
