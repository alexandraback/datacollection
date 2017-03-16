#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void sdump(vector<int> h) {
	int s=h.size();
	for(int i=0;i<s;i++)
		cout<<h[i]<<" ";
	cout<<endl;
	
}
void dump(vector<vector<int> > adj){
	int n=adj.size();
	for(int i=0;i<n; i++)
	{
		for(int j=0;j<n;j++){
			cout<<adj[i][j]<<" ";
		}
		cout<<endl;
	}

}

vector<int> initial (vector<vector<int> > p) {
	int s=p.size();
	vector<int> ret;
	for(int i=0;i<s;i++){
		int tot = 0;
		for(int j=0;j<s;j++)
		 tot+=p[i][j];
		if(tot == 0) 
			ret.push_back(i);
	}
	return ret;
}
int main()
{
	int t;
	cin>>t;
 
	for(int kase = 1;kase <=t ; kase++) {
		int n;
		cin>>n;
		vector<vector<int> > adj(n, vector<int>(n,0));
		vector<vector<int> > tadj;

		
		for(int i =0 ;i<n;i++){
			int m;
			cin>>m;
			int k;

			for(int j=0;j<m;j++){
				cin>>k;
				adj[i][k-1] = 1;
			}
		}
		bool ans = false;
		vector<int> posib = initial(adj);
		vector<int> tp;
		for(int i=0;i<posib.size();i++){
			queue<int> Q;
			Q.push(posib[i]);
			tadj = adj;
			vector<vector<int> > parent(n);
			while(!Q.empty()){
				int node = Q.front();
				Q.pop();
				tp = parent[node];
				tp.push_back(node);
				for(int j=0;j<n;j++){
					if(tadj[j][node] == 1 ){
						if(parent[j].size() == 0){
							parent[j] = tp;
							Q.push(j);
						} else {
							ans = true;
							break;
						}
					}
				}
				if(ans) break;
			}
			if(ans) break;
		}
		cout<<"Case #"<<kase<<": "<<(ans ? "Yes" : "No") <<endl;
						
	}

	return 0;
}
