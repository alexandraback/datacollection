#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("B-small-attempt0.in");
ofstream fout("B-small-attempt0.out");

int E;
int R;
int N;
int v[11];
int A[11][6];
int maxE;

void findmax();
int func(int i,int add,int left);
void computeA();


int main()
{
	
	int T;
	fin>>T;
	int i=0;
	int x,val;


	while(i<T)
	{
		maxE=0;
		fin>>E;
		fin>>R;
		fin>>N;
		for(x=0;x<N;x++)
		{
			fin>>val;
			v[x]=val;
		}
		computeA();
		findmax();

		i++;
		fout<<"Case #";
		fout<<i;
		fout<<": ";
		fout<<maxE;

		if(i!=T)
		{
			 fout<<"\n";
		}
	}
	return(0);
}

void findmax()
{
	func(0,0,E);
}

int func(int i,int add,int left)
{
	if(i==N)
	{//Base cond
		if(add>maxE){maxE=add;}
		return(0);
	}

	int send;
	int x=0;
	for(;x<=left;x++)
	{
		send=left-x+R;
		if(send>E){send=E;}
		func(i+1,add+A[i][x],send);
	}
	return(0);
}


void computeA()
{
	int i;
	int j;
	for(i=0;i<N;i++)
	{
		for(j=0;j<=E;j++)
		{
			A[i][j]=j*(v[i]);
		}
	}
}
