#include<bits/stdc++.h>
using namespace std;
int s[1000010]={0};
int rev(int n)
{
	int c=0;
	while(n)
	{
		c=c*10 + n%10;
		n/=10;
	}
	return c;
}
queue<int > q;
void init()
{
	
	q.push(1);
	s[1]=1;
	while(!q.empty())
	{
		int p=q.front();
		
		//cout<<p<<" "<<s[p]<<endl;
		q.pop();
		if(p>1000000)continue;
		if(!s[p+1])
		{q.push(p+1);s[p+1]=s[p]+1;}
		int r=rev(p);
		if(!s[r])
		{q.push(r);s[r]=s[p]+1;}
	}
}
int main()
{
	freopen("out.txt","w",stdout);
	init();
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n;
		cin>>n;
		cout<<"Case #"<<i+1<<": "<<s[n]<<endl;
	}
	return 0;
}