/*
ID: ashish1610
PROG:
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll				long long int
#define vi				vector<int>
#define vl				vector<ll>
#define	pii				pair<int,int>
#define pil				pair<int, ll>
#define pll				pair<ll, ll>
#define pli 			pair<ll, int>
#define pb(v, a)		v.push_back(a)
#define mp(a, b)		make_pair(a, b)
#define MOD				1000000007
#define rep(i, a, b)	for(i=a; i<=b; ++i)
#define rrep(i, a, b)	for(i=a; i>=b; --i)
#define si(a)			scanf("%d", &a)
#define sl(a)			scanf("%lld", &a)
#define pi(a)			printf("%d", a)
#define pl(a)			printf("%lld", a)
#define pn 				printf("\n")
ll pow_mod(ll a, ll b)
{
	ll res = 1;
	while(b)
	{
		if(b & 1)
			res = (res * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}
	return res;
}
bool visited[1000005];
int main()
{
	int t, tcase;
	si(t);
	rep(tcase, 1, t)
	{
		ll n;
		sl(n);
		cout<<"Case #"<<tcase<<": ";
		if(n <= 20)
			cout<<n<<endl;
		else
		{
			memset(visited, false, sizeof(visited));
			queue<pair<ll, ll> > q;
			q.push(make_pair(1LL, 1LL));
			visited[1] = true;
			ll res = 0;
			while(!q.empty())
			{
				ll val = q.front().first;
				ll tmp_res = q.front().second;
				q.pop();
				if(val == n)
				{
					res = tmp_res;
					break;
				}
				if(val + 1 <= n && !visited[val + 1])
				{
					visited[val + 1] = true;
					q.push(make_pair(val + 1, tmp_res + 1));
				}
				ll tmp = val;
				vi dig;
				while(tmp)
				{
					dig.push_back(tmp % 10);
					tmp /= 10;
				}
				ll rev_val = 0;
				int i;
				rep(i, 0, (int)(dig.size()) - 1)
					rev_val = rev_val * 10 + dig[i];
				if(rev_val <= n && !visited[rev_val])
				{
					visited[rev_val] = true;
					q.push(make_pair(rev_val, tmp_res + 1));
				}
			}
			cout<<res<<endl;
		}
	}
	return 0;
}