#include<iostream>
using namespace std;

int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	int ans,a,b,temp,T;
	cin>>T;
	for (int k=0;k<T;k++)
	{
		scanf("%d/%d",&a,&b);
		cout<<"Case #"<<k+1<<": ";
		int temp=b;
		while (temp!=1&&temp%2==0) temp=temp/2;
		if (temp==1)
		{
			ans=1;
			while ((a*2<b)&&(b%2==0))
			{
				b=b/2;
				ans++;
			}
			if (b%2==0&&ans<=40) cout<<ans<<endl;
			else cout<<"impossible"<<endl;
		}
		else cout<<"impossible"<<endl;
	}
	return 0;
}