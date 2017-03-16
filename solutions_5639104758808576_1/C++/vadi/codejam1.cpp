#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	for(int qq=1;qq<=t;qq++)
	{
		int k;
		string s;
		int ans=0;
		scanf("%d",&k);
		cin>>s;
		int kk=0;
		for(int i=0;i<s.length();i++)
		{
			if(kk<i)
			{
				ans+=i-kk;	
				kk=i;
			}
			kk+=s[i]-'0';
		}	
		cout<<"Case #"<<qq<<": "<<ans<<endl;
	}
	return 0;
}
