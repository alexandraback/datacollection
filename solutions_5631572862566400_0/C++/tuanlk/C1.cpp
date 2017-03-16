#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<queue>
using namespace std;

typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;

#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define DFOR(i,a,b) for(int i=a;i>=b;i--)
#define mp(x,y) make_pair((int)x,(int)y)
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define BUG(x) {cout << #x << " = " << x << endl;}
#define PR(x,a,b) {cout << #x << " = "; FOR(i,a,b) cout << x[i] << ' '; cout << endl;}
#define ll long long
#define DEBUG 1
int test;
int n;
int f[1111];
vi g[1111];
int ans;
int visit[1111];
int st[1111];
int top;
int w1[1111];
int ffg(int u, int v){
    //cout<<"ffg: "<<u<<endl;
    int res=0;
    int ss= g[u].size();
    if (ss>0){
        FOR(i,0,ss-1){
            int w=g[u][i];
            if (w!=v){
                if (visit[w]!=0) continue;
                visit[w]=-1;
                int tmp=1+ffg(w,u);
                if (tmp>res) res= tmp;
            }
        }
    }
    return res;
}
int ffgg(int u, int v1, int v2){
    //cout<<"ffgg: "<<u<<"__"<<v1<<" "<<v2<<endl;
    int res=0;
    int ss= g[u].size();
    if (ss>0){
        FOR(i,0,ss-1){
            int w=g[u][i];
            if ((w!=v1) && (w!= v2)){
                if (visit[w]!=0) continue;
                visit[w]=-1;
                int tmp=1+ffg(w,u);
                if (tmp>res) res= tmp;
            }
        }
    }
    return res;
}
int ff(int start){
    //cout<<"Start:= "<<start<<endl;
    FOR(i,1,n) visit[i]=0;
    FOR(i,1,n) w1[i]=-1;
    top=1;
    st[1]=start;
    st[0]=-1;
    visit[start]=1;
    int w=-1;
    int res=1;
    int bvalue=-1;
    while(0!=1){
        int u= st[top];
        //cout<<"Top:= "<<top<<"| s[top]= "<<st[top]<<endl;
        int v=f[u];
        if (visit[v]==0){
            top++;
            st[top]=v;
            visit[v]=top;
            continue;
        }
        if (visit[v]!=0){
            bvalue=visit[v];
            if (res<top-visit[v]+1) res=top-visit[v]+1;
            if (bvalue==top-1){
                int tmp=top+ ffg(u,v);
                if (tmp>res) res= tmp;
            }
            break;
        }
        break;
    }
    return res;
}
int main(){
    if (DEBUG==1){
        freopen("C-small-attempt3.in","r",stdin);
        freopen("output.txt","w",stdout);
    }
    cin>>test;
    FOR(t,1,test){
        cin>>n;
        //cout<<"N:="<<n<<endl;
        FOR(i,1,n) g[i].clear();
        FOR(i,1,n){
            int value;
            cin>>value;
            f[i]= value;
            g[f[i]].push_back(i);
        }
        ans=1;
        FOR(i,1,n){
            int value= ff(i);
            if (value>ans) ans=value;
        }
        cout<<"Case #"<<t<<": "<<ans;
        if (t<test) cout<<endl;
    }
    return 0;
}
/*
4
4
2 3 4 1
4
3 3 4 1
4
3 3 4 3
10
7 8 10 10 9 2 9 6 3 3
*/
