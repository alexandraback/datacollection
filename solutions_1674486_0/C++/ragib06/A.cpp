#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
using namespace std;

typedef long long lld;

#define SIZE 1000+10

#define IN freopen("A-small-attempt0.in","r",stdin);
#define OUT freopen("A-small-attempt0.out","w",stdout);

int T,N;

vector<int> adj[SIZE];
vector<int> roots;

bool visited[SIZE];

queue<int> Q;

bool bfs(int u){
    while(!Q.empty()){
        Q.pop();
    }

    int i;

    Q.push(u);
    visited[u] = true;

    while(!Q.empty()){
        int top = Q.front();
        Q.pop();

        for(i=0;i<adj[top].size();i++){
            int v = adj[top][i];
            if(visited[v]) return true;
            Q.push(v);
            visited[v] = true;
        }
    }
    return false;
}

int main()
{
	IN
	OUT
	int i,j,t,mi,tmp;

	scanf("%d",&T);
	for(t=1;t<=T;t++){

	    scanf("%d",&N);

	    for(i=1;i<=N;i++)   adj[i].clear();
        roots.clear();

	    for(i=1;i<=N;i++){
	        scanf("%d",&mi);
            for(j=0;j<mi;j++){
                scanf("%d",&tmp);
                adj[tmp].push_back(i);
            }
            if(mi == 0) roots.push_back(i);
	    }

        printf("Case #%d: ",t);


        bool found = false;
	    int len = roots.size();
	    for(i=0;i<len;i++){

	        memset(visited, false, sizeof(visited));

            if(bfs(roots[i])){
                found = true;
                break;
            }
	    }

        if(found)   printf("Yes\n");
        else        printf("No\n");
	}
	return 0;
}
