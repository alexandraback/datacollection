#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <memory.h>

using namespace std;

int a, b, k, t, count0;

int main()
{
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	cin>>t;
	while(t--)
	{
		cout<<"Case #"<<++count0<<": ";
		cin>>a>>b>>k;
		int ans=0;
		for(int i=0; i<a; ++i)
			for(int j=0; j<b; ++j)
				if ((i&j)<k)
					ans++;
		cout<<ans<<endl;
	}
	return 0;
}