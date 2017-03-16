#include<iostream>

unsigned long long box[2][101];
unsigned long long toy[2][101];
unsigned long long cache[101][101];
bool cached[101][101];
unsigned long long min(unsigned long long a, unsigned long long b)
{
	if(a>b) return b;
	return a;
}
unsigned long long max(unsigned long long a, unsigned long long b)
{
	if(a>b) return a;
	return b;
}
unsigned long long foo(int npt,int mpt, int N, int M,bool caching)
{
	if(npt >= N || mpt >= M) return 0;
	//if(caching&&cached[npt][mpt]) return cache[npt][mpt];
	unsigned long long out = 0;
	if(box[1][npt] == toy[1][mpt])
	{
		unsigned long long tmp;
		out = min(box[0][npt],toy[0][mpt]);
		box[0][npt] -= out;
		toy[0][mpt] -= out;
		if(box[0][npt]>toy[0][mpt])
		{
			
			tmp = max(foo(npt,mpt+1,N,M,false),foo(npt+1,mpt+1,N,M,caching));
		}
		else if(box[0][npt] == toy[0][mpt]) tmp = foo(npt+1,mpt+1,N,M,caching);
		else
		{
			tmp = max(foo(npt+1,mpt,N,M,false),foo(npt+1,mpt+1,N,M,caching));
		}
		box[0][npt] += out;
		toy[0][mpt] += out;
		out += tmp;
	}
	else
	{
		out = max(foo(npt+1,mpt,N,M,true),foo(npt,mpt+1,N,M,true));
	}
	//if(caching){cache[npt][mpt] = out;cached[npt][mpt] = true;}
	return out;
}
int main()
{
	int T,N,M;
	std::cin>>T;
	for(int i=1;i<=T;i++)
	{
		for(int a=0;a<101;a++)
			for(int b=0;b<101;b++)
			{
				cache[a][b] = 0;
				cached[a][b] = false;
			}
		std::cin>>N>>M;

		for(int j=0;j<N;j++)std::cin>>box[0][j]>>box[1][j];
		for(int j=0;j<M;j++)std::cin>>toy[0][j]>>toy[1][j];
		std::cout<<"Case #"<<i<<": "<<foo(0,0,N,M,true)<<std::endl;
	}
}