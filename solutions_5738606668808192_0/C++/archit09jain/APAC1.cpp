#include<bits/stdc++.h>
using namespace std;

#define lld long long
#define MAX 100000007

int prime[MAX];

void sieve()
{
	for(int i = 3;i*i<MAX;i+=2)
	{
		if(prime[i]==1)continue;
	
		for(int j = i;j<MAX;j+=i)
		{
			if(prime[j]==0 && (j&1))
			prime[j] = i;	
		}
	}
}

vector<lld> store;

lld divisor(lld n){
	
	if(n<2)return n;
	
	if(n==2)
		return -1;
	
	if(!(n&1))return 2;
	
	if(n<MAX)
	{
		if(prime[n]==0)return -1;
		else
			return prime[n];
	}
	else
	{		
		for(int j = 3;j*j<=n;j+=2)
		{
			if(n%j==0)
				return j;		
		}
		return -1;
	}
}

lld getValue(lld n,int base)
{
	if(n==0)return 0;
	
	if(n&1)
		return getValue(n>>1ll,base)*base + 1;
	else
		return getValue(n>>1ll,base)*base;
}

vector<lld> check(lld n){
	
	vector<lld> result;
	
	for(int base=2;base<=10;base++){
		
		lld value = getValue(n,base);
	
	//	cout<<value<<" ";
		lld d = divisor(value);
	//	cout<<d<<endl;
		if(d!=-1)
			result.push_back(d);
		else
			return result;
	}
	return result;
}
int main()
{
	//freopen("input.in","r",stdin);
	freopen("output.txt","w",stdout);
	
	sieve();

//	for(int i = 0;i<55;i++)
//		cout<<i<<" "<<prime[i]<<"\n";
	
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	
	int t;
	cin>>t;
	
	lld n,j;

	cout<<"Case #1:\n";
	
	for(int tst=1;tst<=t;tst++)
	{
		cin>>n>>j;
		
		for(int i =1;(i<(1<<n-2)) && j>0;i++)
		{
			
			lld x = (i<<1) + (1<<(n-1));
			
			x = x|1ll;
			vector<lld> r = check(x);
			
			
			if(r.size()<9)continue;
				
			j--;
			cout<<getValue(x,10)<<" ";
			
			for(int l = 0;l<9;l++)
				cout<<r[l]<<" ";
			cout<<endl;
		}
		
	}
	
	return 0;
}
