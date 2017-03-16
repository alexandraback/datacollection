#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("out2.txt","w",stdout);
	int t;
	cin>>t;
	for(int T=1;T<=t;T++)
	{
		int c,d,v;
		cin>>c>>d>>v;
		int a[10005],k=0,den[100];
		for(int i=0;i<d;i++)
		{
			int b;
			cin>>b;
			for(int j=0;j<c;j++)
				a[k++]=b;
		}
		int con=0,s=0;
		for(int i=0;i<k&&s<=v;i++)
		{
			//cout<<s<<" "<<a[i]<<endl;
			
			while(a[i]>s+1&&s<v)
			{
				con++;
				int z=s+1;
				//cout<<z<<" yes "<<s<<endl;
				for(int j=0;j<c;j++)
					s+=z;
			}
			s+=a[i];
			//cout<<s<<endl;
		}
		//cout<<s<<endl;
		while(s<v)
			{
				con++;
				int z=s+1;//cout<<z<<" yes "<<s<<endl;
				for(int j=0;j<c;j++)
					s+=z;
			}
		cout<<"Case #"<<T<<": "<<con<<endl;
	}
	return 0;
}