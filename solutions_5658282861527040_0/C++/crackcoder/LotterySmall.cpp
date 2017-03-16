#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    
    int t;
     cin>>t;
	 for(int i=0;i<t;i++)
     {
     	int a, b, ka;
     	cin>>a>>b>>ka;
     	int count =0;
     	for(int j=0;j<a;j++)
     	{
     		for(int k=0;k<b;k++)
     		{
     			if((j&k) < ka) count++;
     		}
     	}
     	cout<<"Case #"<<i+1<<": "<<count<<endl;
     }
	 return 0;     
}
