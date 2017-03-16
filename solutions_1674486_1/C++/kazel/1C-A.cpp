#include<iostream>
bool* chk;
bool bar(int from, int** graph)
{
	if(chk[from]) return true;
	chk[from] = true;
	if(graph[from][0] == 0)return false;
	for(int i=1;i<=graph[from][0];i++)
	{
		if(bar(graph[from][i],graph)) return true;
	}
	return false;
}
bool foo(int** graph)
{
	chk = new bool[graph[0][0]+1];
	for(int n=1;n<=graph[0][0];n++)
	{
		for(int i=1;i<=graph[0][0];i++) chk[i] = false;
		if(bar(n,graph)) return true;
	}
	return false;
}
int main()
{
	int T;
	int N,M;
	int** graph;
	std::cin>>T;
	for(int i=1;i<=T;i++)
	{
		std::cin>>N;
		graph = new int*[N+1];
		graph[0] = new int[1];
		graph[0][0] = N;
		for(int j=1;j<=N;j++)
		{
			std::cin>>M;
			graph[j] = new int[M+1];
			graph[j][0] = M;
			for(int k=1;k<=M;k++) std::cin>>graph[j][k];
		}
		std::cout<<"Case #"<<i<<": ";
		if(foo(graph))std::cout<<"Yes"<<std::endl;
		else std::cout<<"No"<<std::endl;
	}
}