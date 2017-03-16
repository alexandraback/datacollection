#include <iostream>
using namespace std;

int main()
{
	int t;
	cin>>t;
	int r=100;
	int n=3;
	int m=5;
	int k=7;
	cin>>r>>n>>m>>k;
	cout<<"Case #1"<<":\n";
	for (int i = 0; i < r; ++i)
	{
		int num;
		bool flag=false;
		int no2[21];
		int cnt=0;
		for (int j = 0; j < k; ++j)
		{
			cin>>num;
			if(flag==false)
			{
			int p=5;
			int no=0;
			int a[3];
			while(num>1 && no<3)
			{
				if(num%p==0)
				{
					num=num/p;
					a[no]=p;
					no++;
				}
				else
					p--;
			}
			if(no==2)
			{
				no2[cnt]=a[0];
				no2[cnt+1]=a[1];
				cnt+=2;
			}
			if(num==1 && no==3)
				{
					flag=true;
					cout<<a[0]<<a[1]<<a[2]<<endl;
				}
			}
		}
		if(flag==false)
		{
			bool numb[6]={0};
				for (int l = 0; l < cnt; ++l)
				{
					numb[no2[l]]=1;
				}
				int c=0;
				for (int k = 1; k < 6; ++k)
				{
					if(numb[k]==1)
					{
						cout<<k;
						c++;
					}
				}
				if(c==3)
					cout<<endl;
				if(c==2)
					cout<<"1\n";
				if(c==1)
					cout<<"11\n";
				if(c==0)
					cout<<"111\n";
		}
		
			
	}
}
