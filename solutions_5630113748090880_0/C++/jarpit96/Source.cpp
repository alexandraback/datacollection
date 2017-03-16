#include <iostream>
#include<map>

using namespace std;

int main() 
{
	int t, n, temp, temp2;
	cin>>t;
	map<int, int> mp;
	map<int, int>::iterator it;
	for(int i=0; i<t; i++)
	{
		cin>>n;
		
		for(int j=0; j<(2*n)-1; j++)
		{
			for(int k=0; k<n; k++)
			{
				cin>>temp;
				temp2 = mp[temp];
		//		cout<<temp2<<endl;
				mp[temp] = temp2+1;
			}
		}
		cout<<"Case #"<<i+1<<": ";
		for(it = mp.begin(); it!= mp.end(); it++)
		{
			if((*it).second %2 == 1)
			{
				cout<<(*it).first<<" ";
			}
		}
		cout<<endl;
		mp.clear();
	}
	return 0;
}