#include <iostream>
#include <string>
using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int ic=1;ic<=t;++ic)
	{
		cout<<"Case #"<<ic<<": ";
		string s;
		cin>>s;
		int ans=0,total=0;
		for(auto it = s.rbegin();it!=s.rend();++it)
		{
			if(*it=='-' && total%2==0 || 
					*it=='+' && total%2)
			{
				++total;
				++ans;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
