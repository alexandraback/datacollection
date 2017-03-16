#include<iostream>
#include<iomanip>
using namespace std;
double C,F,X;
double calcu(int N)
{
	double time=0;
	for (int i=0;i<N;i++) time+=C/(2+i*F);
	return time+X/(2+N*F);
}
int main()
{
	int T,K,l,r,mid;
	double ans,temp;
	freopen("QR_B.in","r",stdin);
	freopen("QR_B.out","w",stdout);
	cin>>T;
	for (int k=0;k<T;k++)
	{
		cin>>C>>F>>X;
		ans=calcu(0);
		l=0;
		r=1000000;
		/*while (l<r)
		{
			mid=(l+r)/2;
			temp=calcu(mid);
			if (temp<ans)
			{
				ans=temp;
				l=mid;
			}
			else r=mid-1;
		}*/
		for (mid=l+1;mid<r;mid++)
		{
			temp=calcu(mid);
			if (temp<ans) ans=temp;
			else break;
		}
		cout<<"Case #"<<k+1<<": ";
		cout<<setiosflags(ios::fixed);
		cout<<setprecision(7)<<ans<<endl;
	}
}