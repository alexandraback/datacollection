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

int main()
{
	ll t;
	cin>>t;
	for(ll m=1; m<=t; m++)
	{
		ll r, c, w;
		cin>>r>>c>>w;

		ll temp = c/w;
		if(c%w==0)
			temp--;
		
		temp += w;
		temp *= r;

		cout<<"Case #"<<m<<": "<<temp<<endl;
	}
	return 0;
}
