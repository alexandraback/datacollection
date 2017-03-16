#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <cmath>
using namespace std;

int address(int x, int y, int N)
{
	return (x+y*N);
}

int main(int argc, char** argv)
{
	int T;
	cin>>T;
	int* answers = new int[T];
	for(int i=0;i<T;i++)
	{
		int N;
		cin>>N;
		
		//build the adjacency matrix
		int* adjacency = new int[N*N];
		for(int j=0;j<N*N;j++)
		{
			adjacency[j] = 0;
		}
		int* degrees = new int[N];
		for(int j=0;j<N;j++)
		{
			int M;
			cin>>M;
			degrees[j] = M;
			int* edges = new int[M];
			for(int k=0;k<M;k++)
			{
				cin>>edges[k];
				adjacency[address(j,edges[k]-1,N)] = 1;
			}
		}
		//done building the adjacency matrix
		
		int output = 0;
		//initialize bfs queue taking vertex l as start vertex
		for(int w = 0;w<N;w++)
		{
			queue<int> bfs_queue;
			int* a = new int[N];
			for(int j=0;j<N;j++)
			{
				a[j] = 0;
			}
			for(int j=0;j<N;j++)
			{
				if(adjacency[address(w,j,N)] == 1)
				{
					if(a[j] == 0)
					{
						a[j] = 1;
						bfs_queue.push(j);
					}
					else
					{
						a[j] = 2;
						output = 1;
						//deal carefully
					}
				}
			}	
			while(!bfs_queue.empty())
			{
				int vertex = bfs_queue.front();
				bfs_queue.pop();
				for(int j=0;j<N;j++)
				{
					if(adjacency[address(vertex,j,N)] == 1)
					{
						if(a[j] == 0)
						{
							a[j] = 1;
							bfs_queue.push(j);
						}
						else
						{
							a[j] = 2;
							output = 1;
							//deal carefully
						}
					}
				}
			}
		}
		answers[i] = output;
		//}
	}
	for(int i=0;i<T;i++)
	{
		if(answers[i] == 0)
		{
			cout<<"Case #"<<i+1<<": No"<<endl;
		}
		else if(answers[i] == 1)
		{
			cout<<"Case #"<<i+1<<": Yes"<<endl;
		}
	}
	return 0;
}
				
