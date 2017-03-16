#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<math.h>
#include<sstream>

using namespace std;
int* nm;
long long** states;
int E,R,N;
long long dfs(int e, int p)
{
	if(states[e][p]!=0) return states[e][p];
	if(p==N-1)
	{
		states[e][p]=nm[N-1]*e;
		return nm[N-1]*e;
	}
	long long bst=0;
	for(int i=0;i<=e;i++)
	{
		bst=max(dfs(min(e-i+R,E),p+1)+i*nm[p],bst);
	}
	states[e][p]=bst;
	return bst;
}
int main()
{
	int T,i,j;
	cin>>T;
	for(int c=1;c<=T;c++)
	{
		cin>>E>>R>>N;
		nm=new int[N];
		states=new long long*[E+1];
		for(i=0;i<=E;i++)
		{
			states[i]=new long long[N];
			for(j=0;j<N;j++) states[i][j]=0;
		}
		for(i=0;i<N;i++) cin>>nm[i];
		long long out=dfs(E,0);
		cout<<"Case #"<<c<<": "<<out<<endl;
	}
	return 0;
}
