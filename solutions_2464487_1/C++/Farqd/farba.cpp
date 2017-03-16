#include <iostream>

using namespace std;

unsigned long long r,t; 

bool f (long long n)
{
	if(( 2*r+1 +  2*(r+2*(n - 1) )+1  )/2 * n < 0  )
	return false;
	

	if( ( 2*r+1 +  2*(r+2*(n - 1) )+1  )/2 * n <= t )
	return true;
	
	return false;
}


int main()
{
	int z; cin>>z;
	for(int zz=1; zz<=z; zz++)
	{
		cin>>r>>t;
		
		unsigned long long a = 1; unsigned long long b =707106780 * 2 - r;//unsigned long long b =t/r/2;
		while(a+1 < b)
		{

			if(f ( (a+b)/2 ))
				a=(a+b)/2;
			else
				b=(a+b)/2;
		}
		a+=2;
		while(!f(a))
		a--;
		

		cout<<"Case #"<<zz<<": "<<a<<endl;
	}
	return 0;
}
