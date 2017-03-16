#include <iostream>

using namespace std;

int t[11];
int E,R,N;

int WY= 0;

void f(int wynik, int energia, int gdzie)
{
	if(energia > E)
	energia = E;
	if(gdzie==N-1)
	{
		wynik+=energia*t[N-1];
		WY=max(WY, wynik);
		return;
	}
	
	f(wynik, energia+R, gdzie+1);
	for(int i=1; i<=energia; i++)
	{
		f(wynik + i*t[gdzie],  energia-i+R, gdzie+1);
	}
}

int main()
{
	int z; cin>>z;
	for(int zz=1; zz<=z; zz++)
	{
		WY=0;
		 cin>>E>>R>>N;
		for(int i=0; i<N; i++)
		cin>>t[i];
		
		f(0, E, 0);
		
		cout<<"Case #"<<zz<<": "<<WY<<endl;
	}
}
