#include<bits/stdc++.h>
using namespace std;

#define lld long long
#define MAX 1000005

lld dp[MAX];
set<lld> hash;
int visited[10];

bool check()
{
	for(int i = 0;i<10;i++)
	{
		if(visited[i]==0)
			return 0;
	}
	return 1;
}

void mark(lld n)
{
	if(n==0)
		visited[0]=1;
	else{
		
		while(n!=0){
			visited[n%10]=1;
			n/=10;
		}
	}
}

int main()
{
	freopen("input.in","r",stdin);
	freopen("output.txt","w",stdout);
	
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	
	int t,n;
	cin>>t;
	
	memset(dp,-1,sizeof(dp));
	
	for(int tst=1;tst<=t;tst++)
	{
		cin>>n;
		
		if(dp[n]!=-1)
		{
			cout<<dp[n]<<" ";
			continue;
		}
		
		hash.clear();
		memset(visited,0,sizeof(visited));
	
		int flag = 0;
		
		lld x  = n;
		
		while(true)
		{
		//	cout<<n<<" ";
			if(hash.find(n)!=hash.end())
			{
				flag = 1;
				break;
			}
			
			hash.insert(n);
			
			mark(n);
			
			if(check())
				break;
			n+=x;
		}
		
		if(!flag)
			cout<<"Case #"<<tst<<": "<<n<<endl;
		else
			cout<<"Case #"<<tst<<": INSOMNIA\n";
		
		
	}
	
	return 0;
}
