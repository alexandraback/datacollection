#include <iostream>
#include <string>
#include <stack>

#define NINF 5000

using namespace std;
int mat[1001][1001];

int PathUtil(bool visited[],int len,int v,int k,stack<int> &Stack)
{
	int min=1;
	int key;
    visited[v] = true;
 
    for (int j=0;j<k;j++){
        if (!visited[j] && mat[v][j]){
            key=PathUtil(visited,len-1,j,k,Stack)+1;

            if(key>min){
            	min=key;
            }
        }
    }

    if(min==len)
    	Stack.push(v);

    return min;
}

void findPath(int len,int s,int k,stack<int> &Stack){
	bool *visited = new bool[k];
    for (int i = 0; i < k; i++)
        visited[i] = false;

    PathUtil(visited,len,s,k,Stack);
}

int DFSUtil(int v, bool visited[],int k)
{
	int min=1;
	int key;
    visited[v] = true;
 
    for (int j=0;j<k;j++){
        if (!visited[j] && mat[v][j] && v!=j){
            key=DFSUtil(j, visited,k)+1;

            if(key>min){
            	min=key;
            }
        }
    }
    return min;
}
 
int DFS(int v,int k)
{
    bool *visited = new bool[k];
    for (int i = 0; i < k; i++)
        visited[i] = false;
 
    return DFSUtil(v, visited,k);
}

int main(){
	int n,k,var,s,l,min,key,val;

	cin>>n;
	for(int i=0;i<n;i++){
		cin>>k;
		min=-1;

		for(int j=0;j<k;j++){
			for(int l=0;l<k;l++){
				mat[j][l]=0;
			}
		}
		
		for(int j=0;j<k;j++){
			cin>>var;
			mat[j][var-1]= 1;
			mat[var-1][j]= 1;
		}

		for(int j=0;j<k;j++){
			val=DFS(j,k);
			if(val>min){
				min=val;
				key=j;
			}
		}
		/*stack<int> Stack;

		
		findPath(min,key,k,Stack);

		while (Stack.empty() == false){
            int u = Stack.top();
            cout<<u+1<<" ";
            Stack.pop();
        }*/
		cout<<"Case #"<<(i+1)<<": "<<min<<endl;
	}
}