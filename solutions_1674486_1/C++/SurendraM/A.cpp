/*	SURENDRA KUMAR MEENA	*/
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <queue>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;
typedef long long int LL;
#define ALL(s) (s).begin(),(s).end()
#define R(i,m,n)	for(int i=m;i>=n;i--)
#define FF(i,m,n)	for(int i=m;i<n;i++)
#define F(i,n)	FF(i,0,n)
#define VI vector<int>
#define PB push_back
#define CLR(s,v) memset(s,v,sizeof(s))
string to_str(LL x){ ostringstream o;o<<x;return o.str();}
LL to_int(string s){ istringstream st(s); LL i;	st>>i;return i;}
#define FR(it,t) for(typeof(t.begin()) it=t.begin(); it!=t.end(); ++it)
typedef pair<int,int> PI;
#define MP(x,y) make_pair(x,y)
#define f first
#define s second
#define VP vector<PI>
#define S(t)	scanf("%d",&t)

const int mx=1010;
int Set[mx];
int Rank[mx];

void INIT(){
	for(int i=0;i<mx;i++)	Set[i]=i;
	memset(Rank,0,sizeof(Rank));
}

int Find_Set(int x){ return Set[x]==x? x:Set[x]=Find_Set(Set[x]);}
void Union_Set(int u,int v){
	if(Find_Set(u)==Find_Set(v))	return;
	u=Find_Set(u); v=Find_Set(v);
    Set[u] = v;
}

bool isNotInSeq(vector< set<int> >& par, vector< set<int> >& ch, int a,int b) {
    return (par[a].find(b)==par[a].end() && par[b].find(a)==par[b].end());
}

bool used[1010];

bool fn(vector< VI > &v, int& n) {
    F(i,n) {
        CLR(used,0);
        F(j,v[i].size()) {
            queue<int> q;
            q.push(v[i][j]-1);
            while(!q.empty()) {
                int k = q.front(); q.pop();
                if(used[k]) return true;
                used[k]=1;
                F(r,v[k].size()) {
                    q.push(v[k][r]-1);
                }
            }
        }
    }
    return false;
}

int main(){
    int t;
    cin>>t;
    FF(kase,1,t+1){
        cout<<"Case #"<<kase<<": ";
        INIT();
        int n;
        cin>>n;
        vector< VI > v(n);
        vector< set<int> > par(n), ch(n);
        F(i,n) {
            int k;
            cin>>k;
            F(j,k) {
                int r;
                cin>>r;
                Union_Set(i+1, r);
                v[i].PB(r);
                par[i].insert(r-1);
                ch[r-1].insert(i);
/*                FR(it, par[r-1]) {
                    FR(it2, ch[i]) {
                        par[*it2].insert(*it);
                        ch[*it].insert(*it2);
                    }
                }*/
            }
        }
        bool ok=false;
/*        F(i,n) {
            F(j,v[i].size()) {
                FF(k,j+1,v[i].size()) {
                    if(Find_Set(v[i][j]) == Find_Set(v[i][k])) {// && isNotInSeq(par,ch,v[i][j],v[i][k])){
                        ok = true;
                        break;
                    }
                }
                if(ok) break;
            }
            if(ok) break;
        }
 */
        ok = fn(v,n);
        if(ok) cout<<"Yes\n";
        else    cout<<"No\n";
    }
    return 0;
}
