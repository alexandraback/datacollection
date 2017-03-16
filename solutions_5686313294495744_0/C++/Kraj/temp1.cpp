#include<bits/stdc++.h>
using namespace std;



string str,a,b,str1;
string S[16],S1[16];	
int mx,n;
void func(int ind)
{
	int i,j,k,cnt=0;
	k=ind;
	map<string,int>mp,mp1;
	i=0;
	for(i=0;i<n;i++)
	{
		if(ind&(1<<i))
		cnt++;
		else
		mp[S[i]],mp1[S1[i]];
		
	}
	for(i=0;i<n;i++)
	{
		
		if(ind&(1<<i))
		{
			if(mp.find(S[i])==mp.end() || mp1.find(S1[i])==mp1.end())
			break;
		}
		
	}
	if(i==n)
	mx=max(mx,cnt);
	
}
int main()
{
	ifstream cin("1B3s.in");
	ofstream cout("1B3sA.txt");
	int i,j,k,t,m,ind=1;
	
	
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=0;i<n;i++)
		cin>>S[i],cin>>S1[i];
		mx=0;
		for(i=0;i<(1<<n);i++)
			func(i)	;	
				
		cout<<"Case #"<<ind++<<": "<<mx<<endl;
		
		
	}
	
}
