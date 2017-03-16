#include<iostream>
#include<fstream>
using namespace std;
int matrix[1001][1001];
int inedge[1001];
int outedge[1001];
bool dfs(int e,int N,int count[]){
	count[e]+=1;
	for(int i=0;i<N;i++){
		if(matrix[e][i]==1){
			if(count[i]>0){
				return true;
			}
			bool v=dfs(i,N,count);
			if(v==true)
				return true;
		}
	}
	return false;
}
int main()
{
	int count[1001];
	ifstream fin;
	fin.open("E:\\codejam\\input.txt");
	ofstream fout;
	fout.open("E:\\codejam\\output.txt");
	int T;
	fin>>T;
	for(int t=1;t<=T;t++)
	{
		int N,E;
		fin>>N;
		for(int i=0;i<N;i++){
			inedge[i]=0;
			outedge[i]=0;
			for(int j=0;j<N;j++){
				matrix[i][j]=0;
			}
		}//initialize_matrix;
		for(int i=0;i<N;i++)
		{
			fin>>E;
			int node;
			for(int e=0;e<E;e++){
				fin>>node;
				matrix[node-1][i]=1;
				inedge[node-1]+=1;
				outedge[i]+=1;
			}
		}
		
		for(int i=0;i<N;i++){
			//cout<<outedge[i]<<endl;
		}
		/*
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				cout<<matrix[i][j]<<" ";
			}
			cout<<endl;
		}*/
		bool flag=false;
		for(int i=0;i<N;i++)
		{
			if(outedge[i]==0)
			{
				for(int e=0;e<N;e++)
				{
					count[e]=0;
				}
				flag=dfs(i,N,count);
				if(flag==true)
					break;
			}
		}
		if(flag==false){
			fout<<"Case #"<<t<<": "<<"No"<<endl;
		}
		else{
			fout<<"Case #"<<t<<": "<<"Yes"<<endl;
		}
		

	}
	return 0;
}