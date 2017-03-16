//VERDICT:

#include<iostream>
#include<algorithm>
#include<cstring>
//#include<cstdlib>
#include<vector>
//#include<cstdio>
//#include<iomanip>
//#include<map>
//#include<set>
#include<queue>
//#include<deque>
//#include<utility>
#include<cmath>
#define pb push_back
#define mkp make_pair
#define foR(i,j,n) for(int i=j;i<n;i++)
#define error(x) cerr<<#x<<"="<<x<<endl;
#define stf(x) st.find(x)!=st.end()
#define X first
#define Y second
#define pii pair<int,int>
typedef long long ll;
using namespace std;
const int maxn=1010,inf=1000000000,mod=1000003;
vector<int> adj[maxn];
int mark[maxn];
bool dfs(int x,int l){
	mark[x]++;
	foR(i,0,adj[x].size()){
		int next=adj[x][i];
		if(mark[next]==2)
			return true;
		else if (mark[next]==0&&dfs(next,x))
			return true;
	}
	mark[x]++;
	return false;
}
int main(){
	int t;
	cin>>t;
	foR(j,1,t+1){
		fill(mark,mark+maxn,0);
		fill(adj,adj+maxn,vector<int> ());
		int n;
		cin>>n;
		foR(i,0,n){
			int c,x;
			cin>>c;
			while(c--){
				cin>>x;x--;
				adj[i].pb(x);
			}
		}
		bool k=false;
		cout<<"Case #"<<j<<": ";
		foR(i,0,n)
			if(dfs(i,-1)){
				cout<<"Yes"<<endl;
				k=true;
				break;
			}
			else
				fill(mark,mark+maxn,0);
		if(!k)
			cout<<"No"<<endl;
	
	}
	return 0;
}
