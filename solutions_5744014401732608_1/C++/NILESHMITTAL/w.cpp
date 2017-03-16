#include<bits/stdc++.h>
using namespace std;
#define ll long long 

/////////////
 ////////////
int main()
{
	
	ll asd[60][60], i, j,k,o,yr, T, n;
	cin>>T;
	for(yr=1; yr<=T; ++yr)
	{
		cin>>n>>k;
		o=1;
		for(i=1; i<=n-2; ++i) o*=2;
		if(k>o) { 
		
		
		
		
			cout<<"Case #"<<yr<<": IMPOSSIBLE"<<endl;
			continue;
			}
			
	cout<<"Case #"<<yr<<": POSSIBLE"<<endl;
		for(i=1; i<=n; ++i)
		{
			for(j=1; j<=i; ++j) asd[i][j]=0;
			
			/////////////////
			for(j=i+1; j<n; ++j) asd[i][j]=1;
		}
		if(k==o)
		{
			for(i=1; i<n; ++i) asd[i][n]=1;
		}
		else
		{
			asd[1][n]=0;
			for(i=2; i<n; ++i)
			{
				asd[i][n]=(k%2);
				k/=2;
			}
		}
		for(i=1; i<=n; ++i)
		{
			for(j=1; j<=n; ++j)
			{
				cout<<asd[i][j];
				
				
			}
			cout<<endl;
		}
	}
}
