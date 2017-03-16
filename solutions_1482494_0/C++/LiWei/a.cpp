#include <iostream>
using namespace std;
int main()
{
	int c,t,n,i,j,l,s;
	int a[1010],b[1010];
	bool ok;
	cin>>t;
	for(c=0;c<t;c++)
	{
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>a[i]>>b[i];
		}
		for(i=0;i<n-1;i++)
			for(j=0;j<n-1-i;j++)
			{
				if(b[j]<b[j+1])
				{
					swap(b[j],b[j+1]);
					swap(a[j],a[j+1]);
				}
			}
		cout<<"Case #"<<c+1<<": ";
		l=n*2;
		s=0;
		j=0;
		while(l>0)
		{
			ok=0;
			for(i=0;i<n;i++)
				if(s>=b[i])
				{
					//cout<<"b"<<a[i]<<' '<<b[i]<<endl;
					j++;
					if(a[i]==100000)
					{
						s+=1;
						l--;
					}else
					{
						s+=2;
						l-=2;
					}
					b[i]=a[i]=100000;
					ok=1;
				}
			if(ok)
				continue;
			for(i=0;i<n;i++)
				if(s>=a[i])
				{
					//cout<<"a"<<a[i]<<' '<<b[i]<<endl;
					j++;
					s+=1;
					a[i]=100000;
					l--;
					ok=1;
					break;
				}
			if(!ok && l>0)
			{
				cout<<"Too Bad\n";
				break;
			}
		}
		if(l==0)
			cout<<j<<endl;
	}
}
