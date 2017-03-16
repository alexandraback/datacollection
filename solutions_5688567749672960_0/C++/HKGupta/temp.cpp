#include<bits/stdc++.h>
using namespace std;
long long rev(long long n)
{
	long long rev=0;
	while(n>0)
	{
		rev=10*rev+n%10LL;
		n=n/10LL;
	}
	return rev;
}
vector<long long> ct(100000000,-1);
long long cnt(long long n)
{
	if(n<100000000 && ct[n]!=-1)
		return ct[n];
	long long v=0;
	if(n<=20)
	{	
		ct[n]=n;
		return n;	
		
	}
	else 
	{
		long long r=rev(n);
		//cout<<n<<" rev "<<r<<endl;
		if(r>=n || n%10==0)
			v= 1+cnt(n-1);	
		else
			v= 1+min(cnt(n-1),cnt(r));
		
	}
	if(n<100000000)
		ct[n]=v;
	//cout<<n<<"  "<<v<<endl;		
	return v;
}
int main()
{
	int T;
	cin>>T;
	for(int i=0;i<T;i++)
	{
		long long N;
		cin>>N;
		
		ct[1]=1;


		cout<<"Case #"<<i+1<<": "<<cnt(N)<<"\n";	
	}


	return 0;
}