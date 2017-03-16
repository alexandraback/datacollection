#include<bits/stdc++.h>
using namespace std;
vector<int> a;
int n;
int findIndependentLine(vector<int> visited);

int bfs3(int x, vector<int> visited){
	int st = x;
	int c = 1;
	int prev = x;
	
	while(visited[x]==0){
		visited[x]=c++;
		prev = x;
		x=a[x];	
	}
	
	if(visited[x]>n)
		return 0;
		
	if(a[prev]==x && a[x]==prev)
		return c-1 + findIndependentLine(visited);
		
		return 0;
	

		
}



int findIndependentLine(vector<int> visited){
	int mx = 0;
	for(int i=0;i<n;i++){
		if(visited[i])
			continue;
		vector<int> v(n);
		for(int j=0;j<n;j++){
			v[j]=visited[j];
			if(v[j])
				v[j]+=n;
		}
		mx = max(mx, bfs3(i, v));
	}
	return mx;
}


int bfs2(int x, vector<int> visited, int param){
	int st = x;
	int c = 1;
	int prev = x;
	while(visited[x]==0){
		visited[x]=c++;
		prev = x;
		x=a[x];	
	}
	
		
	if(x!=param)
		return 0;

		return c-1;
}


int findReverseLine(int x, vector<int> visited){
	
	vector<int> v;

	int mx=0;
	for(int i=0;i<n;i++){
		if(!visited[i]){
			v.clear();
			v.resize(n);
			for(int j=0;j<n;j++)
				{
					v[j]=visited[j];
					if(v[j])
						v[j]+=n;
				}
			mx=max(mx,bfs2(i, v, x));
		}
	}
	return mx;
	
	
}

int bfs(int x, vector<int> visited){
	int st = x;
	int c = 1;
	int prev = x;
	while(visited[x]==0){
		visited[x]=c++;
		prev = x;
		x=a[x];	
	}
	if(a[x]!=prev)
		return c-visited[x];
	
	else{
		int v1 = findReverseLine(st, visited);
		int v2 = findReverseLine(prev, visited);
		int v3 = findIndependentLine(visited);
		return c-1 + v1+v2+v3;
	}
	
	
}

void eval(){
	cin>>n;
	a.clear();
	a.resize(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
		a[i]--;
	}
	
	int ans=0;
	
	for(int i=0;i<n;i++){
		vector<int> visited(n);
		ans = max(ans, bfs(i, visited));
	}
	
	cout<<ans<<endl;

}

int main(){
	int t;
		freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	cin>>t;
	for(int te=1;te<=t;te++){
		cout<<"Case #"<<te<<": ";
		eval();
	}
}
