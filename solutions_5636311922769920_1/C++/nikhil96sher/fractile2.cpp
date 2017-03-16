#include<bits/stdc++.h>

using namespace std;
#define in(n) scanf("%lld",&n)
#define ll long long

ll c,k,s;

long long win()
{
	ll powkc = 1;
	int i;
	for(i=1;i<c;i++)
		powkc *=k; 
	ll pow2kc =powkc;
	ll sum,power,miss,done,temp,can;
	can = k/c;
	if(k%c!=0)
		can++;
	if(s<can)
	{
		cout<<"IMPOSSIBLE"<<endl;
	}
	else
	{
		sum = 0;
		miss = 1;
		bool flag = true;
		while(can>0 && (miss!=k || flag))
		{
			if(miss==k)
				flag = false;
			powkc = pow2kc;
			sum = 0;

			for(i=0;i<c;i++)
				{
				sum+= powkc*(miss-1);
				powkc/=k;
				if(miss<k)
					miss+=1;
				}
			cout<<sum+1<<" ";
			can--;
		}	
		cout<<endl;
	}
}

int main()
{
	long long t;
	in(t);
	ll ans;
	for(int i=1;i<=t;i++)
	{
		in(k);
		in(c);
		in(s);
		cout<<"Case #"<<i<<": ";
		win();
	}
}