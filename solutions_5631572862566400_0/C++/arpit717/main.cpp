#include <bits/stdc++.h>

using namespace std;
#define sd(x) scanf("%d",&x)
#define slld(x) scanf("%lld",&x)
#define pd(x) printf("%d",x)
#define pull(x) printf("%llu",x)
#define pll(x) printf("%lld",x)

#define pn() printf("\n")
#define loop(i, a, b) for (int i = int(a); i < int(b); i++)
#define MAXN 1000005
typedef long long int ll;
typedef unsigned long long int ull;

ll dp[1005];
int a[1005];
int v[1005];
int p[1005];
list<int> b[1005];
list<int> tree[1005];
ll dist[1005];

ll dfs(int node){

    int nxt1;
    list<int>::iterator it;
    v[node]=1;
    for(it = b[node].begin();it!=b[node].end();++it){
        if(!v[*it]){
            p[*it]=node;
            tree[node].push_back(*it);
            tree[*it].push_back(node);
            dfs(*it);
        }
    }
}


void dfs2(int node,int pt,int cur){

    list<int>::iterator it;
    dist[node]=cur;
    for(it = tree[node].begin();it!=tree[node].end();++it){
        if(*it!=pt){

            dfs2(*it,node,cur+1);
        }
    }
}


int main()
{
freopen("C-small-attempt1.in","r",stdin);
freopen("out0_small.txt","w",stdout);

    int t,mx_idx,n;
    ll mx,ans;
    sd(t);
    loop(k,1,t+1){
        loop(i,1,1005){
            while(!b[i].empty())b[i].pop_back();
            while(!tree[i].empty())tree[i].pop_back();
            p[i]=-1;
        }
        ans=0;
        mx=0;
        sd(n);
        loop(i,1,n+1){
            sd(a[i]);
            b[a[i]].push_back(i);
            b[i].push_back(a[i]);
          //  mx=max(a[i],mx);
        }
        //loop(j,1,1005)dp[j]=0;
        loop(j,1,1005)v[j]=0;
        loop(i,1,n+1){
            if(!v[i]){
                dfs(i);
                p[i]=-1;
            }
        }
        //loop(i,1,5)cout<<"i: "<<i<<" : "<<p[i]<<endl;
        loop(i,1,n+1){
            loop(j,1,1005)dist[j]=0;
            if(p[i]==-1){
                dfs2(i,-1,1);
              //  cout<<"dist: "<<endl;;
                //loop(j,1,5)cout<<"j: "<<j<<" : "<<dist[j]<<" :: ";
                mx=0;
                loop(j,1,1005){
                    if(dist[j]>mx){
                        mx_idx=j;
                        mx=dist[j];
                    }
                }
               // cout<<endl<<endl<<mx_idx<<endl;
                loop(j,1,1005)dist[j]=0;
                dfs2(mx_idx,-1,1);
               // loop(j,1,5)cout<<"j: "<<j<<" : "<<dist[j]<<" :: ";
                mx=0;

                loop(j,1,1005){
                    if(dist[j]>mx){
                        //mx_idx=j;
                        mx=dist[j];
                    }
                }
              //  cout<<"mx: "<<mx<<endl;
                ans=max(mx,ans);
            }
        }
        cout<<"Case #"<<k<<": ";
        cout<<ans<<endl;
    }


    return 0;
}




