#include<bits/stdc++.h>

using namespace std;

inline int f(int a,int b)
{
	if(a==1)
	return b;
	else if(b==1)
	return a;
	else if(a==-1)
	return -b;
	else if(b==-1)
	return -a;
	else if(a==2)
	{
		if(b==2)
		return -1;
		else if(b==3)
		return 4;
		else if(b==4)
		return -3;
		else if(b==-2)
		return 1;
		else if(b==-3)
		return -4;
		else
		return 3;
	}
	else if(a==3)
	{
		if(b==2)
		return -4;
		else if(b==3)
		return -1;
		else if(b==4)
		return 2;
		else if(b==-2)
		return 4;
		else if(b==-3)
		return 1;
		else
		return -2;
	}
	else if(a==4)
	{
		if(b==2)
		return 3;
		else if(b==3)
		return -2;
		else if(b==4)
		return -1;
		else if(b==-2)
		return -3;
		else if(b==-3)
		return 2;
		else
		return 1;
	}
	else
	{
		return -1*f(-a,b);
	}
}

int main()
{
	int T;
	cin>>T;
	for(int idx = 1;idx<=T;idx++)
	{
		bool o = false;
		int L,X;
		cin>>L>>X;
		string S;
		cin>>S;
		
		int a = 1;
		for(int i=0;i<X;i++)
		{
			for(int j=0;j<L;j++)
			{
				a = f(a,(S[j]-'i')+2);
			}
		}
		if(a == -1)
		{
			a = 1;
			int iid = -1;
			for(int i=0;i<X;i++)
			{
				for(int j=0;j<L;j++)
				{
					a = f(a,(S[j]-'i')+2);
					if(a==2)
					{
						iid = i*L+j;
						break;
					}
				}
				if(a==2)
				break;
			}
			int kid = -1;
			int cnt = L*X-1;
			a = 1;
			for(int i=0;i<X;i++)
			{
				for(int j=L-1;j>=0;j--)
				{
					a = f((S[j]-'i')+2,a);
					if(a==4)
					{
						kid = cnt;
						break;
					}
					cnt--;
				}
				if(a==4)
				break;
			}
			if(kid!=-1 and iid!=-1)
			{
				if(kid-iid>1)
				o = true;
			}
			
		}
		if(o)
		cout<<"Case #"<<idx<<": "<<"YES"<<'\n';
		else
		cout<<"Case #"<<idx<<": "<<"NO"<<'\n';
	}
}
