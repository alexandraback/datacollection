#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
bool lst[10]={0};
void chglst(int num)
{
	while(num)
	{
		lst[num%10]=1;
		num/=10;
	}
}
bool chklst()
{
	for(int i=0;i<=9;i++)
		if(!lst[i])return false;
	return true;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	int T;cin>>T;
	for(int ti=1;ti<=T;ti++)
	{
		cout<<"Case #"<<ti<<": ";
		memset(lst,0,sizeof lst);
		LL n;cin>>n;
		if(n==0)cout<<"INSOMNIA"<<endl;
		else
		{
			LL ans=n;
			while(true)
			{
				chglst(ans);
				if(chklst())
				{
					cout<<ans<<endl;
					break;
				}
				ans+=n;
			}
		}

	}
	return 0;
}
