#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <set>
#include <queue>
#include <algorithm>
#include <stack>

#define ll long long int
#define vi vector <int>
#define vl vector <ll>
#define vpii vector <pair<int, int> >
#define vpll vector <pair<ll, ll> >
#define pll pair<ll, ll>

#define f first
#define s second

#define sd(n) scanf("%d", &n)
#define sl(n) scanf("%lld", &n)

#define pb push_back
#define pob pop_back

#define max_size 100005
#define max_capacity INT_MAX
#define max_string_size 1000
#define max_node_size 340

using namespace std;

ll coins[120], pre[40];
ll mini;
ll temp_ar[40];

void recurse(ll place, ll d, ll v)
{
	//cout<<"here: "<<place<<" "<<s<<endl;
	if(place>v)
	{	
		cout<<"here\n";
		for(ll i=0; i<=v; i++)
			temp_ar[i] = 0;

		temp_ar[0] = 1;
		for(ll i=1; i<=v; i++)
		{
			if(coins[i])
			{
				for(ll j=v; j>=0; j--)
				{
					if(j+i<=v && temp_ar[j])
					{
						temp_ar[j+i] = 1;
					}
				}
			}
		}

		ll count = 0;
		for(ll i=1; i<=v; i++)
			if(temp_ar[i]==1)
				count++;


		if(count==v)
		{
			ll temp = 0;
			for(ll i=0; i<=v; i++)
				if(coins[i]==1 && pre[i]==0)
					temp++;

			//cout<<temp<<" "<<mini<<endl;

			if(mini==-1 || mini>temp)
				mini = temp;
		}

		return;
	}

	coins[place] = 1;
	recurse(place+1, d, v);

	if(pre[place]==0)
	{
		coins[place] = 0;
		recurse(place+1, d, v);
	}
}

int main()
{
	ll t;
	cin>>t;
	for(ll c=1; c<=t; c++)
	{
		ll c_, d, v;
		cin>>c_>>d>>v;

		for(ll i=0; i<d; i++)
			cin>>coins[i];

		sort(coins, coins+d);

		ll next = 1;
		ll ans = 0;
		ll pos = 0;
		while(next<=v)
		{
			while(pos<d && coins[pos]<=next)
			{
				next += c_*coins[pos];
				pos++;
			}

			if(next<=v)
			{
				ans++;
				next += c_*next;
			}
		}
		

		cout<<"Case #"<<c<<": "<<ans<<endl;
	}

	return 0;
}
