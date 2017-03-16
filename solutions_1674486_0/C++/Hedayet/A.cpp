//Bismillahir Rahmanir Rahim
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <set>
#include <stack>
#include <map>

#define mp make_pair
#define rep(i,n) for(int i=0,_n=n;i<_n;i++)
#define reps(i,s,n) for(int i=s,_n=n;i<_n;i++)
#define pi 2.0*acos(0.0)
#define MAX 2147483647
#define MIN -2147483647

using namespace std;


typedef long long ll;
typedef vector<int>VI;
typedef map<string,int> MSI;
typedef set<int>SI;
typedef pair<int,int>PAR;
typedef vector<PAR>VP;


int N,color[1009],paths;
VI adj[1090];

void visit(int n,int tar)
{
    if(n==tar){
        paths++;
        return;
    }
    rep(i,adj[n].size())
    visit(adj[n][i],tar);
}

bool dfs(int u,int v){
    paths=0;
    visit(u,v);
    int ret = (paths>1);
    if(ret)return ret;
    paths=0;
    visit(v,u);
    return (paths>1);
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int kas;
	cin>>kas;
	//cout<<kas<<endl;
	rep(cas,kas){
        cin>>N;
        rep(i,N){
            int t;
            cin>>t;
            rep(j,t){
                int v;
                cin>>v;
                v--;
                adj[i].push_back(v);
            }
        }

        int flag=0;

        rep(i,N){
            reps(j,i+1,N){
                if(dfs(i,j)){
                    flag=1;
                    break;
                }
            }
            if(flag)break;
        }

        printf("Case #%d: ",cas+1);

        if(flag)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;

        rep(i,1001)
        adj[i].clear();
	}
return 0;
}
