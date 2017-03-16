# include <iostream>
# include <vector>
# include <map>
# include <deque>
# include <set>
# include <algorithm>
# include <memory>
# include <cstring>
# include <cstdio>
# include <cctype>
# include <cstdlib>
# include <cmath>
# include <utility>
# include <string>
# include <queue>

using namespace std;

# define I(n)   scanf("%d",&(n))
# define read(x) freopen(x,"r",stdin)

int N;
vector<int> adj[1010];
int in[1010];
int v[1010];

bool dfs(int s,int vis){
    //if ( vis[s] != 0 ) return false;
    if ( v[s] == vis ) return true;
    v[s] = vis;

    for(int i=0;i<adj[s].size();i++)
    {
        if ( dfs( adj[s][i],vis ) ) return true;
    }
    return false;
}

int main()
{
	read("A-small-attempt2.in");
	freopen("A2.out","w",stdout);
	int T,x,M;
	I(T);
	for(int cas=1;cas<=T;cas++)
	{
	    I(N);
	    for(int i=0;i<N;i++){
	        adj[i].clear();
	        v[i] = 0;
	    }

	    for(int i=0;i<N;i++){
	        I(M);
	        for(int j=0;j<M;j++){
	            I(x);
	            adj[x-1].push_back(i);
	        }
            in[i] = M;
	    }

        queue<int> q;
        int vis =1;
        bool ok = false;
	    for(int i=0;i<N;i++)
	    {
	        if ( in[i] == 0 ){
	            //q.push(i);
	            if ( !dfs(i,vis++) ) continue;
	            ok = true;
	            break;
	        }
	    }
		cout<<"Case #"<<cas<<": ";
	    if ( ok ){
	        cout<<"Yes"<<endl;
	    }else cout<<"No"<<endl;

        /*
	    if ( q.empty() )
	    {
	        cout<<"Yes"<<endl;
	        continue;
	    }
	    vector<int> t;
	    while( !q.empty() )
	    {
	        int top ;
	        t.push_back(top = q.front());
	        q.pop();

	        for( int i=0;i<adj[top].size();i++)
	        {
	            int c = adj[top][i];
	            in[c] --;
	            if ( in[c] == 0 ){
	                q.push(c);
	            }
	        }
	    }*/

	}
	return 0;
}
