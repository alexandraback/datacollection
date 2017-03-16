#include <iostream>

using namespace std;


int main()
{
	int z; cin>>z;
	for(int zz=1; zz<=z; zz++)
	{
		long long r,t; cin>>r>>t;
		
		long long wynik = 0;
		while(true)
		{
			if(2*r+1 <= t)
			{
				wynik++;
				t-=(r+1) * (r+1) - r*r ;
				r+=2;
			}
			else
			break;
		}
		cout<<"Case #"<<zz<<": "<<wynik<<endl;
	}
	return 0;
}
