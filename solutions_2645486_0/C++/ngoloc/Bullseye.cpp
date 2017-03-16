#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("B-small-attempt1.in");
ofstream fout("out.txt");

int E, R, N;
int V[11];

int A[11][6];

void process(int test){
	fout<<"Case #"<<test<<": ";
	fin>>E>>R>>N;
	for(int i=0;i<=10;i++)
		for(int j=0;j<6;j++)
			A[i][j] = 0;

	for(int i=1;i<=N;i++)
		fin>>V[i];

	for(int i=1;i<=N;i++)
		for(int e=1;e<=E;e++)
		{
			for(int del=0;del<=E;del++)
				if(e-R+del>0&&e-R+del<E)
					A[i][e] = max(A[i-1][e-R+del]+del*V[i],A[i][e]);
		}

	int Max = 0;
	for(int j=1;j<=E;j++)
		Max = max(Max,A[N][j]);
	fout<<Max<<endl;
}

int main(){
	int T;
	fin>>T;
	for(int t=1;t<=T;t++)
		process(t);

	return 0;
}
