#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	ifstream cin;
	ofstream cout;
	cin.open("A-large.in");
	cout.open("A-large-output.txt");
	int t,i;
	cin>>t;
	for(i=1;i<=t;i++)
	{
		int r,c,w,ans;
		cin>>r>>c>>w;
		ans=(c/w)*r;
		ans+=w-1;
		if (c%w != 0)
		{
			ans++;
		}
		cout<<"Case #"<<i<<": "<<ans<<endl;	
	}
}

