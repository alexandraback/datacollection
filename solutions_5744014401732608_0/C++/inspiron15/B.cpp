#include <iostream>
#include<math.h>
using namespace std; 


int main() {
  long long int t, n, m ,b,total;
  cin >> t; 
  long long int sol;
  int a[100][100];
  for (int i = 1; i <= t; ++i) {
  
  	for(int x=0; x<100; x++)
  	{
  	
	   for(int y=0; y<100; y++)
  	 	{
  			a[x][y]=0;			
		}
	}
  
  	for(int x=0; x<100; x++)
  	{
  	
	   for(int y=x+1; y<100; y++)
  	 	{
  			a[x][y]=1;			
		}
	}
  
    cin >> b >> m;
    sol = pow(2,b-2);
    if(m>sol)
    {
    	cout << "Case #" << i << ":";
    	cout<<" IMPOSSIBLE"<<endl;
    	continue;
	}else
	{
		cout << "Case #" << i << ": POSSIBLE";
	}
	
	for(int y=0; y<100; y++)
  	{
  			a[b][y]=0;			
	}
	
	m=sol-m;
	sol=sol/2;
	long long int count = b-2 ;
	while(m!=0)
	{
		if(m>=sol)
		{
			a[count][b-1]=0;
		
			m=m-sol;
		}
		
		if(sol!=1){	
		sol/=2;		
		}
	
		count--;
	}
	
	for(int x=0; x<b; x++)
  	{
  		cout<<"\n";
	   for(int y=0; y<b; y++)
  	 	{
  			cout<<a[x][y];			
		}
	}
	  cout<< endl;
    
  
  
  }
  
  return 0;
}
