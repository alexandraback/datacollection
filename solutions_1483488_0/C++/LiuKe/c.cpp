#include<iostream>
#include<algorithm>
#include<set>
#include<cstdio>
#include<string>
using namespace std;
int T;
long long a,b,bits,k;
set <long long> s;

int main()
{
	freopen("C-small-attempt0.in","r",stdin);
	freopen("c.out","w",stdout);
	cin>>T;
	for (int t=1;t<=T;t++)
	{
		s.clear();
		cin>>a>>b;
		k=10LL;
		for (bits=2;a>=k*10LL;bits++)	k*=10LL;
		if (b>10)
			for (long long i=a;i<=b;i++)
			{
				long long j=i,x,y;
				for (long long ii=1;ii<bits;ii++)
				{
					j=j/k+(j%k)*10;
					if (j>=a && j<=b && i!=j)
					{
						x=i;		y=j;
					//	cout<<i<<" "<<j<<endl;
						if (x>y) swap (x,y);
						s.insert( (b+1)*x+y );
					}	
				}
			}
		cout<<"Case #"<<t<<": "<<s.size()<<endl;
	}
	fclose(stdin);	fclose(stdout);
	return 0;
}
