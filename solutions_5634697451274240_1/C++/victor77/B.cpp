#include <iostream>
#include <string>

using namespace std;

int main()
{
	int T;
	cin>>T;
	for(int case_id=0;case_id<T;case_id++)
	{
		string temp;
		cin>>temp;
		int ans=0;
		char cur='+';
		for(int i=temp.length()-1;i>=0;i--)
		{
			if(temp[i]!=cur)
			{
				ans++;
				cur=temp[i];
			}
				
		}
		cout<<"Case #"<<case_id+1<<": "<<ans<<endl;
	}
	return 0;	
}