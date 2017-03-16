#include<bits/stdc++.h>
using namespace std;
long long m[100];
int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.txt","w",stdout);
	long long a,b,c,B,M,T;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>T;
	m[0]=1;
	for(a=1;a<60;a++)
	{
		m[a]=m[a-1]*2;
	}
	for(a=0;a<T;a++)
	{
		cin>>B>>M;
		cout<<"Case #"<<a+1<<": "; 
		if(1ll<<(B-2)>=M)
		{
			cout<<"POSSIBLE\n";
			cout<<"0";
			for(b=1;b<B;b++)cout<<"1";
			cout<<"\n";
			M--;
			for(b=1;b<B-1;b++)
			{
				for(c=0;c<B-1;c++)
				{
					if(c<=b)cout<<"0";
					else cout<<"1";
				}
				if(M&(1ll<<(b-1)))cout<<"1";
				else cout<<"0";
				cout<<"\n";
			}
			for(b=0;b<B;b++)cout<<"0";
			cout<<"\n";	
		}
		else
		{
			cout<<"IMPOSSIBLE\n";
		}
	}
}
