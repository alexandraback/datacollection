#include <stdlib.h>
#include <fstream>
#include <algorithm>
#include <iostream>
using namespace std;

int cmp ( const void *a , const void *b )  
{  
	return *(int *)a - *(int *)b;  
}  

int main ()
{
	ifstream R("A-small-attempt3.in");
    ofstream W("A-small-attempt3.out");
    
    int t;
    R>>t;
    for (int ti=1;ti<=t;++ti)
    {
    	int a,n;
    	int size[101];
    	R>>a>>n;
    	for(int ni=0;ni<n;++ni)
    	{
    		R>>size[ni];
    	}
		qsort(size,n,sizeof(size[0]),cmp);
		for(int i=0;i<n;++i)
		cout<<size[i]<<endl;
		
		if(a==1)
		{
			W<<"Case #"<<ti<<": "<<n<<endl;
			continue;
		}
		int count=0;
		int b;
		int ansmin=n;
		for(int ni=0;ni<n;++ni)
		{
			cout<<"a"<<a<<" "<<count<<endl;
			if(a>size[ni])
			{
				a=a+size[ni];
				ansmin=min(count+n-ni-1,ansmin);
				cout<<"a"<<a<<" "<<count<<" "<<count+n-ni-1<<endl;
				continue;
			}
			b=a;
			
			while(b<=size[ni])
			{
				b=b+b-1;
				cout<<"b"<<b<<" "<<count<<endl;
				count++;
			}
			a=b+size[ni];
			ansmin=min(count+n-ni-1,ansmin);
			cout<<"a"<<a<<" "<<count<<" "<<count+n-ni-1<<endl;
		}
		ansmin=min(count,ansmin);
	
    		W<<"Case #"<<ti<<": "<<ansmin<<endl;
	}
}
