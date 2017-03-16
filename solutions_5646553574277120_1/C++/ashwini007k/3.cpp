#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("out2.txt","w",stdout);
	long long t;
	cin>>t;
	for(long long T=1;T<=t;T++)
	{
		long long c,d,v;
		cin>>c>>d>>v;
		long long a[10005],k=0,den[100];
		for(long long i=0;i<d;i++)
		{
			long long b;
			cin>>b;
			for(long long j=0;j<c;j++)
				a[k++]=b;
		}
		long long con=0,s=0;
		for(long long i=0;i<k&&s<=v;i++)
		{
			//cout<<s<<" "<<a[i]<<endl;
			
			while(a[i]>s+1&&s<v)
			{
				con++;
				long long z=s+1;
				//cout<<z<<" yes "<<s<<endl;
				for(long long j=0;j<c;j++)
					s+=z;
			}
			s+=a[i];
			//cout<<s<<endl;
		}
		//cout<<s<<endl;
		while(s<v)
			{
				con++;
				long long z=s+1;//cout<<z<<" yes "<<s<<endl;
				for(long long j=0;j<c;j++)
					s+=z;
			}
		cout<<"Case #"<<T<<": "<<con<<endl;
	}
	return 0;
}