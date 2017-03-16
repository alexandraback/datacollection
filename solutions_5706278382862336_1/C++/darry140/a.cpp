#include <iostream>
#include <cstdio>
#include <set>
using namespace std;
long long GCD(long long a,long long b)//a>0 ¥B b>0
{
	if(a<b)
		a+=b,b=a-b,a-=b;//a+b<2^31
	while((a%=b)&&(b%=a));
	return a+b;
}
int main()
{
	freopen("Ain.in","r",stdin);
	freopen("Aout.txt","w",stdout);
	int T;
	cin>>T;
	set<long long> list;
	list.clear();
	for(long long i=1,k=0;k<130;k++,i*=2)
		list.insert(i);
	for(int i=1;i<=T;i++)
	{
		long long x,y;
		scanf("%lld/%lld",&x,&y);
		long long d=GCD(x,y);
		x/=d,y/=d;
		int ans=0;
		while(x<y)
		{
			ans++;
			x*=2;
		}
		printf("Case #%d: ",i);
		if(list.find(y)==list.end())
			cout<<"impossible\n";
		else	
			cout<<ans<<endl;
	}
	return 0;
}
