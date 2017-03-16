//Tirth Maniar
#include<bits/stdc++.h>
using namespace std;

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1 && arg1){
	cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1 && arg1, Args &&... args){
	const char* comma = strchr(names+1,','); cerr.write(names,comma-names) << " : " << arg1 << " | "; __f(comma+1, args...);
}
#else
#define trace(...)
#endif

#define all(c) c.begin(),c.end()
#define tr(container,it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define present(container, element) (container.find(element) != container.end()) 
				// For Set and Map
#define cpresent(container, element) (find(all(container),element) != container.end())
				// For Vector
				// Use v.clear() to remove all elements
#define pb push_back
#define mp make_pair
#define sz(a) int((a).size())
				// Better to use v.empty() instead of comparing with 0 to check if empty
#define F first
#define S second		
			// For pair
#define mod 1000000007
#define scand(x) scanf("%d",&x)
#define printd(x) printf("%d\n",x)
#define scanll(x) scanf("%lld",&x)
#define printll(x) printf("%lld\n",x)

typedef long long ll;
typedef vector<int> vi;		
typedef vector< vi > vvi;    	// 2-d array
typedef pair<int,int> pii;
typedef vector<pii> vpii;

inline int mult(int x,int y){return ((ll)x*y)%mod;}
int power(int x,int y){int ret=1; while(y){ if(y&1) ret = mult(ret,x); x = mult(x,x); y = y/2;} return ret;}
int gcd(int a,int b){ if(b) return gcd(b,a%b); return a;}
vi prime;
void generateprime(int n){ int i,j; vi num(n+5); num[1]=1; for(i=4;i<n;i=i+2) num[i]=1;
	for(i=3;i<n;i++){ if(num[i]==0) { for(j=3*i;j<n;j=j+2*i) num[j] = 1;}} num[0] = 0;
	for(i=2; i<n; i++){ if(num[i]==0) prime.pb(i); num.clear();} 
}

vi root[30];
vi visited(30);
int flag = 0;
int ans,n;
int mat[1005][1005];

void dfs(int c,int u,int v,int len)
{
        int i,k,len2,len1;
        visited[v] = 1;
        for(i=0;i<sz(root[v]);i++)
        {
		//trace(c,u,v,len);
		if(visited[root[v][i]] == 1 && root[v][i] == u)
		{
			flag = 1;
			len2 = len + 1;
			if(ans < len2)
			{
				ans = len2;
			}
			for(k=0;k<=n;k++)
                        {
				//trace(k,visited[k]);
                                if(mat[k][v] == 1 && visited[k] == 0 && mat[v][c] != 1)
                                {
                                        if(ans < len2 + 1)
                                        {
                                                ans = len2 + 1;
                                        }
                                }
				//trace(ans);
                        }
			//trace(c,u,v,root[v][i],ans);
			return;
		}
		if(visited[root[v][i]] == 1 && root[v][i] == c)
		{
			flag = 1;
			len1 = len + 1;
			if(ans < len1)
			{
				ans = len1;
			}
			/*for(k=0;k<=n;k++)
			{
				if(mat[k][root[v][i]] == 1 && visited[k] == 0)
				{
					if(ans < len1 + 1)
					{
						ans = len1 + 1;
					}
				}
			}*/				
			return;
		}	
                if(visited[root[v][i]] == 1)
                {
                        flag = 1;
                        return;
                }
                if(visited[root[v][i]] == 0)
                {
                        dfs(c,v,root[v][i],len+1);
                }
        }
        visited[v] = 2;
}

int main()
{
	int t,z=0,i,j,a[1005];
	scand(t);
	while(t--)
	{
		z++;
		ans = 0;
		scand(n);
		for(i=0;i<=n;i++)
		{
			for(j=0;j<=n;j++)
			{
				mat[i][j] = 0;
			}
		}
		for(i=1;i<=n;i++)
		{
			scand(a[i]);
			mat[i][a[i]] = 1;
			root[i].pb(a[i]);
		}
		for(i=1;i<=n;i++)
		{
			for(j=0;j<=n;j++)
			{
				visited[j] = 0;
			}
			dfs(i,0,i,0);
		}
		printf("Case #%d: %d\n",z,ans);
		for(i=0;i<=n;i++)
		{
			root[i].clear();
			visited[i] = 0;
		}
	}
return 0;
}
