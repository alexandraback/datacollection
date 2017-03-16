#include<iostream>
#include<vector>
#include<fstream>
using namespace std;
void DFS(vector<vector<int> > &graph,vector<int>& visited,int i)
{
	visited[i]++;
	for(int k=0;k<graph[i].size();k++){
		if(visited[graph[i][k]]>0) visited[graph[i][k]]++;
		else DFS(graph,visited,graph[i][k]);
	}
}
int main()
{
	ifstream cin;
	ofstream cout;
	cin.open("A-small-attempt1 (1).in");
	cout.open("output.txt");
	int t,m,n,temp;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		vector< vector<int> > graph;
		vector<int> row;
		vector<int> visited;
		for(int j=0;j<n;j++)
		{
			graph.push_back(row);
			visited.push_back(0);
			cin>>m;
			for(int k=0;k<m;k++){
				cin>>temp;
				graph[j].push_back(temp-1);
			}
		}
		bool diamond=false;
		for(int k=0;k<n;k++){
			for(int h=0;h<n;h++) visited[h]=0;
			DFS(graph,visited,k);
			for(int h=0;h<n;h++) if(visited[h]>=2) {diamond=true; break;}
			if(diamond) break;
		}
		cout<<"Case #"<<i+1<<": ";
		if(diamond)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}




