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
		long long int L,X;
		cin>>L>>X;
		string S;
		cin>>S;
		
		int a = 1;
		
		for(long long int j=0;j<L;j++)
		{
			a = f(a,(S[j]-'i')+2);
		}
		int a1 = 1;
		long long int K = (X%4);
		for(long long int i=0;i<K;i++)
		{
			a1 = f(a1,a);
		}
		if(a1 == -1)
		{
			int b = 1;
			long long int iid = -1;
			for(long long int j=0;j<L;j++)
			{
				b = f(b,(S[j]-'i')+2);
				int tmp = b;
				if(tmp == 2)
				{
					if(iid==-1)
					{
						iid = j;
					}
				}
				else
				{
					for(long long int k=1;k<=3;k++)
					{
						tmp = f(a,tmp);
						if(tmp==2)
						{
							if(iid==-1 and (k*L+j<X*L))
							iid = k*L + j;
							else if(k*L + j< L*X)
							iid = min(iid,k*L+j);
							break;
						}
					}
				}
			}
			long long int kid = -1;
			b = 1;
			for(long long int j=L-1;j>=0;j--)
			{
				b = f((S[j]-'i')+2,b);
				int tmp = b;
				if(tmp == 4)
				{
					kid = max(kid,(X-1)*L + j);
				}
				else
				{
					for(long long int k=1;k<=3;k++)
					{
						tmp = f(tmp,a);
						if(tmp==4 and (X-1-k)*L+j<X*L)
						{
							kid = max(kid,(X-1-k)*L+j);
							break;
						}
					}
				}
			}
			if(kid!=-1 and iid!=-1 and (kid<L*X and kid>=0) and(iid<L*X and iid>=0))
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
