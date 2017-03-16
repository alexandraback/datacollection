#include <iostream>
#include <map>

using namespace std;

int nums[510];
map<int,int>mapa;
int n;
int t;

void imprime(int m)
{
	bool si=true;
	for(int i=0; i<n; i++)
		if(m & (1<<i))
		{
			if(si) si=false;
			else cout<<' ';
			cout<<nums[i];
		}
	cout<<endl;
}

void f(){
    cin>>n;
    mapa=map<int,int>();
    for(int i=0; i<n; i++) cin>>nums[ i ];
    
    for(int i=0; i<(1<<n); i++)
    {
		int suma=0;
		for(int j=0; j<n; j++)
			if( i & (1<<j)) suma+=nums[j];
			
		if(mapa.count(suma))
		{
			imprime(i);
			imprime(mapa[suma]);
			return;
		}
		mapa[suma]=i;
	}
	
	cout<<"Impossible\n";
}


int main(){
    
    cin>>t;
    for(int i=1; i<=t; i++)
    {
		cout<<"Case #"<<i<<":\n";
		f();
	}
    return 0;
}
