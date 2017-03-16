#include<iostream>
#include<algorithm>
int tmp[500];
int set[500];
int nt,ns;
bool issecond;
bool bar(int total,int N,int pt, int* S)
{
	if(pt == N) return false;
	if(total == 0)
	{
		if(issecond)
		{
			for(int i=0;i<ns-1;i++)
			{
				std::cout<<set[i]<<" ";
			}
			std::cout<<set[ns-1]<<std::endl;
			for(int i=0;i<nt-1;i++)
			{
				std::cout<<tmp[i]<<" ";
			}
			std::cout<<tmp[nt-1]<<std::endl;
			return true;
		}
		else
		{
			for(int i=0;i<nt;i++)set[i] = tmp[i];
			ns = nt;
			issecond = true;
			return false;
		}
	}
	else if(total < 0) return false;

	tmp[nt++] = S[pt];
	if(bar(total-S[pt],N,pt+1,S)) return true;
	nt--;
	return bar(total,N,pt+1,S);
	
}
void foo(int N, int* S)
{
	std::sort(S,S+N);
	int sum = 0;
	for(int i=0;i<N;i++)
	{
		sum+= S[i];
	}
	int i;
	for(i=S[0]+S[1];i<sum;i++)
	{
		ns = 0;
		nt = 0;
		issecond = false;
		if(bar(i,N,0,S)) break;
	}
	if(i==sum)std::cout<<"Impossible"<<std::endl;
}

int main()
{
	int T,N;
	int S[500];
	std::cin>>T;
	for(int i=1;i<=T;i++)
	{
		std::cin>>N;
		for(int j=0;j<N;j++)std::cin>>S[j];
		std::cout<<"Case #"<<i<<":"<<std::endl;
		foo(N,S);
	}
}