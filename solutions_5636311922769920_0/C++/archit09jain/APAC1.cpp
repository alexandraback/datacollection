#include<bits/stdc++.h>
using namespace std;

#define lld long long

#define MAX 105

lld dp[MAX];
int main()
{
	freopen("input.in","r",stdin);
	freopen("output.txt","w",stdout);
	
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	
	lld k,c,s;
	int t;
	cin>>t;
	
	for(int tst=1;tst<=t;tst++)
	{
		cin>>k>>c>>s;
		
		cout<<"Case #"<<tst<<": ";
		
		if(k==s){
		
		dp[1] = 0;
		for(int i = 2;i<=c;i++)
			dp[i]  = (dp[i-1]*k) + (k-1);
			
		lld gap = dp[c];
		lld curr = 1;
		for(int i = 0;i<s;i++)
		{
			cout<<curr<<" ";
			curr = curr + gap+1;
		}
		
		cout<<endl;
		}
		else{
			cout<<"IMPOSSIBLE\n";
		}
	}
}

