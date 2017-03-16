#include <iostream>
#include <cmath>

using namespace std;

int ilosc_cyfr(int x)
{
	int wynik=0;
	while(x!=0)
	{
		x/=10;
		wynik++;
	}
	return wynik;
}

int next_permutation(int x, int il)
{
	int wynik=x;
	wynik/=10;
	wynik+=pow(10, il-1)*(x%10);
	return wynik;
}

int main()
{
	ios_base::sync_with_stdio(0);
	int t;
	cin>>t;
	
	for(int it=1; it<=t; it++)
	{
		bool tab[3000000];
		
		int A, B, wynik=0;
		cin>>A>>B;
		
		int ilo=ilosc_cyfr(A);
		
		for(int i=A; i<=B; i++)
			tab[i]=0;
		
		//end of initialization
		
		for(int i=A; i<=B; i++)
		{
			if(tab[i])continue;
			int n=0, x=i;
			for(int j=0; j<ilo; j++)
			{
				if(x>=A && x<=B)
					if(tab[x]==0)
					{
						n++;
						tab[x]=1;
					}
				x=next_permutation(x, ilo);
			}
			wynik+=(n*(n-1))/2;
		}
		cout<<"Case #"<<it<<": "<<wynik<<"\n";
	}
}
