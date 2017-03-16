#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	int t;
	cin>>t;
	for(int it=1; it<=t; it++)
	{
		int n, s, p;
		cin>>n>>s>>p;
		p*=3;
		
		int wynik=0;
		for(int i=0; i<n; i++)
		{
			int a;
			cin>>a;
			if(a>=p-2 && a>=p/3)
				wynik++;
			else
				if(s>0 && a>=p-4 && a>=p/3)
				{
					wynik++;
					s--;
				}
		}
		cout<<"Case #"<<it<<": "<<wynik<<"\n";
	}
}
