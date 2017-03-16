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
#include <sstream>

using namespace std;

#define mp make_pair
#define rep(i,n) for(int i=0,_n=n;i<_n;i++)
#define reps(i,s,n) for(int i=s,_n=n;i<_n;i++)
#define pi 2.0*acos(0.0)
#define MAX 2147483647
#define MIN -2147483647
#define torad(a) (a*pi)/180.0;
#define eps 0.000000001
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front

typedef long long ll;
typedef vector<int>VI;
typedef map<string,int> MSI;
typedef set<int>SI;
typedef pair<int,int>PAR;
typedef vector<PAR>VP;

int K,N,key[409],open[409],adj[40][40],color[109],nodeKey[25][400];
VI inside[25];

int bfs(int S){
    queue<int>Q;
    int t=1,tempKey[50];
    memset(color,0,sizeof(color));
    rep(i,50)tempKey[i]=key[i];

    Q.push(S);
    color[S]=1;
    tempKey[open[S]]--;
    int visited=1;

    rep(i,N){
        if(i==S)continue;
        if(tempKey[open[i]]){
            Q.push(i);
            color[i]=++t;
            visited++;
            tempKey[open[i]]--;
        }
    }

    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        rep(i,N){
            if(adj[u][i]&&color[i]==0){
                Q.push(i);
                color[i]=++t;
                visited++;
            }
        }
    }
    return visited;
}

int main()
{
	freopen("D-small-attempt1.in","r",stdin);
	freopen("output.txt","w",stdout);
	int kas;
	scanf("%d",&kas);
	rep(cas,kas){
	    cin>>K>>N;

	    memset(key,0,sizeof(key));
	    memset(nodeKey,0,sizeof(nodeKey));
	    memset(adj,0,sizeof(adj));

	    rep(i,K){
	        int a;
	        cin>>a;
	        key[a]++;
	    }
	    rep(i,N){
	        int a;

	        cin>>open[i];
	        cin>>a;
	        rep(j,a){
	            int b;
	            cin>>b;
	            nodeKey[i][b]=1;
	        }
	    }

	    rep(i,N){
	        rep(j,N){
	            if(i==j)continue;
	            if(nodeKey[j][open[i]])adj[j][i]=1;
	        }
	    }

	    int yes = 0;

	    printf("Case #%d: ",cas+1);

	    rep(i,N){
	        if(key[open[i]]==0)continue;
            int ret=bfs(i);
            if(ret==N){
                yes=1;
                rep(i,N){
                    if(i)cout<<" ";
                    cout<<color[i];
                }
                cout<<endl;
                break;
            }
	    }
	    if(!yes)puts("IMPOSSIBLE");
	}
return 0;
}
