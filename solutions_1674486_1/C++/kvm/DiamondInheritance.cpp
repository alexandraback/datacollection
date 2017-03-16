#include<iostream>
#include<string>
#include<cstdio>
#include<map>
#include<algorithm>
#include<cmath>
#include<vector>
#include<sstream>
#include<stack>
#include<queue>
#include<cstring>

#define pb push_back
#define LL long long
#define OUTPUT_TO_FILE 1
#define s(n)					scanf("%d",&n)
#define sl(n) 					scanf("%lld",&n)
#define sf(n) 					scanf("%lf",&n)
#define ss(n) 					scanf("%s",n)


using namespace std;
int visited[1001];
int n;
vector<int> v[1001];
bool dfs(int i){
	bool val = false;
	visited[i] = 1;
	for(int j=0;j<v[i].size();j++){
		if(visited[v[i][j]]==2)
			val = true;
		else if(visited[v[i][j]]==0){
			val = val|dfs(v[i][j]);
		}
	}
	visited[i] = 2;
	return val;
}
int main()
{
	freopen("A-large.in","r",stdin);
	freopen("out1.txt","w",stdout);
	int t,t1 = 1,i,j,e;
	cin>>t;
	while(t1 <= t){
		cin>>n;
		int flag = 0;
		for(i=0;i<=n;i++)
			v[i].clear();
		for(i=1;i<=n;i++){
			cin>>e;
			for(j=0;j<e;j++){
				int val;
				cin>>val;
				v[i].pb(val);
			}
		}

		for(i=1;i<=n;i++){
			for(j=0;j<=n;j++)
				visited[j] = 0;
			visited[i] = 1;
			if(dfs(i)){
				flag = 1;
			}
		}
		cout<<"Case #"<<t1<<": ";
		if(flag == 1)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
		t1++;
	}
}