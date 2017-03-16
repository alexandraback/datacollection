#include <iostream>
#define N 4

using namespace std;
int t,x,r,c;
int v[N][N][N]={
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	0,1,0,1, 1,1,1,1 ,0,1,0,1, 1,1,1,1,
	0,0,0,0 ,0,0,1,0 ,0,1,1,1 ,0,0,1,0,
	0,0,0,0, 0,0,0,0, 0,0,0,1, 0,0,1,1
};


int main()
{
	cin>>t;
	for(int i=1;i<=t;++i)
	{
		cin>>x;
		cin>>r;
		cin>>c;
		cout<<"Case #"<<i<<": ";	
		if(v[x-1][r-1][c-1])
			cout<<"GABRIEL"<<endl;
		else
			cout<<"RICHARD"<<endl;
	}
	return 0;
}